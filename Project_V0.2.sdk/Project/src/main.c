/*===========================================================================================
 * Filename: main.c
 *
 * Authors: Kyle O'Hara & Ben Wedemire
 * Student IDs: 3532550 & 3515624
 * Date: 2018/12/3
 *
 * Description: main.c contains the hardware initialization, IP initializations,
 * 				encrypting/decrypting function calls, keypad functionality, UDP function
 * 				calls, library includes, defines and variable initializations
 *
 ==========================================================================================*/

//-----------------------------START section for includes/defines-------------------------------------------//
#include "PmodKYPD.h"
#include "sleep.h"
#include "functions_4261.h"
#include "xblowfish_encipher.h"
#include "xblowfish_decipher.h"
#include "Xgpio.h"
#include <stdio.h>
#include "xparameters.h"
#include "netif/xadapter.h"
#include "platform.h"
#include "platform_config.h"
#include "lwip/tcp.h"
#include "xil_cache.h"
#include "BLOWFISH.C"
#include "BLOWFISH.H"

#if defined (__arm__) || defined(__aarch64__)
	#include "xil_printf.h"
#endif

#if LWIP_DHCP==1
	#include "lwip/dhcp.h"
#endif

#define ENCRYPT_DEVICE_ID 	XPAR_BLOWFISH_ENCIPHER_0_DEVICE_ID
#define DECRYPT_DEVICE_ID	XPAR_BLOWFISH_DECIPHER_0_DEVICE_ID
#define COUNTER_DEVICE_ID 	XPAR_AXI_GPIO_0_DEVICE_ID

#define MAX_FRAME_SIZE 1448 //set the maximum number of bytes that can be passed in a single ethernet frame

PmodKYPD myDevice;

XBlowfish_encipher 	ENCRYPT;
XBlowfish_decipher 	DECRYPT;
XGpio			  	COUNTER;

void DemoInitialize();
char *DemoRun();
void DemoCleanup();
void DisableCaches();
void EnableCaches();
void DemoSleep(u32 millis);

/* defined by each RAW mode application */
void print_app_header();
int start_application();
int start_UDP();
int transfer_data();
int transfer_data_old();
void tcp_fasttmr(void);
void tcp_slowtmr(void);

/* missing declaration in lwIP */
void lwip_init();

#if LWIP_DHCP==1
extern volatile int dhcp_timoutcntr;
err_t dhcp_start(struct netif *netif);
#endif

extern volatile int TcpFastTmrFlag;
extern volatile int TcpSlowTmrFlag;
static struct netif server_netif;
struct netif *echo_netif;
short keybytes = 16;
char *encrypt_key = "1A8C556BAAD4567B"; //not used at the moment
short hardware_encrypt_flag = 0; 	//set this to default to software
short run_start = 0;

void
print_ip(char *msg, struct ip_addr *ip) 
{
	print(msg);
	xil_printf("%d.%d.%d.%d\n\r", ip4_addr1(ip), ip4_addr2(ip), 
			ip4_addr3(ip), ip4_addr4(ip));
}

void
print_ip_settings(struct ip_addr *ip, struct ip_addr *mask, struct ip_addr *gw)
{

	print_ip("Board IP: ", ip);
	print_ip("Netmask : ", mask);
	print_ip("Gateway : ", gw);
}

#if defined (__arm__) && !defined (ARMR5)
#if XPAR_GIGE_PCS_PMA_SGMII_CORE_PRESENT == 1 || XPAR_GIGE_PCS_PMA_1000BASEX_CORE_PRESENT == 1
int ProgramSi5324(void);
int ProgramSfpPhy(void);
#endif
#endif

#ifdef XPS_BOARD_ZCU102
#ifdef XPAR_XIICPS_0_DEVICE_ID
int IicPhyReset(void);
#endif
#endif
//-----------------------------END section for includes/defines---------------------------------------------//


int main()
{
	//-----------------------------START section for Hardware Initializations---------------------------------------------//
	//Setting up the counter

	int status;

	status = XGpio_Initialize(&COUNTER, COUNTER_DEVICE_ID);
	if (status != XST_SUCCESS) return XST_FAILURE;

	XGpio_SetDataDirection(&COUNTER, 1, 0xFFFFFFFF);
	xil_printf("Counter initialized\r\n");

	unsigned long start, end;


	//Setting up the hardware encryption block

	XBlowfish_encipher_Initialize(&ENCRYPT, ENCRYPT_DEVICE_ID); // initialize encrypt block
	XBlowfish_encipher_EnableAutoRestart(&ENCRYPT);
	xil_printf("Hardware encryption initialized\r\n");


	//Setting up the hardware decryption block

	XBlowfish_decipher_Initialize(&DECRYPT, DECRYPT_DEVICE_ID); // initialize decrypt block
	XBlowfish_decipher_EnableAutoRestart(&DECRYPT);
	xil_printf("Hardware decryption initialized\r\n");

	//-----------------------------END the section for Hardware Initializations-------------------------------------------------//

	//-----------------------------START the section for initializing IP--------------------------------------------------------//

	struct ip_addr ipaddr, netmask, gw;

	/* the mac address of the board. this should be unique per board */
	unsigned char mac_ethernet_address[] =
	{ 0x00, 0x0a, 0x35, 0x00, 0x01, 0x02 };
	echo_netif = &server_netif;
#if defined (__arm__) && !defined (ARMR5)
#if XPAR_GIGE_PCS_PMA_SGMII_CORE_PRESENT == 1 || XPAR_GIGE_PCS_PMA_1000BASEX_CORE_PRESENT == 1
	ProgramSi5324();
	ProgramSfpPhy();
#endif
#endif

/* Define this board specific macro in order perform PHY reset on ZCU102 */
#ifdef XPS_BOARD_ZCU102
	IicPhyReset();
#endif

	init_platform();

#if LWIP_DHCP==1
    ipaddr.addr = 0;
	gw.addr = 0;
	netmask.addr = 0;
#else
	/* initliaze IP addresses to be used */
	IP4_ADDR(&ipaddr,  192, 168,   1, 10);
	IP4_ADDR(&netmask, 255, 255, 255,  0);
	IP4_ADDR(&gw,      192, 168,   1,  1);
#endif	
	print_app_header();

	lwip_init();

  	/* Add network interface to the netif_list, and set it as default */
	if (!xemac_add(echo_netif, &ipaddr, &netmask,
						&gw, mac_ethernet_address,
						PLATFORM_EMAC_BASEADDR)) {
		xil_printf("Error adding N/W interface\n\r");
		return -1;
	}
	netif_set_default(echo_netif);

	/* now enable interrupts */
	platform_enable_interrupts();

	/* specify that the network if is up */
	netif_set_up(echo_netif);

#if (LWIP_DHCP==1)
	/* Create a new DHCP client for this interface.
	 * Note: you must call dhcp_fine_tmr() and dhcp_coarse_tmr() at
	 * the predefined regular intervals after starting the client.
	 */
	dhcp_start(echo_netif);
	dhcp_timoutcntr = 24;

	while(((echo_netif->ip_addr.addr) == 0) && (dhcp_timoutcntr > 0))
		xemacif_input(echo_netif);

	if (dhcp_timoutcntr <= 0) {
		if ((echo_netif->ip_addr.addr) == 0) {
			xil_printf("DHCP Timeout\r\n");
			xil_printf("Configuring default IP of 192.168.1.10\r\n");
			IP4_ADDR(&(echo_netif->ip_addr),  192, 168,  1, 10);
			IP4_ADDR(&(echo_netif->netmask), 255, 255, 255,  0);
			IP4_ADDR(&(echo_netif->gw),      192, 168,   1,  1);
		}
	}

	ipaddr.addr = echo_netif->ip_addr.addr;
	gw.addr = echo_netif->gw.addr;
	netmask.addr = echo_netif->netmask.addr;
#endif

	print_ip_settings(&ipaddr, &netmask, &gw);

	//-----------------------------END the section for initializing IP----------------------------------------------------------//

	//-----------------------------START the section for the Encryption/Decryption----------------------------------------------//

	char *data_array;
	int *temp1;
	temp1 = calloc(1,4);
	int *temp12;
	temp12 = calloc(1,4);
	int *temp_int_array;
	int *temp_array;

	DemoInitialize(); //initialize the keypad

	restart: data_array = DemoRun(); //get data from keypad

	char *encrypted_message;
	encrypted_message = calloc(MAX_FRAME_SIZE,sizeof(char));
	char *decrypted_message;
	decrypted_message = calloc(MAX_FRAME_SIZE+8,sizeof(char));


	if (run_start) {
		xil_printf("%s\r\n", data_array);
		xil_printf("Data_array length is: %d\r\n", strlen(data_array));
	} //end if

	int length_string = sizeof(*data_array);

	if (run_start) {
	xil_printf("%d\r\n", length_string);
	} //end if

	int *int_array;
	int_array = data_array;

	if (!hardware_encrypt_flag){ //if software was selected

		temp_int_array = int_array;
		start = XGpio_DiscreteRead(&COUNTER, 1);
		while(*temp_int_array){
			*temp1 = *temp_int_array;
			temp_int_array++;
			*temp12 = *temp_int_array;
			temp_int_array++;
			Blowfish_encipher(temp1,temp12);
			strcat(encrypted_message, temp1);
			strcat(encrypted_message, temp12);
		} //end while
		end = XGpio_DiscreteRead(&COUNTER, 1);

		if (run_start) {
			xil_printf("\nEncrypting\r\n");
			xil_printf("Encrypted String length is: %d\r\n", strlen(encrypted_message));
			xil_printf("Encrypted String is: %s\r\n", encrypted_message);
			xil_printf("Time taken to encrypt: %u\r\n", (end - start));
		} //end if

		int_array = encrypted_message;

		temp_int_array = int_array;
		start = XGpio_DiscreteRead(&COUNTER, 1);
		while(*temp_int_array){
			*temp1 = *temp_int_array;
			temp_int_array++;
			*temp12 = *temp_int_array;
			temp_int_array++;
			Blowfish_decipher(temp1,temp12);
			strcat(decrypted_message, temp1);
			strcat(decrypted_message, temp12);
		} //end while
		end = XGpio_DiscreteRead(&COUNTER, 1);

		if (run_start) {
			xil_printf("\nDecrypting\r\n");
			xil_printf("Decrypted String length is: %d\r\n", strlen(decrypted_message));
			xil_printf("Decrypted String is: %s\r\n", decrypted_message);
			xil_printf("Time taken to decrypt: %u\r\n\n", (end - start));
		} //end if

	} //end if

	else if (hardware_encrypt_flag){
		u32 *xl;
		xl = calloc(1,4);
		u32 *xr;
		xr = calloc(1,4);

		temp_int_array = int_array;
		start = XGpio_DiscreteRead(&COUNTER, 1);
		while(*temp_int_array){
			*temp1 = *temp_int_array;
			XBlowfish_encipher_Set_xl_i(&ENCRYPT, *temp1);
			temp_int_array++;
			*temp12 = *temp_int_array;
			XBlowfish_encipher_Set_xr_i(&ENCRYPT, *temp12);
			temp_int_array++;

			XBlowfish_encipher_Start(&ENCRYPT); //start the encryption process
			while(!XBlowfish_encipher_IsDone); //wait for encryption to complete
			*xl = XBlowfish_encipher_Get_xl_o(&ENCRYPT);
			*xr = XBlowfish_encipher_Get_xr_o(&ENCRYPT);

			strcat(encrypted_message, xl);
			strcat(encrypted_message, xr);
		} // end while
		end = XGpio_DiscreteRead(&COUNTER, 1);

		if (run_start) {
			xil_printf("\nEncrypting\r\n");
			xil_printf("Encrypted String length is: %d\r\n", strlen(encrypted_message));
			xil_printf("Encrypted String is: %s\r\n", encrypted_message);
			xil_printf("Time taken encrypt: %u\r\n", (end - start));
		} //end if

		int_array = encrypted_message;
		temp_int_array = int_array;

		start = XGpio_DiscreteRead(&COUNTER, 1);
		while(*temp_int_array){
			*xl = *temp_int_array;
			XBlowfish_decipher_Set_xl_i(&DECRYPT, *xl);
			temp_int_array++;
			*xr = *temp_int_array;
			XBlowfish_decipher_Set_xr_i(&DECRYPT, *xr);
			temp_int_array++;

			XBlowfish_decipher_Start(&DECRYPT);

			XBlowfish_decipher_Start(&DECRYPT); //start the encryption process
			while(!XBlowfish_decipher_IsDone); //wait for encryption to complete
			*xl = XBlowfish_decipher_Get_xl_o(&DECRYPT);
			*xr = XBlowfish_decipher_Get_xr_o(&DECRYPT);

			strcat(decrypted_message, xl);
			strcat(decrypted_message, xr);
		} //end while
		end = XGpio_DiscreteRead(&COUNTER, 1);


		if (run_start) {
			xil_printf("\nDecrypting\r\n");
			xil_printf("Decrypted String length is: %d\r\n", strlen(decrypted_message));
			xil_printf("Decrypted String is: %s\r\n", decrypted_message);
			xil_printf("Time taken to decrypt: %u\r\n\n", (end - start));
		} //end if

	} //end else if
	else {
		xil_printf("Error\r\n");
		exit(0);
	} //end else
	run_start = 1;
	DemoCleanup();

	//-----------------------------END the section for the Encryption/Decryption-------------------------------------------------//

	//-----------------------------START the section for UDP---------------------------------------------------------------------//

	//Attempt to begin a connection

	start_UDP(encrypted_message);
	start_UDP(decrypted_message);

	free(decrypted_message);
	free(encrypted_message);

	/* receive and process packets */

	if (TcpFastTmrFlag) {
		tcp_fasttmr();
		TcpFastTmrFlag = 0;
	} //end if
	if (TcpSlowTmrFlag) {
		tcp_slowtmr();
		TcpSlowTmrFlag = 0;
	} //end if
	xemacif_input(echo_netif);
	transfer_data();

	/* never reached */
	cleanup_platform();

	goto restart;

	return 0;
}
//-----------------------------END is the section for UDP--------------------------------------------------------------------//

//-----------------------------START is the section for the Keypad-----------------------------------------------------------//
// This is the section for the Keypad
// keytable is determined as follows (indices shown in Keypad position below)
// 12 13 14 15
// 8  9  10 11
// 4  5  6  7
// 0  1  2  3
#define DEFAULT_KEYTABLE "0FED789C456B123A"

void DemoInitialize() {
   EnableCaches();
   KYPD_begin(&myDevice, XPAR_PMODKYPD_0_AXI_LITE_GPIO_BASEADDR);
   KYPD_loadKeyTable(&myDevice, (u8*) DEFAULT_KEYTABLE);
} //end DemoInitialize

char *DemoRun() {
	char *string;
	if (run_start) {
		int num_bytes, place;

		char *inputstr;
		inputstr = calloc(4,1);
		int b=0;;
		char *clear;
		clear = calloc(4,1);
		int multiplier[4] = {1,10,100,1000};
		int i=0;
		u16 keystate;
		XStatus status, last_status = KYPD_NO_KEY;
		u8 key, last_key = 'x';
		// Initial value of last_key cannot be contained in loaded KEYTABLE string

		xil_printf("Enter a number of bytes to be transmitted (0 to 1448).\r\n");
		xil_printf("Press A on the Keypad to confirm selection.\r\n");
		xil_printf("Press F on the Keypad to reset process.\r\n");

		RESET: place = 1000; //use this if reset
		num_bytes = 0;
		while (key == 'A') { //Not sure why this is here
		   keystate = KYPD_getKeyStates(&myDevice);
		   status = KYPD_getKeyPressed(&myDevice, keystate, &key);
		} //end while

		key = 'x';

		Xil_Out32(myDevice.GPIO_addr, 0xF);

		while (1) {
		//Get user input for number of bytes to send

		// Capture state of each key
		keystate = KYPD_getKeyStates(&myDevice);

		// Determine which single key is pressed, if any
		status = KYPD_getKeyPressed(&myDevice, keystate, &key);

		// Print key detect if a new key is pressed or if status has changed
		if (status == KYPD_SINGLE_KEY && (status != last_status || key != last_key) &&  !(key >= 'A')) {
			xil_printf("%c", (char) key);
			last_key = key;
			*(inputstr+i) = key;
			i++;
			//num_bytes = num_bytes + place*(key - 48); //add the value enter to the num_bytes
			//place = place / 10; //change which number place the target is
			//if (place < 1) place = 1;
		} //end if
		else if (status == KYPD_MULTI_KEY && status != last_status)
			xil_printf("Error: Multiple keys pressed\r\n");
		else if (status == KYPD_SINGLE_KEY && status != last_status && key == 'A'){
			xil_printf("\r\n");
			b=0;
			while(i>b){
				num_bytes = num_bytes + multiplier[i-b-1]*(*(inputstr+(b)) - 48);
				b++;
			} //end while
			i=0;
			clear = inputstr;
			while(*clear){
				*clear=0;
				clear++;
			} //end while
			if (num_bytes > MAX_FRAME_SIZE | num_bytes < 0) {
				xil_printf("Try again: Enter a number of bytes less than or equal to 1448!\r\n");
				goto RESET;
			} // end if
			xil_printf("The number of bytes that will be sent is %d\r\n", num_bytes);
			goto SELECT;
		} //end else if
		else if (status == KYPD_SINGLE_KEY && (status != last_status || key != last_key) && key == 'F'){
			xil_printf("Reset button pressed\r\n");
			xil_printf("Enter a number of bytes to be transmitted (1 to 1448).\r\n");
			while (status) {
				keystate = KYPD_getKeyStates(&myDevice);
				status = KYPD_getKeyPressed(&myDevice, keystate, &key);
			} //end while
			goto RESET;
		} //end else if

		last_status = status;
		usleep(1000);
		} //end while

		//Move to Hardware or Software selection

		SELECT:xil_printf("Press 1 for Hardware or 0 for Software then press A to accept\r\n");
		while (key == 'A') {
			keystate = KYPD_getKeyStates(&myDevice);
			status = KYPD_getKeyPressed(&myDevice, keystate, &key);
		} //end while

		key = 'x';

		while (1){
		// Capture state of each key
		 keystate = KYPD_getKeyStates(&myDevice);

		// Determine which single key is pressed, if any
		status = KYPD_getKeyPressed(&myDevice, keystate, &key);

		if (status == KYPD_SINGLE_KEY && (status != last_status || key != last_key) && (key == '1' || key == '0')) {
			xil_printf("%c", (char) key);
			last_key = key;
		} //end if
		else if (status == KYPD_MULTI_KEY && status != last_status)
		   xil_printf("Error: Multiple keys pressed\r\n");

		else if (status == KYPD_SINGLE_KEY && (status != last_status || key != last_key) && key == 'A'){
			xil_printf("\r\n");
			if(last_key == '1'){
				xil_printf("Hardware selected\r\n");
				string = make_transmit_string(num_bytes, (MAX_FRAME_SIZE+8));
				hardware_encrypt_flag = 1;
				break;
			} //end if
			else if (last_key == '0'){
				xil_printf("Software selected\r\n");
				string = make_transmit_string(num_bytes, (MAX_FRAME_SIZE+8));
				hardware_encrypt_flag = 0;
				break;
			} //end else if
			else {
				xil_printf("Error!!!\r\n");
				exit(0);
			} //end else;
		} //end else if
		else if(status == KYPD_SINGLE_KEY && (status != last_status) && !(key == '1' || key == '0' || key == 'F')) {
			xil_printf("Please select either 1 or 0\r\n");
		} //end else if
		else if (status == KYPD_SINGLE_KEY && (status != last_status || key != last_key) && key == 'F'){
			xil_printf("Reset button pressed\r\n");
			xil_printf("Enter a number of bytes to be transmitted (0 to 1448).\r\n");
			while (status) {
				keystate = KYPD_getKeyStates(&myDevice);
				status = KYPD_getKeyPressed(&myDevice, keystate, &key);
			} //end while
			goto RESET;
		} //end else if

		last_status = status;
		usleep(1000);
		} //end while
	}
	else string = "Startup";
	return string;
} //end DemoRun

void DemoCleanup() {
   DisableCaches();
} //end DemoCleanup

//-----------------------------END is the section for the Keypad-------------------------------------------------------------//

void EnableCaches() {
#ifdef __MICROBLAZE__
#ifdef XPAR_MICROBLAZE_USE_ICACHE
   Xil_ICacheEnable();
#endif
#ifdef XPAR_MICROBLAZE_USE_DCACHE
   Xil_DCacheEnable();
#endif
#endif
}

void DisableCaches() {
#ifdef __MICROBLAZE__
#ifdef XPAR_MICROBLAZE_USE_DCACHE
   Xil_DCacheDisable();
#endif
#ifdef XPAR_MICROBLAZE_USE_ICACHE
   Xil_ICacheDisable();
#endif
#endif
}

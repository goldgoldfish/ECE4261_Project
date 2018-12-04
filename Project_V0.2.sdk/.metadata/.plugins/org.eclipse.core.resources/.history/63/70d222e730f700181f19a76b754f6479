/*
 * functions_4261.c
 *
 *  Created on: Nov 3, 2018
 *      Author: bwedemir
 */

/****************************** Include Files ***************************/

#include "stdlib.h"
#include "xil_io.h"

/************************** Function Definitions ************************/

/*** char *make_transmit_string(int num_bytes, int max_length)
**
**   Parameters:
**      num_bytes: The total number of bytes excluding NULLs
**      max_length: The max length the string can be including
**      NULLS
**
**   Return Value:
**      A pointer to the string created
**
**   Description:
**      Create a string of the length num_bytes but not longer
**      than max length
*/

char *make_transmit_string(int num_bytes, int max_length) {
	char *return_string;
	char temp_string[] = "ECE4261";
	int n = 0;
	int mod = 0;
	int s = sizeof(temp_string) - 1;
	//num_bytes = 1456;

	return_string = calloc(num_bytes + 7,sizeof(char));

	if(num_bytes > max_length) {
		xil_printf("Number of bytes entered exceeds max length allowed");
		exit(0);
	} //end if

	while (n < num_bytes){
		mod = n%s;
		return_string[n] = temp_string[mod];
		n++;
	} //end while
	return_string[n] = '\0';
	return return_string;
} //end make_transmit_sting

/*** char *make_transmit_string(int num_bytes, int max_length)
**
**   Parameters:
**      num_bytes: The total number of bytes excluding NULLs
**      max_length: The max length the string can be including
**      NULLS
**
**   Return Value:
**      A pointer to the string created
**
**   Description:
**      Create a string of the length num_bytes but not longer
**      than max length
*/

//char *software_encrypt(char *) {
//
//	int *temp1;
//	temp1 = calloc(1,4);
//	int *temp12;
//	temp12 = calloc(1,4);
//	char *encrypted_message;
//	encrypted_message = calloc(MAX_FRAME_SIZE,sizeof(char));
//
//	int length_string = sizeof(*data_array);
//	xil_printf("%d\r\n", length_string);
//	int *int_array;
//	int_array = data_array;
//
//	InitializeBlowfish(encrypt_key,keybytes); //initialize the algorithm by picking the size of the key and the key
//	int *temp_int_array;
//	temp_int_array = int_array;
//	while(*temp_int_array){
//		*temp1 = *temp_int_array;
//		temp_int_array++;
//		*temp12 = *temp_int_array;
//		temp_int_array++;
//		Blowfish_encipher(temp1,temp12);
//		strcat(encrypted_message, temp1);
//		strcat(encrypted_message, temp12);
//	} //end while
//} //end software_encrypt




/*** void timer_start(void)
**
**   Parameters:
**      none
**
**   Return Value:
**      none
**
**   Description:
**      Start the timer
*/

void timer_start(void){

} //end timer_start

/*** void timer_stop(void)
**
**   Parameters:
**      none
**
**   Return Value:
**      Value of the timer at the stop time
**
**   Description:
**      Stop the timer
*/

void timer_stop(void){

} //end timer_start

/*** void software_encrypt(num_bytes, make_transmit_string())
**
**   Parameters:
**      InstancePtr: A PmodKYPD device to start
**      GPIO_Address: The Base address of the PmodKYPD GPIO
**
**   Return Value:
**      none
**
**   Description:
**      Initialize the PmodKYPD driver device
*/

//software_encrypt(num_bytes, make_transmit_string());

/*** void hardware_encyrpt(num_bytes, make_transmit_string())
**
**   Parameters:
**      InstancePtr: A PmodKYPD device to start
**      GPIO_Address: The Base address of the PmodKYPD GPIO
**
**   Return Value:
**      none
**
**   Description:
**      Initialize the PmodKYPD driver device
*/

//hardware_encrypt(num_bytes, make_transmit_string());

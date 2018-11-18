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

	return_string = calloc(num_bytes - 1,sizeof(char));

	if(num_bytes > max_length) {
		xil_printf("Number of bytes entered exceeds max length allowed");
		exit(0);
	} //end if

	while (n < num_bytes){
		mod = n%s;
		return_string[n] = temp_string[mod];
		n++;
	} //end while
	return return_string;
} //end make_transmit_sting

/*** void KYPD_begin(PmodKYPD *InstancePtr, u32 GPIO_Address)
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

/*** void KYPD_begin(PmodKYPD *InstancePtr, u32 GPIO_Address)
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

// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2017.1
// Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xblowfish_encipher.h"

extern XBlowfish_encipher_Config XBlowfish_encipher_ConfigTable[];

XBlowfish_encipher_Config *XBlowfish_encipher_LookupConfig(u16 DeviceId) {
	XBlowfish_encipher_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XBLOWFISH_ENCIPHER_NUM_INSTANCES; Index++) {
		if (XBlowfish_encipher_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XBlowfish_encipher_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XBlowfish_encipher_Initialize(XBlowfish_encipher *InstancePtr, u16 DeviceId) {
	XBlowfish_encipher_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XBlowfish_encipher_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XBlowfish_encipher_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif


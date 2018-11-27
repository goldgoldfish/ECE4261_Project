// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2017.1
// Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

#ifndef XBLOWFISH_ENCIPHER_H
#define XBLOWFISH_ENCIPHER_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xblowfish_encipher_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Axilites_BaseAddress;
} XBlowfish_encipher_Config;
#endif

typedef struct {
    u32 Axilites_BaseAddress;
    u32 IsReady;
} XBlowfish_encipher;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XBlowfish_encipher_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XBlowfish_encipher_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XBlowfish_encipher_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XBlowfish_encipher_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XBlowfish_encipher_Initialize(XBlowfish_encipher *InstancePtr, u16 DeviceId);
XBlowfish_encipher_Config* XBlowfish_encipher_LookupConfig(u16 DeviceId);
int XBlowfish_encipher_CfgInitialize(XBlowfish_encipher *InstancePtr, XBlowfish_encipher_Config *ConfigPtr);
#else
int XBlowfish_encipher_Initialize(XBlowfish_encipher *InstancePtr, const char* InstanceName);
int XBlowfish_encipher_Release(XBlowfish_encipher *InstancePtr);
#endif


void XBlowfish_encipher_Set_xl_i(XBlowfish_encipher *InstancePtr, u32 Data);
u32 XBlowfish_encipher_Get_xl_i(XBlowfish_encipher *InstancePtr);
u32 XBlowfish_encipher_Get_xl_o(XBlowfish_encipher *InstancePtr);
u32 XBlowfish_encipher_Get_xl_o_vld(XBlowfish_encipher *InstancePtr);
void XBlowfish_encipher_Set_xr_i(XBlowfish_encipher *InstancePtr, u32 Data);
u32 XBlowfish_encipher_Get_xr_i(XBlowfish_encipher *InstancePtr);
u32 XBlowfish_encipher_Get_xr_o(XBlowfish_encipher *InstancePtr);
u32 XBlowfish_encipher_Get_xr_o_vld(XBlowfish_encipher *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif

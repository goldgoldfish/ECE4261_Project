// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2017.1
// Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

// AXILiteS
// 0x00 : Control signals
//        bit 0  - ap_start (Read/Write/COH)
//        bit 1  - ap_done (Read/COR)
//        bit 2  - ap_idle (Read)
//        bit 3  - ap_ready (Read)
//        bit 7  - auto_restart (Read/Write)
//        others - reserved
// 0x04 : Global Interrupt Enable Register
//        bit 0  - Global Interrupt Enable (Read/Write)
//        others - reserved
// 0x08 : IP Interrupt Enable Register (Read/Write)
//        bit 0  - Channel 0 (ap_done)
//        bit 1  - Channel 1 (ap_ready)
//        others - reserved
// 0x0c : IP Interrupt Status Register (Read/TOW)
//        bit 0  - Channel 0 (ap_done)
//        bit 1  - Channel 1 (ap_ready)
//        others - reserved
// 0x10 : Data signal of xl_i
//        bit 31~0 - xl_i[31:0] (Read/Write)
// 0x14 : reserved
// 0x18 : Data signal of xl_o
//        bit 31~0 - xl_o[31:0] (Read)
// 0x1c : Control signal of xl_o
//        bit 0  - xl_o_ap_vld (Read/COR)
//        others - reserved
// 0x20 : Data signal of xr_i
//        bit 31~0 - xr_i[31:0] (Read/Write)
// 0x24 : reserved
// 0x28 : Data signal of xr_o
//        bit 31~0 - xr_o[31:0] (Read)
// 0x2c : Control signal of xr_o
//        bit 0  - xr_o_ap_vld (Read/COR)
//        others - reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XBLOWFISH_ENCIPHER_AXILITES_ADDR_AP_CTRL   0x00
#define XBLOWFISH_ENCIPHER_AXILITES_ADDR_GIE       0x04
#define XBLOWFISH_ENCIPHER_AXILITES_ADDR_IER       0x08
#define XBLOWFISH_ENCIPHER_AXILITES_ADDR_ISR       0x0c
#define XBLOWFISH_ENCIPHER_AXILITES_ADDR_XL_I_DATA 0x10
#define XBLOWFISH_ENCIPHER_AXILITES_BITS_XL_I_DATA 32
#define XBLOWFISH_ENCIPHER_AXILITES_ADDR_XL_O_DATA 0x18
#define XBLOWFISH_ENCIPHER_AXILITES_BITS_XL_O_DATA 32
#define XBLOWFISH_ENCIPHER_AXILITES_ADDR_XL_O_CTRL 0x1c
#define XBLOWFISH_ENCIPHER_AXILITES_ADDR_XR_I_DATA 0x20
#define XBLOWFISH_ENCIPHER_AXILITES_BITS_XR_I_DATA 32
#define XBLOWFISH_ENCIPHER_AXILITES_ADDR_XR_O_DATA 0x28
#define XBLOWFISH_ENCIPHER_AXILITES_BITS_XR_O_DATA 32
#define XBLOWFISH_ENCIPHER_AXILITES_ADDR_XR_O_CTRL 0x2c


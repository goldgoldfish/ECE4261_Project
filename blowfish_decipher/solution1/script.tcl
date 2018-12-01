############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
############################################################
open_project blowfish_decipher
set_top Blowfish_decipher
add_files blowfish_decipher/blowfish_decrypt_ap_cntrl.c
open_solution "solution1"
set_part {xc7z010clg400-1} -tool vivado
create_clock -period 10 -name default
source "./blowfish_decipher/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -flow syn -rtl vhdl -format ip_catalog

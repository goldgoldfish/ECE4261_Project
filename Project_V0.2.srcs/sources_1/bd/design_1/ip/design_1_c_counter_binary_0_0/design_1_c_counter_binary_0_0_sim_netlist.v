// Copyright 1986-2017 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2017.1 (win64) Build 1846317 Fri Apr 14 18:55:03 MDT 2017
// Date        : Fri Nov 30 22:03:56 2018
// Host        : FRECE-ITB205-05 running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode funcsim
//               c:/Users/kohara/Downloads/ECE4261_Project-UDP/ECE4261_Project-UDP/Project_V0.2.srcs/sources_1/bd/design_1/ip/design_1_c_counter_binary_0_0/design_1_c_counter_binary_0_0_sim_netlist.v
// Design      : design_1_c_counter_binary_0_0
// Purpose     : This verilog netlist is a functional simulation representation of the design and should not be modified
//               or synthesized. This netlist cannot be used for SDF annotated simulation.
// Device      : xc7z010clg400-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CHECK_LICENSE_TYPE = "design_1_c_counter_binary_0_0,c_counter_binary_v12_0_10,{}" *) (* downgradeipidentifiedwarnings = "yes" *) (* x_core_info = "c_counter_binary_v12_0_10,Vivado 2017.1" *) 
(* NotValidForBitStream *)
module design_1_c_counter_binary_0_0
   (CLK,
    Q);
  (* x_interface_info = "xilinx.com:signal:clock:1.0 clk_intf CLK" *) input CLK;
  (* x_interface_info = "xilinx.com:signal:data:1.0 q_intf DATA" *) output [31:0]Q;

  wire CLK;
  wire [31:0]Q;
  wire NLW_U0_THRESH0_UNCONNECTED;

  (* C_AINIT_VAL = "0" *) 
  (* C_CE_OVERRIDES_SYNC = "0" *) 
  (* C_FB_LATENCY = "0" *) 
  (* C_HAS_CE = "0" *) 
  (* C_HAS_SCLR = "0" *) 
  (* C_HAS_SINIT = "0" *) 
  (* C_HAS_SSET = "0" *) 
  (* C_IMPLEMENTATION = "0" *) 
  (* C_SCLR_OVERRIDES_SSET = "1" *) 
  (* C_SINIT_VAL = "0" *) 
  (* C_VERBOSITY = "0" *) 
  (* C_WIDTH = "32" *) 
  (* C_XDEVICEFAMILY = "zynq" *) 
  (* c_count_by = "1" *) 
  (* c_count_mode = "0" *) 
  (* c_count_to = "1" *) 
  (* c_has_load = "0" *) 
  (* c_has_thresh0 = "0" *) 
  (* c_latency = "1" *) 
  (* c_load_low = "0" *) 
  (* c_restrict_count = "0" *) 
  (* c_thresh0_value = "1" *) 
  (* downgradeipidentifiedwarnings = "yes" *) 
  design_1_c_counter_binary_0_0_c_counter_binary_v12_0_10 U0
       (.CE(1'b1),
        .CLK(CLK),
        .L({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .LOAD(1'b0),
        .Q(Q),
        .SCLR(1'b0),
        .SINIT(1'b0),
        .SSET(1'b0),
        .THRESH0(NLW_U0_THRESH0_UNCONNECTED),
        .UP(1'b1));
endmodule

(* C_AINIT_VAL = "0" *) (* C_CE_OVERRIDES_SYNC = "0" *) (* C_COUNT_BY = "1" *) 
(* C_COUNT_MODE = "0" *) (* C_COUNT_TO = "1" *) (* C_FB_LATENCY = "0" *) 
(* C_HAS_CE = "0" *) (* C_HAS_LOAD = "0" *) (* C_HAS_SCLR = "0" *) 
(* C_HAS_SINIT = "0" *) (* C_HAS_SSET = "0" *) (* C_HAS_THRESH0 = "0" *) 
(* C_IMPLEMENTATION = "0" *) (* C_LATENCY = "1" *) (* C_LOAD_LOW = "0" *) 
(* C_RESTRICT_COUNT = "0" *) (* C_SCLR_OVERRIDES_SSET = "1" *) (* C_SINIT_VAL = "0" *) 
(* C_THRESH0_VALUE = "1" *) (* C_VERBOSITY = "0" *) (* C_WIDTH = "32" *) 
(* C_XDEVICEFAMILY = "zynq" *) (* ORIG_REF_NAME = "c_counter_binary_v12_0_10" *) (* downgradeipidentifiedwarnings = "yes" *) 
module design_1_c_counter_binary_0_0_c_counter_binary_v12_0_10
   (CLK,
    CE,
    SCLR,
    SSET,
    SINIT,
    UP,
    LOAD,
    L,
    THRESH0,
    Q);
  input CLK;
  input CE;
  input SCLR;
  input SSET;
  input SINIT;
  input UP;
  input LOAD;
  input [31:0]L;
  output THRESH0;
  output [31:0]Q;

  wire \<const1> ;
  wire CLK;
  wire [31:0]Q;
  wire NLW_i_synth_THRESH0_UNCONNECTED;

  assign THRESH0 = \<const1> ;
  VCC VCC
       (.P(\<const1> ));
  (* C_AINIT_VAL = "0" *) 
  (* C_CE_OVERRIDES_SYNC = "0" *) 
  (* C_FB_LATENCY = "0" *) 
  (* C_HAS_CE = "0" *) 
  (* C_HAS_SCLR = "0" *) 
  (* C_HAS_SINIT = "0" *) 
  (* C_HAS_SSET = "0" *) 
  (* C_IMPLEMENTATION = "0" *) 
  (* C_SCLR_OVERRIDES_SSET = "1" *) 
  (* C_SINIT_VAL = "0" *) 
  (* C_VERBOSITY = "0" *) 
  (* C_WIDTH = "32" *) 
  (* C_XDEVICEFAMILY = "zynq" *) 
  (* c_count_by = "1" *) 
  (* c_count_mode = "0" *) 
  (* c_count_to = "1" *) 
  (* c_has_load = "0" *) 
  (* c_has_thresh0 = "0" *) 
  (* c_latency = "1" *) 
  (* c_load_low = "0" *) 
  (* c_restrict_count = "0" *) 
  (* c_thresh0_value = "1" *) 
  (* downgradeipidentifiedwarnings = "yes" *) 
  design_1_c_counter_binary_0_0_c_counter_binary_v12_0_10_viv i_synth
       (.CE(1'b0),
        .CLK(CLK),
        .L({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .LOAD(1'b0),
        .Q(Q),
        .SCLR(1'b0),
        .SINIT(1'b0),
        .SSET(1'b0),
        .THRESH0(NLW_i_synth_THRESH0_UNCONNECTED),
        .UP(1'b0));
endmodule
`pragma protect begin_protected
`pragma protect version = 1
`pragma protect encrypt_agent = "XILINX"
`pragma protect encrypt_agent_info = "Xilinx Encryption Tool 2015"
`pragma protect key_keyowner="Cadence Design Systems.", key_keyname="cds_rsa_key", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=64)
`pragma protect key_block
ZxTZQ0UsS9HXL+cye8KhDHq6JjsRKdBbt7/23hG3Xv4lTOl0WgHvvGUXhuq0kWEjqS5VCl4O7cYh
glsyN2zZsA==

`pragma protect key_keyowner="Mentor Graphics Corporation", key_keyname="MGC-VERIF-SIM-RSA-1", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=128)
`pragma protect key_block
D0MQ3ley4npGPCDj0uKNvxx120GglLBAwtK6OmuXlvAVN0AR4gZjPv9jfdRnj/KJCxgkNVaqUWhg
Egx0h1ObNRySsfchKqdWJxVp84ELTdz8SOdcwsqw3WYcma/EKO0xmVG+Dj5kh3SGzvvfDaBktFb4
bK3AFZY/+Kz6WaLMycE=

`pragma protect key_keyowner="Synopsys", key_keyname="SNPS-VCS-RSA-1", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=128)
`pragma protect key_block
Ib/FxVN0ZG+ayfRlBompcRYBpl17xB6BG0jS3s3PNdG6pBxEZq6Py/W4j+7qAMV4uf9WBeBuwU2q
HYo5rMUEYE6wZf9jBnW23+A53JEyx5cXbckxSK688vZaeemF9wCkbeVwfHM8QNbLc51/qzlRZboH
l7C4B2YP6+l44fhzNYY=

`pragma protect key_keyowner="Aldec", key_keyname="ALDEC15_001", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
ws6JMsAbE3g94lwYREcMoC/8x4NmofYlfb9uHUEoOTvERSt6NSyR1yiG91nsEU3XfNhOQ7b/Wo+P
aa5UrHOplosBwW9O/BOPM9kStFRQfGsf8m20FxpwLUQdlNgNMPZvmEcAaEc+pN3iwPyX09CoU7cW
ox6RnElk1MI4OWVFf77mW8j6e1VlWO+Vc8LKoTynKGAP5hC4BYHQd27IInXzGdz1oVD4Bam4x0/H
sYLHZCISnOa94Q3CL6ay9xgNR41rtS98WTAttjEyFf8ILmaeESW6M4dGV3+EcdfBNzrTTc1nF75N
HxzYnCBLVG6X9yHlNRAwFRouHTyObDyWadNJzQ==

`pragma protect key_keyowner="ATRENTA", key_keyname="ATR-SG-2015-RSA-3", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
jKxqwTVbU6wQlQsyUl5EyNEaloyZKqOqnKP/oSoo8BbsW9jgw2GEmYOdPZbHNARjlp9P52Yzd3cJ
LczzuDU2cV2yn10WPFG38hLnucATA1ff0e8/mPzfxBEbAOPlzTkUFRukOc0zmo/tLK6cZvcaoRPu
DUI30FqzbS3M/o8XdN6yN2QOFivgXW0Xh8ycmXVtjktsm6ElnG31EW/2LkwLAyVftpL7G7j6nMnt
e+d+eKFIoGrxVI+7fida/LT0yaOYHWQh3rAG4GvE+2lORv2wy78727ZIirWNnQu8oy5qQcf7LAqd
e4MLtleFAxEV9eZP09SJZUSUNMj8waYaAU3w8A==

`pragma protect key_keyowner="Xilinx", key_keyname="xilinx_2016_05", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
w06/xQMdplxMd/DX9rImvuDEyUujJNZ5bclIgCUEQ3II7s7VZNfFQwqshU6852btDf1ThZcwb360
Io2jAnYs7UKM/nRMb56sYLBX4Y1+ufAYkpkHIcZcRICnnnvtYZ47grVBHrUfGA/xC7v/201YnNS0
c/L8l8Caa3RS8dR3ZckJnLnQOdimwEUdrhOFCxXNaVvcB1qFzyeB0qRxY/SqYktIcK0cf245rT6J
ycbkjnMIhAqvfqKdgoqIvgkkVe5grJuoukmw5uvFNcNJJ4EbH5xxoUZnl8pXhFueD3O6JeklVONo
/UZlkoZ7Ymk1otUl6y3wzaGnG8SCVGGtrmKfXQ==

`pragma protect key_keyowner="Mentor Graphics Corporation", key_keyname="MGC-PREC-RSA", key_method="rsa"
`pragma protect encoding = (enctype="base64", line_length=76, bytes=256)
`pragma protect key_block
UfsQP2auZLHfFrei87YDKyRJarzSloNXb0ko98ET2n3+fl2xrPZiACL4G/DmmJVs/+CE9pIgbMEx
2LNGFGwaXLF9wJTACG2NYuFdsVL5TzDu/pv9+t44YIPW12tfe9Ud6eOe2+u2POug3E/t5ebRXkya
RhLEFP1Xt7/3XlgwmhVQMM0DyTTWK/Ozjarg2Gs+Xg1nQeHgRJZ94hul7WM0DIy8p76br7sr/SpQ
gGksRPrrvKRRoV5x3XNp+VYntDRoGTqQUrF9AYSFT/a2ScuPhw8A5Sn0bEPi7BX9rTKI0ZgKHXK9
iANXwjavG2TsOAAMn4OkPKUs2EW8/mVZAms5Yg==

`pragma protect key_keyowner="Synplicity", key_keyname="SYNP15_1", key_method="rsa"
`pragma protect encoding = (enctype="base64", line_length=76, bytes=256)
`pragma protect key_block
HVk1iRvNOjo+uC2FOH0mJra+uIuUF8LguuOAR4Gv+N3fwHiFn/bvniRMetCb0GU253fgZhI6OfFL
RTTzBGuZA1RRuIFCqzy77MMV/+dNccarOW6NaNc8zNGVPcm1DtfileupFjC20nbraqSpB+6TBAgO
P6PW9bJn8lr5zTsPeizmwmuHG54ypv/UqJ2vVEN8llkISZTz9DRYMIsfMXPo1jOsVVC3ZgXZi+R/
F2XMUb3/DHoe//yZJrmGDOMUPnxBOYCn+eRw4JUMjd4X+0rWOeYm+VNMzGO42Qo/tIyai+xTEO1d
fy73f+JrInecCduMls/J6EY8hbc5mQzax35kSw==

`pragma protect data_method = "AES128-CBC"
`pragma protect encoding = (enctype = "BASE64", line_length = 76, bytes = 17360)
`pragma protect data_block
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
`pragma protect end_protected
`ifndef GLBL
`define GLBL
`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;
    wire FCSBO_GLBL;
    wire [3:0] DO_GLBL;
    wire [3:0] DI_GLBL;
   
    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (strong1, weak0) GSR = GSR_int;
    assign (strong1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

endmodule
`endif

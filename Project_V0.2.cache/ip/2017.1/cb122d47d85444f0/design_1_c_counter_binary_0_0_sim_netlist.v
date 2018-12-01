// Copyright 1986-2017 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2017.1 (win64) Build 1846317 Fri Apr 14 18:55:03 MDT 2017
// Date        : Fri Nov 30 22:03:56 2018
// Host        : FRECE-ITB205-05 running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode funcsim -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
//               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ design_1_c_counter_binary_0_0_sim_netlist.v
// Design      : design_1_c_counter_binary_0_0
// Purpose     : This verilog netlist is a functional simulation representation of the design and should not be modified
//               or synthesized. This netlist cannot be used for SDF annotated simulation.
// Device      : xc7z010clg400-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CHECK_LICENSE_TYPE = "design_1_c_counter_binary_0_0,c_counter_binary_v12_0_10,{}" *) (* downgradeipidentifiedwarnings = "yes" *) (* x_core_info = "c_counter_binary_v12_0_10,Vivado 2017.1" *) 
(* NotValidForBitStream *)
module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix
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
  decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_c_counter_binary_v12_0_10 U0
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
(* C_XDEVICEFAMILY = "zynq" *) (* downgradeipidentifiedwarnings = "yes" *) 
module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_c_counter_binary_v12_0_10
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
  decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_c_counter_binary_v12_0_10_viv i_synth
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
ByagnIrDqzj3rzCI8/6lgZT00RxcL0icoFzA9Ni3IpL77qZatZ4PR2BNQXRxwfk6nsmVYIAzc0ck
tmzZfcQnJ8931DxxK2NEgJquQ89DdCzwD7rCyWZbsrLJN2/5c84lmO/I+TzcVphW/5NwRV/xQl2X
nBnXVfRf2jZVicnPhLAtjUkOQzymzdBb8hCM5mW2It8FpPzxZiXTbX2JeARh8nSHvMVhieMappXL
Zo7pNLphNA75Usl/iUk81AFrHCQll9UrrbK48ds6nLQo1/gJGXU60uZdTw25RwcI+EDU8TEdrJ0B
1QVUsziCvON8gHneCIEGSm9wzvwHD+FVwDNX+A==

`pragma protect key_keyowner="Synplicity", key_keyname="SYNP15_1", key_method="rsa"
`pragma protect encoding = (enctype="base64", line_length=76, bytes=256)
`pragma protect key_block
S2SKp8hchYBr93/bM1kWC7iGbhYVbki68pnJ+kWZV8EN+slciieVeOW4ewctfIRENvWvj9QbPR29
wIzkFXVy7Ur9EnNXlhwvYYxEaCGkS1Xnu6Q7wtkGuZRZBtpUe9M58BvexIS7GjmI7HSp94GbO8eE
mpeJOPLZlZfE/B+06htadWBDpkGOMtGHnr9caxOmt7zKSAWSONv2UpbDkMFi5dqmnL0xgYqBZwbe
bkfXhKNKBPFxKhlExmHCqQi54UNbdggymU7+OGfIw5YqYo1LV8ZHWcDrzCue5ouczqlZCRpIZWeF
t+7gM3OjfLqHQ5tQdnQyeISlmbAj1cPZhONb5A==

`pragma protect data_method = "AES128-CBC"
`pragma protect encoding = (enctype = "BASE64", line_length = 76, bytes = 17168)
`pragma protect data_block
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
+4Q9JyVonawRKxs=
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

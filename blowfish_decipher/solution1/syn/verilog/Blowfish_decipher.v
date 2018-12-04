// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2017.1
// Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="Blowfish_decipher,hls_ip_2017_1,{HLS_INPUT_TYPE=c,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xc7z010clg400-1,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=8.578000,HLS_SYN_LAT=65,HLS_SYN_TPT=none,HLS_SYN_MEM=4,HLS_SYN_DSP=0,HLS_SYN_FF=426,HLS_SYN_LUT=652}" *)

module Blowfish_decipher (
        ap_clk,
        ap_rst_n,
        s_axi_AXILiteS_AWVALID,
        s_axi_AXILiteS_AWREADY,
        s_axi_AXILiteS_AWADDR,
        s_axi_AXILiteS_WVALID,
        s_axi_AXILiteS_WREADY,
        s_axi_AXILiteS_WDATA,
        s_axi_AXILiteS_WSTRB,
        s_axi_AXILiteS_ARVALID,
        s_axi_AXILiteS_ARREADY,
        s_axi_AXILiteS_ARADDR,
        s_axi_AXILiteS_RVALID,
        s_axi_AXILiteS_RREADY,
        s_axi_AXILiteS_RDATA,
        s_axi_AXILiteS_RRESP,
        s_axi_AXILiteS_BVALID,
        s_axi_AXILiteS_BREADY,
        s_axi_AXILiteS_BRESP,
        interrupt
);

parameter    ap_ST_fsm_state1 = 5'd1;
parameter    ap_ST_fsm_state2 = 5'd2;
parameter    ap_ST_fsm_state3 = 5'd4;
parameter    ap_ST_fsm_state4 = 5'd8;
parameter    ap_ST_fsm_state5 = 5'd16;
parameter    C_S_AXI_AXILITES_DATA_WIDTH = 32;
parameter    C_S_AXI_AXILITES_ADDR_WIDTH = 6;
parameter    C_S_AXI_DATA_WIDTH = 32;

parameter C_S_AXI_AXILITES_WSTRB_WIDTH = (32 / 8);
parameter C_S_AXI_WSTRB_WIDTH = (32 / 8);

input   ap_clk;
input   ap_rst_n;
input   s_axi_AXILiteS_AWVALID;
output   s_axi_AXILiteS_AWREADY;
input  [C_S_AXI_AXILITES_ADDR_WIDTH - 1:0] s_axi_AXILiteS_AWADDR;
input   s_axi_AXILiteS_WVALID;
output   s_axi_AXILiteS_WREADY;
input  [C_S_AXI_AXILITES_DATA_WIDTH - 1:0] s_axi_AXILiteS_WDATA;
input  [C_S_AXI_AXILITES_WSTRB_WIDTH - 1:0] s_axi_AXILiteS_WSTRB;
input   s_axi_AXILiteS_ARVALID;
output   s_axi_AXILiteS_ARREADY;
input  [C_S_AXI_AXILITES_ADDR_WIDTH - 1:0] s_axi_AXILiteS_ARADDR;
output   s_axi_AXILiteS_RVALID;
input   s_axi_AXILiteS_RREADY;
output  [C_S_AXI_AXILITES_DATA_WIDTH - 1:0] s_axi_AXILiteS_RDATA;
output  [1:0] s_axi_AXILiteS_RRESP;
output   s_axi_AXILiteS_BVALID;
input   s_axi_AXILiteS_BREADY;
output  [1:0] s_axi_AXILiteS_BRESP;
output   interrupt;

reg    ap_rst_n_inv;
wire    ap_start;
reg    ap_done;
reg    ap_idle;
(* fsm_encoding = "none" *) reg   [4:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
reg    ap_ready;
wire   [31:0] xl_i;
wire   [31:0] xl_o;
reg    xl_o_ap_vld;
wire   [31:0] xr_i;
wire   [31:0] xr_o;
reg    xr_o_ap_vld;
wire   [4:0] P_address0;
reg    P_ce0;
wire   [30:0] P_q0;
wire   [7:0] S_0_address0;
reg    S_0_ce0;
wire   [30:0] S_0_q0;
wire   [7:0] S_1_address0;
reg    S_1_ce0;
wire   [31:0] S_1_q0;
wire   [7:0] S_2_address0;
reg    S_2_ce0;
wire   [31:0] S_2_q0;
wire   [7:0] S_3_address0;
reg    S_3_ce0;
wire   [31:0] S_3_q0;
wire    ap_CS_fsm_state2;
wire   [0:0] icmp_fu_195_p2;
wire   [4:0] i_1_fu_206_p2;
reg   [4:0] i_1_reg_357;
wire   [31:0] Xl_5_fu_246_p2;
reg   [31:0] Xl_5_reg_362;
wire    ap_CS_fsm_state3;
wire   [31:0] y_fu_318_p2;
reg   [31:0] y_reg_387;
wire    ap_CS_fsm_state4;
reg   [31:0] S_2_load_reg_392;
reg   [31:0] S_3_load_reg_397;
wire   [31:0] Xr_5_fu_333_p2;
wire    ap_CS_fsm_state5;
reg   [31:0] Xl_1_reg_154;
reg   [31:0] temp_reg_164;
reg   [4:0] i_reg_174;
wire   [31:0] tmp_7_fu_201_p1;
wire   [31:0] tmp_3_i_fu_294_p1;
wire   [31:0] tmp_4_i_fu_299_p1;
wire   [31:0] tmp_5_i_fu_304_p1;
wire   [31:0] tmp_6_i_fu_309_p1;
wire   [3:0] tmp_fu_185_p4;
wire   [31:0] P_load_cast_fu_226_p1;
wire   [23:0] tmp_3_fu_238_p1;
wire   [23:0] tmp_4_fu_242_p1;
wire   [7:0] tmp_1_fu_230_p1;
wire   [7:0] tmp_2_fu_234_p1;
wire   [23:0] Xl_5_cast_fu_252_p2;
wire   [7:0] tmp_5_fu_284_p4;
wire   [7:0] b_fu_274_p4;
wire   [7:0] c_fu_264_p4;
wire   [7:0] d_fu_258_p2;
wire   [31:0] S_0_load_cast_fu_314_p1;
wire   [31:0] y_1_fu_324_p2;
wire   [31:0] y_2_fu_328_p2;
reg   [4:0] ap_NS_fsm;

// power-on initialization
initial begin
#0 ap_CS_fsm = 5'd1;
end

Blowfish_decipher_P #(
    .DataWidth( 31 ),
    .AddressRange( 18 ),
    .AddressWidth( 5 ))
P_U(
    .clk(ap_clk),
    .reset(ap_rst_n_inv),
    .address0(P_address0),
    .ce0(P_ce0),
    .q0(P_q0)
);

Blowfish_decipherbkb #(
    .DataWidth( 31 ),
    .AddressRange( 256 ),
    .AddressWidth( 8 ))
S_0_U(
    .clk(ap_clk),
    .reset(ap_rst_n_inv),
    .address0(S_0_address0),
    .ce0(S_0_ce0),
    .q0(S_0_q0)
);

Blowfish_deciphercud #(
    .DataWidth( 32 ),
    .AddressRange( 256 ),
    .AddressWidth( 8 ))
S_1_U(
    .clk(ap_clk),
    .reset(ap_rst_n_inv),
    .address0(S_1_address0),
    .ce0(S_1_ce0),
    .q0(S_1_q0)
);

Blowfish_decipherdEe #(
    .DataWidth( 32 ),
    .AddressRange( 256 ),
    .AddressWidth( 8 ))
S_2_U(
    .clk(ap_clk),
    .reset(ap_rst_n_inv),
    .address0(S_2_address0),
    .ce0(S_2_ce0),
    .q0(S_2_q0)
);

Blowfish_deciphereOg #(
    .DataWidth( 32 ),
    .AddressRange( 256 ),
    .AddressWidth( 8 ))
S_3_U(
    .clk(ap_clk),
    .reset(ap_rst_n_inv),
    .address0(S_3_address0),
    .ce0(S_3_ce0),
    .q0(S_3_q0)
);

Blowfish_decipher_AXILiteS_s_axi #(
    .C_S_AXI_ADDR_WIDTH( C_S_AXI_AXILITES_ADDR_WIDTH ),
    .C_S_AXI_DATA_WIDTH( C_S_AXI_AXILITES_DATA_WIDTH ))
Blowfish_decipher_AXILiteS_s_axi_U(
    .AWVALID(s_axi_AXILiteS_AWVALID),
    .AWREADY(s_axi_AXILiteS_AWREADY),
    .AWADDR(s_axi_AXILiteS_AWADDR),
    .WVALID(s_axi_AXILiteS_WVALID),
    .WREADY(s_axi_AXILiteS_WREADY),
    .WDATA(s_axi_AXILiteS_WDATA),
    .WSTRB(s_axi_AXILiteS_WSTRB),
    .ARVALID(s_axi_AXILiteS_ARVALID),
    .ARREADY(s_axi_AXILiteS_ARREADY),
    .ARADDR(s_axi_AXILiteS_ARADDR),
    .RVALID(s_axi_AXILiteS_RVALID),
    .RREADY(s_axi_AXILiteS_RREADY),
    .RDATA(s_axi_AXILiteS_RDATA),
    .RRESP(s_axi_AXILiteS_RRESP),
    .BVALID(s_axi_AXILiteS_BVALID),
    .BREADY(s_axi_AXILiteS_BREADY),
    .BRESP(s_axi_AXILiteS_BRESP),
    .ACLK(ap_clk),
    .ARESET(ap_rst_n_inv),
    .ACLK_EN(1'b1),
    .ap_start(ap_start),
    .interrupt(interrupt),
    .ap_ready(ap_ready),
    .ap_done(ap_done),
    .ap_idle(ap_idle),
    .xl_o(xl_o),
    .xl_o_ap_vld(xl_o_ap_vld),
    .xl_i(xl_i),
    .xr_o(xr_o),
    .xr_o_ap_vld(xr_o_ap_vld),
    .xr_i(xr_i)
);

always @ (posedge ap_clk) begin
    if (ap_rst_n_inv == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state5)) begin
        Xl_1_reg_154 <= Xl_5_reg_362;
    end else if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
        Xl_1_reg_154 <= xr_i;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state5)) begin
        i_reg_174 <= i_1_reg_357;
    end else if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
        i_reg_174 <= 5'd17;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state5)) begin
        temp_reg_164 <= Xr_5_fu_333_p2;
    end else if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
        temp_reg_164 <= xl_i;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state4)) begin
        S_2_load_reg_392 <= S_2_q0;
        S_3_load_reg_397 <= S_3_q0;
        y_reg_387 <= y_fu_318_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        Xl_5_reg_362 <= Xl_5_fu_246_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state2) & (icmp_fu_195_p2 == 1'd0))) begin
        i_1_reg_357 <= i_1_fu_206_p2;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        P_ce0 = 1'b1;
    end else begin
        P_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        S_0_ce0 = 1'b1;
    end else begin
        S_0_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        S_1_ce0 = 1'b1;
    end else begin
        S_1_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        S_2_ce0 = 1'b1;
    end else begin
        S_2_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        S_3_ce0 = 1'b1;
    end else begin
        S_3_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state2) & (icmp_fu_195_p2 == 1'd1))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_start) & (1'b1 == ap_CS_fsm_state1))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state2) & (icmp_fu_195_p2 == 1'd1))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state2) & (icmp_fu_195_p2 == 1'd1))) begin
        xl_o_ap_vld = 1'b1;
    end else begin
        xl_o_ap_vld = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state2) & (icmp_fu_195_p2 == 1'd1))) begin
        xr_o_ap_vld = 1'b1;
    end else begin
        xr_o_ap_vld = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            if (((1'b1 == ap_CS_fsm_state2) & (icmp_fu_195_p2 == 1'd1))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state3;
            end
        end
        ap_ST_fsm_state3 : begin
            ap_NS_fsm = ap_ST_fsm_state4;
        end
        ap_ST_fsm_state4 : begin
            ap_NS_fsm = ap_ST_fsm_state5;
        end
        ap_ST_fsm_state5 : begin
            ap_NS_fsm = ap_ST_fsm_state2;
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign P_address0 = tmp_7_fu_201_p1;

assign P_load_cast_fu_226_p1 = P_q0;

assign S_0_address0 = tmp_3_i_fu_294_p1;

assign S_0_load_cast_fu_314_p1 = S_0_q0;

assign S_1_address0 = tmp_4_i_fu_299_p1;

assign S_2_address0 = tmp_5_i_fu_304_p1;

assign S_3_address0 = tmp_6_i_fu_309_p1;

assign Xl_5_cast_fu_252_p2 = (tmp_3_fu_238_p1 ^ tmp_4_fu_242_p1);

assign Xl_5_fu_246_p2 = (P_load_cast_fu_226_p1 ^ temp_reg_164);

assign Xr_5_fu_333_p2 = (y_2_fu_328_p2 ^ Xl_1_reg_154);

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_state3 = ap_CS_fsm[32'd2];

assign ap_CS_fsm_state4 = ap_CS_fsm[32'd3];

assign ap_CS_fsm_state5 = ap_CS_fsm[32'd4];

always @ (*) begin
    ap_rst_n_inv = ~ap_rst_n;
end

assign b_fu_274_p4 = {{Xl_5_fu_246_p2[23:16]}};

assign c_fu_264_p4 = {{Xl_5_cast_fu_252_p2[15:8]}};

assign d_fu_258_p2 = (tmp_1_fu_230_p1 ^ tmp_2_fu_234_p1);

assign i_1_fu_206_p2 = ($signed(5'd31) + $signed(i_reg_174));

assign icmp_fu_195_p2 = ((tmp_fu_185_p4 == 4'd0) ? 1'b1 : 1'b0);

assign tmp_1_fu_230_p1 = P_q0[7:0];

assign tmp_2_fu_234_p1 = temp_reg_164[7:0];

assign tmp_3_fu_238_p1 = P_q0[23:0];

assign tmp_3_i_fu_294_p1 = tmp_5_fu_284_p4;

assign tmp_4_fu_242_p1 = temp_reg_164[23:0];

assign tmp_4_i_fu_299_p1 = b_fu_274_p4;

assign tmp_5_fu_284_p4 = {{Xl_5_fu_246_p2[31:24]}};

assign tmp_5_i_fu_304_p1 = c_fu_264_p4;

assign tmp_6_i_fu_309_p1 = d_fu_258_p2;

assign tmp_7_fu_201_p1 = i_reg_174;

assign tmp_fu_185_p4 = {{i_reg_174[4:1]}};

assign xl_o = (Xl_1_reg_154 ^ 32'd891628582);

assign xr_o = (temp_reg_164 ^ 32'd827400743);

assign y_1_fu_324_p2 = (S_2_load_reg_392 ^ y_reg_387);

assign y_2_fu_328_p2 = (S_3_load_reg_397 + y_1_fu_324_p2);

assign y_fu_318_p2 = (S_0_load_cast_fu_314_p1 + S_1_q0);

endmodule //Blowfish_decipher
/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

#include <stdio.h>
#include <string.h>

#include "lwip/err.h"
#include "lwip/tcp.h"
#if defined (__arm__) || defined (__aarch64__)
#include "xil_printf.h"
#endif

err_t accept_callback(void *arg, struct tcp_pcb *newpcb, err_t err);

int transfer_data_old(){
	return 0;
}

int transfer_data(char *data_array) {

	err_t wr_err = ERR_OK;
	struct tcp_pcb *l_tcp_pcb;
	unsigned port = 7;
	ip_addr_t dest_ip = { ((u32_t)0x0B01A8C0UL) }; //this is 192.168.1.11
	ip_addr_t local_ip = { ((u32_t)0x0A01A8C0UL) }; //this is 192.168.1.10

	int length = 0;
	int i = 0;
	while (data_array[i]){
		length++;
		i++;
	} //end while

	xil_printf("Length is: %d.\r\n", length);

	struct pbuf *p = pbuf_alloc(PBUF_TRANSPORT, length, PBUF_RAM);

	/* create new TCP PCB structure */
	l_tcp_pcb = tcp_new();
	if (!l_tcp_pcb) {
		xil_printf("Error creating PCB. Out of Memory\n\r");
		return -1;
	} //end if

	wr_err = tcp_bind(l_tcp_pcb, &local_ip, port);
	if (wr_err != ERR_OK) {
		xil_printf("Unable to bind to port %d: err = %d\n\r", port, wr_err);
		return -2;
	} //end if


	wr_err = tcp_connect(l_tcp_pcb, &dest_ip, 7, NULL); //the NULL can be changed for a callback function
	if (wr_err != ERR_OK) {
		xil_printf("Unable to connect %d: err = %d\n\r", port, wr_err);
		return -2;
	} //end if

	//Sending Data
	tcp_sent(l_tcp_pcb, NULL); //the NULL can be changed for a callback function
	//tcp_sent(l_tcp_pcb, accept_callback(NULL, l_tcp_pcb, wr_err)); //the NULL can be changed for a callback function

	//unsigned char buffer_send[1024] = "My Name Is TCP";
	p->payload = data_array;
	p->len = length;
	p->tot_len = 1024;

	xil_printf("Attempting to send TCP packet.\r\n");

	wr_err = ERR_OK;

	xil_printf("Length is: %d.\r\n", p->len);
	xil_printf("String is: %s.\r\n", p->payload);

	if (tcp_sndbuf(l_tcp_pcb) > p->len) {
		wr_err = tcp_write(l_tcp_pcb, p->payload, p->len, 1);
	} else
		xil_printf("no space in tcp_sndbuf\n\r");

	/*
	if (wr_err != ERR_OK){
		xil_printf("Unable to write to %d: err = %d\n\r", port, wr_err);
		return -2;
	} //end if
	*/

	wr_err = tcp_output(l_tcp_pcb);
	if (wr_err != ERR_OK){
		xil_printf("Unable to output on %d: err = %d\n\r", port, wr_err);
		return -2;
	} //end if

	if(wr_err == ERR_OK){
		p->len++;
	} //end if

	pbuf_free(p);

	tcp_close(l_tcp_pcb);

	return 1;

	/*
	//Call tcp_sent() to specify a callback function for acknowledgements.
	tcp_sent(p, NULL);
	p->payload = data_array;

	//Call tcp_sndbuf() to find the maximum amount of data that can be sent.
	p->len = sizeof(p);
	p->tot_len = p->len;
	if (tcp_sndbuf(tpcb) > p->len) {
		err = tcp_write(tpcb, p->payload, p->len, 1);
	} else
		xil_printf("no space in tcp_sndbuf\n\r");

	//Call tcp_write() to enqueue the data.
	tcp_output(p);

	//Call tcp_output() to force the data to be sent.

	//free the received pbuf
	pbuf_free(p);

	return 0;
	*/

}

void print_app_header()
{
	xil_printf("\n\r\n\r-----lwIP TCP echo server ------\n\r");
	xil_printf("TCP packets sent to port 6001 will be echoed back\n\r");
}

err_t recv_callback(void *arg, struct tcp_pcb *tpcb,
                               struct pbuf *p, err_t err)
{
	/* do not read the packet if we are not in ESTABLISHED state */
	if (!p) {
		tcp_close(tpcb);
		tcp_recv(tpcb, NULL);
		return ERR_OK;
	}

	/* indicate that the packet has been received */
	tcp_recved(tpcb, p->len);

	/* echo back the payload */
	/* in this case, we assume that the payload is < TCP_SND_BUF */
	if (tcp_sndbuf(tpcb) > p->len) {
		err = tcp_write(tpcb, p->payload, p->len, 1);
	} else
		xil_printf("no space in tcp_sndbuf\n\r");

	/* free the received pbuf */
	pbuf_free(p);

	return ERR_OK;
}

err_t accept_callback(void *arg, struct tcp_pcb *newpcb, err_t err)
{
	static int connection = 1;

	/* set the receive callback for this connection */
	tcp_recv(newpcb, recv_callback);

	/* just use an integer number indicating the connection id as the
	   callback argument */
	tcp_arg(newpcb, (void*)(UINTPTR)connection);

	/* increment for subsequent accepted connections */
	connection++;

	return ERR_OK;
}

int start_application()
{
	struct tcp_pcb *pcb;
	err_t err;
	unsigned port = 7;

	/* create new TCP PCB structure */
	pcb = tcp_new();
	if (!pcb) {
		xil_printf("Error creating PCB. Out of Memory\n\r");
		return -1;
	}

	/* bind to specified @port */
	err = tcp_bind(pcb, IP_ADDR_ANY, port);
	if (err != ERR_OK) {
		xil_printf("Unable to bind to port %d: err = %d\n\r", port, err);
		return -2;
	}

	/* we do not need any arguments to callback functions */
	tcp_arg(pcb, NULL);

	/* listen for connections */
	pcb = tcp_listen(pcb);
	if (!pcb) {
		xil_printf("Out of memory while tcp_listen\n\r");
		return -3;
	}

	/* specify callback to use for incoming connections */
	tcp_accept(pcb, accept_callback);

	xil_printf("TCP echo server started @ port %d\n\r", port);

	return 0;
}

int start_connection()
{
	struct tcp_pcb *pcb;
	struct tcp_pcb *tpcb;
	err_t err;
	unsigned port = 7;


	/* create new TCP PCB structure */
	pcb = tcp_new();
	if (!pcb) {
		xil_printf("Error creating PCB. Out of Memory\n\r");
		return -1;
	}

	/* we do not need any arguments to callback functions */
	//tcp_arg(pcb, NULL);

	/* listen for connections */
	//pcb = tcp_listen(pcb);
	//if (!pcb) {
	//	xil_printf("Out of memory while tcp_listen\n\r");
	//	return -3;
	//}
	err = tcp_bind(pcb, IP_ADDR_ANY, port);

	///* specify callback to use for incoming connections */
	//tcp_accept(pcb, transfer_data);

	err = tcp_connect(pcb, IP_ADDR_ANY, port, NULL);

	xil_printf("TCP sending server started @ port %d\n\r", port);

	return 0;
}

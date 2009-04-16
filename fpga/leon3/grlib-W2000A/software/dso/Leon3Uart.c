

#include "DSO_Main.h"
#include "Leon3Uart.h"
#include "DSO_Misc.h"

/*
31: 26 Receiver FIFO count (RCNT) - shows the number of data frames in the receiver FIFO.
25: 20 Transmitter FIFO count (TCNT) - shows the number of data frames in the transmitter FIFO.
10 Receiver FIFO full (RF) - indicates that the Receiver FIFO is full.
9 Transmitter FIFO full (TF) - indicates that the Transmitter FIFO is full.
8 Receiver FIFO half-full (RH) -indicates that at least half of the FIFO is holding data.
7 Transmitter FIFO half-full (TH) - indicates that the FIFO is less than half-full.
6 Framing error (FE) - indicates that a framing error was detected.
5 Parity error (PE) - indicates that a parity error was detected.
4 Overrun (OV) - indicates that one or more character have been lost due to overrun.
3 Break received (BR) - indicates that a BREAK has been received.
2 Transmitter FIFO empty (TE) - indicates that the transmitter FIFO is empty.
1 Transmitter shift register empty (TS) - indicates that the transmitter shift register is empty.
0 Data ready (DR) - indicates that new data is available in the receiver holding register
*/

#define RX_DATAREADY 0x1
#define OVERRUN      0x10 
#define TX_FULL      (1 << 9)

bool UartInit(	const unsigned int CPUFreq,
		const unsigned int BaudRate,
		const unsigned int Control,
		uart_regs * uart) {
	int scaler = CPUFreq/(8*BaudRate);
/*	if you do this outside, more uarts can be used with this file*/
/*	uart = (uart_regs *)GENERIC_UART_BASE_ADDR;*/
	if ((BaudRate < 10) || (CPUFreq < 1000000) || (BaudRate > CPUFreq/8)) {
		return false;
	}
	uart->scaler = scaler;
	uart->control = Control;
	return true;
}

char ReceiveCharBlock(uart_regs * uart) {
	volatile int temp = 0;
	while (1){
		temp = loadmem((int)&uart->status);
		if ((temp & RX_DATAREADY) == 1){
			break;
     		}
	}
	return loadmem((int)&uart->data);
}

void SendCharBlock(uart_regs * uart, char c) {
	volatile int temp = 0;
	while (1) {
		temp = loadmem((int)&uart->status);
		if ((temp & TX_FULL) == 0){
			break;
		}
	}
	uart->data = c;
}

/* interrupts if the rx buffer is empty!*/
void ReceiveString (uart_regs * uart, char * c, unsigned int * size) {
	unsigned int rsize = 0;
	volatile int temp = 0;
	while (rsize < (*size)) {
		temp = loadmem((int)&uart->status);
	        if ((temp & RX_DATAREADY) != 0){
		       break;
		}
		c[rsize] = loadmem((int)&uart->data);
		rsize++;
	}
	*size = rsize;
}

void ReceiveStringBlock (uart_regs * uart, char * c, unsigned int * size) {
	unsigned int rsize = 0;
	while  (rsize < (*size)){
		c[rsize] = ReceiveCharBlock(uart);
		rsize++;
	}
}


void SendStringBlock (uart_regs * uart, char * c, unsigned int * size) {
	unsigned int i = 0;
	while (i < (*size)){
		SendCharBlock(uart,c[i]);
	/*	printf("Sending %c %d\n",c[i],i);*/
		i++;
	}
}

/* interrupts if the tx buffer is full!*/
void SendString (uart_regs * uart, char * c, unsigned int * size) {
	unsigned int i = 0;
	volatile int temp = 0;
	while (i < (*size)){
		temp = loadmem((int)&uart->status);
		if ((temp & TX_FULL) != 0){
			break;
		}
		uart->data = c[i];
		i++;
	}
	*size = i;
}


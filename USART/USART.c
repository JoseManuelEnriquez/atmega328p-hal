/*
 * USART.c
 *
 * Created: 17/03/2025 11:57:32
 *  Author: DCE
 */ 

#include "USART.h"
#include <avr/io.h>

const uart_drv_interface_t UART0 = {
	.init = USART0_init,
	.enaINT_TX = USART0_enaINT_TX,
	.enaINT_RX = USART0_enaINT_RX,
	.disaINT_TX = USART0_disaINT_TX,
	.disaINT_RX = USART0_disaINT_RX,
	.putcharPolling = USART0_putcharPolling,
	.putchar = USART0_putchar,
	.putString = USART0_putString,
	.getchar = USART0_getchar,
	.getcharPolling = USART0_getcharPolling
	};

void USART0_putcharPolling(unsigned char data)
{
	while(!(UCSR0A & (1 << UDRE0))){}
	
	UDR0 = data;
}

void USART0_putchar(unsigned char data)
{
	UDR0 = data;
}

void USART0_putString(char* strPointer)
{
	while(*strPointer)
	{
		USART0_putcharPolling(*strPointer);
		strPointer++;
	}
}

char USART0_getchar(void)
{
	return UDR0;
}

char USART0_getcharPolling(void)
{
	while(!(UCSR0A & (1 << RXC0))){}
	return UDR0;
}
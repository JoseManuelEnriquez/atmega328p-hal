/*
 * usart_drv_interface.h
 *
 * Created: 02/07/2026 21:27:24
 *  Author: josem
 */ 


#ifndef USART_DRV_INTERFACE_H_
#define USART_DRV_INTERFACE_H_

typedef struct{
	void (*init)(uint16_t valueUBRR);
	void (*enaINT_TX)();
	void (*enaINT_RX)();
	void (*disaINT_TX)();
	void (*disaINT_RX)();
	void (*putcharPolling)(unsigned char data);
	void (*putchar)(unsigned char data);
	void (*putString)(char* strPointer);
	char (*getchar)(void);
	char (*getcharPolling)(void);
}uart_drv_interface_t;

#endif /* USART_DRV_INTERFACE_H_ */
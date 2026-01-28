/**
 * @file   USART.h
 * @brief  HAL functions for USART of ATmega328P
 * @author Jose Manuel Enriquez Baena
 * @date   17/03/2025
 */ 

#ifndef USART_H_
#define USART_H_
#include <avr/io.h>


/**
 * @def RECEIVE(ADDRESS,BIT)
 * @brief function-like macro which read a bit 
 */
#define RECEIVE(ADDRESS,BIT) (ADDRESS & (1 << BIT))

/********************************************************************************************
*								USART configuration
********************************************************************************************/

/**
 * @brief Inicialize the USART0 registers
 * @param valueUBRR The baud rate generator value (prescaler) to set the desired communication speed.
 */
static inline void USART0_init(uint16_t valueUBRR)
{
	/* 1.- Set Baud Rate*/
	UBRR0H = (unsigned char)(valueUBRR>>8);
	UBRR0L = (unsigned char)valueUBRR;
	
	/* 2.- Enable receiver and transmitter */
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
	
	/* 3.- Set the mode and speed (default)*/
	
	/* 4.- Set frame format 8 bit data and 1 stop-bit*/
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
}


/********************************************************************************************
*							USART Interrupt configuration
********************************************************************************************/

/**
 * @brief Enable TX interrupt
 */
static inline void USART0_enaINT_TX()
{
	UCSR0B |= (1 << UDRIE0);
}

/**
 * @brief Enable RX interrupt
 */
static inline void USART0_enaINT_RX()
{
	UCSR0B |= (1 << RXCIE0);
}

/**
 * @brief Disable TX interrupt
 */
static inline void USART0_disaINT_TX()
{
	UCSR0B &=~(1 << UDRIE0);
}

/**
 * @brief Disable RX interrupt
 */
static inline void USART0_disaINT_RX()
{
	UCSR0B &=~(1 << RXCIE0);
}

/********************************************************************************************
*								Prototype functions
********************************************************************************************/

/**
 * @brief Transmits a single character via USART0 using polling.
 * @param data The character to be sent
 * @note This function blocks until the Transmit Buffer is empty.
 */
void USART0_putcharPolling(unsigned char data);

/**
 * @brief Transmits a single character via USART0 using interrupt.
 * @param data The character to be sent
 */
void USART0_putchar(unsigned char data);

/**
 * @brief Transmits a single character via USART0 using polling.
 * @param strPointer Pointer to the string to sent
 * @note This function blocks until the Transmit Buffer is empty.
 */
void USART0_putString(char* strPointer);

/**
 * @brief Read a character using interrupt
 */
char USART0_getchar(void);

/**
 * @brief Read a character using polling
 */
char USART0_getcharPolling(void);

#endif /* USART_H_ */
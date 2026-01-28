/**
 * @file   USART.h
 * @brief  LOW_DRIVES para configurar la USART0 de ATmega328P
 * @author Jose Manuel Enriquez Baena
 * @date   17/03/2025 11:41:28
 *  
 * Fichero que contiene funciones(LOW_DRIVES) para trabajar comodamente con la USART de ATmega328P.
 * Funciones de inicializacion de USART y activacion y desactivacion de las interrupciones de TX, RX. Ademas de varias funciones de 
 * uso normal como imprimir una cadena o un caracter haciendo uso de polling.
 * 
 */ 

#ifndef USART_H_
#define USART_H_
#include <avr/io.h>


/**
 * @def RECEIVE(ADDRESS,BIT)
 * @brief Funcion Macro para comprobar si se ha recibido un dato
 */
#define RECEIVE(ADDRESS,BIT) (ADDRESS & (1 << BIT))

/********************************************************************************************
*								Configuracion USART
********************************************************************************************/

/**
 * @brief Inicializa los registros necesarios para hacer funcionar la USART
 * @param valueUBRR Factor para tener la frecuencia deseada
 */
static inline void USART0_init(uint16_t valueUBRR)
{
	/* 1.- Set Bau Rate*/
	UBRR0H = (unsigned char)(valueUBRR>>8);
	UBRR0L = (unsigned char)valueUBRR;
	
	/* 2.- Enable receiver and transmitter */
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
	
	/* 3.- Set the mode and speed (default)*/
	
	/* 4.- Set frame format 8 bit data and 1 stop-bit*/
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
}


/********************************************************************************************
*							Configuracion de interrupciones USART
********************************************************************************************/

/**
 * @brief Activa las interrupciones TX
 */
static inline void USART0_enaINT_TX()
{
	UCSR0B |= (1 << UDRIE0);
}

/**
 * @brief Activa las interrupciones RX
 */
static inline void USART0_enaINT_RX()
{
	UCSR0B |= (1 << RXCIE0);
}

/**
 * @brief Desactiva las interrupciones TX
 */
static inline void USART0_disaINT_TX()
{
	UCSR0B &=~(1 << UDRIE0);
}

/**
 * @brief Desactiva las interrupciones RX
 */
static inline void USART0_disaINT_RX()
{
	UCSR0B &=~(1 << RXCIE0);
}

/********************************************************************************************
*								Prototipos de Funciones
********************************************************************************************/

/**
 * @brief Imprime caracter usando la tecnica de polling
 * @param data Caracter a imprimir
 */
void USART0_putcharPolling(unsigned char data);

/**
 * @brief Imprime caracter sin polling para usar con interrupcion
 * @param data Caracter a imprimir 
 */
void USART0_putchar(unsigned char data);

/**
 * @brief Imprime una cadena de caracteres usando polling (usa USART0_putcharPolling())
 * @param strPointer Puntero a la cadena de caracteres
 */
void USART0_putString(char* strPointer);

/**
 * @brief Lee un caracter por la USART para usar con interrupciones
 */
char USART0_getchar(void);

/**
 * @brief Lee un caracter por la USART usando la tecnica de polling
 */
char USART0_getcharPolling(void);

#endif /* USART_H_ */
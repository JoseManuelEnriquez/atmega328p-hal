/*
 *  TMR4.h
 *
 *  Created: 19/05/2025 10:49:21
 *  Author: Jose Manuel Enriquez Baena
 * 
 * 	Description: Fichero que contiene los low-drivers para usar Timer 4 usando !OCR4A y OCR4D
 */ 

#ifndef TMR4_H_
#define TMR4_H_

/*******************/
/*	  LIBRERIAS    */
/*******************/
#include <avr/io.h>


/*******************/
/*	   MACROS	   */
/*******************/

#define DIV_CK2		0x02
#define DIV_CK4		0x03
#define DIV_CK8		0x04
#define DIV_CK16	0x05
#define DIV_CK32	0x06
#define DIV_CK64	0x07
#define DIV_CK128	0x08
#define DIV_CK256	0x09
#define DIV_CK512	0x0A
#define DIV_CK1024	0x0B
#define DIV_CK2048	0x0C
#define DIV_CK4096	0x0D
#define DIV_CK8192	0x0E
#define DIV_CK16384 0x0F

/****************************/
/*	   Funciones Timer 4	*/
/****************************/

/**
 * @brief Inicializa el timer con el modo Phase and Frecuency Correct PWM, los puertos PC6 y PD7 como output
 * 		  y los registros !OC4A y OC4D usando el modo Compare Output
 */
static inline void TMR4_PWM_Phase_Init()
{
	DDRC |= (1 << DDC6);					// PC6 output
	DDRD |= (1 << DDD7);					// PD7 output
	TCCR4A |= (1 << COM4A0) | (1 << PWM4A); // Compare Output Mode !OC4A and enable PWM canal A
	TCCR4C |= (1 << COM4D1) | (1 << PWM4D); // Compare Output Mode OC4D and enable PWM canal D
	TCCR4D |= (1 << WGM40);					// Enable Timer Phase and Frecuency Correct PWM waveform generation mode 
}


/**
 * @brief Resetea el contador y comienza el conteo
 * @param divClock Preescalado
 */
static inline void TMR4_PWM_Phase_Start(uint8_t divClock)
{
	TCNT4 = 0;				   // Reseteamos el contador 
	TCCR4B |= (divClock<<CS40); // Preescalado
}

/**
 * @brief Configura los registros para obtener el ciclo de trabajo que deseamos
 * @param valueOCR4A Valor del registro !OCR4A
 * @param valueOCR4D Valor del registro OCR4D
 * 
 * Inicializa el valor de OCR4D y !OCR4A. Como !OCR4A esta negado, el valor que se pase por parametro se resta
 * con 255.
 * 
 */
static inline void TMR4_PWM_Phase_Duty(uint8_t valueOCR4A, uint8_t valueOCR4D)
{
	OCR4D = valueOCR4D;
	OCR4A = 255-valueOCR4A;
}

/**
 * @brief Para el conteo del timer 
 */
static inline void TMR4_PWM_Stop()
{
	TCCR4B&=~((1<<CS40) | (1<<CS41) | (1<<CS42) | (1<<CS43));
}

#endif /* TMR4_H_ */
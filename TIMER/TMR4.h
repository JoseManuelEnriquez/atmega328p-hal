/**
 * @file TMR4.h
 * @brief HAL functions for Timer 4
 * @date 21/04/2025
 * @author Jose Manuel Enriquez Baena
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

/**
 * @defgroup CLK_PRESCALERS Clock Prescaler Definitions
 * @brief Available clock division factors for timer/counter modules.
 */
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
/**@ */

/****************************/
/*	   Funciones Timer 4	*/
/****************************/

/**
 * @brief Inicialize the timer with Phase mode, Frecuency Correct PWM, ports PC6, PD7 configure like output
 * 		  , !OC4A and OC4D registers configure like Compare Output mode
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
 * @brief Reset the count and start 
 * @param divClock Preescaler
 */
static inline void TMR4_PWM_Phase_Start(uint8_t divClock)
{
	TCNT4 = 0;				    // Reset
	TCCR4B |= (divClock<<CS40); // Configures preescaler
}

/**
 * @brief Configures the registers to set the desired PWM duty cycle.
 * @param valueOCR4A Value for the !OCR4A register. 
 * @param valueOCR4D Value for the OCR4D register.
 * @details Initializes the OCR4D and !OCR4A values. Since !OCR4A uses inverted logic, 
 * the parameter value is subtracted from 255 before being written to the register.
 */
static inline void TMR4_PWM_Phase_Duty(uint8_t valueOCR4A, uint8_t valueOCR4D)
{
	OCR4D = valueOCR4D;
	OCR4A = 255-valueOCR4A;
}

/**
 * @brief Stop the count
 */
static inline void TMR4_PWM_Stop()
{
	TCCR4B&=~((1<<CS40) | (1<<CS41) | (1<<CS42) | (1<<CS43));
}

#endif /* TMR4_H_ */
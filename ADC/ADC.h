/**
 * @file ADC.h
 * @brief ADC Functions for a ATmega328P
 * @author Jose Manuel Enriquez Baena
 */

#ifndef ADC_h
#define ADC_h

#include <avr/io.h>

/**
 * @defgroup Reference voltage
 * @{
 */
#define AVCC 0x01
#define AREF 0x00
/**
 * @}
 */


/**
 * @defgroup Align configuration 
 * @{
 */
#define ALIGN_LEFT 1
#define ALIGN_RIGHT 0
/**
 * @}
 */


/**
 * @defgroup Channels
  * @{
 */
#define ADC0 0x00 /// Channel 0
#define ADC1 0x01 /// Channel 1
#define ADC2 0x02 /// Channel 2
#define ADC3 0x03 /// Channel 3
#define ADC4 0x04 /// Channel 4
#define ADC5 0x05 /// Channel 5
#define ADC6 0x06 /// Channel 6
#define ADC7 0x07 /// Channel 7
/**@} */

/**
 * @brief Inicialize and configure the ADC registers
 * @param Vref Reference voltage 
 * @param align align configuration 
 */
static inline void ADC_init(uint8_t Vref, uint8_t align)
{
	/* 1- Clean configuration */
	ADCSRA = 0x00;
	ADMUX  = 0x00;
	ADCSRB = 0x00;
	/* 2 - Configurate Vref */
	ADMUX |= (Vref << REFS0);
	/* 3 - Select align format */
	ADCSRA |= (align << ADLAR);
	/* 4- Select Pre-scaling */
	ADCSRA |= 0x07;
	/* 5 - Enable ADC */
	ADCSRA |= (1 << ADEN);
}

/**
 * @brief Active ADC interruptions
 */
static inline void ADC_EnaInterrupt()
{
	ADCSRA |= (1 << ADIE);
}

/**
 * @brief Desactive ADC interruptions
 */
static inline void ADC_DisaInterrupt()
{
	ADCSRA &=~(1 << ADIE);
}

/**
 * @brief Inicialize conversion
 * @param channel Channel to read the conversion
 */
void ADC_StartConversion(uint8_t channel);

/**
 * @brief Start reading ADC using polling
 * @param channel Channel to read the conversion
 */
uint16_t ReadValueADCPolling(uint8_t channel);

#endif
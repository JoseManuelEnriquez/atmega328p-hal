/**
 * @file   EXT_INT.h
 * @brief  HAL Functions for Interruptions in ATmega328P
 * @author Jose Manuel Enriquez Baena
 */

#ifndef EXT_INT_H_
#define EXT_INT_H_
#include <avr/interrupt.h>

/**
 * @def   LOW_LEVEL
 * @brief Interrupt when there is a low-level
 */
#define LOW_LEVEL 0

/**
 * @def   CHANGE
 * @brief Interrupt when the digital value changes.
 */
#define CHANGE 1

/**
 * @def   FALLING
 * @brief Interrupt when there is a Falling Edge.
 */
#define FALLING 2

/**
 * @def   RISING
 * @brief Interrupt when there is a Rising Edge.
 */
#define RISING 3


/************************************/
/* 				INT0 				*/
/************************************/

/**
 * @brief Enable the External Interrupt INT0
 */
static inline void INT0_enable()
{
	EIMSK |= (1 << INT0);
}

/**
 * @brief Disable the External Interrupt INT0
 */
static inline void INT0_disable()
{
	EIMSK &=~(1 << INT0);
}

/**
 * @brief Configure the INT0 interrupt
 * @param typeTrigger Configure the interrupt trigger source.
 */
static inline void INT0_config(uint8_t typeTrigger) // Para darle cuando queremos que se active la interrupcion
{
	EICRA |= typeTrigger;
}



/************************************/
/* 				INT1 				*/
/************************************/

/**
 * @brief Enable the External Interrupt INT1
 */
static inline void INT1_enable()
{
	EIMSK |= (1 << INT1);
}

/**
 * @brief Disable the External Interrupt INT1
 */
static inline void INT1_disable()
{
	EIMSK &=~(1 << INT1);
}

/**
 * @brief Configure the INT1 interrupt
 * @param typeTrigger Configure the interrupt trigger source.
 */
static inline void INT1_config(uint8_t typeTrigger)
{
	EICRA |= (typeTrigger<<2);
}



/************************************/
/* 				PCINT 				*/
/************************************/

/**
 * @brief Enables a specific Pin Change Interrupt (PCINT) group.
 * @param PinChange The index of the PCINT group to enable (0, 1, or 2).
 */
static inline void PCINT_enable(uint8_t PinChange)
{
	PCICR |= (1 << PinChange);
}

/**
 * @brief Disable a specific Pin Change Interrupt (PCINT) group.
 * @param PinChange Elegir cual de las tres (0,1,2) de las interrupciones activar
 */
static inline void PCINT_disable(uint8_t PinChange)
{
	PCICR &=~(1 << PinChange);
}

/**
 * @brief Enable a specific Pin change interrupt from PCINT2
 * @param PCINT The specific pin change interrupt (PCINT16-PCINT23)
 */
static inline void PCINT_config_MSK2(uint8_t PCINT)
{
	PCMSK2 |= (1 << PCINT);
}

/**
 * @brief Enable a specific Pin change interrupt from PCINT1
 * @param PCINT The specific pin change interrupt (PCINT16-PCINT23)(PCINT8-PCINT14)
 */
static inline void PCINT_config_MSK1(uint8_t PCINT)
{
	PCMSK1 |= (1 << PCINT);
}

/**
 * @brief Enable a specific Pin change interrupt from PCINT0
 * @param PCINT The specific pin change interrupt(PCINT0-PCINT7)
 */
static inline void PCINT_config_MSK0(uint8_t PCINT)
{
	PCMSK0 |= (1 << PCINT);
}


#endif /* EXT_INT_H_ */
/**
 * @file TMR1.h
 * @brief HAL functions for Timer 1
 * @date 21/04/2025
 * @author Jose Manuel Enriquez Baena
 */


#ifndef TMR1_H_
#define TMR1_H_

/**
 * @defgroup CLK_PRESCALERS Clock Prescaler Definitions
 * @brief Available clock division factors for timer/counter modules.
 */
#define DIV_CLK_1	 1
#define DIV_CLK_8	 2
#define DIV_CLK_64	 3
#define DIV_CLK_256  4
#define DIV_CLK_1024 5
/**@ 
*/

/**
 * @defgroup Compare Match functions Definitions
 * @brief Available compare mathc funcionts for timer/counter modules.
 */
#define NORMAL_HW    0
#define TOGGLE_HW	 1
#define CLEAR_HW     2
#define SET_HW		 3
/**@ 
*/


/**
 * @brief Inicialize timer 1 (16 bits)
 */
static inline void TMR1_CTC_init()
{
	TCCR1B |= (1<<WGM12);
}
	
/**
 * @brief Enable interrupt timer 1
 */
static inline void TMR1_CTC_enaInterrupt()
{
	TIMSK1 |= (1<<OCIE1A);
}
	
/**
 * @brief Disable interrupt timer 1
 */
static inline void TMR1_CTC_disInterrupt()
{
	TIMSK1 &=~(1<<OCIE1A);
}

/**
 * @brief Start timer 1
 * @param divClock Prescaler
 */
static inline void TMR1_CTC_Start(uint8_t divClock)
{
	TCCR1B |= (divClock<<CS10);
}
	
/**
 * @brief Stop timer 1
 */
static inline void TMR1_CTC_Stop()
{
	TCCR1B &=~(1<<CS12) & ~(1<<CS11) & ~(1<<CS10);
}

/**
 * @brief Set Top Value
 * @param valueCounterA Top Value
 */
static inline void TMR1_CTC_Set(uint16_t valueCounterA)
{
	OCR1A = valueCounterA;
}

/**
 * @brief Configures the hardware timer to toggle the OC1A pin.
 * @details Sets the Timer/Counter 1 to Compare Match mode with a toggle 
 * operation on the OC1A output pin.
 */
static inline void TMR1_HW_toggleOC1A()
{
	TCCR1A |= (TOGGLE_HW << COM1A0);
}

/**
 * @brief Configures the hardware timer to clear the OC1A pin.
 * @details  Sets the Timer/Counter 1 to Compare Match mode with a set 
 * operation on the OC1A output pin.
 */
static inline void TMR1_HW_SETOC1A()
{
	TCCR1A |= (SET_HW << COM1A0);
}

/**
 * @brief Configures the hardware timer to clear the OC1A pin.
 * @details  Sets the Timer/Counter 1 to Compare Match mode with a clear 
 * operation on the OC1A output pin.
 */
static inline void TMR1_HW_CLEAROC1A()
{
	TCCR1A |= (CLEAR_HW << COM1A0);
}

#endif /* TMR1_H_ */
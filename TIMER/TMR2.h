/**
 * @file TMR2.h
 * @brief HAL functions for Timer 2
 * @date 21/04/2025
 * @author Jose Manuel Enriquez Baena
 */

#ifndef TMR2_H_
#define TMR2_H_

/**
 * @defgroup CLK_PRESCALERS Clock Prescaler Definitions
 * @brief Available clock division factors for timer/counter modules.
 */
#define DIV_CLK_1    1
#define DIV_CLK_8    2
#define DIV_CLK_32   3
#define DIV_CLK_64   4
#define DIV_CLK_128  5
#define DIV_CLK_256  6
#define DIV_CLK_1024 7
/**@ */

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
 * @brief Inicialize timer 2 (8 bits)
 */
static inline void TMR2_CTC_init()
{
	TCCR2A |= (1 << WGM21);
}

/**
 * @brief Start timer 2
 * @param divClock Prescaler
 */
static inline void TMR2_CTC_Start(uint16_t divClock)
{
	TCCR2B |= (divClock<<CS20);
}

/**
 * @brief Stop timer 2
 */
static inline void TMR2_CTC_Stop()
{
	TCCR2B &=~(1<<CS20) & ~(1<<CS21) & ~(1<<CS22);
}

/**
 * @brief Enable interrupt timer 2
 */
static inline void TMR2_CTC_enaInterrupt()
{
	TIMSK2 |= (1<<OCIE2A);
}
/**
 * @brief Disable interrupt timer 2
 */
static inline void TMR2_CTC_disaInterrupt()
{
	TIMSK2 &=~(1<<OCIE2A);
}

/**
 * @brief Set init Value
 * @param valueCounterA init Value
 */
static inline void TMR2_CTC_Set(uint8_t valueCounterA)
{
	OCR2A = valueCounterA;
}

/**
 * @brief Configures the hardware timer to toggle the OC2A pin.
 * @details Sets the Timer/Counter 2 to Compare Match mode with a toggle 
 * operation on the OC2A output pin.
 */
static inline void TMR2_HW_toggleOC2A()
{
	TCCR2A |= (1<<COM2A0);
}

/**
 * @brief Configures the hardware timer to clear the OC2A pin.
 * @details  Sets the Timer/Counter 2 to Compare Match mode with a clear 
 * operation on the OC2A output pin.
 */
static inline void TMR2_HW_CLEAROC2A()
{
	TCCR2A |= (2<<COM2A0);
}

/**
 * @brief Configures the hardware timer to clear the OC2A pin.
 * @details  Sets the Timer/Counter 2 to Compare Match mode with a set 
 * operation on the OC2A output pin.
 */
static inline void TMR2_HW_SETOC2A()
{
	TCCR2A |= (3<<COM2A0);
}

#endif
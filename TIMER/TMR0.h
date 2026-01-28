/**
 *  @file TMR0.h
 *  @brief HAL functions for Timer 0
 *  @author Jose Manuel Enriquez Baena
 * 	@date 21/04/2025
 */

#ifndef TMR0_H_
#define TMR0_H_

/**
 * @defgroup CLK_PRESCALERS Clock Prescaler Definitions
 * @brief Available clock division factors for timer/counter modules.
 */
#define DIV_CLK_1    1
#define DIV_CLK_8    2
#define DIV_CLK_64   3
#define DIV_CLK_256  4
#define DIV_CLK_1024 5
/**@ */

/**
 * @defgroup Compare Match functions Definitions
 * @brief Available compare mathc funcionts for timer/counter modules.
 */
#define NORMAL_HW    0
#define TOGGLE_HW	 1
#define CLEAR_HW     2
#define SET_HW		 3
/**@ */

/**
 * @brief Inicialize timer 0
 */
static inline void TMR0_CTC_init()
{
	TCCR0A |= (1 << WGM01);
}

/**
 * @brief Start timer 0
 * @param divClock Prescaler
 */
static inline void TMR0_CTC_Start(uint16_t divClock)
{
	TCCR0B |= (divClock<<CS00);
}

/**
 * @brief Stop timer 0
 */
static inline void TMR0_CTC_Stop()
{
	TCCR0B &=~(1<<CS00) & ~(1<<CS01) & ~(1<<CS02);
}

/**
 * @brief Enable interrupt timer 0
 */
static inline void TMR0_CTC_enaInterrupt()
{
	TIMSK0 |= (1<<OCIE0A);
}

/**
 * @brief Disable interrupt timer 0
 */
static inline void TMR0_CTC_disaInterrupt()
{
	TIMSK0 &=~(1<<OCIE0A);
}

/**
 * @brief Set init Value
 * @param valueCounterA init Value
 */
static inline void TMR0_CTC_Set(uint8_t valueCounterA)
{
	OCR0A = valueCounterA;
}

/**
 * @brief Configures the hardware timer to toggle the OC0A pin.
 * @details Sets the Timer/Counter 0 to Compare Match mode with a toggle 
 * operation on the OC0A output pin.
 */
static inline void TMR0_HW_toggleOC0A()
{
	TCCR0A |= (1<<COM0A0);
}

/**
 * @brief Configures the hardware timer to clear the OC0A pin.
 * @details  Sets the Timer/Counter 0 to Compare Match mode with a clear 
 * operation on the OC0A output pin.
 */
static inline void TMR0_HW_CLEAROC0A()
{
	TCCR0A |= (2<<COM0A0);
}

/**
 * @brief Configures the hardware timer to clear the OC0A pin.
 * @details  Sets the Timer/Counter 0 to Compare Match mode with a set 
 * operation on the OC0A output pin.
 */
static inline void TMR0_HW_SETOC0A()
{
	TCCR0A |= (3<<COM0A0);
}

#endif
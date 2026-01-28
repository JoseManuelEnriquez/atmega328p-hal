#ifndef TMR0_H_
#define TMR0_H_

/**
 * @defgroup Macros para elegir el prescalado
 */
#define DIV_CLK_1    1
#define DIV_CLK_8    2
#define DIV_CLK_64   3
#define DIV_CLK_256  4
#define DIV_CLK_1024 5
/**@ */

/**
 * @brief Inicializar el timer0 (8bits)
 */
static inline void TMR0_CTC_init()
{
	TCCR0A |= (1 << WGM01);
}

/**
 * @brief Comienza la cuenta del timer0
 * @param divClock Preescalado
 */
static inline void TMR0_CTC_Start(uint16_t divClock)
{
	TCCR0B |= (divClock<<CS00);
}

/**
 * @brief Parar la cuenta del timer0
 */
static inline void TMR0_CTC_Stop()
{
	TCCR0B &=~(1<<CS00) & ~(1<<CS01) & ~(1<<CS02);
}

/**
 * @brief Habilita la interrupcion Timer0
 */
static inline void TMR0_CTC_enaInterrupt()
{
	TIMSK0 |= (1<<OCIE0A);
}

/**
 * @brief Deshabilita la interrupcion Timer0
 */
static inline void TMR0_CTC_disaInterrupt()
{
	TIMSK0 &=~(1<<OCIE0A);
}

/**
 * @brief Elegir comienzo de la cuenta
 * @param valueCounterA Valor de inicio
 */
static inline void TMR0_CTC_Set(uint8_t valueCounterA)
{
	OCR0A = valueCounterA;
}

/**
 * @brief Configura para usar Timer por hardware y que su funcion sea permutar el pin OC0A
 */
static inline void TMR0_HW_toggleOC0A()
{
	TCCR0A |= (1<<COM0A0);
}

/**
 * @brief Configura para usar Timer por hardware y que su funcion sea poner un nivel Bajo el pin OC0A
 */
static inline void TMR0_HW_CLEAROC0A()
{
	TCCR0A |= (2<<COM0A0);
}

/**
 * @brief Configura para usar Timer por hardware y que su funcion sea poner un nivel Alto el pin OC0A
 */
static inline void TMR0_HW_SETOC0A()
{
	TCCR0A |= (3<<COM0A0);
}

#endif
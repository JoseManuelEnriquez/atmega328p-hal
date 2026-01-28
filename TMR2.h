#ifndef TMR2_H_
#define TMR2_H_

/**
 * @defgroup Macros para elegir el prescalado
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
 * @brief Inicializar el timer2 (8bits)
 */
static inline void TMR2_CTC_init()
{
	TCCR2A |= (1 << WGM21);
}

/**
 * @brief Comienza la cuenta del timer2
 * @param divClock Preescalado
 */
static inline void TMR2_CTC_Start(uint16_t divClock)
{
	TCCR2B |= (divClock<<CS20);
}

/**
 * @brief Parar la cuenta del timer2
 */
static inline void TMR2_CTC_Stop()
{
	TCCR2B &=~(1<<CS20) & ~(1<<CS21) & ~(1<<CS22);
}

/**
 * @brief Habilita la interrupcion Timer2
 */
static inline void TMR2_CTC_enaInterrupt()
{
	TIMSK2 |= (1<<OCIE2A);
}

/**
 * @brief Deshabilita la interrupcion Timer2
 */
static inline void TMR2_CTC_disaInterrupt()
{
	TIMSK2 &=~(1<<OCIE2A);
}

/**
 * @brief Elegir comienzo de la cuenta
 * @param valueCounterA Valor de inicio
 */
static inline void TMR2_CTC_Set(uint8_t valueCounterA)
{
	OCR2A = valueCounterA;
}

/**
 * @brief Configura para usar Timer por hardware y que su funcion sea permutar
 */
static inline void TMR2_HW_toggleOC2A()
{
	TCCR2A |= (1<<COM2A0);
}

/**
 * @brief Configura para usar Timer por hardware y que su funcion sea poner un nivel Bajo
 */
static inline void TMR2_HW_CLEAROC2A()
{
	TCCR2A |= (2<<COM2A0);
}

/**
 * @brief Configura para usar Timer por hardware y que su funcion sea poner un nivel Alto
 */
static inline void TMR2_HW_SETOC2A()
{
	TCCR2A |= (3<<COM2A0);
}

#endif
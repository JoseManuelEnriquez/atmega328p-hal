/*
 * TMR1.h
 *
 * Created: 21/04/2025 10:29:17
 *  Author: DCE
 */ 


#ifndef TMR1_H_
#define TMR1_H_

/**
 * @defgroup Macros para configurar el prescalado
 */
#define DIV_CLK_1	 1
#define DIV_CLK_8	 2
#define DIV_CLK_64	 3
#define DIV_CLK_256  4
#define DIV_CLK_1024 5
/**@ 
*/

#define NORMAL_HW    0
#define TOGGLE_HW	 1
#define CLEAR_HW     2
#define SET_HW		 3



/**
 * @brief Inicializar el timer1 (16bits)
 */
static inline void TMR1_CTC_init()
{
	TCCR1B |= (1<<WGM12);
}
	
/**
 * @brief Habilita la interrupcion Timer1
 */
static inline void TMR1_CTC_enaInterrupt()
{
	TIMSK1 |= (1<<OCIE1A);
}
	
/**
 * @brief Deshabilita la interrupcion Timer1
 */
static inline void TMR1_CTC_disInterrupt()
{
	TIMSK1 &=~(1<<OCIE1A);
}

/**
 * @brief Comienza la cuenta del timer1
 * @param divClock Preescalado
 */
static inline void TMR1_CTC_Start(uint8_t divClock)
{
	TCCR1B |= (divClock<<CS10);
}
	
/**
 * @brief Parar la cuenta del timer1
 */
static inline void TMR1_CTC_Stop()
{
	TCCR1B &=~(1<<CS12) & ~(1<<CS11) & ~(1<<CS10);
}

/**
 * @brief Elegir valor de parada de la cuenta
 * @param valueCounterA Valor de parada
 */
static inline void TMR1_CTC_Set(uint16_t valueCounterA)
{
	OCR1A = valueCounterA;
}

/**
 * @brief Configura para usar Timer por hardware y que su funcion sea permutar
 */
static inline void TMR1_HW_toggleOC1A()
{
	TCCR1A |= (TOGGLE_HW << COM1A0);
}

/**
 * @brief Configura para usar Timer por hardware y que su funcion sea poner un nivel Alto
 */
static inline void TMR1_HW_SETOC1A()
{
	TCCR1A |= (SET_HW << COM1A0);
}

/**
 * @brief Configura para usar Timer por hardware y que su funcion sea poner un nivel Bajo
 */
static inline void TMR1_HW_CLEAROC1A()
{
	TCCR1A |= (CLEAR_HW << COM1A0);
}

#endif /* TMR1_H_ */
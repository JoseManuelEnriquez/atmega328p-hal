/*
 *  WHEELS.c
 *
 *  Created: 19/05/2025 12:50:53
 *  Author: Jose Manuel Enriquez Baena
 * 
 * 	Description: Fichero .c con las implementaciones de los low-drivers definidos en WHEELS.h
 */ 

#include "WHEELS.h"

/***********************/
/*      FUNCIONES      */
/***********************/

void Robot_FWD(uint8_t speedLeft, uint8_t speedRight)
{
	/**
	 *  MOTOR IZQUIERDO
	 * 	EN1 = 0 -> Rueda hacia delante. Transistores: Q7 y Q8 -> ON | Q6 y Q9 -> OFF
	 *  EN1 = 1 -> Rueda hacia atras Transistores: Q7 y Q8 -> OFF | Q6 y Q9 -> ON
	 * 
	 *  MOTOR DERECHO 
	 * 	EN2 = 0 -> Rueda hacia delante. Transistores: Q14 y Q16 -> ON | Q13 y Q15 -> OFF
	 *  EN2 = 1 -> Rueda hacia atras. Transistores: Q14 y Q16 -> OFF | Q13 y Q15 -> ON
	 */


	/* Ambos puertos a 0 -> EN1 = 0 y EN2 = 0 | Rueda izquierda y derecha hacia delante */
	GPIO_out_EN1 &=~ (1 << EN1); // EN1
	GPIO_out_EN2 &=~ (1 << EN2); // EN2

	/* Configuracion del Timer 4 y comienzo conteo */
	TMR4_PWM_Phase_Start(DIV_CK64);
	TMR4_PWM_Phase_Duty(speedLeft,speedRight);
}

void Robot_BWD(uint8_t speedLeft, uint8_t speedRight)
{
	/**
	 *  MOTOR IZQUIERDO
	 * 	EN1 = 0 -> Rueda hacia delante. Transistores: Q7 y Q8 -> ON | Q6 y Q9 -> OFF
	 *  EN1 = 1 -> Rueda hacia atras Transistores: Q7 y Q8 -> OFF | Q6 y Q9 -> ON
	 * 
	 *  MOTOR DERECHO 
	 * 	EN2 = 0 -> Rueda hacia delante. Transistores: Q14 y Q16 -> ON | Q13 y Q15 -> OFF
	 *  EN2 = 1 -> Rueda hacia atras. Transistores: Q14 y Q16 -> OFF | Q13 y Q15 -> ON
	 */

	/* Ambos puertos a 1 -> EN1 = 1 y EN2 = 1 | Rueda izquierda y Rueda derecha hacia atras*/
	GPIO_out_EN1 |= (1 << EN1); // EN1
	GPIO_out_EN2 |= (1 << EN2); // EN2

	/* Configuracion del Timer 4 y comienzo conteo */
	TMR4_PWM_Phase_Start(DIV_CK64);
	TMR4_PWM_Phase_Duty(speedLeft,speedRight);
}

void Robot_STOP()
{
	TMR4_PWM_Stop();
}

void Robot_RIGHT(uint8_t speedLeft, uint8_t speedRight)
{
	/**
	 * MOTOR IZQUIERDO -> Debe ir hacia atras, EN1 = 1
	 * 
	 * MOTOR DERECHO -> Debe ir hacia delante, EN2 = 0
	 */

	/* EN1 = 1 y EN2 = 0 */
	GPIO_out_EN1 |=  (1 << EN1);
	GPIO_out_EN2 &=~ (1 << EN2);

	/* Configuracion del Timer 4 y comienzo conteo */
	TMR4_PWM_Phase_Start(DIV_CK64);
	TMR4_PWM_Phase_Duty(speedLeft,speedRight);
}	

void Robot_LEFT(uint8_t speedLeft, uint8_t speedRight)
{
	/**
	 * MOTOR IZQUIERDO -> Debe ir hacia delante, EN1 = 0
	 * 
	 * MOTOR DERECHO -> Debe ir hacia atras, EN2 = 1
	 */

	GPIO_out_EN1 &=~(1 << EN1);
	GPIO_out_EN2 |= (1 << EN2);

	/* Configuracion del Timer 4 y comienzo conteo */
	TMR4_PWM_Phase_Start(DIV_CK64);
	TMR4_PWM_Phase_Duty(speedLeft,speedRight);
}
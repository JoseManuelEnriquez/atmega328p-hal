/*
 *  WHEELS.h
 *
 *  Created: 19/05/2025 12:45:43
 *  Author: Jose Manuel Enriquez Baena
 * 
 * 	Description: Fichero .h que contiene los low-drivers para los motores del Robot MiniQ_2WD
 */ 


#ifndef WHEELS_H_
#define WHEELS_H_


/*****************/
/*     MACROS	 */
/*****************/

#define EN1 6 
#define EN2 6
#define GPIO_mode_EN1 DDRD
#define GPIO_mode_EN2 DDRE
#define GPIO_out_EN1 PORTD
#define GPIO_out_EN2 PORTE


/*******************/
/*	  LIBRERIAS    */
/*******************/
#include "TMR4.h"
#include <avr/io.h>


/**
 * @brief Inicializa los puertos PD6, PE6, Timer 4 y los puertos PWM1(velocidad motor izquierdo),PWM2 (velocidad motor derecho).
 * 
 * Los puertos PD6 y PE6 son los puertos que son las etiquetas EN1(motor izquierdo) y EN2(motor derecho) 
 * del robot para activar los motores.
 * 
 * PD6 -> EN1
 * PE6 -> EN2
 * 
 */
static inline void WHEELS_init()
{
	GPIO_mode_EN1 |= (1 << EN1); // EN1
	GPIO_mode_EN2 |= (1 << EN2); // EN2
	TMR4_PWM_Phase_Init();
}

/**
 * @brief Los motores avanzan hacia delante
 * @param speedLeft Velocidad motor izquierdo
 * @param speedRight Veloricad motor derecho
 * 
 * Activa los puertos PD6 y PE6 como sean necesario a la velocidad pasada por parametros para cada motor.
 * Los valores de speedLeft y speedRight deben ser los valores que se meterian en los registors OC4Rx para PWM
 * 
 */
void Robot_FWD(uint8_t speedLeft, uint8_t speedRight);

/**
 * @brief Los motores avanzan hacia atras
 * @param speedLeft Velocidad motor izquierdo
 * @param speedRight Velocidad motor derecho
 * 
 * Activa los puertos PD6 y PE6 como sean necesario a la velocidad pasada por parametros para cada motor.
 * Los valores de speedLeft y speedRight deben ser los valores que se meterian en los registors OC4Rx para PWM
 * 
 */
void Robot_BWD(uint8_t speedLeft, uint8_t speedRight);

/**
 * @brief Para el robot
 * 
 * Paro el timer que controla el PWM
 * 
 */
void Robot_STOP();

/**
 * @brief Gira el robot sobre si mismo hacia la derecha
 * @param speedLeft Velocidad del motor izquierdo
 * @param speedRight Velocidad del motor derecho 
 * 
 * Los valores de speedLeft y speedRight deben ser los valores que se meterian en los registors OC4Rx para PWM
 * 
 */
void Robot_RIGHT(uint8_t speedLeft, uint8_t speedRight);

/**
 * @brief Gira el robot sobre si mismo hacia la izquierda
 * @param speedLeft Velocidad del motor izquierdo
 * @param speedRight Velocidad del motor derecho 
 * 
 * Los valores de speedLeft y speedRight deben ser los valores que se meterian en los registors OC4Rx para PWM
 * 
 */
void Robot_LEFT(uint8_t speedLeft, uint8_t speedRight);

#endif /* WHEELS_H_ */
/**
 * @file PORTS.h
 * @brief Macros y funcion para inicializar los pines que se usan y configurarlos
 * @author Jose Manuel Enriquez Baena
 *
 */


#ifndef PORTS_H_
#define PORTS_H_
#include <avr/io.h>
#include "MACROS.h"

#define GPIO_0_mode DDRD
#define GPIO_0_out PORTD
#define GPIO_0_in PIND

#define LED_3 3
#define LED_4 4
#define PUSHBUTTON 2
#define PRESSED 0


/**
 * @brief Funcion para inicializar todos los pines y puertos I/O que usemos
 */
static inline GPIO_init()
{
	SETBIT(GPIO_0_mode,LED_3);
	SETBIT(GPIO_0_mode,LED_4);
	SETBIT(GPIO_0_out,PUSHBUTTON); // Activate pull-up resistor
}

#endif /* PORTS_H_ */
/*
 * GPIO.c
 *
 * Created: 27/10/2024 19:27:52
 *  Author: Jose Manuel Enriquez Baena
 */ 

#include "GPIO.h"

void GPIO_Init(volatile uint8_t * port, uint8_t pin, GPIO_direction_t direction){
	
	if(direction == INPUT)
		*port &= ~(1 << pin);
											
	else if(direction == OUTPUT)
		*port |= (1 << pin);						
}

void GPIO_Write(volatile uint8_t * port, uint8_t pin, GPIO_value_t digitalValue){
	if(digitalValue == LOW)
	*port &= ~(1 << pin);
	
	else if(digitalValue == HIGH)
	*port |= (1 << pin);
}

uint8_t GPIO_Read(volatile uint8_t * port, uint8_t pin){
	// Devuelve el resultado de la & con el registro, pero posiciona el valor del bit
	// en el LSB del byte que devuelve.
	uint8_t temp = 0;
	temp = (* port & (1 << pin));
	return ( temp);


}

void GPIO_Pullup(volatile uint8_t * port, uint8_t pin,  GPIO_pullup_t pullupState){
	if(pullupState == OFF)
	*port &= ~(1 << pin);
	
	else if(pullupState == ON)
	*port |= (1 << pin);
}

void GPIO_Toggle(volatile uint8_t * port, uint8_t pin){
	*port ^= (1 << pin);

}
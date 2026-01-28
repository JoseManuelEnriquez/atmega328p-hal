/**
 * @file   GPIO.h
 * @brief  HAL functions for GPIO
 * @author Jose Manuel Enriquez Baena
 *
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h> 
#include <avr/io.h> 

/**
 * @enum  GPIO_direction_t
 * @brief Pin direction
 */
typedef enum{
	INPUT,OUTPUT
}GPIO_direction_t;

/**
 * @enum  GPIO_value_t
 * @brief Digital Value
 */
typedef enum{
	HIGH, LOW
}GPIO_value_t;

/**
 * @enum  GPIO_pullup_t
 * @brief Active/Desactive pull-up resistor
 */
typedef enum{
	ON, OFF
}GPIO_pullup_t;

/********************************************************************************************
*								Prototype functions
********************************************************************************************/

/**
 * @brief Configure the pin 
 * @param port The hardware port to be initialized (e.g., PORTB)
 * @param pin The pin number to configure.
 * @param direction The pin mode: GPIO_INPUT or GPIO_OUTPUT.
 */
void GPIO_Init(volatile uint8_t * port, uint8_t pin,  GPIO_direction_t direction);

/**
 * @brief Writes a digital value to a specific pin
 * @param port Pointer to the target GPIO port register
 * @param pin The pin number to be modified
 * @param digitalValue Digital Value: LOW(0) o HIGH(1)
 */
void GPIO_Write(volatile uint8_t * port, uint8_t pin, GPIO_value_t digitalValue);

/**
 * @brief Read a digital value from a specific pin
 * @param port The hardware port
 * @param pin The pin number to be read
 */
uint8_t GPIO_Read(volatile uint8_t * port, uint8_t pin);

/**
 * @brief Active/Desactive the pull-up resistor of a specific pin
 * @param port The hardware port
 * @param pin The pin number
 * @param pullupState State of the pull-up: ON, OFF
 */
void GPIO_Pullup(volatile uint8_t * port, uint8_t pin,  GPIO_pullup_t pullupState);

/**
 * @brief Toggle the value of a specific pin
 * @param port The hardware port
 * @param pin The pin number
 */
void GPIO_Toggle(volatile uint8_t * port, uint8_t pin);

#endif /* GPIO_H_ */
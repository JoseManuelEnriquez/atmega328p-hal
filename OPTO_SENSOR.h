/*
 *  OPTO_SENSOR.h
 *
 *  Created: 12/05/2025 10:07:46
 *  Author: Jose Manuel Enriquez Baena
 * 
 * 	Archivo que contiene las funciones para usar el sensor optico
 * 
 */ 


#ifndef OPTO_SENSOR_H_
#define OPTO_SENSOR_H_


/********************************************/
/*			LIBRERIAS NECESARIAS			*/
/********************************************/
#define F_CPU 16000000UL
#include "ADC.h"
#include "m_general.h"
#include "m_usb.h"


/********************************************/
/*					MACROS					*/
/********************************************/

/* MACROS PARA ELEGIR EL SENSOR QUE QUERAMOS USAR */
#define IR0	 ADC7
#define IR1	 ADC6
#define IR2  ADC5
#define IR3	 ADC4
#define IR4  ADC1

/* MACROS PARA DEFINIR EL UMBRAL TANTO DEL COLOR NEGRO COMO DEL COLOR BLANCO*/
#define BLACK 580
#define WHITE 900

/********************************************/
/*			FUNCIONES DEL SENSOR			*/
/********************************************/

/**
 * @brief Inicializa el sensor
 */
static inline void OPTO_SENSOR_init()
{
	ADC_init(AVCC,ALIGN_RIGHT);
}

/**
 * @brief Hace una lectura del sensor
 * @param sensorIR_number Numero del sensor por el que queremos leer
 * @return Devuelve el valor que marca el sensor
 */
uint16_t check_IR_Sensor(uint8_t sensorIR_number);

/**
 * @brief Hace una lectura de los 5 sensores y lo imprime usando USB
 */
void readSensors();

#endif /* OPTO_SENSOR_H_ */
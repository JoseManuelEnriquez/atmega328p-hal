/*
 *  OPTO_SENSOR.c
 *
 *  Created: 12/05/2025 10:11:39
 *  Author: Jose Manuel Enriquez Baena
 */ 

#include "OPTO_SENSOR.h"

void imprimir(uint16_t sensores[5]); // funcion privada

uint16_t check_IR_Sensor(uint8_t sensorIR_number)
{
	uint16_t value;
	value = ReadValueADCPolling(sensorIR_number);
	return value;
}

void readSensors()
{
	uint16_t sensores[5];
	sensores[0] = check_IR_Sensor(IR0);
	sensores[1] = check_IR_Sensor(IR1);
	sensores[2] = check_IR_Sensor(IR2);
	sensores[3] = check_IR_Sensor(IR3);
	sensores[4] = check_IR_Sensor(IR4);
	imprimir(sensores);
}

void imprimir(uint16_t sensores[5])
{
	m_usb_tx_string("\f");
	if(sensores[0] <= BLACK){
		m_usb_tx_string("Sensor 0: NEGRO\t\t");
		m_usb_tx_uint(sensores[0]);
		m_usb_tx_string("\n\n\r");
	}else{
		m_usb_tx_string("Sensor 0: BLANCO\t");
		m_usb_tx_uint(sensores[0]);
		m_usb_tx_string("\n\n\r");
	}
	
	if(sensores[1] <= BLACK){
		m_usb_tx_string("Sensor 1: NEGRO\t\t");
		m_usb_tx_uint(sensores[1]);
		m_usb_tx_string("\n\n\r");
	}else{
		m_usb_tx_string("Sensor 1: BLANCO\t");
		m_usb_tx_uint(sensores[1]);
		m_usb_tx_string("\n\n\r");
	}
	if(sensores[2] <= BLACK){
		m_usb_tx_string("Sensor 2: NEGRO\t\t");
		m_usb_tx_uint(sensores[2]);
		m_usb_tx_string("\n\n\r");
	}else{
		m_usb_tx_string("Sensor 2: BLANCO\t");
		m_usb_tx_uint(sensores[2]);
		m_usb_tx_string("\n\n\r");
	}
	if(sensores[3] <= BLACK){
		m_usb_tx_string("Sensor 3: NEGRO\t\t");
		m_usb_tx_uint(sensores[3]);
		m_usb_tx_string("\n\n\r");
	}else{
		m_usb_tx_string("Sensor 3: BLANCO\t");
		m_usb_tx_uint(sensores[3]);
		m_usb_tx_string("\n\n\r");
	}
	if(sensores[4] <= BLACK){
		m_usb_tx_string("Sensor 4: NEGRO\t\t");
		m_usb_tx_uint(sensores[4]);
		m_usb_tx_string("\n\n\r");
	}else{
		m_usb_tx_string("Sensor 4: BLANCO\t");
		m_usb_tx_uint(sensores[4]);
		m_usb_tx_string("\n\n\r");
	}
}
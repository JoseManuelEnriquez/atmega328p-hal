#include "ADC.h"

void ADC_StartConversion(uint8_t channel)
{
	ADMUX &= ~(1 << MUX3) & ~(1 << MUX2) & ~(1 << MUX1) & ~(1 << MUX0); // Clean channel
	ADMUX |= (channel); 	// Select channel
	ADCSRA |= (1 << ADSC); 	// start conversion
}

uint16_t ReadValueADCPolling(uint8_t channel)
{
	ADCSRA |= (1 << ADIF); 	// clean the flag
	ADC_StartConversion(channel);
	while(!(ADCSRA & (1 << ADIF))){}
	return ADC;
}


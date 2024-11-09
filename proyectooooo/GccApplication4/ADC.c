/*
 * ADC.c
 *
 * Created: 08/11/2024 04:56:42 p. m.
 *  Author: emili
 */ 
#include "ADC.h"
#include <avr/io.h>

void ADC_init() {
	ADMUX = (1 << REFS0);
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

int ADC_read(int pin) {
	ADMUX = (ADMUX & 0xF8) | (pin & 0x07);
	ADCSRA |= (1 << ADSC);
	while (ADCSRA & (1 << ADSC));
	return ADCW;
}

float ADC_convertToVoltage(int value) {
	return (value * 5.0) / 1023.0;
}

/*
 * USART.c
 *
 * Created: 08/11/2024 04:56:12 p. m.
 *  Author: emili
 */ 

#define F_CPU 16000000UL  // Define la frecuencia del reloj en 16 MHz para Arduino Uno
#include "USART.h"
#include <avr/io.h>
#include <string.h>

void USART_init(long baudRate) {
	uint16_t ubrr = F_CPU/16/baudRate-1;
	UBRR0H = (ubrr >> 8);
	UBRR0L = ubrr;
	UCSR0B = (1 << TXEN0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void USART_sendData(const char* data) {
	for (int i = 0; i < strlen(data); i++) {
		while (!(UCSR0A & (1 << UDRE0)));
		UDR0 = data[i];
	}
}

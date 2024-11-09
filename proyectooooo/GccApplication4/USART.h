/*
 * USART.h
 *
 * Created: 08/11/2024 04:59:01 p. m.
 *  Author: emili
 */ 
#ifndef USART_H
#define USART_H

#include <avr/io.h>

void USART_init(long baudRate);
void USART_sendData(const char* data);

#endif

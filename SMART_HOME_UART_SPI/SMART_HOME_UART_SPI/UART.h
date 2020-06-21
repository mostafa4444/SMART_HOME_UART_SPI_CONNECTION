/*
 * UART.h
 *
 * Created: 6/1/2020 6:04:57 PM
 *  Author: user
 */ 


#ifndef UART_H_
#define UART_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include "Bit_Math.h"
#include "STD_Types.h"
#define BAUD_RATE 9600
#define UBRR_COUNT ((F_CPU/(16UL*(BAUD_RATE)))-1)


void UART_INIT();
void UART_SEND_CHAR(char data);
void UART_SEND_STRING(char * string);
uint8 UART_RECIEVE();




#endif /* UART_H_ */
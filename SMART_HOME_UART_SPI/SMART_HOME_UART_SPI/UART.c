/*
 * UART.c
 *
 * Created: 6/1/2020 6:05:08 PM
 *  Author: user
 */ 
#include "UART.h"

void UART_INIT(){
	//UCSRA
	UCSRB |= (1<<TXEN) | (1<<RXEN);
	UCSRC |= (1<<URSEL); // Select Register
	UCSRC |= (1<<UCSZ1) | (1<<UCSZ0);  // Select 8 bit size
	UBRRL = UBRR_COUNT; // BUT UBRR
	UBRRH = UBRR_COUNT>>8;
}

void UART_SEND_CHAR(char data){
	while(!(UCSRA & (1<<UDRE)));
	UDR = data;
}
void UART_SEND_STRING(char * string){
	unsigned short count = 0;
	while(string[count] != '\0'){
		UART_SEND_CHAR(string[count]);
		count++;
	}
}
unsigned char UART_RECIEVE(){
	while(!(UCSRA & (1<<RXC))); // when still 0 stop here when 1 continue
	return UDR;
}
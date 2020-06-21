/*
* SMART_HOME_UART_SPI.c
*
* Created: 6/1/2020 6:03:23 PM
* Author : user
*/

#include "main.h"
#include <avr/interrupt.h>
	uint8 data = 0;

int main(void)
{
	UART_INIT();
	SPI_INIT();
	while (1)
	{
		data = UART_RECIEVE();
		if(SPI_TxRX(data) == '5'){
			Toggle_Bit(PORTA_Reg , DIO_ChannelA0);
		}
	}
}


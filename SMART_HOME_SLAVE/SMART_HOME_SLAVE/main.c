/*
* SMART_HOME_SLAVE.c
*
* Created: 6/4/2020 1:09:23 PM
* Author : user
*/

#include "SPI.h"
#define F_CPU 16000000UL
#include "DIO_CFG.h"
int main(void)
{
	SPI_INIT();
	/* Replace with your application code */
	while (1)
	{
		if(SPI_TxRX('5') == '1'){
			DIO_WriteChannel(DIO_ChannelB0 , STD_HIGH);
		}else{
			DIO_WriteChannel(DIO_ChannelB0 , STD_LOW);

		}

	}
}


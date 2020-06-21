/*
* SMART_HOME_SLAVE.c
*
* Created: 6/4/2020 1:09:23 PM
* Author : user
*/

#include "main.h"
int main(void)
{
	LCD_INIT();
	SPI_INIT();
	Init_Timer();
	LCD_STRING("Servo Angle 0");
	/* Replace with your application code */
	while (1)
	{
		switch(SPI_TxRX('5')){
			case '1':
			DIO_WriteChannel(DIO_ChannelC0 , STD_HIGH);
			break;
			case '2':
			DIO_WriteChannel(DIO_ChannelC0 , STD_LOW);
			break;
			case '3':
			DIO_WriteChannel(DIO_ChannelC1 , STD_HIGH);
			break;
			case '4':
			DIO_WriteChannel(DIO_ChannelC1 , STD_LOW);
			break;
			case '5':
			DIO_WriteChannel(DIO_ChannelC2 , STD_HIGH);
			break;
			case '6':
			DIO_WriteChannel(DIO_ChannelC2 , STD_LOW);
			break;
			case '7':
			DIO_WriteChannel(DIO_ChannelC3 , STD_HIGH);
			break;
			case '8':
			DIO_WriteChannel(DIO_ChannelC3 , STD_LOW);
			break;
			case 'a':
			ServoMotor(45);
			LCD_Clear();
			LCD_STRING("Servo Angle 45");
			break;
			case 'b':
			ServoMotor(90);
			LCD_Clear();
			LCD_STRING("Servo Angle 90");
			break;
			case 'c':
			ServoMotor(135);
			LCD_Clear();
			LCD_STRING("Servo Angle 135");
			break;
			case 'd':
			ServoMotor(180);
			LCD_Clear();
			LCD_STRING("Servo Angle 180");
			break;
			case 'e':
			ServoMotor(0);
			LCD_Clear();
			LCD_STRING("Servo Angle 0");
			break;
		}
	}
}



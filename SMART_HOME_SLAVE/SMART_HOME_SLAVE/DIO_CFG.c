

#include "DIO_CFG.h"

const DIO_PinConfig PinConfig[] = {
	//PORTA
	{Output,STD_LOW},
	{Output,STD_LOW},
	{Output,STD_LOW},
	{Output,STD_LOW},
	{Output,STD_LOW},
	{Output,STD_LOW},
	{Output,STD_LOW},
	{Output,STD_LOW},
	//PORTB
	{Output,STD_LOW}, // LED Blank
	{Output,STD_LOW},
	{Output,STD_LOW},
	{Output,STD_LOW},
	{Input,STD_LOW}, // SS Bit
	{Input,STD_LOW}, // MOSI Bit
	{Output,STD_LOW}, // MISO Bit
	{Input,STD_LOW}, // SCK Bit
	//PORTC
	{Output,STD_LOW},
	{Output,STD_LOW},
	{Output,STD_LOW},
	{Output,STD_LOW},
	{Output,STD_LOW},
	{Output,STD_LOW},
	{Output,STD_LOW},
	{Output,STD_LOW},
	//PORTD	STD_LOW
	{Output,STD_LOW},
	{Output,STD_LOW},
	{Input, STD_LOW},
	{Output,STD_LOW},
	{Output,STD_LOW},
	{Output,STD_LOW},
	{Output,STD_LOW},
	{Output,STD_LOW}
};

void DIO_Init(){
	DIO_PORTS Portx;
	DIO_Channels ChannelPos;
	uint8 count = 0; 
	for(count = DIO_ChannelA0;count<PINCOUNT;count++){
		Portx = count/8;
		ChannelPos = count%8;
		switch(Portx){
			case DIO_PORTA:
				if(PinConfig[count].PinDirection == Output){
					Set_Bit(DDRA_Reg,ChannelPos);
				}
				else{
					Clear_Bit(DDRA_Reg,ChannelPos);
				}
			break;
			case DIO_PORTB:
				if(PinConfig[count].PinDirection == Output){
					Set_Bit(DDRB_Reg,ChannelPos);
				}
				else{
					Clear_Bit(DDRB_Reg,ChannelPos);
				}
			break;
			case DIO_PORTC:
				if(PinConfig[count].PinDirection == Output){
					Set_Bit(DDRC_Reg,ChannelPos);
				}
				else{
					Clear_Bit(DDRC_Reg,ChannelPos);
				}
			break;
			case DIO_PORTD:
				if(PinConfig[count].PinDirection == Output){
					Set_Bit(DDRD_Reg,ChannelPos);
				}
				else{
					Clear_Bit(DDRD_Reg,ChannelPos);
				}
			break;
		}
		
	}
}
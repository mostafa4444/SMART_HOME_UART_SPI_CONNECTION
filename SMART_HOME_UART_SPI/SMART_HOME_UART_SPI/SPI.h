/*
* SPI.h
*
* Created: 6/1/2020 6:05:40 PM
*  Author: user
*/


#ifndef SPI_H_
#define SPI_H_

#include "STD_Types.h"
#include <avr/io.h>
#include "DIO_CFG.h"

// ---------------------------- Start Hardware Configuration --------------------------------
typedef enum{
	SLAVE = 0,
	MASTER
	}SPI_MODE;
typedef struct SPCR_REGISTER{
	uint8 SPR0_BIT :1;
	uint8 SPR1_BIT :1;
	uint8 CPHA_BIT :1;
	uint8 CPOL_BIT :1;
	uint8 MSTR_BIT :1;
	uint8 DORD_BIT :1;
	uint8 SPE_BIT :1;
	uint8 SPIE_BIT :1;

}SPCR_REGISTER;

typedef struct{
	uint8 SPI2X_BIT :1;
	uint8 EM_BIT1 :1;
	uint8 EM_BIT2 :1;
	uint8 EM_BIT3 :1;
	uint8 EM_BIT4 :1;
	uint8 EM_BIT5 :1;
	uint8 WCOL_BIT :1;
	uint8 SPIF_BIT :1;

}SPSR_REGISTER;

typedef union{
	
	uint8 ALL_REGISTER;
	SPSR_REGISTER SPSR_REG;
	
}SPSR_REGISTER_CONFIGRATION;
	
typedef union{
	
	uint8 ALL_REGISTER;
	SPCR_REGISTER SPCR_REG;
	
}SPCR_REGISTER_CONFIGRATION;	

typedef struct{
	SPCR_REGISTER_CONFIGRATION SPCR_PART;
	SPSR_REGISTER_CONFIGRATION SPSR_PART;
	uint8 SPDR_REG;
}SPI_REGISTERS;

#define SPI_CFG ((volatile SPI_REGISTERS*) 0x2D)
//------------------------------- End Of Hardware Configuration & Start Functions Prototype -----------------------------------
#define SPI_MISO 6
#define SPI_MOSI 5
#define SPI_SCK 7
#define SPI_SS 4
#define SLAVE_ENABLE() (PORTC &=~ (1<<SPI_SS))  // Clear Slave = zero to start spi
#define SLAVE_DISABLE() (PORTC |= (1<<SPI_SS))  // Set Slave bit

void SPI_INIT();
uint8 SPI_TxRX(uint8 data);



#endif /* SPI_H_ */
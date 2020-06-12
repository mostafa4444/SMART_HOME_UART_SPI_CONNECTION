#include "SPI.h"




void SPI_INIT(){
	DIO_Init();
	SPI_CFG->SPCR_PART.SPCR_REG.SPE_BIT = STD_HIGH;
}
uint8 SPI_TxRX(uint8 data){ // Transfer Data
	SPI_CFG->SPDR_REG = data;
	while(!(SPI_CFG->SPSR_PART.SPSR_REG.SPIF_BIT));
	return SPI_CFG->SPDR_REG;
}
#include"SPI.h"
#include"STD_Lib.h"
#include"BIT_Math.h"
#include"avr/io.h"



void SPI_VidMasterInit(void){
	//selct master
	SET_BIT(SPCR,MSTR);
	//MSB
	CLR_BIT(SPCR,DORD);
	// divide by 16
	SET_BIT(SPCR,SPR0);
	CLR_BIT(SPCR,SPR1);
	CLR_BIT(SPCR,SPI2X);

	//CLK setup
	SET_BIT(SPCR,CPHA);
	SET_BIT(SPCR,CPOL);

   //SPI enable
	SET_BIT(SPCR,SPE);
}

void SPI_VidSlaveInit(void){
	//selct slave
		CLR_BIT(SPCR,MSTR);

	//MSB
		CLR_BIT(SPCR,DORD);
	//CLK setup
		SET_BIT(SPCR,CPHA);
		SET_BIT(SPCR,CPOL);
	//SPI enable
		SET_BIT(SPCR,SPE);
}

void SPI_U8Transmit(u8 Copy_U8Data){
	SPDR=Copy_U8Data;
}
u8 SPI_U8Recieve(void){
	while((GET_BIT(SPSR,SPIF))==0);
	return SPDR;
}





















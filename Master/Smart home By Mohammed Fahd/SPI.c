/*
 * SPI.c
 *
 * Created: 1/8/2021 5:00:58 PM
 *  Author: fadal
 */ 

#include "SPI.h"

void SPI_init(SPI_Status status){
	switch(status){
		case Master:
		 DDRB |= ((1<<SCK)|(1<<MOSI)|(1<<SS));
		 DDRB &= ~(1<<MISO);
		 Slave_Dis();
		 //SPCR = ((1<<SPE)|(1<<MSTR)); 
		 SPI->SPI_SPCR = ((1<<SPE)|(1<<MSTR));
		break;
		
		case Slave:
		 DDRB |= (1<<MISO);
		 DDRB &=~ ((1<<MOSI)|(1<<SCK)|(1<<SS));
		 SPI->SPI_SPCR = (1<<SPE);
		break;
	}
}

Uint8 SPI_TxRx(Uint8 data){
	SPDR = data;
	while(!((SPSR>>SPIF)&1)); // ( (SPSR&&(1<<7))==0 ) ;
	return SPDR;
}

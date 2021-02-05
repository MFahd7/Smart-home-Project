/*
* SPI.h
*
* Created: 1/8/2021 5:01:10 PM
*  Author: fadal
*/


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>

typedef unsigned char Uint8;
#define SS 4
#define  MOSI 5
#define MISO 6
#define  SCK 7

#define Slave_En() (PORTB &=~ (1<<SS))
#define Slave_Dis() (PORTB |= (1<<SS))

typedef enum{
	Master=0,
	Slave
 }SPI_Status;

void SPI_init(SPI_Status status);
Uint8 SPI_TxRx(Uint8 data);

typedef struct{
	
	Uint8 SSPR:2;
	Uint8 SCPHA:1;
	Uint8 SCPOL:1;
	Uint8 SMSTR:1;
	Uint8 SDORD:1;
	Uint8 SSPE:1;
	Uint8 SSPIE:1;
	
}SPI_SPCRbits;



typedef struct{
	
	Uint8 SPI_SPCR;
	Uint8 SPI_SPSR;
	Uint8 SPI_SPDR;
	
}SPI_RegTypes;

#define  SPI ((volatile SPI_RegTypes *)0x2D)

#endif /* SPI_H_ */
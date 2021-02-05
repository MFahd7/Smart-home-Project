/*
 * smart home project Slave.c
 *
 * Created: 2/2/2021 12:24:51 PM
 * Author : fadal
 */ 

#include "DIO.h"
#include "SPI.h"
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
    SPI_init(Slave);
	DIO_Init();
	
	DIO_WriteChannel(DIO_ChannelD5,STD_High);
	TCCR1A = (1<<COM1A1)|(1<<WGM10);
	TCCR1B = (1<<WGM12)|(1<<CS11)|(1<<CS10); //PRESCALAr =64  FPWM 8bit
	OCR1A = 80; //spd of fan
	
    while (1) 
    {
				
			if(SPI_TxRx(0x11)== 0x01){
				DIO_WriteChannel(DIO_ChannelD4,STD_High);
				if (SPI_TxRx(0x11)== 0x01)
				{
					DIO_WriteChannel(DIO_ChannelD4,STD_low);
				}
			}
			if (SPI_TxRx(0x22)== 0x02){
				DIO_WriteChannel(DIO_ChannelD6,STD_High);
				if (SPI_TxRx(0x22)== 0x02)
				{
					DIO_WriteChannel(DIO_ChannelD6,STD_low);
				}
			}
			if (SPI_TxRx(0x33)== 0x03){
				DIO_WriteChannel(DIO_ChannelD7,STD_High);
				if (SPI_TxRx(0x33)== 0x03)
				{
					DIO_WriteChannel(DIO_ChannelD7,STD_low);
				}
			}
			if (SPI_TxRx(0x44)== 0x04){
			   DIO_WriteChannel(DIO_ChannelC3,STD_High); // out of if
			   DIO_WriteChannel(DIO_ChannelC4,STD_low);
			   _delay_ms(1000);
			   if (SPI_TxRx(0x44)== 0x04)
			   {
				   DIO_WriteChannel(DIO_ChannelC3,STD_low);
				   DIO_WriteChannel(DIO_ChannelC4,STD_low);
			   }
			}
		
    }
	
	
}

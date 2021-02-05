/*
 * Smart home By Mohammed Fahd.c
 *
 * Created: 1/26/2021 3:07:05 PM
 * Author : fadal
 */

#define F_CPU 16000000UL
#include <util/delay.h>
#include "DIO.h"
#include "LCDh.h"
#include "UART.h"
#include "KeyPadh.h"

int main(void){
	
	DIO_Init();
	LCD_Init();
    uart_init();
    keyPad_Init();
	  
   LCD_StringPOS("Enter the ",1,0x80);
   LCD_StringPOS("Password:",2,0xC1);   
   
    while (1){
		
	  checkR0();
	  checkR1();
	  checkR2();
	  checkR3();
	  
	}
	
}

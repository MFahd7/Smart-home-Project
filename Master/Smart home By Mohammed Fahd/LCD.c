/*
 * LCD.c
 *
 * Created: 12/14/2020 4:03:10 PM
 *  Author: fadal
 */ 

#include "LCDh.h"

void LCD_Init(void){
	_delay_ms(20);
	 DIO_WriteChannel(RW,STD_low);
	 LCD_Cmd(0x33);
	 _delay_us(130);
	 LCD_Cmd(0x32);
	 LCD_Cmd(0x28);  
	 LCD_Cmd(0x06); //entry mode
	 LCD_Cmd(0x0F); //cursor display 0x0C OR 0x0F
	 LCD_Cmd(0x01); //clr display
	 _delay_ms(2);
} 

void LCD_Cmd(Uint8 cmd){
	
	LCDDataPort = (LCDDataPort & 0x0F)|(cmd & 0xF0);
	 DIO_WriteChannel(RS,STD_low);
	  DIO_WriteChannel(E,STD_low);
	  _delay_ms(100);
	  DIO_WriteChannel(E, STD_High);
	  
	  _delay_ms(5);
	  LCDDataPort = (LCDDataPort & 0x0F)|(cmd << 4);
/**/  DIO_WriteChannel(RS,STD_low);
	  DIO_WriteChannel(E,STD_low);
	  _delay_ms(100);
	  DIO_WriteChannel(E, STD_High);
	  _delay_ms(2);
}

void LCD_Char(Uint8 data){
	
		LCDDataPort = (LCDDataPort & 0x0F)|(data & 0xF0);
		DIO_WriteChannel(RS,STD_High);
		DIO_WriteChannel(E,STD_low);
		_delay_ms(100);
		DIO_WriteChannel(E, STD_High);
		
		_delay_ms(3);
		LCDDataPort = (LCDDataPort & 0x0F)|(data << 4);
		DIO_WriteChannel(RS,STD_High);
		DIO_WriteChannel(E,STD_low);
		_delay_ms(100);
		DIO_WriteChannel(E, STD_High);
		_delay_ms(3);	
}

void LCD_String(char *str){
	
	Uint8 i = 0;
	while(str[i] != '\0'){
	 LCD_Char(str[i]);
	  i++;
	}
	
}

void LCD_StringPOS(char *str, Uint8 line, Uint8 pos){
	
	switch(line){
		case 1:
		   LCD_Cmd (0x80| (pos & 0x0F));
		   LCD_String(str);
		break;
		
		case 2:
		    LCD_Cmd (0xC0| (pos & 0x0F));
		    LCD_String(str);
		break;
		
	}
	
}

void LCD_CustomChar(Uint8 loc, Uint8 *msg ){
	if(loc < 8){
		LCD_Cmd(0x40 + loc*8);
		for (Uint8 i = 0; i<8; i++){
			LCD_Char(msg[i]);
		}
	}
}

void LCD_Clr()
{
	LCD_Cmd(0x01);
}
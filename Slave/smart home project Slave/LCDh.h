/*
 * LCDh.h
 *
 * Created: 12/14/2020 4:03:45 PM
 *  Author: fadal
 */ 


#ifndef LCDH_H_
#define LCDH_H_

#include "DIO.h"
#define F_CPU 16000000UL
#include <util/delay.h>

#define LCDDataPort PORTA_Reg
#define RS DIO_ChannelB1
#define RW DIO_ChannelB2
#define E DIO_ChannelB3

void LCD_Init(void);
void LCD_Cmd(Uint8 cmd);
void LCD_Char(Uint8 data);
void LCD_String(char *str); 
void LCD_StringPOS(char *str, Uint8 line, Uint8 pos);
void LCD_CustomChar(Uint8 loc, Uint8 *msg );
void LCD_clr();

#endif /* LCDH_H_ */
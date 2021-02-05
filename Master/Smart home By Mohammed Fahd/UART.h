/*
 * UART.h
 *
 * Created: 1/1/2021 5:39:34 PM
 *  Author: fadal
 */ 


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#define F_CPU 16000000UL
#define Baudrate 9600
#define doupleSpeed 0 // 0 less speed

#if doupleSpeed == 0  
   #define MyUBRR ((F_CPU/(16UL*Baudrate))-1)
#else
   #define MyUBRR ((F_CPU/(8UL*Baudrate))-1)   //we can cast it to char
#endif

void uart_init();
void uart_txchar(char data);
char Uart_Rxchar();
void Uart_Txstring(char * string);

#endif /* UART_H_ */
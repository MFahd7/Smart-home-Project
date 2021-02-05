/*
 * UART.c
 *
 * Created: 1/1/2021 5:39:21 PM
 *  Author: fadal
 */ 

#include "UART.h"


void uart_init(){
	UCSRB |= ((1<<RXEN)|(1<<TXEN));
	UCSRC |= ((1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0));
	UBRRL = MyUBRR; //AACC
	UBRRH = (MyUBRR>>8); //00AA
}
void uart_txchar(char data){
	//while(((UCSRA>>UDRE)&1) ==0);
	while(!((UCSRA>>UDRE)&1));              //udre is set auto
	 UDR = data;   
}
char Uart_Rxchar(){
	while(!((UCSRA>>RXC)&1));
	 return UDR;
}
void Uart_Txstring(char * string){
	unsigned char i =0;
	while(string[i] != '\0'){
		uart_txchar(string[i]);
		i++;
	}
}

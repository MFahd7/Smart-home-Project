/*
 * KeyPad.c
 *
 * Created: 12/16/2020 4:49:01 PM
 *  Author: fadal
 */ 

#include "KeyPadh.h"
#include "UART.h"
#include "SPI.h"
#include "Servo.h"
char pass[4] = "0011";
char correct[9] = "\0";
Uint8  i , check, status = 1;

void keyPad_Init(){
	DIO_WriteChannel(C0, STD_High); //define C0 ... & pull up res
	DIO_WriteChannel(C1, STD_High);
	DIO_WriteChannel(C2, STD_High);
	DIO_WriteChannel(C3, STD_High); 
}

void checkR0(){ //we put 0 to R0  1110
	DIO_WriteChannel(R0, STD_low);
	DIO_WriteChannel(R1, STD_High);
	DIO_WriteChannel(R2, STD_High);
	DIO_WriteChannel(R3, STD_High);
	
	if (DIO_readChn(C0) == STD_low){	
			  
	   LCD_Char('*'); //7
	   correct[i] = '7';
	   i++;
	   check++;
	   while(DIO_readChn(C0) == STD_low);  
	}
	if (DIO_readChn(C1) == STD_low){
		
		LCD_Char('*'); //8
		correct[i] = '8';
		i++;
		check++;
		while(DIO_readChn(C1) == STD_low);
	}
	if (DIO_readChn(C2) == STD_low){
		
		LCD_Char('*'); //9
		correct[i] = '9';
		i++;
		check++;
		while(DIO_readChn(C2) == STD_low);
		
	}
	if (DIO_readChn(C3) == STD_low){
		
		LCD_Char('*'); // /
		correct[i] = '/';
		i++;
		check++;
		while(DIO_readChn(C3) == STD_low);
		
	}
}

void checkR1(){
	DIO_WriteChannel(R0, STD_High);
	DIO_WriteChannel(R1, STD_low);
	DIO_WriteChannel(R2, STD_High);
	DIO_WriteChannel(R3, STD_High);
	
	if (DIO_readChn(C0) == STD_low){
		
		LCD_Char('*'); //4
		correct[i] = '4';
		i++;
		check++;
		while(DIO_readChn(C0) == STD_low);
	}
	if (DIO_readChn(C1) == STD_low){
		
		LCD_Char('*'); //5
		correct[i] = '5';
		i++;
		check++;
		while(DIO_readChn(C1) == STD_low);
	}
	if (DIO_readChn(C2) == STD_low){
		
		LCD_Char('*'); //6
		correct[i] = '6';
		i++;
		check++;
		while(DIO_readChn(C2) == STD_low);
	}
	if (DIO_readChn(C3) == STD_low){
		
		LCD_Char('*'); //x
		correct[i] = 'x';
		i++;
		check++;
		while(DIO_readChn(C3) == STD_low);
	}
}

void checkR2(){
	DIO_WriteChannel(R0, STD_High);
	DIO_WriteChannel(R1, STD_High);
	DIO_WriteChannel(R2, STD_low);
	DIO_WriteChannel(R3, STD_High);
	
	if (DIO_readChn(C0) == STD_low){
		LCD_Char('*'); //1
		correct[i] = '1';
		i++;
		check++;
		while(DIO_readChn(C0) == STD_low);
	}
	if (DIO_readChn(C1) == STD_low){

		LCD_Char('*'); //2
		correct[i] = '2';
		i++;
		check++;
		while(DIO_readChn(C1) == STD_low);
	}
	if (DIO_readChn(C2) == STD_low){
		
		LCD_Char('*'); //3
		correct[i] = '3';
		i++;
		check++;
		while(DIO_readChn(C2) == STD_low);
	}
	if (DIO_readChn(C3) == STD_low){
		
		LCD_Char('*'); // -
		correct[i] = '-';
		i++;
		check++;
		while(DIO_readChn(C3) == STD_low);
		
	}
}

void checkR3(){
	
	DIO_WriteChannel(R0, STD_High);
	DIO_WriteChannel(R1, STD_High);
	DIO_WriteChannel(R2, STD_High);
	DIO_WriteChannel(R3, STD_low);
	
	if (DIO_readChn(C0) == STD_low){
		
	  // LCD_Clr();
		 
		while(DIO_readChn(C0) == STD_low);
	}
	if (DIO_readChn(C1) == STD_low){
		
		LCD_Char('*'); // 0
		DIO_WriteChannel(DIO_ChannelD4,STD_High);
		_delay_ms(300);
		DIO_WriteChannel(DIO_ChannelD4,STD_low);
		correct[i] = '0';
		i++;
		check++;
		while(DIO_readChn(C1) == STD_low);	
	}
	if (DIO_readChn(C2) == STD_low){
		
		if(CheckPass() == 1){
			LCD_Cmd(0x01);

			DIO_WriteChannel(DIO_ChannelD5,STD_High);
			 ICR1 = 4999;
			 TCCR1A = (1<<COM1A1)|(1<<WGM11);
			 TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS11)|(1<<CS10); // mode 14
			 OCR1A = 50;
			servoAngle(90);
			LCD_String("  Welcome Sir");
			
			SPI_init(Master);
			Slave_En();
			while(1){
			switch(Uart_Rxchar()){
				 case '1':
				 SPI_TxRx(0x01);
				 Uart_Txstring("\r\n");
				 Uart_Txstring("Room1 ON \r\n");
				 if (Uart_Rxchar()== '1')
				 {
					 SPI_TxRx(0x01);
					 Uart_Txstring("Room1 OFF \r\n");
				 }
				 break;
				 
				 case '2':
				 SPI_TxRx(0x02);
				 Uart_Txstring("\r\n");
				 Uart_Txstring("Room2 ON \r\n");
				 if (Uart_Rxchar()== '2')
				 {
					 SPI_TxRx(0x02);
					 Uart_Txstring("Room2 OFF \r\n");
				 }
				 break;
				
				case '3':
				 SPI_TxRx(0x03);
				 Uart_Txstring("\r\n");
				 Uart_Txstring("TV ON \r\n");
				 if (Uart_Rxchar()== '3')
				 {
					 SPI_TxRx(0x03);
					 Uart_Txstring("TV OFF \r\n");
				 }
				break;
				
				case '4':
				 SPI_TxRx(0x04);
				 Uart_Txstring("\r\n");
				 Uart_Txstring("Fan is Working \r\n");
				 if (Uart_Rxchar()== '4')
				 {
					 SPI_TxRx(0x04);
					 Uart_Txstring("Fan is Closing \r\n");
				 }
				break;
				
				case '5':
				servoAngle(0);
				 Uart_Txstring("\r\n");
				 Uart_Txstring("Door is closed \r\n");
				 if (Uart_Rxchar()== '5')
				 {
					 servoAngle(90);
					 Uart_Txstring("Door is open \r\n");
				 }
				break;
				 
				default:
				Uart_Txstring("Sorry no such option \r\n");
				
			}
		  }
		}
		else{
			LCD_Cmd(0x01);
			LCD_String("Wrong Password!");
			_delay_ms(880);
			LCD_StringPOS("Enter the      ",1,0x80);
			LCD_StringPOS("Password:",2,0xC1);
		}
		status = 0;
		i = 0;
		check = 0;
		while(DIO_readChn(C2) == STD_low);
	}
	if (DIO_readChn(C3) == STD_low){
		
		LCD_Char('*'); //+
		correct[i] = '+';
		i++;
		check++;
		while(DIO_readChn(C3) == STD_low);	
	}
	
 }
 
int CheckPass(){
	if(check != 4){
		return 0;
	}
	else{
		int i;
		for(i=0;i<3;i++){
			if(correct[i] != pass[i]){
				return 0;
			}
			else{
				return 1;
			}
			
		}
	}
}
 
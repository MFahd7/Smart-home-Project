/*
 * ADC.c
 *
 * Created: 12/19/2020 6:13:45 PM
 *  Author: fadal
 */ 



#include "ADC.h"

void ADC_Init(){
	ADMUX = (1<<REFS0)|(1<<REFS1);
	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

unsigned short ADC_Read(unsigned char channel){
	 unsigned short data = 0;
  	ADMUX |= (ADMUX & 0xE0)|(channel & 0X1F); 
	ADCSRA |= (1<<ADSC);
	while (((ADCSRA>>ADIF)&1)==0);
	
	ADCSRA |= (1<<ADIF); //4
	 data = ADCL;
	 data |= ADCH<<8;
     return data;
}

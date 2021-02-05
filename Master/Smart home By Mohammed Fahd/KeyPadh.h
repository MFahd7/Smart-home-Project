/*
 * KeyPadh.h
 *
 * Created: 12/16/2020 4:49:25 PM
 *  Author: fadal
 */ 



#ifndef KEYPADH_H_
#define KEYPADH_H_

#include "LCDh.h"

#define C0 DIO_ChannelC0  // input
#define C1 DIO_ChannelC1
#define C2 DIO_ChannelC2
#define C3 DIO_ChannelC3
#define R0 DIO_ChannelC4  // output
#define R1 DIO_ChannelC5
#define R2 DIO_ChannelC6
#define R3 DIO_ChannelC7

void keyPad_Init();
void checkR0();
void checkR1();
void checkR2();
void checkR3();
int CheckPass();

#endif /* KEYPADH_H_ */
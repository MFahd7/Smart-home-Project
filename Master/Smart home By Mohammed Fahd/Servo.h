/*
 * Servo.h
 *
 * Created: 2/3/2021 11:53:14 AM
 *  Author: fadal
 */ 


#ifndef SERVO_H_
#define SERVO_H_


#define MiniAngle 0
#define MaxAngle 180

#define MiniCount 250
#define Maxcount 500

 void servoAngle(unsigned short angle){
	OCR1A = (((Maxcount-MiniCount)*(angle - MiniAngle))/(MaxAngle - MiniAngle))+ MiniCount-1;
 }


#endif /* SERVO_H_ */
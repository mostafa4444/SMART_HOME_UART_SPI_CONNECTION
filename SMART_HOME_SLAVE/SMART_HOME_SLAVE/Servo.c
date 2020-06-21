/*
 * Servo.c
 *
 * Created: 6/21/2020 1:42:50 PM
 *  Author: user
 */ 
#include "Servo.h"

void ServoMotor(unsigned short angle){
		OCR1A = (((angle - min_angle) * (max_count - min_count))/ (max_angle - min_angle)) + min_count - 1;
}

void Init_Timer(){
	TCCR1A |= (1<<COM1A1) | (1<<WGM11);
	TCCR1B |= (1<<WGM12) | (1<<WGM13) | (1<<CS11) | (1<<CS10);
	ICR1 = 4999;
}
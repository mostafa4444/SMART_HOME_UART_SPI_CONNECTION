/*
 * Servo.h
 *
 * Created: 6/21/2020 1:42:39 PM
 *  Author: user
 */ 


#ifndef SERVO_H_
#define SERVO_H_


#include <avr/io.h>
#define min_angle 0
#define max_angle 180
#define min_count 250
#define max_count 500


void ServoMotor(unsigned short angle);
void Init_Timer();

#endif /* SERVO_H_ */
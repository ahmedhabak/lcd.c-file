/*
 * MOTOR.c
 *
 * Created: 4/5/2023 7:16:40 AM
 *  Author: GENIUS 1
 */ 
#include "MOTOR_Interface.h"

/*****************************Configurations**************************************/
#define IN1 PINA0
#define IN2 PINA1

#define IN3 PINA2
#define IN4 PINA3

#define IN5 PINA4
#define IN6 PINA5

#define IN7 PINA6
#define IN8 PINA7








/*****************************function definitions**************************************/

void MOTOR_Cw(MOTOR_NUM MOTOR_N)
{
	//FIRST IS SHOULD CONFIGURE THE BINS AS OUPUT IN THE DIO FILE CONFIGURATIONS
	switch(MOTOR_N){
		case M1:
			DIO_WritePin(IN1,HIGH);
			DIO_WritePin(IN2,LOW);
			break;
			case M2:
			DIO_WritePin(IN3,HIGH);
			DIO_WritePin(IN4,LOW);
			break;
			case M3:
			DIO_WritePin(IN5,HIGH);
			DIO_WritePin(IN6,LOW);
			break;
			case M4:
			DIO_WritePin(IN7,HIGH);
			DIO_WritePin(IN8,LOW);
			break;
	}
}
void MOTOR_Ccw(MOTOR_NUM MOTOR_N)
{
	//FIRST IS SHOULD CONFIGURE THE BINS AS OUPUT IN THE DIO FILE CONFIGURATIONS
	switch(MOTOR_N){
		case M1:
		DIO_WritePin(IN1,LOW);
		DIO_WritePin(IN2,HIGH);
		break;
		case M2:
		DIO_WritePin(IN3,LOW);
		DIO_WritePin(IN4,HIGH);
		break;
		case M3:
		DIO_WritePin(IN5,LOW);
		DIO_WritePin(IN6,HIGH);
		break;
		case M4:
		DIO_WritePin(IN7,LOW);
		DIO_WritePin(IN8,HIGH);
		break;
	}
}
void MOTOR_Stop(MOTOR_NUM MOTOR_N)
{
	//FIRST IS SHOULD CONFIGURE THE BINS AS OUPUT IN THE DIO FILE CONFIGURATIONS
	switch(MOTOR_N){
		case M1:
		DIO_WritePin(IN1,LOW);
		DIO_WritePin(IN2,LOW);
		break;
		case M2:
		DIO_WritePin(IN3,LOW);
		DIO_WritePin(IN4,LOW);
		break;
		case M3:
		DIO_WritePin(IN5,LOW);
		DIO_WritePin(IN6,LOW);
		break;
		case M4:
		DIO_WritePin(IN7,LOW);
		DIO_WritePin(IN8,LOW);
		break;
	}
}

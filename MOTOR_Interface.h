

#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_

#include "DIO_Interface.h"

typedef enum{
	M1,
	M2,
	M3,
	M4
	}MOTOR_NUM;
	
void MOTOR_Cw(MOTOR_NUM);
void MOTOR_Ccw(MOTOR_NUM);
void MOTOR_Stop(MOTOR_NUM);



#endif /* MOTOR_INTERFACE_H_ */
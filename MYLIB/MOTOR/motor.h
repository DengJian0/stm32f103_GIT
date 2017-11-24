#ifndef _MOTOR_H
#define _MOTOR_H
#include "stm32f10x.h" 
#include "timer.h"
#include "pid.h"

void MOTOR_Inite(void);
void MOTOR_SPEED_PositCrl(struct _POSIT_PID posit_pid ,u16 cntx);

////////////////////////////////////////////////////////////////////
void MOTOR_SET(u16 plus);



#endif

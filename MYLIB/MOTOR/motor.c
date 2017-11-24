#include "motor.h"

void MOTOR_Inite()
{
	TIM1_OC_Init();
}
void MOTOR_SET(u16 plus)
{
	TIM1_OCH1_SET_PULSE(plus);
  TIM1_OCH2_SET_PULSE(plus);
}

void MOTOR_SPEED_PositCrl(struct _POSIT_PID posit_pid ,u16 cntx)
{
	 
	
}


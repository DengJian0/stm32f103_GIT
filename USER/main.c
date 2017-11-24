#include "stm32f10x.h"
#include "motor.h"
#include "timer.h"
#include "pid.h"


void delay_ms(u16 ms);
u16 plus=0;
u16 speed=0;
int main()
{

	u16 flag=0;
	//u16 plus=0;
	
	//delay_init();

	MOTOR_Inite();
	NVIC_PriorityGroupConfig(0x02);
	TIM3_ECODE_Init();
  TIM4_GetSpeed_Init();
	delay_ms(2000);
	Posit_PID_Init();
	Posit_PID_Set_CNTx(0xD0);
	
  while(1)
	{
	
//		delay_ms(2000);
//		
	//	MOTOR_SET(speed); 
//		
//		if(flag==0)
//			plus+=10;
//		else
//			plus-=10;
//		
//		if(plus==1000)
//			flag=1;
//		if(plus==0)
//			flag=0;
	}	
}

void delay_ms(u16 ms)
{
	u8 i,j;
	for(i=110;i>0;i--)
	{
		for(j=ms;j>0;j--);
	}
}

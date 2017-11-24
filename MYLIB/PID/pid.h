#ifndef _PID_H
#define _PID_H

#include "stm32f10x.h"

#include<stdio.h>
#include<stdlib.h>

struct _incre_pid
{
	float SetSpeed; // 
	float ActualSpeed; // 
	float err; // 
	float err_next; // 
	float err_last; // 
	float Kp,Ki,Kd; // 
} ;

struct _POSIT_PID
{
	u16   SET_CNTX; //  目标速度
	
	u16  ACT_CNTx;
  u16 err_now;      //  当前误差
  u16 err_last; //  上次误差
	
  float Kp,Ki,Kd; //  PID系数
	
  u16 integral; //  积分累加
	
	u16 ctrlout;  //控制量输出
	
	float Imax;
} ;

//positional pid
//
void Posit_PID_Set_CNTx(u16 set_CNTx);   //设置理想速度值
void Posit_PID_Init(void);
u16 Posit_PID_Conver(u16 act_cntx);




////incremental pid;
//void Incre_PID_Init(void);
//u16 Posit_PID_Conver(struct _POSIT_PID posit_pid,u16 act_cntx);   //输入编码器的值   输出PID修改后的 控制电机的PWM值 compare

#endif

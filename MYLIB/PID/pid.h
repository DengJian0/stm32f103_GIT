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
	u16   SET_CNTX; //  Ŀ���ٶ�
	
	u16  ACT_CNTx;
  u16 err_now;      //  ��ǰ���
  u16 err_last; //  �ϴ����
	
  float Kp,Ki,Kd; //  PIDϵ��
	
  u16 integral; //  �����ۼ�
	
	u16 ctrlout;  //���������
	
	float Imax;
} ;

//positional pid
//
void Posit_PID_Set_CNTx(u16 set_CNTx);   //���������ٶ�ֵ
void Posit_PID_Init(void);
u16 Posit_PID_Conver(u16 act_cntx);




////incremental pid;
//void Incre_PID_Init(void);
//u16 Posit_PID_Conver(struct _POSIT_PID posit_pid,u16 act_cntx);   //�����������ֵ   ���PID�޸ĺ�� ���Ƶ����PWMֵ compare

#endif

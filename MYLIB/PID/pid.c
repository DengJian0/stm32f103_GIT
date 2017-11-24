#include "pid.h"

//void Posit_PID_Conver(struct _POSIT_PID posit_pid,u16 act_cntx)
//{
//	//posit_pid.
//}

void Posit_PID_Set(struct _POSIT_PID* posit_pid)
{
	posit_pid->Imax=20;
	posit_pid->integral=0;
	posit_pid->Kd=0.2;
	posit_pid->Ki=0.5;
	posit_pid->Kp=0.5;
	posit_pid->SET_CNTX=200;
}


u16 Posit_PID_Conver(struct _POSIT_PID posit_pid,u16 act_cntx)
{
	posit_pid.ACT_CNTx=act_cntx;
	posit_pid.err_now=	posit_pid.ACT_CNTx-  posit_pid.SET_CNTX;
	
	
	//ÅÐ¶Ï»ý·Ö±¥ºÍ
	if(posit_pid.integral<posit_pid.Imax)
  posit_pid.integral+=posit_pid.err_now;
	//	
	posit_pid.ctrlout=posit_pid.Kp*posit_pid.err_now+posit_pid.Ki*posit_pid.integral+posit_pid.Kd*(posit_pid.err_now-posit_pid.err_last);
	posit_pid.err_last=posit_pid.err_now;
	//	pid.voltage=pid.Kp*pid.err+pid.Ki*pid.integral+pid.Kd*(pid.err-pi
//d.err_last);
	return  posit_pid.ctrlout;
}

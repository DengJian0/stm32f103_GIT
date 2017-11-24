#include "pid.h"

//void Posit_PID_Conver(struct _POSIT_PID posit_pid,u16 act_cntx)
//{
//	//posit_pid.
//}

struct _POSIT_PID posit_pid;

void Posit_PID_Init(void)    //初始化
{
	posit_pid.ACT_CNTx=0;
	posit_pid.ctrlout=0;
	posit_pid.err_last=0;
	posit_pid.err_now=0;
	posit_pid.Imax=20;
	posit_pid.integral=0;
	posit_pid.Kd=5;
	posit_pid.Ki=5;
	posit_pid.Kp=5;
	posit_pid.SET_CNTX=0;
}

void Posit_PID_Set_CNTx(u16 set_CNTx)  //设置理想速度
{
	posit_pid.SET_CNTX=set_CNTx;
}


u16 Posit_PID_Conver(u16 act_cntx)    //PID计算
{
	posit_pid.ACT_CNTx=act_cntx;
	posit_pid.err_now=	posit_pid.ACT_CNTx-  posit_pid.SET_CNTX;
	
	//判断积分饱和
	if(posit_pid.integral<posit_pid.Imax)
  posit_pid.integral+=posit_pid.err_now;
	//	
	posit_pid.ctrlout=posit_pid.Kp*posit_pid.err_now+posit_pid.Ki*posit_pid.integral+posit_pid.Kd*(posit_pid.err_now-posit_pid.err_last);
	posit_pid.err_last=posit_pid.err_now;
	//	pid.voltage=pid.Kp*pid.err+pid.Ki*pid.integral+pid.Kd*(pid.err-pi
//d.err_last);
	return  posit_pid.ctrlout;
}

#ifndef __USER_CONTORL_H__
#define __USER_CONTORL_H__

extern  void Set_ID(const char *ptr);
extern  void Read_ID(void);
extern void help(void);
extern void reset(void);
extern void Peripheral_Equipment_Init(void);
extern  void Init_Choose(uint16_t m);
extern void Moudule_Contorl(char a);
extern void Led_Contorl(char a);
extern void Speaker_Action_Contorl(char a);
extern void Set_Speaker_Power(const char *ptr);
extern void Speaker_Contorl(char x);
extern void Information(void);
#endif

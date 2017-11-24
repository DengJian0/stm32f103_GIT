/****************************************Copyright (c)****************************************************
**                                 http://www.myzygroup.com.cn
**--------------File Info---------------------------------------------------------------------------------
** File name:           user_contorl.c
** Last modified Date:  2015-12-01
** Last Version:        V1.00
**
**--------------------------------------------------------------------------------------------------------
** Created by:          Kylin Li
** Created date:        2015-12-01
** Version:             V1.00
** Descriptions:        Dock Flex Test
**
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/
#include "Baseboard.h"
#include "Baseboard_Flash.h"
#include "Resistance_Test_Board.h"
#include "Short_Test_Board.h"

#define Short 1
#define Resistance 2
extern uint16_t	channel;
extern uint8_t GulNum; 
//=============================================================
/*************************************************
**函数名:Set_ID
**功能:设置ID
**注意事项：范围（0-65535）
*************************************************/
void Set_ID(const char *ptr)
{
	uint32_t leve;
  if(strncmp(ptr,"SET ID M",7)==0)
  {
		leve=(ptr[8]-0x30)*10000+(ptr[9]-0x30)*1000+(ptr[10]-0x30)*100+(ptr[11]-0x30)*10+(ptr[12]-0x30);
		if((GulNum==13)&&(leve<65535))
		{
			Baseboard_WriteFlash(0x30,leve); 
			Print_String("ID:M");	Print_U32(Baseboard_ReadFlash(0X30));	Print_String("\r\n@_@");	
		}
	else 
    Print_String("This command is illegal,please check it again\r\n@_@"); 
	}
}

/*************************************************
**函数名:Read_ID
**功能:读ID号
**注意事项：
*************************************************/
void Read_ID()
{
	Print_String("ID:M");	Print_U32(Baseboard_ReadFlash(0X30));	Print_String("\r\n@_@");
}
/*************************************************
**函数名:help
**功能:列出所有指令
**注意事项：
*************************************************/
void help()
{
	channel =Baseboard_ReadFlash(0x1FF);
	if(channel==1)
	{
	Print_String("//********************************************************************//\r\n");
	Print_String("//********************************************************************//\r\n");
	Print_String("//**                                                                **//\r\n");
	Print_String("//**      the list of Station_3 command:                            **//\r\n");	
	Print_String("//**          1: Short Test                                         **//\r\n");
  Print_String("//**          2: LTA Controls 0V                                    **//\r\n");	
  Print_String("//**          3: LTA Controls 1V8                                   **//\r\n");	
	Print_String("//**          4: HW Help                                            **//\r\n");	
	Print_String("//**          5: Open 2V7 To LDO14_2V65                             **//\r\n");	
	Print_String("//**          6: Close 2V7 To LDO14_2V65                            **//\r\n");	
	Print_String("//**          7: Open 1V8 To LTA_SW1                                **//\r\n");	
	Print_String("//**          8: Close 1V8 To LTA_SW1                               **//\r\n");	
	Print_String("//**          9: Open 1V8 To LTA_SW2                                **//\r\n");	
	Print_String("//**         10: Close 1V8 To LTA_SW2                               **//\r\n");	
	Print_String("//**         11: Open Uxx                                           **//\r\n");	
	Print_String("//**         12: Close Uxx                                          **//\r\n");	
	Print_String("//**         13: Cap Test                                           **//\r\n");	
	Print_String("//**         14: Capacitance Calibration                            **//\r\n");	
	Print_String("//**         15: Read Capacitance Value                             **//\r\n");	
	Print_String("//**         16: Reset Capacitance Value                            **//\r\n");	
	Print_String("//**         17: Lightning Out                                      **//\r\n");	
	Print_String("//**         18: Lightning Reset                                    **//\r\n");	
  Print_String("//**                                                                **//\r\n");
	Print_String("//**         19: Reset Fixture                                      **//\r\n");	
	Print_String("//**         20: Module Up                                          **//\r\n");
  Print_String("//**         21: Module Down                                        **//\r\n");
	Print_String("//**         22: Speaker Up                                         **//\r\n");	
	Print_String("//**         23: Speaker Down                                       **//\r\n");		
	Print_String("//**         24: Open Speaker                                       **//\r\n");
	Print_String("//**         25: Close Speaker                                      **//\r\n");
	Print_String("//**         26: Set Speaker Power xx                               **//\r\n");	
	Print_String("//**         27: Set ID Mxxxxx                                      **//\r\n");	
	Print_String("//**         28: Read ID                                            **//\r\n");	
	Print_String("//**         29: Fixture Information                                **//\r\n");	
	Print_String("//**         30: Open Powerx xxxx                                   **//\r\n");	
	Print_String("//**         31: Close Powerx                                       **//\r\n");	
	Print_String("//**                                                                **//\r\n");
	Print_String("//****************   Kunshan Myzy Technology Co.,Ltd.   **************//\r\n");
	Print_String("//***********************   www.myzygroup.com   **********************//\r\n@_@");	

	}
	else if(channel==2)
	{

	Print_String("//********************************************************************//\r\n");
	Print_String("//********************************************************************//\r\n");
	Print_String("//**                                                                **//\r\n");
	Print_String("//**      the list of Station_2 command:                           **//\r\n");
	Print_String("//**          1: Resistance Test                                    **//\r\n");		
	Print_String("//**          2: Calibration                                        **//\r\n");	
	Print_String("//**          3: Read Offset Value                                  **//\r\n");	
	Print_String("//**          4: Reset Offset Value                                 **//\r\n");	
	Print_String("//**          5: Voltage                                            **//\r\n");	
	Print_String("//**          6: High Power Mode Sensitivity Test                   **//\r\n");	
	Print_String("//**          7: Low Power Mode Sensitivity Test                    **//\r\n");
	Print_String("//**          8: MAX4782 xy  (x=0/1) (y=0/1/2/3)                    **//\r\n");		
	Print_String("//**          9: Read Channel Value                                 **//\r\n");	
	Print_String("//**                                                                **//\r\n");	
	Print_String("//**         10: Module Up                                          **//\r\n");
  Print_String("//**         11: Module Down                                        **//\r\n");
	Print_String("//**         12: Speaker Up                                         **//\r\n");	
	Print_String("//**         13: Speaker Down                                       **//\r\n");		
	Print_String("//**         14: Open Speaker                                       **//\r\n");
	Print_String("//**         15: Close Speaker                                      **//\r\n");
	Print_String("//**         16: Set Speaker Power xx                               **//\r\n");	
	Print_String("//**         17: Set ID Mxxxxx                                      **//\r\n");	
	Print_String("//**         18: Read ID                                            **//\r\n");	
	Print_String("//**         19: Fixture Information                                **//\r\n");	
	Print_String("//**         20: Open Powerx xxxx                                   **//\r\n");	
	Print_String("//**         21: Close Powerx                                       **//\r\n");	
	Print_String("//**         22: Reset Fixture                                      **//\r\n");	
	Print_String("//**                                                                **//\r\n");
	Print_String("//****************   Kunshan Myzy Technology Co.,Ltd.   **************//\r\n");
	Print_String("//***********************   www.myzygroup.com   **********************//\r\n@_@");	
}
	else
	{
	Print_String("//********************************************************************//\r\n");
	Print_String("//********************************************************************//\r\n");
	Print_String("//**                                                                **//\r\n");
	Print_String("//**      the list of Baseboard command:                            **//\r\n");
	Print_String("//**          1: Set Init To Station_2 Board                        **//\r\n");	
	Print_String("//**          2: Set Init To Station_3 Board                        **//\r\n");
	Print_String("//**                                                                **//\r\n");
	Print_String("//****************   Kunshan Myzy Technology Co.,Ltd.   **************//\r\n");
	Print_String("//***********************   www.myzygroup.com   **********************//\r\n@_@");	

	}
}
void Information()
{

	channel =Baseboard_ReadFlash(0x1FF);
	if(channel==1)
	{	
	Print_String("Last Version:  V1.0.20151202\r\n");
	Print_String("Descriptions:  Station_3\r\n");
	Print_String("Programmer:    Curry Shao    EE\r\n");
	Print_String("Emil:          curry.shao@myzygroup.com\r\n");
	Print_String("URL:           http://www.myzygroup.com.cn\r\n");
	Print_String("Vendor:        KunShan Myzy Technology Co.,Ltd.\r\n@_@");
	}
else if(channel==2)
{
	Print_String("Last Version:  V1.0.20151202\r\n");
	Print_String("Descriptions:  Station_2\r\n");
	Print_String("Programmer:    Kylin Li  EE\r\n");
	Print_String("Emil:          lizuolin@myzygroup.com\r\n");
	Print_String("URL:           http://www.myzygroup.com.cn\r\n");
	Print_String("Vendor:        KunShan Myzy Technology Co.,Ltd.\r\n@_@");
}
}
/*************************************************
**函数名:reset
**功能:软件复位
**注意事项：
*************************************************/
void reset()
{
	Delay_ms(50);
  NVIC_SystemReset();
}

/*************************************************
**函数名:Peripheral_Equipment_Init
**功能:外部附件初始化
**注意事项：
*************************************************/
void Peripheral_Equipment_Init()
{
	channel =Baseboard_ReadFlash(0x1FF);
	switch(channel)
	{
		case 1: {Short_Test_Board_Init();Print_String("Initialized to Station_3 Board\r\n@_@");	};break;
		case 2:	{Resistance_Init();Print_String("Initialized to Station_2 Board\r\n@_@");};break;
		default:{Print_String("Initialization is not set\r\n@_@");};break;
	}
}

/*************************************************
**函数名:Init_Choose
**功能:选择初始化
**注意事项：
*************************************************/
void Init_Choose(uint16_t m)
{
	if(m==Short)
	{	
	Baseboard_WriteFlash(0x1FF,1);
	Print_String("Set the initialized to Station_3 Board\r\n@_@");	
	}
else if	(m==Resistance)
	{	
	Baseboard_WriteFlash(0x1FF,2);
	Print_String("Set the initialized to Station_2 Board\r\n@_@");			
	}	
	channel =Baseboard_ReadFlash(0x1FF);	
}
/*************************************************
**函数名:Moudule_Contorl
**功能:每个工位主气缸下降上升控制
**注意事项：
*************************************************/
void Moudule_Contorl(char x)
{
	if(x==1)//工位3
	{
		if((Baseboard_Sensor_GetState(Sensor3,0,0)==0)||(Baseboard_ReadFlash(0x1FF)==2))
		{
			Baseboard_Cylinder_On(Cylinder2);
			Baseboard_Sensor_GetState(Sensor2,0,2000);
			if(( Baseboard_Sensor_GetState(Sensor2,0,0)==0)&&(Baseboard_Sensor_GetState(Sensor1,0,0)!=0))
			{	
				Baseboard_Cylinder_On(Cylinder8);//红灯
				Baseboard_Cylinder_Off(Cylinder6);	
				Delay_ms(200);
				Print_String("Module Down Pass\r\n@_@");
			}
		
			else
			{	
				Baseboard_Cylinder_On(Cylinder6);//绿灯
				Baseboard_Cylinder_Off(Cylinder8);
				Baseboard_Cylinder_Off(Cylinder2);
				Delay_ms(100);
				Print_String("Module Down Fail\r\n@_@");
			}
		}
		else
		{
			Print_String("Please Lightning Reset\r\n@_@");
		}
	}
	else//工位2 
	{
		if((Baseboard_Sensor_GetState(Sensor3,0,0)==0)||(Baseboard_ReadFlash(0x1FF)==2))
		{
			Baseboard_Cylinder_On(Cylinder6);//绿灯
			Baseboard_Cylinder_Off(Cylinder8);
			Baseboard_Cylinder_Off(Cylinder2);
			Baseboard_Sensor_GetState(Sensor2,1,2000);
		if( Baseboard_Sensor_GetState(Sensor2,0,0)!=0)
		{
			Delay_ms(100);
			Print_String("Module Up Pass\r\n@_@");	
		}	
	 }
		else
		{
			Print_String("Please Lightning Reset\r\n@_@");
		}		
		
	}
}
/*************************************************
**函数名:Led_Contorl
**功能:每个工位LED指示灯
**注意事项：
*************************************************/
void Led_Contorl(char x)
{
	if(x==1)
	{
		Baseboard_Cylinder_On(Cylinder8);//红灯
		Baseboard_Cylinder_Off(Cylinder6);	
		Delay_ms(100);
		Print_String("Open Red Led Pass\r\n@_@");
	}
	else
	{
		Baseboard_Cylinder_On(Cylinder6);//绿灯
		Baseboard_Cylinder_Off(Cylinder8);
		Delay_ms(100);
		Print_String("Open Green Led Pass\r\n@_@");		
	}
}
/*************************************************
**函数名:Speaker_Action_Contorl
**功能:喇叭上升下降控制
**注意事项：
*************************************************/
void Speaker_Action_Contorl(char x)
{
	if(x==1)
	{
		Baseboard_Cylinder_On(Cylinder1);
		Baseboard_Sensor_GetState(Sensor5,0,2000);
		if( (Baseboard_Sensor_GetState(Sensor5,0,0))==0)
		{		
			Delay_ms(200);
			Print_String("Speaker Up Pass\r\n@_@");
		}
		else
		{		
			Baseboard_Cylinder_Off(Cylinder1);
			Delay_ms(100);
			Print_String("Speaker Up Fail\r\n@_@");
		}							
	}
	else
	{
		Baseboard_Cylinder_Off(Cylinder1);
		Delay_ms(100);
		if((Baseboard_Sensor_GetState(Sensor5,1,200))==1)
		Print_String("Speaker Down Pass\r\n@_@");
		else
		Print_String("Speaker Down Fail\r\n@_@");			
	}	
}
/*************************************************
**函数名:Speaker_Contorl
**功能:喇叭声音开关控制
**注意事项：
*************************************************/
void Speaker_Contorl(char x)
{
	if(x==1)
	{
		ad9833_data(1000,0,2,0 );
		Baseboard_Speaker_LOW(Speaker_control);
		Delay_ms(100);
		Print_String("Open Speaker Pass\r\n@_@");
	
	}
	else
	{
		Baseboard_Speaker_HIGH(Speaker_control);
		Delay_ms(100);
		Print_String("Close Speaker Pass\r\n@_@");		
	}
}
/*************************************************
**函数名:Set_Speaker_Power
**功能:设置声音大小
**注意事项：0-31
*************************************************/
void Set_Speaker_Power(const char *ptr)
{
	uint32_t leve;
  if(strncmp(ptr,"SET SPEAKER POWER",16)==0)
  {
		leve=(ptr[18]-0x30)*10+(ptr[19]-0x30);
		if((GulNum==20)&&(leve<32))
		{	
			Set_Spk_Power(leve);
			Print_String("Set Speaker Power ");Print_U32(leve);Print_String(" Pass\r\n@_@");
		}
		else 
    Print_String("This command is illegal,please check it again\r\n@_@");	
	}
}	

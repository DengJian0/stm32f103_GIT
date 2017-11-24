/****************************************Copyright (c)****************************************************
**                                 http://www.toptest.com.tw
**--------------File Info---------------------------------------------------------------------------------
** File name:           user_command.c
** Last modified Date:  2016-8-01
** Last Version:        V1.00
**
**--------------------------------------------------------------------------------------------------------
** Created by:          Kylin Li
** Created date:        2016-8-01
** Version:             V1.00
** Descriptions:        
**
**********************************************************************************************************/   

#include "Baseboard.h"
/* Includes ------------------------------------------------------------------*/

/*********************************************************************************************************
  Command ∂®“Â
*********************************************************************************************************/

const char  *str1="HELP";
const char  *str2="READ FLASH";
const char  *str3="WRITE FLASH";
const char  *str4="READ LEVEL";
uint8_t user_check(uint8_t *ptr)
{
	a_A(ptr);
	
	if(ptr[0]=='\0'){Print_String("\n@_@");}	
	else if(strcmp(str1,(const char *)ptr)==0){return 0;}
	else if(strcmp(str2,(const char *)ptr)==0){printf("flash is  %d\r\n",Baseboard_ReadFlash(ADDR_1));return 0;}
	else if(strcmp(str3,(const char *)ptr)==0){	Baseboard_WriteFlash(ADDR_1,23465);printf("flash is  %d\r\n",Baseboard_ReadFlash(ADDR_1));return 0;}		
	else if(strcmp(str4,(const char *)ptr)==0){printf("The Level is %d\r\n",Baseboard_IO_GetState(IO2,0,1000));return 0;}
  else if(ptr[0]=='\0'){Print_String("\r\n@_@");return 0;}
  else{Print_String("This command is illegal,please check it again\r\n@_@");return 0;}	
	return 0;
}



/************************ (C) COPYRIGHT Shenzhen Leader Technology Co.,Ltd.  *****END OF FILE****/


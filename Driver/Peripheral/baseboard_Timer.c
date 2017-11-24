/****************************************Copyright (c)****************************************************
**                                 http://www.myzygroup.com.cn
**--------------File Info---------------------------------------------------------------------------------
** File name:           time.c
** Last modified Date:  2015-06-03
** Last Version:        V1.00
**
**--------------------------------------------------------------------------------------------------------
** Created by:          Lim Lee
** Created date:        2015-06-08
** Version:             V1.00
** Descriptions:        Tiger
**
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/
#include "stm32f10x_rcc.h"
#include "Baseboard_Timer.h"
#include "stm32f10x_tim.h"
/*********************************************************************************************************
* Function Name:        TIMER32_0_IRQHandler
* Description:          TIMER0 ??????
* Input:                ?
* Output:               ?
* Return:               ?
*********************************************************************************************************/
uint32_t timer3_counter;
uint32_t LED;
void Basevoard_LED_Init()
{
  GPIO_InitTypeDef  gpioinitstruct = {0};

  gpioinitstruct.GPIO_Pin    = LED_PIN;
  gpioinitstruct.GPIO_Mode   = GPIO_Mode_Out_PP;
  gpioinitstruct.GPIO_Speed  = GPIO_Speed_2MHz;

  GPIO_Init(LED_PORT, &gpioinitstruct);

  GPIO_SetBits(LED_PORT, LED_PIN);
}
//==============================================================
void TIM3_IRQHandler(void)
{
	TIM_ClearFlag(TIM3, TIM_FLAG_Update);
	timer3_counter++;
	LED++;
	if(LED==500)
	{
		GPIO_ResetBits(GPIOC, GPIO_Pin_8);	
	}
	else if(LED>1000)
	{
		LED = 0;
		GPIO_SetBits(GPIOC, GPIO_Pin_8);	
	}	
}
/*********************************************************************************************************
** Function name:        timer0Init
** Descriptions:        32????0?????
** input parameters:    ?
** output parameters:   ?
** Returned value:      ?
*********************************************************************************************************/
void timer_Init (void)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
		NVIC_InitTypeDef NVIC_InitStructure;
		//?????????
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
		//???????
		TIM_DeInit(TIM3); 
		TIM_TimeBaseStructure.TIM_Period = 100; 								 	//1ms??			 
		TIM_TimeBaseStructure.TIM_Prescaler = (72000000/100000 - 1);              
		TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;     
		TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
		TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
		TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);	
		//????
		NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  //?????2 ??????? 
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;		  	 //?????0 ????????
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;	
		NVIC_Init(&NVIC_InitStructure);	  		
		//???
		TIM_ClearFlag(TIM3, TIM_FLAG_Update);					  
		TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);		
		//?????			 
		TIM_Cmd(TIM3, ENABLE); 
		Basevoard_LED_Init();
}


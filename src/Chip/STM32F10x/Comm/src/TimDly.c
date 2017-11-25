/*
 ============================================================================
 Name        : TimDly.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "stm32f10x.h"
#include "TimDly.h"

void TimDlyMs(uint16_t ms)
{
  TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6 , ENABLE);
	
	/* ʱ��Ԥ��Ƶ��Ϊ36000������Ƶ72Mʱ��������ÿ500us��1*/
  TIM_TimeBaseInitStructure.TIM_Prescaler = 3599;
  TIM_TimeBaseInitStructure.TIM_Period = ms * 2;
  TIM_TimeBaseInit(TIM6, &TIM_TimeBaseInitStructure);

	/* ���ö�ʱʱ�䵽���Ժ�ֹͣ��ʱ������ */
  TIM_SelectOnePulseMode(TIM6, TIM_OPMode_Single);
  
  TIM_ClearFlag(TIM6, TIM_IT_Update);
  
  TIM_Cmd(TIM6, ENABLE);
  
  while(TIM_GetFlagStatus(TIM6, TIM_IT_Update) == RESET);
  
  TIM_ClearFlag(TIM6, TIM_IT_Update);
}

void TimDlyUs(uint16_t us)
{
  TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7 , ENABLE);
	
	TIM_TimeBaseInitStructure.TIM_Prescaler = 7200-1;
	TIM_TimeBaseInitStructure.TIM_Period = us;
	TIM_TimeBaseInit(TIM7, &TIM_TimeBaseInitStructure);
	
	TIM_SelectOnePulseMode(TIM7, TIM_OPMode_Single);
	
	TIM_ClearFlag(TIM7, TIM_IT_Update);
	
	while(TIM_GetFlagStatus(TIM7, TIM_IT_Update) == RESET);
	
	TIM_ClearFlag(TIM7, TIM_IT_Update);
}


/*
 * IODefCfg.h
 *  �弶IO������
 *  Created on: 20IODefCfg��x��x��
 *      Author: HeHuiBo
 */

#ifndef IODefCfg_H_
#define IODefCfg_H_

#include "stm32f10x.h"

/*LED��������*/
#define LED0_PORT_CLK    RCC_APB2Periph_GPIOA
#define LED0_PORT        GPIOA
#define LED0_PIN_BIT     GPIO_Pin_0

#define LED0_PORT_CLK    RCC_APB2Periph_GPIOA
#define LED0_PORT        GPIOA
#define LED0_PIN_BIT     GPIO_Pin_1

#define BEEP_PORT_CLK    RCC_APB2Periph_GPIOA
#define BEEP_PORT        GPIOA
#define BEEP_PIN_BIT     GPIO_Pin_8

#endif /* IODefCfg_H_ */

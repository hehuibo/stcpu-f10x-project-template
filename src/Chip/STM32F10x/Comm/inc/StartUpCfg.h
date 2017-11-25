#ifndef _STM_STARTUPCFG_H
#define _STM_STARTUPCFG_H

#include "stm32f10x.h"

#define NVIC_DISABLE_INTERRUPTS()    __set_FAULTMASK(1)
#define NVIC_ENABLE_INTERRUPTS()	 __set_FAULTMASK(0)

enum BOOTMODECMD
{
  iCmdReBoot = 0,               /*ֱ�Ӹ�λ*/
  iCmdIAPUpGradeMode = 1,       /*����Boot����ģʽ*/
  
};

struct BootMessage
{
  unsigned int magic;
  enum BOOTMODECMD bootcmd;
};

void vStartUpConfigure(void);

void ReBoot(enum BOOTMODECMD Mode);

#if defined (_LOADER) || defined (_NoRTOSKernel) 
uint32_t xGetTickCount(void);

void SysTickDlyMs(uint32_t ms);
#endif

#endif

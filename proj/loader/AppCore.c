#include "main.h"

#define FSM_TIMEOUT_1S      100
uint16_t g_uiDelay1S = FSM_TIMEOUT_1S;

/****״̬��*****/
volatile xTGlobalFsm_t g_FSM;

/***��ʼ��оƬ�ڲ���Դ***/
static void InitChipInternal(void)
{
  vGPIO_Configure();

}

/***��ʼ����Χ�豸***/
static void InitBoardPeripheral(void)
{ 

}


static void AppTargetInit(void)
{
  vStartUpConfigure();
}

/*
 ============================================================================
		��ʼ��
 ============================================================================
 */
void AppTaskInit(void)
{
  AppTargetInit();
  
  /***��ʼ��оƬ�ڲ���Դ***/
  InitChipInternal();
  
  /***��ʼ����Χ�豸***/
  InitBoardPeripheral();  
}


/*
 ============================================================================
		��ѵ����
 ============================================================================
 */
/*******************10MSTask**************************/
void vDelay10MSTask(void)
{
  if(FSM_IsOff(g_FSM.FSM_TASK_DELAY10MS)){
    return;
  }  
  FSM_SetOff(g_FSM.FSM_TASK_DELAY10MS);
	
  if((g_uiDelay1S >0 )&&(--g_uiDelay1S == 0)){
    FSM_SetOn(g_FSM.FSM_TASK_DELAY1S);
    g_uiDelay1S = FSM_TIMEOUT_1S;
  }

}
/*********************1STask****************************/
void vDelay1STask(void)
{
  if(FSM_IsOff(g_FSM.FSM_TASK_DELAY1S)){
    return;
  }  
  FSM_SetOff(g_FSM.FSM_TASK_DELAY1S);
}

/***************MainTask*************************/

void vMainTask(void)
{

}

/**����**/
const pfnFsmFUNCTION_t g_fnAppTaskAry = {
  vDelay10MSTask,
  vDelay1STask,
  vMainTask
};

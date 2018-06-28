/***********************************************
Copyright:Elite
FileName:ϵͳʱ��SysTick��ʱ����
Author:z
Version:1.0
Date:2018.5.16
Description:��ʱ����ʱ����
Function List:
History:
ʹ�����̣��δ�ʱ�ӳ�ʼ��SysTick_Init() -> �趨��ʱʱ��SysTickDelayMs(int ms)
****************************************************/

#include "systick.h"
#include "NUC029xAN.h"
#include <stdint.h>  
static int SysTickDelay = 0;
void SysTick_Init(void)//��ʼ���ں˶�ʱ��
{
    NVIC_EnableIRQ(SysTick_IRQn);//ʹ��SysTick�ж�
    SysTick_Config(50000);  //װ��1mS
	  SysTickInterrupt_Disable();  //�����ж�
}
void SysTickInterrupt_Enable(void)//�����ж�
{
    SysTick->CTRL = SysTick->CTRL | (1<<0);
}

void SysTickInterrupt_Disable(void)//�����ж�
{
    SysTick->CTRL = SysTick->CTRL & (~(1<<0));
}

void SysTick_Handler(void)//�ж�
{
     if(SysTickDelay !=0)
		 {
		     SysTickDelay--;
			   if(SysTickDelay == 0)
			   {
			       SysTickInterrupt_Disable();//�����ж�
			   }
		 }			 
}

int SysTick_GetIntFlag(void)//��ȡϵͳ��ʱ��״̬
{
	  return(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk ? 1:0);
}

void SysTick_ClearIntFlag(void)//��ձ�־λ
{
    SysTick->CTRL = SysTick->CTRL | SysTick_CTRL_COUNTFLAG_Msk;
}

void SysTickDelayMs(int ms)
{
	  SysTickDelay = ms;
    SysTickInterrupt_Enable();//�����ж�
	  while(SysTickDelay != 0){}
    SysTickInterrupt_Disable();//�����ж�
}
/*
void SYS_CKO_Init(void)//����3.6��Ϊʱ�������,��֤ʱ��׼ȷ��
{
	  CLK_EnableCKO(CLK_CLKSEL2_FRQDIV_S_HXT,0,0);
    SYS->P3_MFP &= ~(SYS_MFP_P36_Msk | SYS_MFP_P36_Msk);
    SYS->P3_MFP |= (SYS_MFP_P36_CKO | SYS_MFP_P36_CKO);
}
*/

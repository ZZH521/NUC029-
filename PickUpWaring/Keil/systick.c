/***********************************************
Copyright:Elite
FileName:系统时钟SysTick延时程序
Author:z
Version:1.0
Date:2018.5.16
Description:定时器延时程序
Function List:
History:
使用流程：滴答时钟初始化SysTick_Init() -> 设定延时时间SysTickDelayMs(int ms)
****************************************************/

#include "systick.h"
#include "NUC029xAN.h"
#include <stdint.h>  
static int SysTickDelay = 0;
void SysTick_Init(void)//初始化内核定时器
{
    NVIC_EnableIRQ(SysTick_IRQn);//使能SysTick中断
    SysTick_Config(50000);  //装载1mS
	  SysTickInterrupt_Disable();  //屏蔽中断
}
void SysTickInterrupt_Enable(void)//开启中断
{
    SysTick->CTRL = SysTick->CTRL | (1<<0);
}

void SysTickInterrupt_Disable(void)//屏蔽中断
{
    SysTick->CTRL = SysTick->CTRL & (~(1<<0));
}

void SysTick_Handler(void)//中断
{
     if(SysTickDelay !=0)
		 {
		     SysTickDelay--;
			   if(SysTickDelay == 0)
			   {
			       SysTickInterrupt_Disable();//屏蔽中断
			   }
		 }			 
}

int SysTick_GetIntFlag(void)//获取系统定时器状态
{
	  return(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk ? 1:0);
}

void SysTick_ClearIntFlag(void)//清空标志位
{
    SysTick->CTRL = SysTick->CTRL | SysTick_CTRL_COUNTFLAG_Msk;
}

void SysTickDelayMs(int ms)
{
	  SysTickDelay = ms;
    SysTickInterrupt_Enable();//开启中断
	  while(SysTickDelay != 0){}
    SysTickInterrupt_Disable();//屏蔽中断
}
/*
void SYS_CKO_Init(void)//设置3.6脚为时钟输出脚,验证时钟准确性
{
	  CLK_EnableCKO(CLK_CLKSEL2_FRQDIV_S_HXT,0,0);
    SYS->P3_MFP &= ~(SYS_MFP_P36_Msk | SYS_MFP_P36_Msk);
    SYS->P3_MFP |= (SYS_MFP_P36_CKO | SYS_MFP_P36_CKO);
}
*/

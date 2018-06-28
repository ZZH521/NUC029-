#ifndef __MAIN_H__
#define __MAIN_H__
#include "NUC029xAN.h"
#include <stdio.h>
#include "NUC029xAN.h"
#include "detect.h"
#include "BR262_Driver.h"
#include "I2C.h"
#include "systick.h"
#include "delay.h"
#include "buzzer.h"
#include "adc_driver.h"
#include "wdt_driver.h"
#include "485_driver.h"


#define PLL_CLOCK           50000000
static void CORE_Clock_Init(void)//内核初始化
{
    CLK_EnableXtalRC(CLK_PWRCON_XTL12M_EN_Msk);//使能外部12M晶振
    CLK_WaitClockReady(CLK_CLKSTATUS_XTL12M_STB_Msk);//等待晶振准备完成
	  //CLK_EnableXtalRC(CLK_PWRCON_OSC22M_EN_Msk);//使能内部22M晶振
    //CLK_WaitClockReady(CLK_CLKSTATUS_OSC22M_STB_Msk);//等待晶振准备完成
    CLK_SetCoreClock(PLL_CLOCK);//设置系统时钟来源于PLL
}

static void SYS_Init(void)//时钟初始化
{ 
	  SYS_UnlockReg();//解锁写保护
	
	  CORE_Clock_Init();
	  WDT_Clock_Init();//看门狗时钟初始化  
	  ADC_Clock_Init();//ADC时钟初始化
	  U485_Clock_Init();//串口时钟
    
    SYS_LockReg();//写保护
}

#endif


/**************************************************
Copyright:Elite
FileName: 看门狗程序
Author:z
Version:1.0
Date:2018.5.24
Description:s、ms、us软件延时程序
Function List:
History:
*********************************************************/
#include "wdt_driver.h"
#include "NUC029xAN.h"

void WDT_Clock_Init(void)//看门狗时钟初始化
{
    CLK->APBCLK = CLK_APBCLK_UART0_EN_Msk | CLK_APBCLK_WDT_EN_Msk;//使能看门狗
	  CLK->CLKSEL1 = CLK_CLKSEL1_UART_S_PLL | CLK_CLKSEL1_WDT_S_LIRC;//选择10K内部晶振作为看门狗时钟
}

void WDT_Load_Value(void)//装载计数值
{//复位时间2^14 /10K  = 1.6S
	  SYS_UnlockReg();    //解锁寄存器读保护 
    WDT_Open(WDT_TIMEOUT_2POW14, WDT_RESET_DELAY_1026CLK, TRUE, FALSE);//设置看门狗定时器溢出周期、看门狗定时器复位延时时间、使能系统复位功能、不使能系统唤醒功能
    SYS_LockReg();		
}

void WDT_Reset_Count(void)//喂狗
{
			SYS_UnlockReg();    //解锁寄存器读保护 
			WDT_RESET_COUNTER();//重装计数值 
      SYS_LockReg();		
}

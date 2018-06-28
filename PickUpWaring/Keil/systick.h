#ifndef __SYSTICK_H__
#define __SYSTICK_H__

int SysTick_GetIntFlag(void);   //获取系统定时器状态
void SysTick_ClearIntFlag(void);//清空标志位
void SysTick_Init(void);     //初始化内核定时器
void SysTickInterrupt_Disable(void);//屏蔽中断
void SysTickInterrupt_Enable(void); //开启中断
void SysTickDelayMs(int ms);//延时
#endif

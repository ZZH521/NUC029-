#ifndef __WDT_DRIVER_H__
#define __WDT_DRIVER_H__

void WDT_Clock_Init(void);//看门狗时钟初始化
void WDT_Load_Value(void);//装载计数值
void WDT_Reset_Count(void);//喂狗

#endif

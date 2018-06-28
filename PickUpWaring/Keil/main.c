/**************************************************
Copyright:Elite
FileName: 主程序，初始化262芯片，检测芯片和咪头状态
Author:z
Version:1.0
Date:2018.5.24
Description:main.h包含main函数需要的所有头文件
Function List:
History:
*********************************************************/
#include "main.h"

int main(void)
{   uint8_t a[5] = {0x01,0x02,0x03,0x04,0x05};
    SYS_Init();//时钟初始化
	  Buzzer_Gpio_Init();//蜂鸣器IO初始化
	  ADC_Init();//选择ADC通道、配置ADC转化模式
	  U485_Init();//选择串口、波特率
    U485EN_Gpio_Init();//485使能脚初始化
    IIC_IOinit();
    Init_BR262();//初始化262
//	  WDT_Load_Value();//装载看门狗定时器初值	 
		SysTick_Init();
	  
    U485rec_Interrupt_Enable();//开启串口接收中断

    /*测试*/		
		while(1)
		{			
        P11 = 1;	
        U485SendData(UART1, a, 5);		
			  //UART_Write(UART1, a, 5);
			  P11 = 0;
			  U485SendData(UART1, a, 5);		
	      WDT_Reset_Count();//喂狗
			  delayms(500);
		    P36 = ~P36;			  
		}
	
		while(1)
    {
			  WDT_Reset_Count();//喂狗
        Process();
    }
}
		

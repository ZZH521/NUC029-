/***********************************************
Copyright:Elite
FileName:系统时钟SysTick延时程序
Author:z
Version:1.0
Date:2018.5.24
Description:
Function List:
History:
****************************************************/

#include "buzzer.h"
#include "delay.h"
#include "NUC029xAN.h"
#include "detect.h"
#include "ADC_Driver.h"
int ADC_Data = 0;//存放AD转换的数值
int ADC_Data0_count = 0;//记录连续得到转换值为0的次数
int MIC_Status = 1;//咪头状态默认1为正常状态
int light_flag = 0;//闪灯标志位,默认不闪烁（咪头、262都正常）
int count = 0;//

void Buzzer_Gpio_Init(void)
{
    GPIO_SetMode(P2, BIT6, GPIO_PMD_OUTPUT);//P2.6推挽输出模式，作为蜂鸣器控制口使用
    GPIO_SetMode(P3, BIT6, GPIO_PMD_OUTPUT);//p3.6推挽输出模式，作为led控制口使用
	  P26 = 0;//默认蜂鸣器关闭
	  P36 = 0;//默认led不亮
}

void Process(void)
{
    delayms(12);
	  BR262_detect();// 检测262状态      
		ADC_Data = ADC_Sample();
		if(ADC_Data==0)
		{
				ADC_Data0_count++;
				if(ADC_Data0_count==10)//连续10次AD转换值为0
				{
						MIC_Status = 0;//0代表咪头损坏
				}
		}
		else
		{
				MIC_Status = 1;//1代表咪头正常
				ADC_Data0_count = 0;
		}

		if((g_input == 0)||(MIC_Status == 0))//262能量值为0或咪头AD值为0
		{
				P26 = 1;//启动蜂鸣器
				light_flag = 1;
		}
		else
		{
				P26 = 0;//
				light_flag = 0;
		}
        
		if(light_flag)
		{
			  count++;
			  if(count == 150000)
				{
					  count = 0;
				    P36 = ~P36;//led闪烁
				}				
		}
		else
		{
				P36 = 0;
		}
}


/***********************************************
Copyright:Elite
FileName:ADC驱动
Author:z
Version:1.0
Date:2018.5.24
Description:
Function List:
History:
****************************************************/
#include "adc_driver.h"
#include "NUC029xAN.h"

void ADC_Clock_Init(void)//ADC时钟初始化
{
    CLK_EnableModuleClock(ADC_MODULE);//使能ADC时钟    
    CLK_SetModuleClock(ADC_MODULE, CLK_CLKSEL1_ADC_S_HXT, CLK_CLKDIV_ADC(4));//使用外部晶振12M分频
}

void ADC_Init(void)//选择ADC通道、配置ADC转化模式
{	  
	
	  P1->OFFD &= ~(BIT0<<16);  //P1.0作为模拟输入，应关闭数字通道防止漏电流
	  P1->OFFD |=  (BIT0<<16);  
	
    SYS->P1_MFP &= ~(SYS_MFP_P10_Msk );//P1.0作为模拟输入脚
    SYS->P1_MFP |=   SYS_MFP_P10_AIN0 ;
	  
    ADC_Open(ADC, ADC_ADCR_DIFFEN_SINGLE_END, ADC_ADCR_ADMD_SINGLE_CYCLE, 0x1<<0);//adc.单端信号。单周期扫描模式。使能P1.0
    ADC_POWER_ON(ADC);//使能AD转换器
    ADC_CLR_INT_FLAG(ADC, ADC_ADF_INT);//清除AD转化完成标志位   
}

int ADC_Sample(void)//AD转换
{
    int data; 
    ADC_START_CONV(ADC);//开始转化
    while(!ADC_GET_INT_FLAG(ADC, ADC_ADF_INT));//等待转化完成
	  ADC_CLR_INT_FLAG(ADC, ADC_ADF_INT);//清除AD转化完成标志位	
    data = ADC_GET_CONVERSION_DATA(ADC, 0);
    return data;
}



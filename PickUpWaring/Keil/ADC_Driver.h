#ifndef __ADC_DRIVER_H__
#define __ADC_DRIVER_H__

void ADC_Clock_Init(void);//ADC时钟初始化
void ADC_Init(void);//选择ADC通道、配置ADC转化模式
int ADC_Sample(void);//AD转换

#endif


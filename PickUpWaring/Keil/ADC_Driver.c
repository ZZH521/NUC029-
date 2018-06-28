/***********************************************
Copyright:Elite
FileName:ADC����
Author:z
Version:1.0
Date:2018.5.24
Description:
Function List:
History:
****************************************************/
#include "adc_driver.h"
#include "NUC029xAN.h"

void ADC_Clock_Init(void)//ADCʱ�ӳ�ʼ��
{
    CLK_EnableModuleClock(ADC_MODULE);//ʹ��ADCʱ��    
    CLK_SetModuleClock(ADC_MODULE, CLK_CLKSEL1_ADC_S_HXT, CLK_CLKDIV_ADC(4));//ʹ���ⲿ����12M��Ƶ
}

void ADC_Init(void)//ѡ��ADCͨ��������ADCת��ģʽ
{	  
	
	  P1->OFFD &= ~(BIT0<<16);  //P1.0��Ϊģ�����룬Ӧ�ر�����ͨ����ֹ©����
	  P1->OFFD |=  (BIT0<<16);  
	
    SYS->P1_MFP &= ~(SYS_MFP_P10_Msk );//P1.0��Ϊģ�������
    SYS->P1_MFP |=   SYS_MFP_P10_AIN0 ;
	  
    ADC_Open(ADC, ADC_ADCR_DIFFEN_SINGLE_END, ADC_ADCR_ADMD_SINGLE_CYCLE, 0x1<<0);//adc.�����źš�������ɨ��ģʽ��ʹ��P1.0
    ADC_POWER_ON(ADC);//ʹ��ADת����
    ADC_CLR_INT_FLAG(ADC, ADC_ADF_INT);//���ADת����ɱ�־λ   
}

int ADC_Sample(void)//ADת��
{
    int data; 
    ADC_START_CONV(ADC);//��ʼת��
    while(!ADC_GET_INT_FLAG(ADC, ADC_ADF_INT));//�ȴ�ת�����
	  ADC_CLR_INT_FLAG(ADC, ADC_ADF_INT);//���ADת����ɱ�־λ	
    data = ADC_GET_CONVERSION_DATA(ADC, 0);
    return data;
}



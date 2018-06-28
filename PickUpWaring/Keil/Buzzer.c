/***********************************************
Copyright:Elite
FileName:ϵͳʱ��SysTick��ʱ����
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
int ADC_Data = 0;//���ADת������ֵ
int ADC_Data0_count = 0;//��¼�����õ�ת��ֵΪ0�Ĵ���
int MIC_Status = 1;//��ͷ״̬Ĭ��1Ϊ����״̬
int light_flag = 0;//���Ʊ�־λ,Ĭ�ϲ���˸����ͷ��262��������
int count = 0;//

void Buzzer_Gpio_Init(void)
{
    GPIO_SetMode(P2, BIT6, GPIO_PMD_OUTPUT);//P2.6�������ģʽ����Ϊ���������ƿ�ʹ��
    GPIO_SetMode(P3, BIT6, GPIO_PMD_OUTPUT);//p3.6�������ģʽ����Ϊled���ƿ�ʹ��
	  P26 = 0;//Ĭ�Ϸ������ر�
	  P36 = 0;//Ĭ��led����
}

void Process(void)
{
    delayms(12);
	  BR262_detect();// ���262״̬      
		ADC_Data = ADC_Sample();
		if(ADC_Data==0)
		{
				ADC_Data0_count++;
				if(ADC_Data0_count==10)//����10��ADת��ֵΪ0
				{
						MIC_Status = 0;//0������ͷ��
				}
		}
		else
		{
				MIC_Status = 1;//1������ͷ����
				ADC_Data0_count = 0;
		}

		if((g_input == 0)||(MIC_Status == 0))//262����ֵΪ0����ͷADֵΪ0
		{
				P26 = 1;//����������
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
				    P36 = ~P36;//led��˸
				}				
		}
		else
		{
				P36 = 0;
		}
}


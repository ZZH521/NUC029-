/**************************************************
Copyright:Elite
FileName: �����򣬳�ʼ��262оƬ�����оƬ����ͷ״̬
Author:z
Version:1.0
Date:2018.5.24
Description:main.h����main������Ҫ������ͷ�ļ�
Function List:
History:
*********************************************************/
#include "main.h"

int main(void)
{   uint8_t a[5] = {0x01,0x02,0x03,0x04,0x05};
    SYS_Init();//ʱ�ӳ�ʼ��
	  Buzzer_Gpio_Init();//������IO��ʼ��
	  ADC_Init();//ѡ��ADCͨ��������ADCת��ģʽ
	  U485_Init();//ѡ�񴮿ڡ�������
    U485EN_Gpio_Init();//485ʹ�ܽų�ʼ��
    IIC_IOinit();
    Init_BR262();//��ʼ��262
//	  WDT_Load_Value();//װ�ؿ��Ź���ʱ����ֵ	 
		SysTick_Init();
	  
    U485rec_Interrupt_Enable();//�������ڽ����ж�

    /*����*/		
		while(1)
		{			
        P11 = 1;	
        U485SendData(UART1, a, 5);		
			  //UART_Write(UART1, a, 5);
			  P11 = 0;
			  U485SendData(UART1, a, 5);		
	      WDT_Reset_Count();//ι��
			  delayms(500);
		    P36 = ~P36;			  
		}
	
		while(1)
    {
			  WDT_Reset_Count();//ι��
        Process();
    }
}
		

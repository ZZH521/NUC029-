/**************************************************
Copyright:Elite
FileName: ���Ź�����
Author:z
Version:1.0
Date:2018.5.24
Description:s��ms��us�����ʱ����
Function List:
History:
*********************************************************/
#include "wdt_driver.h"
#include "NUC029xAN.h"

void WDT_Clock_Init(void)//���Ź�ʱ�ӳ�ʼ��
{
    CLK->APBCLK = CLK_APBCLK_UART0_EN_Msk | CLK_APBCLK_WDT_EN_Msk;//ʹ�ܿ��Ź�
	  CLK->CLKSEL1 = CLK_CLKSEL1_UART_S_PLL | CLK_CLKSEL1_WDT_S_LIRC;//ѡ��10K�ڲ�������Ϊ���Ź�ʱ��
}

void WDT_Load_Value(void)//װ�ؼ���ֵ
{//��λʱ��2^14 /10K  = 1.6S
	  SYS_UnlockReg();    //�����Ĵ��������� 
    WDT_Open(WDT_TIMEOUT_2POW14, WDT_RESET_DELAY_1026CLK, TRUE, FALSE);//���ÿ��Ź���ʱ��������ڡ����Ź���ʱ����λ��ʱʱ�䡢ʹ��ϵͳ��λ���ܡ���ʹ��ϵͳ���ѹ���
    SYS_LockReg();		
}

void WDT_Reset_Count(void)//ι��
{
			SYS_UnlockReg();    //�����Ĵ��������� 
			WDT_RESET_COUNTER();//��װ����ֵ 
      SYS_LockReg();		
}

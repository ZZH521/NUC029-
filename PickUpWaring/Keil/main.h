#ifndef __MAIN_H__
#define __MAIN_H__
#include "NUC029xAN.h"
#include <stdio.h>
#include "NUC029xAN.h"
#include "detect.h"
#include "BR262_Driver.h"
#include "I2C.h"
#include "systick.h"
#include "delay.h"
#include "buzzer.h"
#include "adc_driver.h"
#include "wdt_driver.h"
#include "485_driver.h"


#define PLL_CLOCK           50000000
static void CORE_Clock_Init(void)//�ں˳�ʼ��
{
    CLK_EnableXtalRC(CLK_PWRCON_XTL12M_EN_Msk);//ʹ���ⲿ12M����
    CLK_WaitClockReady(CLK_CLKSTATUS_XTL12M_STB_Msk);//�ȴ�����׼�����
	  //CLK_EnableXtalRC(CLK_PWRCON_OSC22M_EN_Msk);//ʹ���ڲ�22M����
    //CLK_WaitClockReady(CLK_CLKSTATUS_OSC22M_STB_Msk);//�ȴ�����׼�����
    CLK_SetCoreClock(PLL_CLOCK);//����ϵͳʱ����Դ��PLL
}

static void SYS_Init(void)//ʱ�ӳ�ʼ��
{ 
	  SYS_UnlockReg();//����д����
	
	  CORE_Clock_Init();
	  WDT_Clock_Init();//���Ź�ʱ�ӳ�ʼ��  
	  ADC_Clock_Init();//ADCʱ�ӳ�ʼ��
	  U485_Clock_Init();//����ʱ��
    
    SYS_LockReg();//д����
}

#endif


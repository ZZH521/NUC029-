/***********************************************
Copyright:Elite
FileName:485����
Author:z
Version:1.0
Date:2018.6.13
Description:485��������
Function List:
History:
****************************************************/
#include "485_driver.h"
#include "NUC029xAN.h"
#define  recLength 50  //�����������
uint8_t b[5] = {11,22,33,44,55};//���Է���
uint8_t RecBuffer[recLength] ;//���Խ���
void U485_Clock_Init(void)//485ʱ�ӳ�ʼ��
{
    CLK_EnableModuleClock(UART1_MODULE);//ʹ�ܴ�UART1
    CLK_SetModuleClock(UART1_MODULE, CLK_CLKSEL1_UART_S_HXT, CLK_CLKDIV_UART(1));//ѡ�񴮿�ʱ��(12m)
}

void U485_Init(void)//ѡ�񴮿ڡ�������
{
    SYS->P1_MFP &= ~(SYS_MFP_P12_Msk | SYS_MFP_P13_Msk);//p30��p31��Ϊ��������ʹ��
    SYS->P1_MFP |= (SYS_MFP_P12_RXD1 | SYS_MFP_P13_TXD1);//p30 rxd p31 txd

    SYS_ResetModule(UART1_RST);//��λ����
    UART_Open(UART1, 115200);//ѡ������
}

void UART1_IRQHandler(void)//�����ж�
{
    int i = 0;
    while(!UART_GET_INT_FLAG(UART1,UART_ISR_RDA_INT_Msk));//Ϊ0�ж�δ������Ϊ1�жϷ���
//		while(UART_IS_RX_READY(UART1))//�������з��͹���������
//		{
//			 RecBuffer[i] = UART_READ(UART1);//��λ�Ĵ�����ȡ���������жϱ�־λ
//			 i++;
//		}
		U485RecData(UART1,RecBuffer,recLength);
		P11 = 1;
		UART_Write(UART1, b, 5);
}

void U485rec_Interrupt_Enable(void)//�����ж�
{
	  UART_ENABLE_INT(UART1, UART_IER_RDA_IEN_Msk);
    NVIC_EnableIRQ(UART1_IRQn);//����uart1�ж�
}

void U485rec_Interrupt_Disable(void)//�����ж�
{
	  UART_DISABLE_INT(UART1, UART_IER_RDA_IEN_Msk );
    NVIC_DisableIRQ(UART1_IRQn);//�ر�uart1�ж�
}

void U485EN_Gpio_Init(void)//485ʹ�ܽų�ʼ��
{
    GPIO_SetMode(P1, BIT1, GPIO_PMD_OUTPUT);//P1.1�������ģʽ����Ϊ485ʹ�ܽ�
	  P11 = 0;//Ĭ�Ͻ���ģʽ
}

void U485SendData(UART_T* uart, uint8_t *pu8TxBuf, uint32_t u32WriteBytes)//��������
{
	  P11 = 1;//ʹ��485��Ϊ���Ͷ˿�
    UART_Write(uart, pu8TxBuf, u32WriteBytes);//�����ڲ���װ��ÿ���ֽڷ�����ɵ��ж�
	  P11 = 0;//�������485���óɽ���ģʽ
}

void U485RecData(UART_T* uart, uint8_t *pu8RxBuf, uint32_t u32ReadBytes)//��������
{
    P11 = 0;//�������485���óɽ���ģʽ
    UART_Read(uart, pu8RxBuf, u32ReadBytes);//�����ڲ���װ�˽���Ϊ�յ��ж�
	  // P11 = 1;//�������485���óɽ���ģʽ
}



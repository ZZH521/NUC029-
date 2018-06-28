#ifndef __485_DRIVER_H__
#define __485_DRIVER_H__
#include "NUC029xAN.h"

void U485_Clock_Init(void);//485ʱ�ӳ�ʼ��
void U485_Init(void);//ѡ�񴮿ڡ�������
void UART0_IRQHandler(void);//�����ж�
void U485rec_Interrupt_Enable(void);//�����ж�
void U485rec_Interrupt_Disable(void);//�����ж�
void U485EN_Gpio_Init(void);//485ʹ�ܽų�ʼ��
void U485SendData(UART_T* uart, uint8_t *pu8TxBuf, uint32_t u32WriteBytes);//��������
void U485RecData(UART_T* uart, uint8_t *pu8RxBuf, uint32_t u32ReadBytes);//��������

#endif

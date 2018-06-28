#ifndef __485_DRIVER_H__
#define __485_DRIVER_H__
#include "NUC029xAN.h"

void U485_Clock_Init(void);//485时钟初始化
void U485_Init(void);//选择串口、波特率
void UART0_IRQHandler(void);//串口中断
void U485rec_Interrupt_Enable(void);//开启中断
void U485rec_Interrupt_Disable(void);//屏蔽中断
void U485EN_Gpio_Init(void);//485使能脚初始化
void U485SendData(UART_T* uart, uint8_t *pu8TxBuf, uint32_t u32WriteBytes);//发送数据
void U485RecData(UART_T* uart, uint8_t *pu8RxBuf, uint32_t u32ReadBytes);//接收数据

#endif

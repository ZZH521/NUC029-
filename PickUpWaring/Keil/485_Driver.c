/***********************************************
Copyright:Elite
FileName:485驱动
Author:z
Version:1.0
Date:2018.6.13
Description:485驱动程序
Function List:
History:
****************************************************/
#include "485_driver.h"
#include "NUC029xAN.h"
#define  recLength 50  //定义接收数组
uint8_t b[5] = {11,22,33,44,55};//测试发送
uint8_t RecBuffer[recLength] ;//测试接收
void U485_Clock_Init(void)//485时钟初始化
{
    CLK_EnableModuleClock(UART1_MODULE);//使能串UART1
    CLK_SetModuleClock(UART1_MODULE, CLK_CLKSEL1_UART_S_HXT, CLK_CLKDIV_UART(1));//选择串口时钟(12m)
}

void U485_Init(void)//选择串口、波特率
{
    SYS->P1_MFP &= ~(SYS_MFP_P12_Msk | SYS_MFP_P13_Msk);//p30、p31作为串口引脚使用
    SYS->P1_MFP |= (SYS_MFP_P12_RXD1 | SYS_MFP_P13_TXD1);//p30 rxd p31 txd

    SYS_ResetModule(UART1_RST);//复位串口
    UART_Open(UART1, 115200);//选择波特率
}

void UART1_IRQHandler(void)//串口中断
{
    int i = 0;
    while(!UART_GET_INT_FLAG(UART1,UART_ISR_RDA_INT_Msk));//为0中断未发生，为1中断发生
//		while(UART_IS_RX_READY(UART1))//接收所有发送过来的数据
//		{
//			 RecBuffer[i] = UART_READ(UART1);//移位寄存器读取数据清零中断标志位
//			 i++;
//		}
		U485RecData(UART1,RecBuffer,recLength);
		P11 = 1;
		UART_Write(UART1, b, 5);
}

void U485rec_Interrupt_Enable(void)//开启中断
{
	  UART_ENABLE_INT(UART1, UART_IER_RDA_IEN_Msk);
    NVIC_EnableIRQ(UART1_IRQn);//开启uart1中断
}

void U485rec_Interrupt_Disable(void)//屏蔽中断
{
	  UART_DISABLE_INT(UART1, UART_IER_RDA_IEN_Msk );
    NVIC_DisableIRQ(UART1_IRQn);//关闭uart1中断
}

void U485EN_Gpio_Init(void)//485使能脚初始化
{
    GPIO_SetMode(P1, BIT1, GPIO_PMD_OUTPUT);//P1.1推挽输出模式，作为485使能脚
	  P11 = 0;//默认接收模式
}

void U485SendData(UART_T* uart, uint8_t *pu8TxBuf, uint32_t u32WriteBytes)//发送数据
{
	  P11 = 1;//使能485作为发送端口
    UART_Write(uart, pu8TxBuf, u32WriteBytes);//函数内部封装了每个字节发送完成的判断
	  P11 = 0;//发送完成485配置成接收模式
}

void U485RecData(UART_T* uart, uint8_t *pu8RxBuf, uint32_t u32ReadBytes)//接收数据
{
    P11 = 0;//发送完成485配置成接收模式
    UART_Read(uart, pu8RxBuf, u32ReadBytes);//函数内部封装了接收为空的判断
	  // P11 = 1;//发送完成485配置成接收模式
}



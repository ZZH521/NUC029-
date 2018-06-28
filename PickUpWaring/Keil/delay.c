/**************************************************
Copyright:Elite
FileName: 延时程序
Author:z
Version:1.0
Date:2018.5.15
Description:s、ms、us软件延时程序
Function List:
History:
*********************************************************/
#include "delay.h"

volatile void delays(int s)
{	
    int i = 0,j = 0;
	  for(j = 0 ; j < s ; j++)
				for(i = 0; i < 1000; i++)
		    {
						int num = 50000/(3*2) - 4;//一条指令分3部进行，每部需要2个时钟周期 1ms = 6x * 1000/内核时钟 4 修正系数
						while(num--);
				}
}

volatile void delayms(int ms)
{
    int i = 0;
		for(i = 0; i < ms; i++)
		{
				int num = 50000/(3*2) - 3;//一条指令分3部进行，每部需要2个时钟周期 1ms = 6x * 1000/内核时钟  3修正系数
				while(num--);
		}
}

volatile void delayus(int us)
{
    int i = 0;
		for(i = 0; i < us; i++)
		{
				int num = 50000/(3*2*1000) - 2;//一条指令分3部进行，每部需要2个时钟周期 1us = 6x * 1000*1000/内核时钟 2修正系数
				while(num--);
		}
}


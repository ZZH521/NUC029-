/**************************************************
Copyright:Elite
FileName: ��ʱ����
Author:z
Version:1.0
Date:2018.5.15
Description:s��ms��us�����ʱ����
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
						int num = 50000/(3*2) - 4;//һ��ָ���3�����У�ÿ����Ҫ2��ʱ������ 1ms = 6x * 1000/�ں�ʱ�� 4 ����ϵ��
						while(num--);
				}
}

volatile void delayms(int ms)
{
    int i = 0;
		for(i = 0; i < ms; i++)
		{
				int num = 50000/(3*2) - 3;//һ��ָ���3�����У�ÿ����Ҫ2��ʱ������ 1ms = 6x * 1000/�ں�ʱ��  3����ϵ��
				while(num--);
		}
}

volatile void delayus(int us)
{
    int i = 0;
		for(i = 0; i < us; i++)
		{
				int num = 50000/(3*2*1000) - 2;//һ��ָ���3�����У�ÿ����Ҫ2��ʱ������ 1us = 6x * 1000*1000/�ں�ʱ�� 2����ϵ��
				while(num--);
		}
}


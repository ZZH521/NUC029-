#ifndef __SYSTICK_H__
#define __SYSTICK_H__

int SysTick_GetIntFlag(void);   //��ȡϵͳ��ʱ��״̬
void SysTick_ClearIntFlag(void);//��ձ�־λ
void SysTick_Init(void);     //��ʼ���ں˶�ʱ��
void SysTickInterrupt_Disable(void);//�����ж�
void SysTickInterrupt_Enable(void); //�����ж�
void SysTickDelayMs(int ms);//��ʱ
#endif

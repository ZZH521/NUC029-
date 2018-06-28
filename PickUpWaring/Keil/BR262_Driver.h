#ifndef _262H
#define _262H

#include <stdio.h>
#include "NUC029xAN.h"
#define BR262_I2C_Addr      0x61  	//BR262��I2C��ַ	


#define RESET_REG                               0x01  	//BR262��������
#define SWITCH_MODE_REG                         0x10  	//ת��BR262�豸ģʽ�Ĵ�����ַ 
#define SET_PREAMPGAIN_REG                      0x2A  	//����ǰ������Ĵ�����ַ 
#define GET_PREAMPGAIN_REG   	                0x2B  	//��ȡǰ������Ĵ�����ַ 
#define SET_MAINVOLUME_REG   	                0x30  	//�����������Ĵ�����ַ 
#define GET_MAINVOLUME_REG   	                0x31  	//��ȡ�������Ĵ�����ַ 
#define SET_PARAM_REG                           0x32  	//���ò����Ĵ�����ַ 
#define GET_PARAM_REG                           0x33  	//��ȡ�����Ĵ�����ַ 
#define NR_OUTPUT                               0x0001  //����Channel0��Channel1��Single��Dualģʽ
#define Channel0_Talk_Mode                      0x0003  //����0ģʽ
#define Channel1_Talk_Mode                      0x0004  //����1ģʽ
#define Mixing_Ratio                            0x0005  //����1������2��ϱ�
#define Mixing_Destination                      0x0006  //��������
#define Channel0_EQ_Gain_Exponent               0x0107  //����0��EQ����ָ��
#define Channel1_EQ_Gain_Exponent               0x0118  //����1��EQ����ָ��
#define Channel0_LongTerm_Energy                0x0132  //����0��������ֵ
#define Channel0_ShortTerm_Energy               0x0133  //����0��������ֵ
#define Channel1_LongTerm_Energy                0x0136  //����1��������ֵ
#define Channel1_ShortTerm_Energy               0x0137  //����1��������ֵ

#define Single_Output    0x00     //���������������CH1
#define Dual_Output      0x01     //˫���������CH0+CH1

#define Far_Talk_Mode    0x00     //Far talking distance (2.5 to 5 m)
#define Close_Talk_Mode  0x01     //Close talking distance (5 to 10 cm)
#define Near_Talk_Mode   0x02     //Near talking distance (50 to 100 cm)

#define Standby_Mode     0x00     //����ģʽ����ģʽ������ģʽ��˯��ģʽ֮���ת�����ɻ��ڣ�ͨ������Ҫ����
#define Deep_sleep_Mode  0x01     //˯��ģʽ���������źŴ���оƬ������ģ��鶼�����ã�����BR262����͹�������ģʽ��
#define Active_Mode      0x02     //����ģʽ�����н����㷨��������õ�ģʽ��
#define Bypass_Mode      0x03     //ֱͨģʽ������ֱ�ӵ�������������źŴ��������Բɼ�������Ƶ��������Ϣ��


extern void Init_BR262(void);
extern void BR262_Reset(void);
extern void Set_Preamp_Gain(uint8_t I2CAdd,uint8_t channelID,uint8_t gain);
extern uint8_t Get_Preamp_Gain(uint8_t I2CAdd);
extern void Set_NR_Output(uint8_t I2CAdd,uint8_t Single_Dual);
extern void Set_Channel0_TalkMode(uint8_t I2CAdd,uint8_t TalkMode);
extern void Set_Channel1_TalkMode(uint8_t I2CAdd,uint8_t TalkMode);
extern void Set_Mixing_Ratio(uint8_t I2CAdd,uint8_t Ratiohigh,uint8_t Ratiolow);
extern void Set_Mixing_Destination(uint8_t I2CAdd,uint8_t destination);
extern void Change_BR262_DeviceMode(uint8_t I2CAdd,uint8_t mode);
extern void Set_Channel0_EQ_Gain_Exponent(uint8_t I2CAdd,uint8_t exponent);
extern void Set_Channel1_EQ_Gain_Exponent(uint8_t I2CAdd,uint8_t exponent);
extern void Get_Channel0_ShortTerm_Energy(uint8_t I2CAdd,uint16_t *data);
extern void Get_Channel0_LongTerm_Energy(uint8_t I2CAdd,uint16_t *data);
extern void Get_Channel1_ShortTerm_Energy(uint8_t I2CAdd,uint16_t *data);
extern void Get_Channel1_LongTerm_Energy(uint8_t I2CAdd,uint16_t *data);
extern void Set_Master_Volume(uint8_t I2CAdd,uint8_t channelID,uint8_t volumehigh,uint8_t volumelow);
extern void Get_Master_Volume(uint8_t I2CAdd,uint16_t *Channel0_volume,uint16_t *Channel1_volume);
extern void Set_NS_Param(uint8_t ns_level);

#endif

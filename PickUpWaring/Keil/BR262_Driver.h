#ifndef _262H
#define _262H

#include <stdio.h>
#include "NUC029xAN.h"
#define BR262_I2C_Addr      0x61  	//BR262的I2C地址	


#define RESET_REG                               0x01  	//BR262参数重置
#define SWITCH_MODE_REG                         0x10  	//转换BR262设备模式寄存器地址 
#define SET_PREAMPGAIN_REG                      0x2A  	//设置前置增益寄存器地址 
#define GET_PREAMPGAIN_REG   	                0x2B  	//获取前置增益寄存器地址 
#define SET_MAINVOLUME_REG   	                0x30  	//设置主音量寄存器地址 
#define GET_MAINVOLUME_REG   	                0x31  	//获取主音量寄存器地址 
#define SET_PARAM_REG                           0x32  	//设置参数寄存器地址 
#define GET_PARAM_REG                           0x33  	//获取参数寄存器地址 
#define NR_OUTPUT                               0x0001  //设置Channel0和Channel1的Single或Dual模式
#define Channel0_Talk_Mode                      0x0003  //输入0模式
#define Channel1_Talk_Mode                      0x0004  //输入1模式
#define Mixing_Ratio                            0x0005  //输入1与输入2混合比
#define Mixing_Destination                      0x0006  //混合输出端
#define Channel0_EQ_Gain_Exponent               0x0107  //输入0的EQ增益指数
#define Channel1_EQ_Gain_Exponent               0x0118  //输入1的EQ增益指数
#define Channel0_LongTerm_Energy                0x0132  //输入0长期能量值
#define Channel0_ShortTerm_Energy               0x0133  //输入0短期能量值
#define Channel1_LongTerm_Energy                0x0136  //输入1长期能量值
#define Channel1_ShortTerm_Energy               0x0137  //输入1短期能量值

#define Single_Output    0x00     //单声道输出，禁用CH1
#define Dual_Output      0x01     //双声道输出，CH0+CH1

#define Far_Talk_Mode    0x00     //Far talking distance (2.5 to 5 m)
#define Close_Talk_Mode  0x01     //Close talking distance (5 to 10 cm)
#define Near_Talk_Mode   0x02     //Near talking distance (50 to 100 cm)

#define Standby_Mode     0x00     //待机模式，该模式是其他模式和睡眠模式之间的转换过渡环节，通常不需要设置
#define Deep_sleep_Mode  0x01     //睡眠模式，不进行信号处理。芯片的所有模拟块都被禁用，这是BR262的最低功率运行模式。
#define Active_Mode      0x02     //工作模式，运行降噪算法，这是最常用的模式。
#define Bypass_Mode      0x03     //直通模式，输入直接到输出，不进行信号处理，但可以采集输入音频的数据信息。


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

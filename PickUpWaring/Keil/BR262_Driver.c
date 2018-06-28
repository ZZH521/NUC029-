
#include "BR262_Driver.h"
#include "I2C.h"


uint8_t temp;
uint16_t channel0_volume,channel1_volume;

void Init_BR262(void)
{
    //Set_NS_Param(24);
    //Set_Channel0_TalkMode(BR262_I2C_Addr,Far_Talk_Mode);
    //Set_Channel0_TalkMode(BR262_I2C_Addr,Near_Talk_Mode);
    //Set_Channel0_TalkMode(BR262_I2C_Addr,Close_Talk_Mode);
    Set_Channel0_TalkMode(BR262_I2C_Addr,Close_Talk_Mode);
    Set_Channel1_TalkMode(BR262_I2C_Addr,Near_Talk_Mode);
    //Get_Master_Volume(BR262_I2C_Addr,&channel0_volume,&channel1_volume);
    //Set_Master_Volume(BR262_I2C_Addr,0x00,0x7f,0xff);
    //Set_Master_Volume(BR262_I2C_Addr,0x01,0x7f,0xff);
    
    
    //Channel0 EQ
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x08,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x09,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x0A,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x0B,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x0C,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x0D,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x0E,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x0F,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x10,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x11,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x12,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x13,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x14,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x15,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x16,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x17,0x7f,0xff);
    
    //Channel1 EQ
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x19,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x1A,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x1B,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x1C,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x1D,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x1E,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x1F,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x20,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x21,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x22,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x23,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x24,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x25,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x26,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x27,0x7f,0xff);
    I2C0SlaveRegWrite_4Byte(BR262_I2C_Addr,SET_PARAM_REG,0x01,0x28,0x7f,0xff);
    
    Set_Mixing_Destination(BR262_I2C_Addr,0x01);
    //Set_Mixing_Ratio(BR262_I2C_Addr,0x00,0x00);//总0x8000=32768，,0%为0x0000
    //Set_Mixing_Ratio(BR262_I2C_Addr,0x66,0x48);//总0x8000=32768，,80%为0x6648
    Set_Mixing_Ratio(BR262_I2C_Addr,0x73,0x33);//总0x8000=32768，,90%为0x7333
    //Set_Mixing_Ratio(BR262_I2C_Addr,0x79,0x99);//总0x8000=32768，,95%为0x7999
    //Set_Mixing_Ratio(BR262_I2C_Addr,0x7E,0xB8);//总0x8000=32768，,99%为0x7EB8
    //Set_Mixing_Ratio(BR262_I2C_Addr,0x40,0x00);//总0x8000=32768，,50%为0x4000
    //Set_Mixing_Ratio(BR262_I2C_Addr,0x7F,0xFF);//总0x8000=32768，,100%为0x7FFF

    Set_Channel0_EQ_Gain_Exponent(BR262_I2C_Addr,0x02);
    Set_Channel1_EQ_Gain_Exponent(BR262_I2C_Addr,0x02);
    Set_Preamp_Gain(BR262_I2C_Addr,0x00,0x05);
    Set_Preamp_Gain(BR262_I2C_Addr,0x01,0x05);
    
    Change_BR262_DeviceMode(BR262_I2C_Addr,Active_Mode);
    
    //BR262_Reset();

    //Set_NR_Output(BR262_I2C_Addr,Single_Output);
}

void BR262_Reset(void)
{
	I2C0SlaveRegWrite_WithoutData(BR262_I2C_Addr,RESET_REG);
}

void Set_Preamp_Gain(uint8_t I2CAdd,uint8_t channelID,uint8_t gain)
{
	I2C0SlaveRegWrite_2Byte(I2CAdd,SET_PREAMPGAIN_REG,channelID, gain);
}

uint8_t Get_Preamp_Gain(uint8_t I2CAdd)//高4位代表Channel1，低4位代表Channel0
{
        uint8_t gain;
        gain = I2C0SlaveRegRead(I2CAdd,GET_PREAMPGAIN_REG);
        return gain;
}

void Set_NR_Output(uint8_t I2CAdd,uint8_t Single_Dual)
{
	I2C0SlaveRegWrite_4Byte(I2CAdd, SET_PARAM_REG, 0x00,(uint8_t)(NR_OUTPUT&0x00FF),0x00, Single_Dual);
}

void Set_Channel0_TalkMode(uint8_t I2CAdd,uint8_t TalkMode)
{
	I2C0SlaveRegWrite_4Byte(I2CAdd, SET_PARAM_REG,0x00, (uint8_t)(Channel0_Talk_Mode&0x00FF),0x00, TalkMode);
}

void Set_Channel1_TalkMode(uint8_t I2CAdd,uint8_t TalkMode)
{
	I2C0SlaveRegWrite_4Byte(I2CAdd, SET_PARAM_REG,0x00, (uint8_t)(Channel1_Talk_Mode&0x00FF),0x00, TalkMode);
}

void Set_Mixing_Ratio(uint8_t I2CAdd,uint8_t Ratiohigh,uint8_t Ratiolow)
{
	I2C0SlaveRegWrite_4Byte(I2CAdd, SET_PARAM_REG,0x00, (uint8_t)(Mixing_Ratio&0x00FF),Ratiohigh, Ratiolow);
}

void Set_Mixing_Destination(uint8_t I2CAdd,uint8_t destination)
{
	I2C0SlaveRegWrite_4Byte(I2CAdd, SET_PARAM_REG,0x00, (uint8_t)(Mixing_Destination&0x00FF),0x00, destination);
}

void Change_BR262_DeviceMode(uint8_t I2CAdd,uint8_t mode)
{
	I2C0SlaveRegWrite(I2CAdd,SWITCH_MODE_REG,mode);
}

void Set_Channel0_EQ_Gain_Exponent(uint8_t I2CAdd,uint8_t exponent)
{
	I2C0SlaveRegWrite_4Byte(I2CAdd, SET_PARAM_REG,0x00, (uint8_t)(Channel0_EQ_Gain_Exponent&0x00FF),0x00, exponent);
}

void Set_Channel1_EQ_Gain_Exponent(uint8_t I2CAdd,uint8_t exponent)
{
	I2C0SlaveRegWrite_4Byte(I2CAdd, SET_PARAM_REG,0x00, (uint8_t)(Channel1_EQ_Gain_Exponent&0x00FF),0x00, exponent);
}

void Get_Channel0_ShortTerm_Energy(uint8_t I2CAdd,uint16_t *data)
{
        I2C0SlaveRegRead_2Byte(I2CAdd, GET_PARAM_REG,(Channel0_ShortTerm_Energy&0xFF00)>>8,(uint8_t)(Channel0_ShortTerm_Energy&0x00FF),data);
}

void Get_Channel0_LongTerm_Energy(uint8_t I2CAdd,uint16_t *data)
{
	I2C0SlaveRegRead_2Byte(I2CAdd, GET_PARAM_REG,(Channel0_LongTerm_Energy&0xFF00)>>8,(uint8_t)(Channel0_LongTerm_Energy&0x00FF),data);
}

void Get_Channel1_ShortTerm_Energy(uint8_t I2CAdd,uint16_t *data)
{
        I2C0SlaveRegRead_2Byte(I2CAdd, GET_PARAM_REG,(Channel1_ShortTerm_Energy&0xFF00)>>8,(uint8_t)(Channel1_ShortTerm_Energy&0x00FF),data);
}

void Get_Channel1_LongTerm_Energy(uint8_t I2CAdd,uint16_t *data)
{
        I2C0SlaveRegRead_2Byte(I2CAdd, GET_PARAM_REG,(Channel1_ShortTerm_Energy&0xFF00)>>8,(uint8_t)(Channel1_ShortTerm_Energy&0x00FF),data);
}

void Set_Master_Volume(uint8_t I2CAdd,uint8_t channelID,uint8_t volumehigh,uint8_t volumelow)
{
        I2C0SlaveRegWrite_3Byte(I2CAdd,SET_MAINVOLUME_REG,channelID,volumehigh,volumelow);
}

void Get_Master_Volume(uint8_t I2CAdd,uint16_t *Channel0_volume,uint16_t *Channel1_volume)
{
        uint8_t master_volume[4];
        I2C0SlaveRegReadMany(I2CAdd,GET_MAINVOLUME_REG,master_volume,4);
        *Channel0_volume = (((uint16_t)(master_volume[0]))<<8) + (uint16_t)master_volume[1];
        *Channel1_volume = (((uint16_t)(master_volume[2]))<<8) + (uint16_t)master_volume[3];
}

void Set_NS_Param(uint8_t ns_level)
{
	uint8_t ns_level_temph = 0;
	uint8_t ns_level_templ = 0;
	uint8_t ns_gain_one = 0;
	uint8_t ns_gain_two = 0;
	uint8_t channel0_talkmode = 0;
	uint8_t channel1_talkmode = 0;
	if(ns_level < 7)
	{
		ns_gain_one = 7;
		ns_gain_two = 6;
		ns_level_temph = (uint16_t)(75-ns_level*5)*436 / 256;
		ns_level_templ = (uint16_t)(75-ns_level*5)*436 % 256;
		channel0_talkmode = 0x00;
		channel1_talkmode = 0x00;
	}
	else if(ns_level < 14)
	{
		ns_gain_one = 7;
		ns_gain_two = 6;
		ns_level_temph = (uint16_t)(75-(ns_level-7)*5)*436 / 256;
		ns_level_templ = (uint16_t)(75-(ns_level-7)*5)*436 % 256;
		channel0_talkmode = 0x02;
		channel1_talkmode = 0x00;
	}
	else if(ns_level <21)
	{
		ns_gain_one = 5;
		ns_gain_two = 6;
		ns_level_temph = (uint16_t)(75-(ns_level-14)*5)*436 / 256;
		ns_level_templ = (uint16_t)(75-(ns_level-14)*5)*436 % 256;
		channel0_talkmode = 0x02;
		channel1_talkmode = 0x02;
	}
	else if(ns_level <25)
	{
		ns_gain_one = 7;
		ns_gain_two = 7;
		ns_level_temph = (uint16_t)(75-(ns_level-21)*5)*436 / 256;
		ns_level_templ = (uint16_t)(75-(ns_level-21)*5)*436 % 256;
		channel0_talkmode = 0x01;
		channel1_talkmode = 0x02;
	}
	else return;
        Set_Preamp_Gain(BR262_I2C_Addr,0x00,ns_gain_one);
        Set_Preamp_Gain(BR262_I2C_Addr,0x01,ns_gain_two);
        Set_Channel0_TalkMode(BR262_I2C_Addr,channel0_talkmode);
        Set_Channel1_TalkMode(BR262_I2C_Addr,channel1_talkmode);
        Set_Mixing_Destination(BR262_I2C_Addr,0x01);
        Set_Mixing_Ratio(BR262_I2C_Addr,ns_level_temph,ns_level_templ);
        Set_Channel0_EQ_Gain_Exponent(BR262_I2C_Addr,0x02);
        Set_Channel1_EQ_Gain_Exponent(BR262_I2C_Addr,0x02);
        Change_BR262_DeviceMode(BR262_I2C_Addr,Active_Mode);
}

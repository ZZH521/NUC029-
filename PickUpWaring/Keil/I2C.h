#ifndef _IICH
#define _IICH

#include <stdio.h>
#include "NUC029xAN.h"


#define SCL_HIGH    P35 = 1;
#define SCL_LOW     P35 = 0;

#define SDA0_HIGH    	P34 = 1;
#define SDA0_LOW    	P34 = 0;
#define READ_SDA0     	P34


extern void delay(volatile uint32_t delay);
extern void delay_ms(uint16_t ms);
extern void IIC_IOinit(void);
extern void SDA_OUTPUT(void);
extern void SDA_INPUT(void);
extern void SDA_LOW(void);
extern void SDA_HIGH(void);
extern uint8_t READ_SDA(void);
extern void IIC_Start(void);
extern void IIC_Stop(void);
extern uint8_t IIC_Wait_Ack(void);
extern void IIC_Ack(void);
extern void IIC_NAck(void);
extern void IIC_Write_Byte(uint8_t data);
extern uint8_t IIC_Read_Byte(uint8_t ack);
extern uint8_t I2C0SlaveRegWrite(uint8_t i2c_addr,uint8_t regAddr,uint8_t regData);
extern uint8_t I2C0SlaveRegWrite_WithoutData(uint8_t i2c_addr,uint8_t regAddr);
extern uint8_t I2C0SlaveRegWrite_2Byte(uint8_t i2c_addr,uint8_t regAddr,uint8_t channel,uint8_t regData);
extern uint8_t I2C0SlaveRegWrite_3Byte(uint8_t i2c_addr,uint8_t regAddr,uint8_t ParamAddr,uint8_t DataHigh,uint8_t DataLow);
extern uint8_t I2C0SlaveRegWrite_4Byte(uint8_t i2c_addr,uint8_t regAddr,uint8_t ParamAddrHigh,uint8_t ParamAddrLow,uint8_t DataHigh,uint8_t DataLow);
extern uint8_t I2C0SlaveRegRead(uint8_t i2c_addr, uint8_t regAddr);
extern uint8_t I2C0SlaveRegRead_2Byte(uint8_t i2c_addr, uint8_t regAddr,uint8_t paramh,uint8_t paraml, uint16_t *data);
extern uint8_t I2C0SlaveRegWriteMany(uint8_t i2c_addr,uint16_t regAddr,uint8_t *regData,uint32_t length);
extern uint8_t I2C0SlaveRegReadMany(uint8_t i2c_addr, uint8_t regAddr,uint8_t *dat,uint32_t length);





#endif

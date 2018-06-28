
#include "I2C.h"
//模拟I2C协议
//P3.5---SCL0
//P3.4---SDA0



void delay(volatile uint32_t delay)
{
    while(delay--);
}

//函数名；delay_ms
//输入：无
//输出：无
//描述：延时1ms

void delay_ms(uint16_t ms)
{    
    uint16_t i,j;
    for(i=0;i<ms;i++)
        for(j=0;j<564;j++);
}
void IIC_IOinit(void)
{

        GPIO_SetMode(P3, BIT4, GPIO_PMD_OUTPUT);
	      GPIO_SetMode(P3, BIT5, GPIO_PMD_OUTPUT);
        GPIO_SetMode(P3, BIT4, GPIO_PMD_QUASI);
        GPIO_SetMode(P3, BIT5, GPIO_PMD_QUASI);
        SDA_HIGH();
        SCL_HIGH

}



/*以下是模拟的I2C相关函数*/

void SDA_OUTPUT(void)
{
    GPIO_SetMode(P3, BIT4, GPIO_PMD_OUTPUT);
}

void SDA_INPUT(void)
{
    GPIO_SetMode(P3, BIT4, GPIO_PMD_INPUT);
}

void SDA_HIGH(void)
{
    SDA0_HIGH
}

void SDA_LOW(void)
{
    SDA0_LOW
}

uint8_t READ_SDA(void)
{
    return READ_SDA0;
}


//IIC起始信号
void IIC_Start(void)
{

    SDA_OUTPUT(); //SDA 输出
    delay(10);
    SDA_HIGH();
    delay(10);
    SCL_HIGH
    delay(10);
    SDA_LOW();
    delay(10);
    SCL_LOW
}

//IIC停止信号
void IIC_Stop(void)
{
	SDA_OUTPUT(); //SDA 输出
	delay(10);
	SCL_LOW
	delay(10);
	SDA_LOW();
	delay(10);
	SCL_HIGH
	delay(10);
	SDA_HIGH();
	delay(10);
}
//等待应答信号到来
//返回值： 1，接收应答失败
//      0,接收应答成功

uint8_t IIC_Wait_Ack(void)
{
    volatile uint32_t ucErrTime = 0;

    SDA_INPUT();
    SCL_HIGH
    while(READ_SDA())
    {
    	ucErrTime++;
    	if(ucErrTime > 2000)
    	{
    		IIC_Stop();
    		return 1;
    	}
    }
    delay(10);
    SCL_LOW
    delay(10);
    return 0;
}

//产生ACK应答
void IIC_Ack(void)
{
	SCL_LOW
	SDA_OUTPUT();
	delay(10);
	SDA_LOW();
	delay(10);
	SCL_HIGH
	delay(10);
	SCL_LOW
	delay(10);
}

//不产生ACK应答
void IIC_NAck(void)
{
	SCL_LOW
	SDA_OUTPUT();
	delay(10);
	SDA_HIGH();
	delay(10);
	SCL_HIGH
	delay(10);
	SCL_LOW
	delay(10);
}

//IIC 发送一个字节
//返回从机有无应答
//1,有应答
//0,无应答
void IIC_Write_Byte(uint8_t data)
{
    uint8_t t;
    SDA_OUTPUT();
    SCL_LOW//拉低时钟开始传输数据
    delay(10);
    for(t=0;t<8;t++)
    {
    	if((data&0x80)>>7)
    	{
    		SDA_HIGH();
    	}
    	else
    	{
    		SDA_LOW();
    	}
    	data <<= 1;
    	delay(10);
    	SCL_HIGH
    	delay(10);
    	SCL_LOW
    	delay(20);
    }
}

//读取一个字节，ack = 1 时，发送ACK ack=0,发送nACK
uint8_t IIC_Read_Byte(uint8_t ack)
{
    uint8_t i,receive = 0;
    SDA_INPUT();
    delay(10);
    for(i=0;i<8;i++)
    {
    	SCL_LOW
    	delay(10);
    	SCL_HIGH
    	delay(10);
    	receive<<= 1;
    	if(READ_SDA())
    	{
          receive++;
    	}
    	delay(10);
    }
    if(!ack)
    {
    	IIC_NAck();
    }
    else
    {
    	IIC_Ack();
    }
    return receive;
}


/*模拟I2C的write函数*/

uint8_t I2C0SlaveRegWrite_WithoutData(uint8_t i2c_addr,uint8_t regAddr)
{
    IIC_Start();//START信号
    IIC_Write_Byte(i2c_addr << 1);
    if(IIC_Wait_Ack())  return 0;
 
    IIC_Write_Byte(regAddr);//写寄存器地址
    if(IIC_Wait_Ack())  return 0;

    IIC_Stop();
    delay(10);
    return 1;
}

uint8_t I2C0SlaveRegWrite(uint8_t i2c_addr,uint8_t regAddr,uint8_t regData)
{
    IIC_Start();//START信号
    IIC_Write_Byte(i2c_addr << 1);
    if(IIC_Wait_Ack())  return 0;
 
    IIC_Write_Byte(regAddr);//写寄存器地址
    if(IIC_Wait_Ack())  return 0;

    IIC_Write_Byte(regData);
    if(IIC_Wait_Ack())  return 0;

    IIC_Stop();
    delay(10);
    return 1;
}

uint8_t I2C0SlaveRegWrite_2Byte(uint8_t i2c_addr,uint8_t regAddr,uint8_t channel,uint8_t regData)
{
    IIC_Start();//START信号
    IIC_Write_Byte(i2c_addr << 1);
    if(IIC_Wait_Ack())  return 0;
 
    IIC_Write_Byte(regAddr);//写寄存器地址
    if(IIC_Wait_Ack())  return 0;
    
    IIC_Write_Byte(channel);
    if(IIC_Wait_Ack())  return 0;

    IIC_Write_Byte(regData);
    if(IIC_Wait_Ack())  return 0;

    IIC_Stop();
    delay(10);
    return 1;
}

uint8_t I2C0SlaveRegWrite_3Byte(uint8_t i2c_addr,uint8_t regAddr,uint8_t ParamAddr,uint8_t DataHigh,uint8_t DataLow)
{
    IIC_Start();//START信号
    IIC_Write_Byte(i2c_addr << 1);
    if(IIC_Wait_Ack())  return 0;
 
    IIC_Write_Byte(regAddr);//写寄存器地址
    if(IIC_Wait_Ack())  return 0;

    IIC_Write_Byte(ParamAddr);
    if(IIC_Wait_Ack())  return 0;

    IIC_Write_Byte(DataHigh);
    if(IIC_Wait_Ack())  return 0;
    
    IIC_Write_Byte(DataLow);
    if(IIC_Wait_Ack())  return 0;

    IIC_Stop();
    delay(10);
    return 1;
}


uint8_t I2C0SlaveRegWrite_4Byte(uint8_t i2c_addr,uint8_t regAddr,uint8_t ParamAddrHigh,uint8_t ParamAddrLow,uint8_t DataHigh,uint8_t DataLow)
{
    IIC_Start();//START信号
    IIC_Write_Byte(i2c_addr << 1);
    if(IIC_Wait_Ack())  return 0;
 
    IIC_Write_Byte(regAddr);//写寄存器地址
    if(IIC_Wait_Ack())  return 0;

    IIC_Write_Byte(ParamAddrHigh);
    if(IIC_Wait_Ack())  return 0;
    
    IIC_Write_Byte(ParamAddrLow);
    if(IIC_Wait_Ack())  return 0;
    
    IIC_Write_Byte(DataHigh);
    if(IIC_Wait_Ack())  return 0;
    
    IIC_Write_Byte(DataLow);
    if(IIC_Wait_Ack())  return 0;

    IIC_Stop();
    delay(10);
    return 1;
}

/*模拟I2C的read函数*/

uint8_t I2C0SlaveRegRead(uint8_t i2c_addr, uint8_t regAddr)
{
    uint8_t tmp;
    IIC_Start();
    IIC_Write_Byte(i2c_addr << 1);
    if(IIC_Wait_Ack())  return 0;

    IIC_Write_Byte(regAddr);//写寄存器地址
    if(IIC_Wait_Ack())  return 0;

    IIC_Start();
    IIC_Write_Byte(i2c_addr<<1 | 0x01);
    if(IIC_Wait_Ack())    return 0;

    tmp = IIC_Read_Byte(0);
      
    IIC_Stop();
    delay(10);

    return tmp;
}

uint8_t I2C0SlaveRegRead_2Byte(uint8_t i2c_addr, uint8_t regAddr,uint8_t paramh,uint8_t paraml, uint16_t *data)
{
    uint8_t datal,datah;
    IIC_Start();
    IIC_Write_Byte(i2c_addr << 1);
    if(IIC_Wait_Ack())  return 0;

    IIC_Write_Byte(regAddr);
    if(IIC_Wait_Ack())  return 0;
    
    IIC_Write_Byte(paramh);
    if(IIC_Wait_Ack())  return 0;
    
    IIC_Write_Byte(paraml);//写寄存器地址
    if(IIC_Wait_Ack())  return 0;

    IIC_Start();
    IIC_Write_Byte(i2c_addr<<1 | 0x01);
    if(IIC_Wait_Ack())    return 0;

    datah = IIC_Read_Byte(1);
    datal = IIC_Read_Byte(0);
    IIC_Stop();
    delay(10);
    *data = (datah<<8) + datal;
    return 1;
}



uint8_t I2C0SlaveRegWriteMany(uint8_t i2c_addr,uint16_t regAddr,uint8_t *regData,uint32_t length)
{
    uint32_t i;
    uint8_t tmp,state;
    state = 1;
    while(state)
    {
      IIC_Start();//START信号
      IIC_Write_Byte(i2c_addr << 1);
      if(IIC_Wait_Ack())  
      {
        return 1;
      }

      IIC_Write_Byte((regAddr & 0xff00) >> 8);//写寄存器高地址
      if(IIC_Wait_Ack())  
      {
        return 1;
      }
      IIC_Write_Byte((regAddr & 0x00ff));//写寄存器低地址
      if(IIC_Wait_Ack()) 
      {
        return 1;
      }

      i = 0;
      while(length)
      {
          tmp = regData[i];
          IIC_Write_Byte(tmp);
          if(IIC_Wait_Ack())  
          {
            return 1;
          }
          length--;
          i++;
      }

      IIC_Stop();
      delay(10);
      state = 0;
    }
    return 0;
}

uint8_t I2C0SlaveRegReadMany(uint8_t i2c_addr, uint8_t regAddr,uint8_t *dat,uint32_t length)
{
    IIC_Start();
    IIC_Write_Byte(i2c_addr << 1);
    if(IIC_Wait_Ack())  return 0;

    IIC_Write_Byte(regAddr);//写寄存器低地址
    if(IIC_Wait_Ack())  return 0;

    IIC_Start();
    IIC_Write_Byte(i2c_addr << 1 | 0x01);
    if(IIC_Wait_Ack())    return 0;

    while(length)
    {
      if(length == 1)
      {
        dat[0] = IIC_Read_Byte(0);  //无应答NAck
      }
      else 
      {
        dat[length-1] = IIC_Read_Byte(1);  //应答Ack
      }
      length--;
    }

    IIC_Stop();
    delay(10);

    return 0;
	
}


#include "BR262_Driver.h"
#include "detect.h"

uint16_t mic_threshold_value = 10;//设定能量值比较值
uint16_t g_ch1_shortterm_energy;
uint16_t g_ch0_shortterm_energy;
uint16_t input_detect_right = 0;
uint16_t input_detect_fail = 0;
uint8_t g_input = 0;
void BR262_detect(void)
{
	  Get_Channel0_ShortTerm_Energy(BR262_I2C_Addr,&g_ch0_shortterm_energy);//获取通道0能量值
    Get_Channel1_ShortTerm_Energy(BR262_I2C_Addr,&g_ch1_shortterm_energy);//获取通道1能量值
        //Get_Channel1_ShortTerm_Energy
	  if((g_ch0_shortterm_energy <= mic_threshold_value) || (g_ch1_shortterm_energy <= mic_threshold_value))
	  {
		    input_detect_fail++;
			  input_detect_right = 0;
	  }
	  else
	  {
		    input_detect_fail=0;
		    input_detect_right ++;
	  }
	  if(input_detect_fail==10)
	  {
		    input_detect_fail = 0;
        g_input = 0;
		
  	}
	  if(input_detect_right==10)
	  {
		    input_detect_right = 0;
		    g_input = 1;
	  }
}

#include "main.h" 

uint16_t sensor_value;
uint8_t sen_val_first_byte;
uint8_t sen_val_second_byte;
uint8_t sensor_v[18]={'s','e','n','s','o','r',' ','v','a','l','u','e',':',' '};
int main(void){
	/*Enable clock access to GPIOC*/
	RCC->AHB1ENR |= GPIOCEN;
  /*set PC13 as input pin*/
	GPIOC->MODER  &=~ (1U << 26);
	GPIOC->MODER  &=~ (1U << 27);
	uart3_tx_init();
	pal_adc_init();
	
	while(1){
		int flag=0;
		start_converstion();
		sensor_value=(uint16_t)adc_read();
		sen_val_first_byte = (sensor_value>>8) & 0xFF;
		sen_val_second_byte= (sensor_value) & 0xFF;
		sensor_v[14]=sen_val_first_byte;
		sensor_v[15]=sen_val_second_byte;
		sensor_v[16]=0x0a; /*new line*/
		sensor_v[17]=0x0D;/*/r*/
	
		if((GPIOC->IDR & BTN_PIN)!=0 & flag==0)  
		{
			flag=1;		
		}		
		else
		{
					UART_Write_String(sensor_v);
			    flag=0;
			    break;
		}
	}
}

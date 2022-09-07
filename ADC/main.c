#include <stdint.h>
#include <stdio.h>
#include "stm32f446xx.h"
#include "uart.h"
#include "adc.h"
#include "main.h" 

uint32_t sensor_value;
int main(void){
	uart3_tx_init();
	pal_adc_init();
	
	while(1){
		start_converstion();
		sensor_value=adc_read();
		UART_Write_String((int)sensor_value);
		
	}
}

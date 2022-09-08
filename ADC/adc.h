#include <stdint.h>
#include "stm32f446xx.h"
#define GPIOAEN  (1U<<0)
#define ADC1EN	  (1U<<8)
#define ADC_CH1   (1U<<0)
#define ADC_SEQ_LEN_1 0x00
#define CR2_ADON   (1U<<0)
#define CR2_SWSTART (1U<<30) 
#define SR_EOC			(1U<<1)

void pal_adc_init(void);
uint32_t adc_read(void);
void start_converstion(void);


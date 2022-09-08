#include <stdint.h>
#include <stdio.h>
#include "stm32f446xx.h"
#include "uart.h"
#include "adc.h"

#define GPIOCEN      (1U << 2)
#define PIN13        (1U << 13)
#define BTN_PIN				 PIN13

extern uint16_t sensor_value;
extern uint8_t sen_val_first_byte;
extern uint8_t sen_val_second_byte;
extern uint8_t sensor_v[18];

extern void uart3_tx_init(void);
extern void uart3_write(int ch);
extern void UART_Write_String(uint8_t *p);
extern void pal_adc_init(void);
extern void start_converstion(void);
extern uint32_t adc_read(void);
extern void UART_Write_Int(int *i);

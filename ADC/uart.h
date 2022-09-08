#include <stdio.h>
#include <stdint.h>
#include "stm32f446xx.h"


void uart3_tx_init(void);
void uart3_write(int ch);
void UART_Write_String(uint8_t *p);
void UART_Write_Int(int *i);




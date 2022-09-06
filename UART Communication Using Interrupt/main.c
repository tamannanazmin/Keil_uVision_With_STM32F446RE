#include<stdio.h>
#include<stdint.h>
#include "stm32f446xx.h"
#include "uart.h"
#include "exti.h"
#include "main.h"

#define GPIOAEN   (1U<<0)
#define PIN5			(1U<<5)
#define LED				 PIN5 

static void exti_callback(void);
void EXTI15_10_IRQHandler(void);
void UART_Write_String(char *p);
int main(void){
	/*Enable clock access to GPIOA*/
	RCC->AHB1ENR |= GPIOAEN;
	/*Set PA5 as output pin*/
	GPIOA-> MODER |= (1U<<10);
	GPIOA-> MODER &=~(1U<<11);
	
	pc13_exti_init();
	uart3_tx_init();
	while(1){
		
	}
}
static void exti_callback(void){
	UART_Write_String("Hello From Tamanna...\r\n");
}
void EXTI15_10_IRQHandler(void){
	int i;
	if((EXTI->PR & LINE13)!=0)
	{
		/*Clear PR flag*/
		EXTI->PR |= LINE13;
		/*Do someting....*/
		exti_callback();
		GPIOA->BSRR |= LED;
		for(i=0;i<500000;i++);
		GPIOA->BSRR |= (1U<<21);
		for(i=0;i<50000;i++);
	}
}



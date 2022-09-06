#include "uart3.h"

static void uart_set_bd(USART_TypeDef *USARTx, uint32_t PeriphCLK, uint32_t BaudRate);
static uint32_t compute_uart_bd (uint32_t PeriphCLK, uint32_t BaudRate);

void uart3_tx_init(void);
void uart3_write(int ch);
void UART_Write_String(char *p);
//int __io_putchar(int ch);



void uart3_tx_init(void)
{

	//confiure uart gpio pin
	RCC->AHB1ENR  |= GPIOCEN;  // enable gpio clk
	GPIOC->MODER  |= (1<<21);  // alternet mode of gpio pin
	GPIOC->MODER  |= (1<<23);
	
	GPIOC->AFR[1] |= (1<<8); // PC12 alternet func AFRL2 type to uart_tx AF7
	GPIOC->AFR[1] |= (1<<9);
	GPIOC->AFR[1] |= (1<<10);
	
	GPIOC->AFR[1] |= (1<<12); // PA2 alternet func AFRL2 type to uart_tx AF7
	GPIOC->AFR[1] |= (1<<13);
	GPIOC->AFR[1] |= (1<<14);
	
	
	//GPIOA->AFR[1] |= (1<<6);
	
	//configure uart module
	RCC->APB1ENR |= UART3EN;  //enable clk to uart2
	uart_set_bd(USART3, SYS_FREQ, UART_BR); // config baudrate
	USART3->CR1 = CR1_TE; //config transfer direction by usart control reg   // M=0, PS=0 not need to code
	USART3->CR1 |=  CR1_UE;  // enable uart   |= or operator  for different from previous        
}

void uart3_write(int ch)
{
	while(!(USART3->SR & SR_TXE)){}     // make sure data reg is empty 
	USART3->DR  =  (ch & 0xFF);  // write to transmit data register
}

void UART_Write_String(char *p)
	{
	while(*p!='\0')
{
uart3_write(*p);
p++;
}
}

/*int __io_putchar(int ch)
{
	uart1_write(ch);
	return ch;
}*/

static void uart_set_bd(USART_TypeDef *USARTx, uint32_t PeriphCLK, uint32_t BaudRate)   // baudrate calculation
{
	USARTx->BRR = compute_uart_bd(PeriphCLK, BaudRate);
}

static uint32_t compute_uart_bd (uint32_t PeriphCLK, uint32_t BaudRate)
{
	return ((PeriphCLK + (BaudRate/2))/BaudRate);
}	

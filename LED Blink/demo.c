 #include "stm32f446xx.h"
int main()
{
	
	/* PA5=GPIO pin 5	output mode*/
	RCC-> AHB1ENR |= 0x1;
	GPIOA-> MODER |= 0x400;

	while(1){
		int i;
		GPIOA-> BSRR |= (1 << 5);
		for(i=0;i<1600000;i++){}
		GPIOA-> BSRR |= (1 << 21);
		for(i=0;i<1600000;i++){}
	}
}



#include "main.h"

int main(){
	uart3_tx_init();
	while(1){
		UART_Write_String("Hello Prashun....\r\n");
	}
}

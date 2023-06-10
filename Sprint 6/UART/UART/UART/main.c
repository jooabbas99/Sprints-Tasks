/*
 * UART.c
 *
 * Created: 5/1/2023 6:21:44 PM
 * Author : Youssef Abbas
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include "UART/uart.h"

int main(void)
{
    /* Replace with your application code */
	UART_init();
	//uint8_t arr []= {'h','e','l','l','o'};
	//uint8_t i = 0;
	uint8_t data ='0';
	UART_sendData(data);
    while (1) 
    {
		//UART_sendData(arr[i]);
		//i = ((i+1)%5);
		//if (i == 0)
			//UART_sendData('\n');	
			
		data = UART_getData();
		UART_sendData(' ');

		UART_sendData(data);
		UART_sendData('\n');
		
		_delay_ms(500);
    }
}


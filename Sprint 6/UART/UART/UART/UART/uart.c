/*
 * uart.c
 *
 * Created: 5/1/2023 6:22:40 PM
 *  Author: Youssef Abbas
 */ 
#include "uart.h"
#include "uart_register.h"
#include "../utilities/BIT_MATH.h"
#include <stdint.h>


void UART_init(void){
	// set BaudRate => 9600/8000 MH 
	UBRRL = 51;
	UBRRH = 0;
	// set frame format -> 8Bit data , 1 stop , No Parity
	UCSRC = 0x86;
	
	//Enable RX And TX
	UCSRB = 0x18;
}
void UART_sendData(uint8_t data){
	// check if transmit register is empty 
	//while(READ_BIT(UCSRA,6) == 1); 
	  while((UCSRA&0x20) == 0x00);
	UDR = data;
}
uint8_t UART_getData(void){
	// check if transmit register is empty
	
	//while(READ_BIT(UCSRA,7) == 1);
	 while((UCSRA&0x80) == 0x00);
	uint8_t data = UDR;
	// clear flag
	SET_BIT(UCSRA,7);
	return data;
}

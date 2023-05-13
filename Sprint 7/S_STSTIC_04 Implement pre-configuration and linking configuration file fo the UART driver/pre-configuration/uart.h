 /*
 * uart.h
 *
 * Created: 5/1/2023 6:22:57 PM
 *  Author: Youssef Abbas
 */ 


#ifndef UART_H_
#define UART_H_
#include <stdint.h>


void UART_init(void);
void UART_sendData(uint8_t data);
uint8_t UART_getData(void);


#endif /* UART_H_ */
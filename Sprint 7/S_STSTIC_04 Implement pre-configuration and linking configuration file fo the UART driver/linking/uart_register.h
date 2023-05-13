/*
 * uart_register.h
 *
 * Created: 5/1/2023 6:23:09 PM
 *  Author: Youssef Abbas
 */ 


#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_

#define UDR		(*((volatile uint8_t*) 0x2C ))
#define UCSRA	(*((volatile uint8_t*) 0x2B ))
#define UCSRB	(*((volatile uint8_t*) 0x2A ))
#define UCSRC	(*((volatile uint8_t*) 0x40 ))
#define UBRRL	(*((volatile uint8_t*) 0x29 ))
#define UBRRH	(*((volatile uint8_t*) 0x40 ))


#endif /* UART_REGISTER_H_ */
/*
 * uart_private.h
 *
 * Created: 5/25/2023 12:21:54 PM
 *  Author: Youssef Abbas
 */ 

#ifndef PRIVATE_H_
#define PRIVATE_H_

#include "../../i_lib/std_types.h"

// Registers
#define UCSRC_REG   (*((volatile uint8 *)0x40))
#define UDR_REG     (*((volatile uint8 *)0x2C))
#define UCSRA_REG   (*((volatile uint8 *)0x2B))
#define UCSRB_REG   (*((volatile uint8 *)0x2A))
#define UBRRH_REG   (*((volatile uint8 *)0x40))
#define UBRRL_REG   (*((volatile uint8 *)0x29))

// USART Control and Status Register C (UCSRC)
#define URSEL  7
#define UMSEL  6
#define UPM    4
#define USBS   3
#define UCSZ   1
#define UCPOL  0

// USART Control and Status Register A (UCSRA)
#define RXC    7
#define TXC    6
#define UDRE   5
#define FE     4
#define DOR    3
#define PE     2
#define U2X    1

// USART Control and Status Register B (UCSRB)
#define RXCIE  7
#define TXCIE  6
#define UDRIE  5
#define RXEN   4
#define TXEN   3
#define UCSZ2  2
#define RXB8   1
#define TXB8   0

#endif /* PRIVATE_H_ */

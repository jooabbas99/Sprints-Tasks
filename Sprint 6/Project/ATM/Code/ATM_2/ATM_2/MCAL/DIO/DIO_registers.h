//
// Created by Youssef Abbas on 25/04/2023.
//

#ifndef ATMEGA32A_DIO_REGISTERS_H
#define ATMEGA32A_DIO_REGISTERS_H

// DEFINE DIO REGISTERS  ADDRESSES

// PORTA registers
#define PORTA *((volatile uint8 *)0x3B)
#define DDRA *((volatile uint8 *)0x3A)
#define PINA *((volatile uint8 *)0x39)

// PORTB registers
#define PORTB *((volatile uint8 *)0x38)
#define DDRB *((volatile uint8 *)0x37)
#define PINB *((volatile uint8 *)0x36)


// PORTC registers
#define PORTC *((volatile uint8 *)0x35)
#define DDRC *((volatile uint8 *)0x34)
#define PINC *((volatile uint8 *)0x33)

// PORTD registers
#define PORTD *((volatile uint8 *)0x32)
#define DDRD *((volatile uint8 *)0x31)
#define PIND *((volatile uint8 *)0x30)

// PIN A NUMBERS

#define PINA0       0
#define PINA1       1
#define PINA2       2
#define PINA3       3
#define PINA4       4
#define PINA5       5
#define PINA6       6
#define PINA7       7

// PIN B NUMBERS

#define PINB0       0
#define PINB1       1
#define PINB2       2
#define PINB3       3
#define PINB4       4
#define PINB5       5
#define PINB6       6
#define PINB7       7

// PIN A NUMBERS

#define PINC0       0
#define PINC1       1
#define PINC2       2
#define PINC3       3
#define PINC4       4
#define PINC5       5
#define PINC6       6
#define PINC7       7

// PIN A NUMBERS

#define PIND0       0
#define PIND1       1
#define PIND2       2
#define PIND3       3
#define PIND4       4
#define PIND5       5
#define PIND6       6
#define PIND7       7

#endif //ATMEGA32A_DIO_REGISTERS_H

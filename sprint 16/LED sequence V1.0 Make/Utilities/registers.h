/*
 * registers.h
 *
 * Created: 4/6/2023 8:24:10 PM
 *  Author: youss
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "types.h"

/*

	DEFINE REGISTERS 
*/

// PORTA registers 
#define PORTA *((volatile uint8_t *)0x3B)
#define DDRA *((volatile uint8_t *)0x3A)
#define PINA *((volatile uint8_t *)0x39)

// PORTB registers
#define PORTB *((volatile uint8_t *)0x38)
#define DDRB *((volatile uint8_t *)0x37)
#define PINB *((volatile uint8_t *)0x36)


// PORTC registers
#define PORTC *((volatile uint8_t *)0x35)
#define DDRC *((volatile uint8_t *)0x34)
#define PINC *((volatile uint8_t *)0x33)

// PORTD registers
#define PORTD *((volatile uint8_t *)0x32)
#define DDRD *((volatile uint8_t *)0x31)
#define PIND *((volatile uint8_t *)0x30)



#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7


// define Interrupt registers  
// MCUCR
#define MCUCR *((volatile uint8_t*)0x55)
// MCUCSR
#define MCUCSR *((volatile uint8_t*)0x54)
//GICR
#define GICR *((volatile uint8_t*)0x5B)

//GIFR
#define GIFR *((volatile uint8_t*)0x5A)

#endif /* REGISTERS_H_ */
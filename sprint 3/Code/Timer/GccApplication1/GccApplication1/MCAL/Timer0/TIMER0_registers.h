/*
 * TIMER_registers.h
 *
 * Created: 4/15/2023 11:55:27 PM
 *  Author: youss
 */ 


#ifndef TIMER_REGISTERS_H_
#define TIMER_REGISTERS_H_



#define TCCR0 *((volatile uint8_t *)0x53)
#define TCNT0 *((volatile uint8_t *)0x32)
#define OCR0 *((volatile uint8_t *)0x5C)
#define TIFR *((volatile uint8_t *)0x59)
#define TIMSK *((volatile uint8_t *)0x58)



#endif /* TIMER_REGISTERS_H_ */
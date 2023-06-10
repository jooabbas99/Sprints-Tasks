/*
 * timer_registers.h
 *
 * Created: 6/10/2023 10:21:05 AM
 *  Author: Youssef Abbas
 */ 


#ifndef TIMER_REGISTERS_H_
#define TIMER_REGISTERS_H_


// TIMER0
#define TCCR0	*((volatile uint8_t*)0x53)
#define TCNT0	*((volatile uint8_t*)0x52)
#define TIFR	*((volatile uint8_t*)0x58)
#define OCR0    *((volatile uint8_t*)0x3C)


#endif /* TIMER_REGISTERS_H_ */
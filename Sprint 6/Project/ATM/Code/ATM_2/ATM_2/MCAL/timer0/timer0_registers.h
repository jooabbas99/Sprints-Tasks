/*
 * TIMER_registers.h
 *
 * Created: 4/26/2023 12:50:44 PM
 *  Author: Youssef Abbas
 */ 


#ifndef TIMER_REGISTERS_H_
#define TIMER_REGISTERS_H_


/*============= TIMER0 registers =============*/

#define TCCR0 (*((volatile uint8_t*)0x53))
#define TCNT0 (*((volatile uint8_t*)0x52))
#define OCR0  (*((volatile uint8_t*)0x5C))
#define TIFR  (*((volatile uint8_t*)0x58))
#define TIMSK (*((volatile uint8_t*)0x59))



#endif /* TIMER_REGISTERS_H_ */
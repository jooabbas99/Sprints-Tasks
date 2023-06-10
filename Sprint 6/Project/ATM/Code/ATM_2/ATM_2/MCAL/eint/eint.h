/*
 * eint.h
 *
 * Created: 5/18/2023 9:47:34 PM
 *  Author: Youssef Abbas
 */ 


#ifndef EINT_H_
#define EINT_H_


#include "../../utilities/types.h"



/* MCUCR register bits*/
#define ISC00		0
#define ISC01		1
#define ISC10		2
#define ISC11		3
/* MCUCSR register bits*/
#define ISC2		6
/* GICR register bits*/
#define INT0		6
#define INT1		7
#define INT2		5
/* GIFR register bits*/
#define INTF0		6
#define INTF1		7
#define INTF2		5

void eint_init();
void set_call_back_int0(void(*g_ptr)(void));
void set_call_back_int1(void(*g_ptr)(void));
void set_call_back_int2(void(*g_ptr)(void));

// SET Global interrupt I-BIT to 1
#define sei() __asm__ __volatile__("sei" :: \
: "memory")

// SET Global interrupt I-BIT to 0
#define cli() __asm__ __volatile__("cli" :: \
: "memory")

// ISR Define

#define ISR(INT_VECT)                                  \
void INT_VECT(void) __attribute__((signal, used)); \
void INT_VECT(void)

#endif /* EINT_H_ */
/*
 * interrupt.h
 *
 * Created: 4/9/2023 11:10:53 PM
 *  Author: youss
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

// External Interrupt 1
#define EXT_INT_0 __vector_1
// External Interrupt 2
#define EXT_INT_1 __vector_2
// External Interrupt 3
#define EXT_INT_2 __vector_3


//GICR INT0
#define GICR_INT_0  6
//GICR INT1
#define GICR_INT_1  7
//GICR INT2
#define GICR_INT_2  5

#define ISC00   0
#define ISC01   1

// SET Global interrupt I-BIT to 1
#define sei() __asm__ __volatile__("sei":::"memory")

// SET Global interrupt I-BIT to 0
#define cli() __asm__ __volatile__("cli":::"memory")


// ISR Define 

#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used)); \
void INT_VECT(void)


#endif /* INTERRUPT_H_ */
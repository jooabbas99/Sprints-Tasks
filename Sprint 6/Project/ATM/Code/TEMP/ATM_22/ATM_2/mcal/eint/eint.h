/*
 * EINT.h
 *
 * Created: 4/26/2023 12:45:49 PM
 *  Author: Youssef Abbas
 */ 


#ifndef EINT_H_
#define EINT_H_

#include "INT_registers.h"


#define EXI_ISC00_BIT	    0
#define EXI_ISC01_BIT	    1

#define EXI_ISC10_BIT	    2
#define EXI_ISC11_BIT	    3



#define EXI_ISC2_BIT		    6


/* GICR */
/* Bit 6 */
#define EXI_INT0_BIT		    6
/* Bit 7  */
#define EXI_INT1_BIT		    7
/* Bit 5 */
#define EXI_INT2_BIT		    5

//GIFR
/* Bit 6 */
#define EXI_INTF0_BIT	    6
/* Bit 7 */
#define EXI_INTF1_BIT	    7
/* Bit 5  */
#define EXI_INTF2_BIT	    5


// SET Global interrupt I-BIT to 1
#define sei() __asm__ __volatile__("sei" ::: "memory")

// SET Global interrupt I-BIT to 0
#define cli() __asm__ __volatile__("cli" ::: "memory")

// ISR Define


#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used)); \
void INT_VECT(void)




#endif /* EINT_H_ */
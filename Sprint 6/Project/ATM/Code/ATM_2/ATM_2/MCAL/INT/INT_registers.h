/*
 * INT_registers.h
 *
 * Created: 4/26/2023 12:46:25 PM
 *  Author: Youssef Abbas
 */ 


#ifndef INT_REGISTERS_H_
#define INT_REGISTERS_H_
// EINT_REGISTERS

// define Interrupt registers
// MCUCR
#define MCUCR *((volatile uint8_t *)0x55)
// MCUCSR
#define MCUCSR *((volatile uint8_t *)0x54)
// GICR
#define GICR *((volatile uint8_t *)0x5B)

// GIFR
#define GIFR *((volatile uint8_t *)0x5A)


#endif /* INT_REGISTERS_H_ */
/*
 * INT_registers.h
 *
 * Created: 4/26/2023 12:46:25 PM
 *  Author: Youssef Abbas
 */ 


#ifndef INT_REGISTERS_H_
#define INT_REGISTERS_H_
// EINT_REGISTERS

/* Global Interrutpt */
#define GLOBAL_INTERRUPT_ENABLE_BIT      7
#define TIMER_SREG_REG            *( ( volatile u8 * ) 0x5F )



// define Interrupt registers
#define EXI_MCUCR_REG			*( ( volatile u8 * ) 0x55 )
#define EXI_MCUCSR_REG			*( ( volatile u8 * ) 0x54 )
#define EXI_GICR_REG			*( ( volatile u8 * ) 0x5B )
#define EXI_GIFR_REG			*( ( volatile u8 * ) 0x5A )

#define SREG *((volatile uint8 *)0x5F)

#endif /* INT_REGISTERS_H_ */
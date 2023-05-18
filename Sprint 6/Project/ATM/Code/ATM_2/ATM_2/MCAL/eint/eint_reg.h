/*
 * eint_reg.h
 *
 * Created: 5/18/2023 9:47:42 PM
 *  Author: Youssef Abbas
 */ 


#ifndef EINT_REG_H_
#define EINT_REG_H_


#define MCUCR	(*(volatile uint8*)(0x55))
#define MCUCSR	(*(volatile uint8*)(0x54))
#define GICR	(*(volatile uint8*)(0x5B))
#define GIFR	(*(volatile uint8*)(0x5A))

#define SREG 	(*(volatile uint8*)(0x5F)) // for global interrupt


#endif /* EINT_REG_H_ */
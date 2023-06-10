/*
 * dio_private.h
 *
 * Created: 6/6/2023 11:14:16 AM
 *  Author: Youssef Abbas
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_


// DEFINE DIO REGISTERS  ADDRESSES

// PORTA registers
#define DIO_PORTA_REG *((volatile uint8 *)0x3B)
#define DIO_DDRA_REG *((volatile uint8 *)0x3A)
#define DIO_PINA_REG *((volatile uint8 *)0x39)

// PORTB registers
#define DIO_PORTB_REG *((volatile uint8 *)0x38)
#define DIO_DDRB_REG *((volatile uint8 *)0x37)
#define DIO_PINB_REG *((volatile uint8 *)0x36)


// PORTC registers
#define DIO_PORTC_REG *((volatile uint8 *)0x35)
#define DIO_DDRC_REG *((volatile uint8 *)0x34)
#define DIO_PINC_REG *((volatile uint8 *)0x33)

// PORTD registers
#define DIO_PORTD_REG *((volatile uint8 *)0x32)
#define DIO_DDRD_REG *((volatile uint8 *)0x31)
#define DIO_PIND_REG *((volatile uint8 *)0x30)

// PIN A NUMBERS
typedef enum {
	 PIN0    =   0,
	 PIN1    =   1,
	 PIN2    =   2,
	 PIN3    =   3,
	 PIN4    =   4,
	 PIN5    =   5,
	 PIN6    =   6,
	 PIN7    =   7
}enm_dio_pin_t;





#endif /* DIO_PRIVATE_H_ */
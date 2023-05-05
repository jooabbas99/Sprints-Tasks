/*
 * EINT.h
 *
 * Created: 4/26/2023 12:45:49 PM
 *  Author: Youssef Abbas
 */ 


#ifndef EINT_H_
#define EINT_H_

#include "INT_registers.h"

/*

Interrupt Vector	Interrupt
INT0_vect	External Interrupt 0
INT1_vect	External Interrupt 1
INT2_vect	External Interrupt 2
TIMER0_OVF_vect	Timer/Counter 0 Overflow
TIMER0_COMPA_vect	Timer/Counter 0 Compare Match A
TIMER0_COMPB_vect	Timer/Counter 0 Compare Match B
TIMER1_OVF_vect	Timer/Counter 1 Overflow
TIMER1_COMPA_vect	Timer/Counter 1 Compare Match A
TIMER1_COMPB_vect	Timer/Counter 1 Compare Match B
TIMER1_CAPT_vect	Timer/Counter 1 Capture
TIMER2_OVF_vect	Timer/Counter 2 Overflow
TIMER2_COMPA_vect	Timer/Counter 2 Compare Match A
TIMER2_COMPB_vect	Timer/Counter 2 Compare Match B
USART0_RX_vect	USART0 Receive Complete
USART0_UDR_vect	USART0 Data Register Empty
USART1_RX_vect	USART1 Receive Complete
USART1_UDR_vect	USART1 Data Register Empty
I2C_vect	I2C Interrupt
SPI_vect	SPI Interrupt
ADC_vect	ADC Interrupt
EE_READY_vect	EEPROM Ready Interrupt
PORT_A_vect	Port A Pin Change Interrupt
PORT_B_vect	Port B Pin Change Interrupt
PORT_C_vect	Port C Pin Change Interrupt
PORT_D_vect	Port D Pin Change Interrupt
TIMER0_BRK_vect	Timer/Counter 0 Overflow / BRK
TIMER0_UF_vect	Timer/Counter 0 Overflow
SLEEP_MODE_vect	Sleep Mode / Watchdog Timer Reset
WDT_vect	Watchdog Timer Overflow
RESET_vect	Reset


*/
#define INT0_vect 1
#define INT1_vect 2
#define INT2_vect 3
#define TIMER2_COMP_vect 4
#define TIMER2_OVF_vect 5

#define TIMER1_CAPT_vect 6
#define TIMER1_COMPA_vect 7
#define TIMER1_COMPB_vect 8
#define TIMER1_OVF_vect 9
//#define TIMER0_OVF_vect 10
#define TIMER0_COMP_vect 11

#define SPI_vect 12
#define USART_RX_vect 13
#define USART_UDRE_vect 14
#define USART_TX_vect 15
#define ADC_vect 16
#define EE_READY_vect 17

#define ANA_COMP_vect 18

#define TWI_vect 10
#define SPM_RDY_vect 29

// GICR INT0
#define GICR_INT_0 6
// GICR INT1
#define GICR_INT_1 7
// GICR INT2
#define GICR_INT_2 5

#define ISC00 0
#define ISC01 1

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
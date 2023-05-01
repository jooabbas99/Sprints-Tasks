
#ifndef MOVING_CAR_SYSTEM_REGISTERS_H
#define MOVING_CAR_SYSTEM_REGISTERS_H

#include "std_types.h"

#define F_CPU 1000000

/**
* @brief Contains information about the result of the most recently executed arithmetic instruction.
* Bit 7 I: Global Interrupt Enable
* Bit 6 T: Bit Copy Storage
* Bit 5 H: Half Carry Flag
* Bit 4 S: Sign Bit
* Bit 3 V: Overflow Flag
* Bit 2 N: Negative Flag
* Bit 1 Z: Zero Flag
* Bit 0 C: Carry Flag
*/
#define SREG *((uint8 *)0x5F)

/**
 * @defgroup AVR-Ports Port addresses
 * De-referenced addresses of ports.
 * @{
 */
#define PORTA *((uint8 *)0x3B)
#define PORTB *((uint8 *)0x38)
#define PORTC *((uint8 *)0x35)
#define PORTD *((uint8 *)0x32)
/**@}*/

/**
 * @defgroup AVR-Pins Pin addresses
 * De-referenced addresses of pins.
 * @{
 */
#define PINA *((uint8 *)0x39)
#define PINB *((uint8 *)0x36)
#define PINC *((uint8 *)0x33)
#define PIND *((uint8 *)0x30)
/**@}*/

/**
 * @defgroup AVR-DDR DDR addresses
 * De-referenced addresses of DDR.
 * @{
 */
#define DDRA *((uint8 *)0x3A)
#define DDRB *((uint8 *)0x37)
#define DDRC *((uint8 *)0x34)
#define DDRD *((uint8 *)0x31)
/**@}*/

/**
* @brief MCUSR - MCU Control Register
* Controls the triggering mechanism of INT1 and INT0.
* Interrupt 1 sense control
* | ISC11 Bit 3 | ISC10 Bit 2 | Description                       |
* |-------------|-------------|-----------------------------------|
* | 0           | 0           | INT1 triggered on low level.      |
* | 0           | 1           | Any logic change triggers.        |
* | 1           | 0           | Falling edge generates interrupt. |
* | 1           | 1           | Rising edge generates interrupt.  |
* Interrupt 0 sense control.
* | ISC01 Bit 3 | ISC00 Bit 2 | Description                       |
* |-------------|-------------|-----------------------------------|
* | 0           | 0           | INT0 triggered on low level.      |
* | 0           | 1           | Any logic change triggers.        |
* | 1           | 0           | Falling edge generates interrupt. |
* | 1           | 1           | Rising edge generates interrupt.  |
*/
#define MCUCR *((uint8 *)0x55)

/**
* @brief MCUCSR MCU Control and Status Register
* Controls the triggering mechanism of INT2.
* This is done through ISC2 Bit 6.
* 0 - Falling edge activates the interrupt.
* 1 - Rising edge activates the interrupt.
*/
#define MCUCSR *((uint8 *)0x54)

/**
* @brief GICR - General Interrupt Control Register
* Bit 7 - INT1: External Interrupt Request 1 enable.
* Bit 6 - INT0: External Interrupt Request 0 enable.
* Bit 5 - INT2: External Interrupt Request 2 enable.
*/
#define GICR *((uint8 *)0x5B)

/**
* @brief GIFR - General Interrupt Flag Register
* Bit 7 - INTF1: External Interrupt Flag 1.
* Bit 6 - INTF0: External Interrupt Flag 0.
* Bit 5 - INTF2: External Interrupt Flag 2.
*/
#define GIFR *((uint8 *)0x5A)


#define TCCR0 *((uint8 *)0x53)
#define TCNT0 *((uint8 *)0x52)
#define TIMSK *((uint8 *)0x59)
#define OCR0 *((uint8 *)0x5C)
#define TIFR *((uint8 *)0x58)

typedef enum {
    CS00 = 0, CS01, CS02, WGM01, COM00, COM01, WGM00, FOC0
}TCCR0_BITS;

typedef  enum {
    TOV0 = 0, OCF0
}TIFR_BITS;

typedef enum {
    TOIE0 = 0, OCIE0
}TIMSK_BITS;
#endif //MOVING_CAR_SYSTEM_REGISTERS_H

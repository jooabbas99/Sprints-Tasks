/*
 * spi_registers.h
 *
 * Created: 5/12/2023 6:30:35 PM
 *  Author: Youssef Abbas
 */ 


#ifndef SPI_REGISTERS_H_
#define SPI_REGISTERS_H_



#define SPCR *((volatile uint8 *)0x2D)
#define SPSR *((volatile uint8 *)0x2E)
#define SPDR *((volatile uint8 *)0x2F)

#define SPR0 0
#define SPR1 1
#define CPHA 2
#define CPOL 3
#define MSTR 4
#define DORD 5
#define SPE 6
#define SPIE 7

#define SPI2X 0
#define WCOL 6
#define SPIF 7


#endif /* SPI_REGISTERS_H_ */
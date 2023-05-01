/*
 * DIO.h
 *
 * Created: 4/6/2023 8:42:11 PM
 *  Author: youss
 */ 


#ifndef DIO_H_
#define DIO_H_

// includes 
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manibulation.h"
// all internal typedefs for DIO 

// all macros 
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'
// direction 
#define IN 0
#define OUT 1
// values 
#define LOW 0
#define HIGH 1
// function prototypes 

void DIO_init(uint8_t portNumber,uint8_t pinNumber,uint8_t direction); // init pin direction 

void DIO_write(uint8_t portNumber,uint8_t pinNumber,uint8_t value);//write data

void DIO_toggle(uint8_t portNumber,uint8_t pinNumber); // toggle values 

void DIO_read(uint8_t portNumber,uint8_t pinNumber, uint8_t * data); // read data


#endif /* DIO_H_ */
/*
 * EEPROM.h
 *
 * Created: 2023-05-05 6:03:44 PM
 *  Author: HAZEM-PC
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_


#include "../../Utilities/Std_Types.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define ERROR	0
#define E_SUCCESS 1

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

uint8 EEPROM_writeByte(uint32 u16addr,uint8 u8data);
uint8 EEPROM_readByte(uint32 u16addr,uint8 *u8data);



#endif /* EEPROM_H_ */
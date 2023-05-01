/*
 * Keypad.h
 *
 *  Created on: Apr 20, 2023
 *      Author: HAZEM-PC
 */


#ifndef KEYPAD_H_
#define KEYPAD_H_

/*******************************************************************************
 *                             FILE INCLUSION                                  *
 *******************************************************************************/
#include "../../MCAL/DIO/GPIO.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Keypad configurations for number of rows and columns */
#define KEYPAD_NUM_COLS                  3
#define KEYPAD_NUM_ROWS                  3

/* Keypad Port Configurations */
#define KEYPAD_PORT_ID                   PORTC_ID

#define KEYPAD_FIRST_ROW_PIN_ID           PIN2
#define KEYPAD_FIRST_COLUMN_PIN_ID        PIN5

/* Keypad button logic configurations */
#define KEYPAD_BUTTON_PRESSED            LOGIC_LOW


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Get the Keypad pressed button
 */
uint8 KEYPAD_getPressedKey(void);

#endif /* KEYPAD_H_ */

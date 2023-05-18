

#ifndef KEYPAD_H_
#define KEYPAD_H

/*******************************************************************************
 *                             FILE INCLUSION                                  *
 *******************************************************************************/

#include "../../utilities/types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Keypad configurations for number of rows and columns */
#define KEYPAD_NUM_COLS                  3
#define KEYPAD_NUM_ROWS                  3

/* Keypad Port Configurations */
#define KEYPAD_PORT_ID                   PORT_A

#define KEYPAD_FIRST_ROW_PIN_ID           PINA5
#define KEYPAD_FIRST_COLUMN_PIN_ID        PINA2

/* Keypad button logic configurations */
#define KEYPAD_BUTTON_PRESSED            DIO_HIGH

#define KPD_NO_KEY_PRESSED 12

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Get the Keypad pressed button
 */
uint8 KEYPAD_getPressedKey(void);

#endif /* KEYPAD_H_ */

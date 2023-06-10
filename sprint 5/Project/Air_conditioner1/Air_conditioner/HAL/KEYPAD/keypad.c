/*
 * Keypad.c
 *
 *  Created on: Apr 20, 2023
 *      Author: HAZEM-PC
 */

/*******************************************************************************
 *                             FILE INCLUSION                                  *
 *******************************************************************************/
#include "../../Utilities/Common_Macros.h"
#include "keypad.h"

/*******************************************************************************
 *                      Functions Prototypes(Private)                          *
 *******************************************************************************/

static uint8 KEYPAD_3x3_adjustKeyNumber(uint8 button_number);

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
uint8 KEYPAD_getPressedKey(void)
{
	uint8 col,row,value;
	uint8 keypad_port_value = 0;
	while(1)
	{
		for(col=0;col<KEYPAD_NUM_COLS;col++) /* loop for columns */
		{
			/* 
			 * Each time setup the direction for all keypad port as input pins,
			 * except this column will be output pin
			 */
			GPIO_setPortDirection(KEYPAD_PORT_ID,PORT_INPUT);
			GPIO_setPinDirection(KEYPAD_PORT_ID,KEYPAD_FIRST_COLUMN_PIN_ID+col,PIN_OUTPUT);
			
#if(KEYPAD_BUTTON_PRESSED == LOGIC_LOW)
			/* Clear the column output pin and set the rest pins value */
			keypad_port_value = ~(1<<(KEYPAD_FIRST_COLUMN_PIN_ID+col));
#else
			/* Set the column output pin and clear the rest pins value */
			keypad_port_value = (1<<(KEYPAD_FIRST_COLUMN_PIN_ID+col));
#endif
			GPIO_writePort(KEYPAD_PORT_ID,keypad_port_value);

			for(row=0;row<KEYPAD_NUM_ROWS;row++) /* loop for rows */
			{
				/* Check if the switch is pressed in this row */
				GPIO_readPin(KEYPAD_PORT_ID,row+KEYPAD_FIRST_ROW_PIN_ID,&value);
				if(value == KEYPAD_BUTTON_PRESSED)
				{
					return KEYPAD_3x3_adjustKeyNumber((row*KEYPAD_NUM_COLS)+col+1);
				}
			}
		}
		return 0;
		
	}	
}


static uint8 KEYPAD_3x3_adjustKeyNumber(uint8 button_number)
{
	uint8 keypad_button = 0;
	switch(button_number)
	{
		case 1: keypad_button = 1;
				break;
		case 2: keypad_button = 2;
				break;
		case 3: keypad_button = 3;
				break;
		case 4: keypad_button = 4;
				break;
		case 5: keypad_button = 5;
				break;
		case 6: keypad_button = 6;
				break;
		case 7: keypad_button = 7;
				break;
		case 8: keypad_button = 8;
				break;
		case 9: keypad_button = 9;
				break;
		default: keypad_button = button_number;
				break;
	}
	return keypad_button;
}

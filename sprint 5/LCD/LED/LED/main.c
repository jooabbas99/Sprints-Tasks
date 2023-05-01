/*
 * LED.c
 *
 * Created: 4/17/2023 1:59:52 PM
 * Author : youss
 */ 

#include <avr/io.h>
#include "LCD/LCD_interface.h"

int main(void)
{
	LCD_Init();			/* Initialize LCD */

	LCD_String("ElectronicWINGS");	/* write string on 1st line of LCD*/
	LCD_Command(0xC0);		/* Go to 2nd line*/
	LCD_String("Hello World");	/* Write string on 2nd line*/

	return 0;
}


/*
 * LCD.c
 *
 * Created: 4/19/2023 5:11:58 PM
 * Author : youss
 */ 

#include <avr/io.h>

#include "LCD/LCD_interface.h"
int main(void)
{
    /* Replace with your application code */
	LCD_vidInit();
	LCD_vidWriteCharctr('H');
    while (1) 
    {
    }
}


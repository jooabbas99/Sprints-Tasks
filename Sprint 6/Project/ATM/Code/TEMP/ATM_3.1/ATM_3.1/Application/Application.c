/*
 * CFile1.c
 *
 * Created: 4/25/2023 5:46:57 PM
 *  Author: youss
 */ 

// GLOBAL VARS 
#include "Application.h"

#include "../HAL/KEYPAD/keypad.h"
#include "../HAL/LCD/lcd.h"
#include "../HAL/Buzzer/buzzer.h"
#include "../MCAL/TIMER_0/TIMER_0.h"



void AppInit(){

	LCD_init();
	
	LCD_clearScreen();
	LCD_displayStringRowColumn(0,4,"welcome");
	Timer0_Delay(1000);
	LCD_displayStringRowColumn(1,0,"default temp=");
	
}
void AppStart(){

	
}

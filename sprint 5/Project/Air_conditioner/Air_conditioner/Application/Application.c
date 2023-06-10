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
#include "../HAL/Temp_sensor/LM35.h"
#include "../HAL/LED/LED.h"
#include "../MCAL/TIMER_0/TIMER_0.h"
#define DEFAULT_TEMP 25
#define MAX_TEMP   35
#define MIN_TEMP   18

uint8 current_temp ;
uint8 target_temp ;
uint8 buffer;
uint8 is_workinig;

void setMode(void);
void resetMode(void);
void resetMode(){
	LCD_clearScreen();
	LCD_displayStringRowColumn(0,0,"TEMP IS RESETED ");
	LCD_moveCursor(1,4);
	LCD_intgerToString(DEFAULT_TEMP);
	target_temp = DEFAULT_TEMP;
	buffer = target_temp;
	Timer0_Delay(1000);
	
}


void setMode(){

	uint8 key,label_size = (buffer - 18);
	uint8 label[16]=">>>>>>>>>>>>>>>>";
	LCD_clearScreen();
	LCD_displayStringRowColumn(0,0,"MIN=");
	LCD_moveCursor(0,4);
	LCD_intgerToString(MIN_TEMP);
	
	LCD_moveCursor(0,7);
	LCD_intgerToString(buffer);
	
	LCD_displayStringRowColumn(0,10,"MAX=");
	LCD_moveCursor(0,14);
	LCD_intgerToString(MAX_TEMP);
	LCD_moveCursor(1,0);
	for(int i=0;i<label_size;i++)
		LCD_displayCharacter(label[i]);
	
	key = KEYPAD_getPressedKey();
	// check number 1,2,3
	switch(key){
		case 1 : // incremnt 
			buffer ++ ;
			setMode();
		break;
		case 2: // decrement
			buffer -- ;
			setMode();
		break;
		case 3 : // set mode 
			target_temp = buffer;
			return;
		break;
		default: // error
			setMode();
		break;
	}
	
	
	
}


void AppInit(){
	target_temp = DEFAULT_TEMP;
	buffer = target_temp;
	LCD_init();
	ADC_init(AVCC,F_8);
	LED_init(PORTB_ID,PIN3);
	// init current temp for first time
	
	Timer0_Delay(10);
	// welcome display
	LCD_clearScreen();
	LCD_displayStringRowColumn(0,4,"welcome");
	Timer0_Delay(1000);
	LCD_displayStringRowColumn(1,0,"default temp=");
	LCD_moveCursor(1,14);
	LCD_intgerToString(DEFAULT_TEMP);
	Timer0_Delay(1000);
	current_temp = LM35_getTemperature(ADC0);
	LCD_clearScreen();
	LCD_displayStringRowColumn(0,0,"Current Temp");
	LCD_moveCursor(1,5);
	LCD_intgerToString(current_temp);
	
	Timer0_Delay(1000);
	if (current_temp <= target_temp ){
		is_workinig = 0;
	}else{
		is_workinig = 1;
	}
	
	// start working 
	if (!is_workinig){
		// start LED 
		LED_digitalwrite(PORTD_ID,PIN0,Low);
	}else{
		LED_digitalwrite(PORTD_ID,PIN0,High);
	}
}
void AppStart(){
	static uint8 p_temp = 0;
	uint8 key;
	// read temp value 
	current_temp = LM35_getTemperature(ADC0);
	if (current_temp- p_temp != 0){
		p_temp = current_temp;
		if (current_temp <= target_temp ){
			is_workinig = 0;
			}else{
			is_workinig = 1;
		}
		LCD_clearScreen();
		LCD_displayStringRowColumn(0,0,"C=");
		LCD_moveCursor(0,2);
		LCD_intgerToString(current_temp);
		LCD_displayStringRowColumn(0,6,"S=");
		LCD_moveCursor(0,8);
		LCD_intgerToString(target_temp);
		if (!is_workinig){
			// start LED
			LED_digitalwrite(PORTD_ID,PIN0,Low);
			}else{
			LED_digitalwrite(PORTD_ID,PIN0,High);
		}
		if(is_workinig){
			LCD_displayStringRowColumn(0,12,"S=ON");
			} else {
			LCD_displayStringRowColumn(0,11,"S=OFF");
		}
		LCD_displayStringRowColumn(1,0,"4-SET    5-RESET");	
	}
		// keypad status
		key = KEYPAD_getPressedKey();
		// check button pressed 
		
		// case 1 => 4 SET MODE 
		switch(key){
			case 4:
			//setMode
			setMode();
			break;
			case 5:
				resetMode();
			break;
			
		}
		
		// case 2 => 5 
		
		
	// check if any key is pressed 
	
}

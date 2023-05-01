/*
 * Air_conditioner.c
 *
 * Created: 2023-04-22 8:22:20 AM
 * Author : HAZEM-PC
 */ 

#include "HAL/KEYPAD/keypad.h"
#include "HAL/LCD/lcd.h"
#include "MCAL/DIO/GPIO.h"
#include "MCAL/TIMER_0/TIMER_0.h"
#include "HAL/Temp_sensor/LM35.h"
#include "avr/interrupt.h"

void event(void);


int main()
{
	uint8 key=0;
	LCD_init();
	ADC_init(AVCC,F_8);
	SREG  |= (1<<7);
	LCD_displayString("Welcome To LCD");
	LCD_displayStringRowColumn(1,0,"4 Bits Data Mode");
	
    while(1)
    {
    	
        key = KEYPAD_getPressedKey();

		
    }

}

void event(void)
{
	GPIO_togglePin(PORTD_ID,PIN7);
}






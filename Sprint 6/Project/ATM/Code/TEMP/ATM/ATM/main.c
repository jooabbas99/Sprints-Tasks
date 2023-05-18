/*
 * ATM.c
 *
 * Created: 5/2/2023 6:46:35 PM
 * Author : Youssef Abbas
 */ 

#include "ECUAL/LCD/lcd.h"
int main(void)
{
    /* Replace with your application code */
	ST_LCD_t lcd ;
	lcd.E_port = PORT_C;
	lcd.RS_port = PORT_C;
	lcd.RW_port = PORT_C;
	lcd.lcd_data_port = PORT_C;
	lcd.RS_pin = PINC1;
	lcd.RS_pin = PINC2;
	lcd.RS_pin = PINC3;
	lcd.lcd_data1_pin = PINC4;
	lcd.lcd_data2_pin = PINC5;
	lcd.lcd_data3_pin = PINC6;
	lcd.lcd_data4_pin = PINC7;
	
	LCD_init(lcd);
	LCD_displayString(lcd,"Hi How Are You");
    while (1) 
    {
		
    }
}


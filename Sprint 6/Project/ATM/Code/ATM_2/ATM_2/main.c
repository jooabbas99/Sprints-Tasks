/*
 * ATM.c
 *
 * Created: 5/2/2023 6:46:35 PM
 * Author : Youssef Abbas
 */ 

#include "ECUAL/LCD/lcd.h"
#include "ECUAL/KEYPAD/keypad.h"
#include "ECUAL/Button/button.h"
#include "MCAL/timer0/timer0.h"

int main(void)
{
    /* Replace with your application code */
	ST_LCD_t lcd ;
	lcd.E_port = PORT_C;
	lcd.RS_port = PORT_C;
	lcd.RW_port = PORT_C;
	lcd.lcd_data_port = PORT_C;
	lcd.RS_pin = PINC1;
	lcd.RW_pin = PINC2;
	lcd.E_pin = PINC3;
	lcd.lcd_data1_pin = PINC4;
	lcd.lcd_data2_pin = PINC5;
	lcd.lcd_data3_pin = PINC6;
	lcd.lcd_data4_pin = PINC7;
	
	// init keypad 
	ST_KPD_t kpd ;
	kpd.cols_port = PORT_A;
	kpd.rows_port = PORT_A;
	kpd.cols_first_pin = PINA2;
	kpd.rows_first_pin = PINA5;
	kpd.number_of_cols = 3;
	kpd.number_of_rows = 3;
	
	KPD_init(kpd);
	BUTTON_init(PORT_D,PIND2);
	LCD_init(lcd);
	LCD_clearScreen(lcd);
	LCD_displayStringRowColumn(lcd,0,4,"welcome");
	uint8_t key;
	while (1) 
    {
		// pressed key 
		//uint8_t key  = KPD_get_pressed_key(kpd);
		key = 2;
		BUTTON_read_zero_enter(PORT_D,PIND2,&key);
		if (key!=2)
		{
					
			LCD_clearScreen(lcd);
			LCD_displayStringRowColumn(lcd,0,4,"Enter Mode");
			LCD_intgerToString(lcd,key);
			Timer0_Delay(2000);
			key = 2;
		}else{
			LCD_clearScreen(lcd);
		}

		//if (key != NO_KEY_PRESSED)
		//{
			//LCD_clearScreen(lcd);
			//LCD_intgerToString(lcd,key);
			//Timer0_Delay(500);
		//}else{
			//LCD_clearScreen(lcd);
		//}
		
    }
}


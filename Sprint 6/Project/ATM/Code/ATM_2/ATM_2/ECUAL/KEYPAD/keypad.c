/*
 * keypad.c
 *
 * Created: 5/4/2023 1:17:17 PM
 *  Author: Youssef Abbas
 */ 
#include "keypad.h"
#include "../../MCAL/timer0/timer0.h"
#include "../../MCAL/DIO/DIO.h"


void KPD_init(ST_KPD_t kpd){
	// set cols as an input
	for (uint8 i = 0 ; i<kpd.number_of_rows;i++)
	{
		dio_init(kpd.rows_port,(kpd.rows_first_pin+i),DIO_IN);
	}
	// set rows as input 
	for (uint8 i = 0 ; i<kpd.number_of_cols;i++)
	{
		dio_init(kpd.cols_port,(kpd.cols_first_pin+i),DIO_OUT);
	}
	
}
void KPD_get_pressed_key(ST_KPD_t kpd,uint8*key){
	uint8 value; // counters
	// cols loops
	*key= KPD_NO_KEY_PRESSED;
	for (uint8 col = 0 ; col < kpd.number_of_cols;col++)
	{
		// activate cols
		
		dio_write_pin(kpd.cols_port,(kpd.cols_first_pin+col),DIO_HIGH);
		// rows loops
		
		for (uint8 row = 0;row<kpd.number_of_rows;row++)
		{
			// get read 
			dio_read_pin(kpd.rows_port,(kpd.rows_first_pin+row),&value);
			// check if button is pressed
			if (value == DIO_HIGH)
			{
				// return key (row_number * numbers_of_cols) + (column number +1)
				*key =  ((row * kpd.number_of_cols) + col + 1);
				return;
			}
			Timer0_Delay(10);
		}
		
		dio_write_pin(kpd.cols_port,(kpd.cols_first_pin+col),DIO_LOW);
		Timer0_Delay(10);
	}
	
	
}
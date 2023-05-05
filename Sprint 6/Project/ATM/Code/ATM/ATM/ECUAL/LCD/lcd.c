/*
 * lcd.c
 *
 * Created: 5/2/2023 9:07:23 PM
 *  Author: Youssef Abbas
 */ 
#include "lcd.h"
#include "../../MCAL/timer0/timer0.h"
#include "../../Utilities/bit_math.h"
#include "../../Utilities/types.h"
#include <stdlib.h>
void LCD_init(ST_LCD_t lcd){
	dio_init(lcd.E_port,lcd.E_pin,DIO_OUT);
	dio_init(lcd.RS_port,lcd.RS_pin,DIO_OUT);
	dio_init(lcd.RW_port,lcd.RW_pin,DIO_OUT);
	dio_init(lcd.lcd_data_port,lcd.lcd_data1_pin,DIO_OUT);
	dio_init(lcd.lcd_data_port,lcd.lcd_data2_pin,DIO_OUT);
	dio_init(lcd.lcd_data_port,lcd.lcd_data3_pin,DIO_OUT);
	dio_init(lcd.lcd_data_port,lcd.lcd_data4_pin,DIO_OUT);
	
	LCD_sendCommand(lcd,LCD_GO_TO_HOME);
	LCD_sendCommand(lcd,LCD_TWO_LINES_FOUR_BITS_MODE); /* use 2-line lcd + 4-bit Data Mode + 5*7 dot display Mode */
	
	LCD_sendCommand(lcd,LCD_CURSOR_OFF); /* cursor off */
	LCD_sendCommand(lcd,LCD_CLEAR_COMMAND); /* clear LCD at the beginning */
}
/*
 * Description :
 * Send the required command to the screen
 */
void LCD_sendCommand(ST_LCD_t lcd,uint8_t command){
	
	dio_write_pin(lcd.RS_port,lcd.RS_pin,DIO_LOW); /* Instruction Mode RS=0 */
	dio_write_pin(lcd.RW_port,lcd.RW_pin,DIO_LOW); /* write data to LCD so RW=0 */
	Timer0_Delay(1);
	dio_write_pin(lcd.E_port,lcd.E_pin,DIO_HIGH); /* write data to LCD so E=1 */
	Timer0_Delay(1);
	// write command
	dio_write_pin(lcd.lcd_data_port,lcd.lcd_data1_pin,READ_BIT(command,0));
	dio_write_pin(lcd.lcd_data_port,lcd.lcd_data2_pin,READ_BIT(command,1));
	dio_write_pin(lcd.lcd_data_port,lcd.lcd_data3_pin,READ_BIT(command,2));
	dio_write_pin(lcd.lcd_data_port,lcd.lcd_data4_pin,READ_BIT(command,3));
	Timer0_Delay(1);
	dio_write_pin(lcd.E_port,lcd.E_pin,DIO_LOW); /* write data to LCD so E=1 */	
}

/*
 * Description :
 * Display the required character on the screen
 */
void LCD_displayCharacter(ST_LCD_t lcd,uint8_t data){
		dio_write_pin(lcd.RS_port,lcd.RS_pin,DIO_LOW); /* Instruction Mode RS=0 */
		dio_write_pin(lcd.RW_port,lcd.RW_pin,DIO_HIGH); /* write data to LCD so RW=1 */
		Timer0_Delay(1);
		dio_write_pin(lcd.E_port,lcd.E_pin,DIO_HIGH); /* write data to LCD so E=1 */
		Timer0_Delay(1);
		// write command
		dio_write_pin(lcd.lcd_data_port,lcd.lcd_data1_pin,READ_BIT(data,0));
		dio_write_pin(lcd.lcd_data_port,lcd.lcd_data2_pin,READ_BIT(data,1));
		dio_write_pin(lcd.lcd_data_port,lcd.lcd_data3_pin,READ_BIT(data,2));
		dio_write_pin(lcd.lcd_data_port,lcd.lcd_data4_pin,READ_BIT(data,3));
		Timer0_Delay(1);
		dio_write_pin(lcd.E_port,lcd.E_pin,DIO_LOW); /* write data to LCD so E=1 */
}

/*
 * Description :
 * Display the required string on the screen
 */
void LCD_displayString(ST_LCD_t lcd,const char *Str){
	uint8_t i = 0;
	while(Str[i] != '\0')
	{
		LCD_displayCharacter(lcd,Str[i]);
		i++;
	}
}

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_moveCursor(ST_LCD_t lcd,uint8_t row,uint8_t col){
	uint8_t lcd_memory_address = 0;
	
	/* Calculate the required address in the LCD DDRAM */
	switch(row)
	{
		case 0:
		lcd_memory_address=col;
		break;
		case 1:
		lcd_memory_address=col+0x40;
		break;
		case 2:
		lcd_memory_address=col+0x10;
		break;
		case 3:
		lcd_memory_address=col+0x50;
		break;
	}
	/* Move the LCD cursor to this specific address */
	LCD_sendCommand(lcd,lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(ST_LCD_t lcd,uint8_t row,uint8_t col,const char *Str){
	LCD_moveCursor(lcd,row,col); /* go to to the required LCD position */
	LCD_displayString(lcd,Str); /* display the string */
}

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_intgerToString(ST_LCD_t lcd,int data){
	  char buff[16]; /* String to hold the ascii result */
	  itoa(data,buff,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
	  LCD_displayString(lcd,buff); /* Display the string */
}

/*
 * Description :
 * Send the clear screen command
 */
void LCD_clearScreen(ST_LCD_t lcd){
	LCD_sendCommand(lcd,LCD_CLEAR_COMMAND); /* Send clear display command */
	
}

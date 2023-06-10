/*
 * LCD.h
 *
 * Created: 4/17/2023 2:09:43 PM
 *  Author: youss
 */ 


#ifndef LCD_H_
#define LCD_H_
#define F_CPU 8000000UL			/* Define CPU Frequency e.g. here 8MHz */

#include <util/delay.h>
#include <avr/io.h>

#define LCD_DATA_PORT PORTC
#define LCD_DATA_DIR DDRC
#define LCD_COMMAND_PORT PORTD
#define LCD_COMMAND_DIR DDRD

#define RS PIND0 /* Define Register Select (data/command reg.)pin */
#define RW PIND1 /* Define Read/Write signal pin */
#define EN PIND3 /* Define Enable signal pin */

#define LCD_Data_Dir DDRC		/* Define LCD data port direction */
#define LCD_Command_Dir DDRD		/* Define LCD command port direction register */
#define LCD_Data_Port PORTC		/* Define LCD data port */
#define LCD_Command_Port DDRD		/* Define LCD data port */


void LCD_8_bit_init(void);
void LCD_8_bit_sendCommand(uint8_t command);
void LCD_8_bit_sendChar(uint8_t data);
void LCD_8_bit_sendString(uint8_t *data);


void LCD_4_bit_init(void);
void LCD_4_bit_sendCommand(uint8_t command);
void LCD_4_bit_sendChar(uint8_t data);
void LCD_4_bit_sendString(uint8_t data);

void LCD_String (char *str);
void LCD_Init (void);
void LCD_String_xy (char row, char pos, char *str);

void LCD_Clear();

#endif /* LCD_H_ */
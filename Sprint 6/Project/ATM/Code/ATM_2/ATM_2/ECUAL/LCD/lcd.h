/*
 * lcd.h
 *
 * Created: 5/2/2023 9:07:31 PM
 *  Author: Youssef Abbas
 */ 


#ifndef LCD_H_
#define LCD_H_


#include "../../mcal/dio/dio.h"

/* LCD Commands */
#define LCD_CLEAR_COMMAND              0x01
#define LCD_GO_TO_HOME                 0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE  0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE   0x28
#define LCD_CURSOR_OFF                 0x0C
#define LCD_CURSOR_ON                  0x0E
#define LCD_SET_CURSOR_LOCATION        0x80



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
typedef struct {
	uint8 RS_port;
	uint8 RW_port;
	uint8 E_port;
	uint8 RS_pin;
	uint8 RW_pin;
	uint8 E_pin;
	uint8 lcd_data_port;
	uint8 lcd_data1_pin;
	uint8 lcd_data2_pin;
	uint8 lcd_data3_pin;
	uint8 lcd_data4_pin;
} ST_LCD_t;

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */

void LCD_init(ST_LCD_t lcd);
/*
 * Description :
 * Send the required command to the screen
 */
void LCD_sendCommand(ST_LCD_t lcd,uint8 command);

/*
 * Description :
 * Display the required character on the screen
 */
void LCD_displayCharacter(ST_LCD_t lcd,uint8 data);

/*
 * Description :
 * Display the required string on the screen
 */
void LCD_displayString(ST_LCD_t lcd,const char *Str);

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_moveCursor(ST_LCD_t lcd,uint8 row,uint8 col);

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(ST_LCD_t lcd,uint8 row,uint8 col,const char *Str);

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_intgerToString(ST_LCD_t lcd,int data);

/*
 * Description :
 * Send the clear screen command
 */
void LCD_clearScreen(ST_LCD_t lcd);


#endif /* LCD_H_ */
/*
 * app.h
 *
 * Created: 2023-05-13 2:56:13 AM
 *  Author: HAZEM-PC
 */ 


#ifndef APP_H_
#define APP_H_

/**********FILE INCLUSION**********/
#include "../MCAL/UART/UART.h"
#include "../HAL/EEPROM/EEPROM.h"
#include "../MCAL/TWI/TWI.h"
#include "../MCAL/DIO/GPIO.h"
#include "../MCAL/SPI/spi.h"

/**********MACRO DEFINITIONS**********/
#define PAN_SIZE				20
#define PIN_SIZE				10
#define PAN_BASE_ADDRESS		0x0100
#define PIN_BASE_ADDRESS		0x0125
#define CARD_STATE_ADDRESS		0x0050
#define PASS_NOT_SET			0xFF
#define PASS_SET				0x00
#define PROGRAMMING_MODE		'1'
#define USER_MODE				'2'
#define NO_OF_ITERATIONS		3
#define SYSTEM_INIT				0x00
#define SYSTEM_SAVE_PASSWORD	0xAA
#define SYSEM_LOCK_STATE		0x44
#define SYSTEM_MENU_STATE		0xBB
#define SYSTEM_USER_STATE		0x88
#define MAX_PAN_SIZE			19
#define MIN_PAN_SIZE			16
#define MAX_PIN_SIZE			4
#define NEW_LINE				'\x0D'


/**********FUNCTION PROTOTYPES**********/
void APP_check_PAN_number(uint8 a[],uint8* a_size,uint8* str,uint8 min,uint8 max);
void APP_check_PIN_number(uint8 a[],uint8* a_size,uint8* str,uint8 max);
uint8 APP_compare_PIN (uint8* pin_1,uint8* pin_2,uint8 pin_size);
void APP_Trigger_signal(void);
void APP_user_mode(void);
void APP_system_menu(void);
void APP_system_init(void);
#endif /* APP_H_ */
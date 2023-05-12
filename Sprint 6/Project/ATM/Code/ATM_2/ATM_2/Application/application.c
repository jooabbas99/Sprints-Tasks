/*
 * application.c
 *
 * Created: 5/6/2023 10:16:26 AM
 *  Author: Youssef Abbas
 */ 


#include "application.h"
#include "../ECUAL/BUTTON/button.h"
#include "../ECUAL/BUZZER/buzzer.h"
#include "../ECUAL/KEYPAD/keypad.h"
#include "../ECUAL/LCD/lcd.h"

#include "../MCAL/timer0/timer0.h"
//#include "../MCAL/INT/INT.h"
#include <avr/interrupt.h>
#include <stdlib.h>

#include "../Utilities/bit_math.h"

/************************************************************************/
/*                              Define Global vars                      */
/************************************************************************/


// LCD 
ST_LCD_t atm_lcd;
// BUZZER 
ST_BUZZER_t buzzer;
// KEYPAD
ST_KPD_t kpd;
// ZERO_ENTER_Btn
ST_PBTN_t zero_enter_btn;
uint8 btn;
// CARD signal trigger
volatile uint8 card_trigger_signal ;
uint8 ATM_STATUS,reset_mode,counter1,btn_value_temp;

uint8 pin[PIN_LENTH];
uint8 PAN_temp,account_status;

ST_accountsDB_t accountsDB[ACCOUNTS_DB_SIZE]={
	{2000.0, RUNNING, "8989374615436850"},
	{1000.0, BLOCKED, "1025358796325690"},
	{1000.0, RUNNING, "9856874521563250"},
	{5000.0, BLOCKED, "1234567891234560"},
	{300.00, RUNNING, "9632569547856965"},
	{1250.0, BLOCKED, "0526842055286340"},
	{1500.5, RUNNING, "4521478332156640"},
	{8000.0, BLOCKED, "3695214854623250"},
	{8000.1, RUNNING, "6523158469753250"},
	{100000.0,BLOCKED,"8956302301546840"}
};
ST_accountsDB_t accountRefrence;
void appInit(void){
	 reset_mode = 0;
	 card_trigger_signal = 0;
	 ATM_STATUS = ATM_NORMAL_MODE;
	// init LCD
	atm_lcd.E_port = PORT_C;
	atm_lcd.E_pin = PINC3;
	atm_lcd.RS_port = PORT_C;
	atm_lcd.RS_pin = PINC1;
	atm_lcd.RW_port = PORT_C;
	atm_lcd.RW_pin = PINC2;
	// data pins
	atm_lcd.lcd_data_port = PORT_C;
	atm_lcd.lcd_data1_pin = PINC4;
	atm_lcd.lcd_data2_pin = PINC5;
	atm_lcd.lcd_data3_pin = PINC6;
	atm_lcd.lcd_data4_pin = PINC7;
	LCD_init(atm_lcd);
	// keypad 
	kpd.cols_port = PORT_A;
	kpd.rows_port = PORT_A;
	kpd.number_of_cols = 3;
	kpd.number_of_rows = 3;
	kpd.cols_first_pin = PINA2;
	kpd.rows_first_pin = PINA5;
	
	KPD_init(kpd);
	// Buzzer
	buzzer.buzzer_port = PORT_D;
	buzzer.buzzer_pin = PIND3;
	buzzer_init(buzzer);
	// button 
	zero_enter_btn.button_port = PORT_D;
	zero_enter_btn.button_pin = PIND2;
	BUTTON_init(zero_enter_btn);
	// init pin as input
	dio_init(PORT_B,PINB2,DIO_IN);
	
	
	// enable INTERRRUPT 
	// enable interrupt mode 
	SET_BIT(MCUCSR,ISC2);
	//enable GICR
	//SET_BIT(GICR,GICR_INT_2);
	SET_BIT(GICR,5);
	SET_BIT(SREG,1);
	sei();
	
}

void idelMenu(void){
	LCD_clearScreen(atm_lcd);
	LCD_displayStringRowColumn(atm_lcd,0,5,"WELCOME");
	// delay 1 second
	Timer0_Delay(1000);
	LCD_clearScreen(atm_lcd);
	LCD_displayString(atm_lcd,"Insert a Card");
	
}

void readNumber(ST_KPD_t a_kpd,ST_PBTN_t a_zero_enter_btn,uint8 *a_key){
	// read numbers from keypad and zero btn 
	uint8 kpd_value ,btn_value; 
	KPD_get_pressed_key(a_kpd,&kpd_value);
	BUTTON_read_zero_enter(a_zero_enter_btn,&btn_value);
	Timer0_Delay(10);
	while(kpd_value ==KPD_NO_KEY_PRESSED && btn_value==BTN_NO_PRESS){
			 KPD_get_pressed_key(a_kpd,&kpd_value);
			 	Timer0_Delay(10);
			 BUTTON_read_zero_enter(a_zero_enter_btn,&btn_value);
				Timer0_Delay(10);
	}
	if (kpd_value != KPD_NO_KEY_PRESSED)
	{
		*a_key=kpd_value;
	} 
	else if (btn_value != BTN_NO_PRESS)
	{
		*a_key = btn_value;
	}
}



// read PAN from CARD MCU
void readPAN(uint8*pan[]);
// check PAN IN DB
uint8 checkPAN(uint8*pan[],ST_accountsDB_t *accRef){
	uint8 count=0,length;
	length=strlen(pan);
	for(int x=0; x < ACCOUNTS_DB_SIZE; x++)
	{
		if(strcmp((const char *)pan ,(const char *)accountsDB[x].primaryAccountNumber) == 0){
			*accRef=accountsDB[x];
			//            memcpy(accountRefrence->primaryAccountNumber,accountsDB[x].primaryAccountNumber,length+1);
			//            accountRefrence->state=accountsDB[x].state;
			return ACC_FOUND;
		}
	}
	return ACC_NOT_FOUNT;
}



void readAmount(float *amount){
	uint8 amount_display[8] = "0000.00";
	LCD_clearScreen(atm_lcd);
	LCD_displayStringRowColumn(atm_lcd,0,3,"ENTER AMOUNT");
	LCD_displayStringRowColumn(atm_lcd,1,3,amount_display);
	for(uint8 i = 0 ; i=<6;i++){
		if (i == 4)
		{
			// skip decimal point 
			i++;
		}
		readNumber(kpd,zero_enter_btn,&amount_display[i]);
		LCD_displayStringRowColumn(atm_lcd,1,(3+i),amount_display);
		Timer0_Delay(10);
	}
	*amount = atof((const char *)amount_display);
}
void appStart(void){	
	if (ATM_STATUS == ATM_BLOKED_MODE)
	{
		LCD_clearScreen(atm_lcd);
		LCD_displayStringRowColumn(atm_lcd,0,3,"OUT FOR MENTENANCE");
		return;	
	}	
	if (reset_mode == 0)
	{
		idelMenu();
		reset_mode = 1;
		return;
	}
	if (card_trigger_signal == CARD_INSERTED)
	{
		LCD_clearScreen(atm_lcd);
		LCD_displayStringRowColumn(atm_lcd,0,3,"CARD Detected");
		LCD_displayStringRowColumn(atm_lcd,1,0,"READING ...");
		// READ PAN NUMBER 
		readPAN(PAN_temp);
		
		// READ PIN
		counter1 = 0;
		uint8 is_pin_correct = 0;
		do{
			if (is_pin_correct == INVALID_PIN && counter1 != 0)
			{
				LCD_clearScreen(atm_lcd);
				LCD_displayStringRowColumn(atm_lcd,0,0,"INVALID Retry");
			}
			else
			{
						
			LCD_clearScreen(atm_lcd);
			LCD_displayStringRowColumn(atm_lcd,0,0,"ENTER YOUR PIN");
			}

			// read PIN
			for (uint8 i = 0;i<PIN_LENTH;i++ )
			{
				readNumber(kpd,zero_enter_btn,&pin[0]);
				LCD_displayStringRowColumn(atm_lcd,1,(5+i),"X");
				Timer0_Delay(50);
			}
					
			// wait for enter
			readNumber(kpd,zero_enter_btn,&btn_value_temp);
			while(btn_value_temp != BTN_ENTER_PRESSED){
				readNumber(kpd,zero_enter_btn,&btn_value_temp);
			}
			// check if PIN is correct
			counter1++;
			//if (counter1 == 1)
			//{
				//is_pin_correct = 0;
			//}
		}while((counter1<2)&&!is_pin_correct);
				
		// check if PIN entered twise wrong
		if (counter1>=2)
		{
			// Turn Alarm ON
			LCD_clearScreen(atm_lcd);
			LCD_displayStringRowColumn(atm_lcd,0,3,"ATM BLOCKED");
			LCD_displayStringRowColumn(atm_lcd,1,0,"INVALIDS TRYS");
			Timer0_Delay(1000);
			buzzer_digitalwrite(buzzer,DIO_HIGH);
			ATM_STATUS = ATM_BLOKED_MODE;
			return;
		}
		
		// read amounts 
		readAmount(float *amount);
		
		
		// check PAN 
		account_status = checkPAN(PAN_temp,&accountRefrence)
		if(account_status == ACC_NOT_FOUNT){
			LCD_clearScreen(atm_lcd);
			LCD_displayStringRowColumn(atm_lcd,0,0,"This is a fraud card");
			// start ALARM
			buzzer_digitalwrite(buzzer,DIO_HIGH);
			ATM_STATUS = ATM_BLOKED_MODE;
			return;
		}
		if(accountRefrence.en_state == BLOCKED){
			LCD_clearScreen(atm_lcd);
			LCD_displayStringRowColumn(atm_lcd,0,0,"This card is stolen");
			// start ALARM
			buzzer_digitalwrite(buzzer,DIO_HIGH);
			ATM_STATUS = ATM_BLOKED_MODE;
			return;
		}
		
		
		// every think is good 
		
		
		
		

		// if it true
		LCD_clearScreen(atm_lcd);
		LCD_displayStringRowColumn(atm_lcd,0,3,"OK");
		Timer0_Delay(1000);
	}
}


ISR(INT2_vect){
	card_trigger_signal = !card_trigger_signal;
}

/*
 * application.c
 *
 * Created: 5/6/2023 10:16:26 AM
 *  Author: Youssef Abbas
 */ 

/*****************************************************
*               ATM Application Code                  *
******************************************************
* This code implements the functionality of an ATM    *
* (Automated Teller Machine). It allows users to       *
* perform various operations such as inserting a card,*
* entering a PIN, withdrawing money, and checking     *
* account balance.                                   *
*                                                    *
* The code is written in C programming language and    *
* is intended to be used with a specific hardware     *
* setup. It utilizes various peripherals such as an   *
* LCD display, keypad, buzzer, and SPI (Serial       *
* Peripheral Interface) for communication.           *
*                                                    *
* The code is organized into several functions, each  *
* responsible for a specific task. Here's an overview *
* of the main functions:                              *
*                                                    *
* 1. appStart(): This function serves as the entry    *
*    point of the ATM application. It checks the ATM  *
*    status and mode and performs the necessary       *
*    actions based on these conditions.               *
*                                                    *
* 2. idelMenu(): This function displays a welcome     *
*    message on the LCD screen when the ATM is        *
*    idle and waiting for user input.                 *
*                                                    *
* 3. readCardInfo(): This function reads the card     *
*    information (PAN and PIN) from the SPI interface *
*    and stores it in the provided card structure.    *
*                                                    *
* 4. readPIN(): This function reads the PIN entered   *
*    by the user from the keypad and stores it in an  *
*    array. It also displays asterisks on the LCD     *
*    screen to mask the PIN input.                    *
*                                                    *
* 5. checkCardInfo(): This function compares the card *
*    information (PAN and PIN) with the account       *
*    database to verify the card's authenticity. It   *
*    returns the appropriate status based on the      *
*    comparison result.                               *
*                                                    *
* 6. readAmount(): This function reads the desired    *
*    withdrawal amount entered by the user from the   *
*    keypad and displays it on the LCD screen. It     *
*    converts the entered amount to a floating-point  *
*    value and stores it in the provided variable.    *
*                                                    *
* Each function is documented with inline comments    *
* to explain its purpose and the logic behind it.     *
*                                                    *
******************************************************/

#include "application.h"

#include "../utilities/types.h"
#include "../ecual/button/button.h"
#include "../ecual/buzzer/buzzer.h"
#include "../ecual/keypad/keypad.h"
#include "../ecual/lcd/lcd.h"
#include "../mcal/spi/spi.h"
#include "../mcal/timer0/timer0.h"
#include <avr/interrupt.h>
#include <string.h>

#include "../utilities/bit_math.h"

//
// Define Global vars /
//

// LCD
ST_LCD_t atm_lcd;

// BUZZER
ST_BUZZER_t buzzer;

// KEYPAD
ST_KPD_t kpd;

// ZERO_ENTER_Btn
ST_PBTN_t zero_enter_btn;

// Variable to store button value
uint8 btn;

// Volatile variable to indicate the triggering of the card signal
volatile uint8 card_trigger_signal;

// Variables for ATM status, mode, and counters
uint8 ATM_STATUS, atm_mode, counter1, btn_value_temp;

// Array to store the PIN
uint8 pin[PIN_LENTH];

// Temporary variable to store PAN
uint8 PAN_temp;

// Variable to store the status of the account
uint8 account_status;

// Maximum amount limit for transactions
#define MAX_AMOUNT 5000

// Structure for referencing an account
ST_accountsDB_t accountRefrence;

// Initialization of the account database with predefined account information

/*
Account information is initialized using the ST_accountsDB_t structure.
Each account has the following attributes:

Account balance (floating-point value)
Account status (RUNNING or BLOCKED)
PAN (Personal Account Number) as a string
The account information is stored in an array called accountsDB.
*/
ST_accountsDB_t accountsDB[ACCOUNTS_DB_SIZE] = {
	{2000.0, RUNNING, "8989374615436850"},
	{1000.0, BLOCKED, "1025358796325690"},
	{1000.0, RUNNING, "9856874521563250"},
	{5000.0, BLOCKED, "1234567891234560"},
	{300.00, RUNNING, "9632569547856965"},
	{1250.0, BLOCKED, "0526842055286340"},
	{1500.5, RUNNING, "4521478332156640"},
	{8000.0, BLOCKED, "3695214854623250"},
	{8000.1, RUNNING, "6523158469753250"},
	{100000.0, BLOCKED, "8956302301546840"}
};

// Maximum amount limit for transactions
#define MAX_AMOUNT 5000
// Structure for referencing an account
ST_accountsDB_t accountRefrence;


ISR(INT2_vect){
	card_trigger_signal = !card_trigger_signal;
}

void appInit(void){
	// Set the initial ATM mode to FRIST_RUN
	atm_mode = FRIST_RUN;
	// Initialize the card trigger signal to 0
	card_trigger_signal = 0;

	// Set the ATM status to ATM_NORMAL_MODE
	ATM_STATUS = ATM_NORMAL_MODE;

	// Initialize the LCD
	atm_lcd.E_port = PORT_C;
	atm_lcd.E_pin = PINC3;
	atm_lcd.RS_port = PORT_C;
	atm_lcd.RS_pin = PINC1;
	atm_lcd.RW_port = PORT_C;
	atm_lcd.RW_pin = PINC2;
	atm_lcd.lcd_data_port = PORT_C;
	atm_lcd.lcd_data1_pin = PINC4;
	atm_lcd.lcd_data2_pin = PINC5;
	atm_lcd.lcd_data3_pin = PINC6;
	atm_lcd.lcd_data4_pin = PINC7;
	LCD_init(atm_lcd);

	// Initialize the keypad
	kpd.cols_port = PORT_A;
	kpd.rows_port = PORT_A;
	kpd.number_of_cols = 3;
	kpd.number_of_rows = 3;
	kpd.cols_first_pin = PINA2;
	kpd.rows_first_pin = PINA5;
	KPD_init(kpd);

	// Initialize the buzzer
	buzzer.buzzer_port = PORT_D;
	buzzer.buzzer_pin = PIND3;
	buzzer_init(buzzer);

	// Initialize the zero enter button
	zero_enter_btn.button_port = PORT_D;
	zero_enter_btn.button_pin = PIND2;
	BUTTON_init(zero_enter_btn);

	// Initialize the pin as input
	dio_init(PORT_B, PINB2, DIO_IN);

	// Initialize the SPI as a slave
	SPI_initSlave();

	// Enable interrupt for INT2
	SET_BIT(MCUCSR, ISC2);
	SET_BIT(GICR, INT2);
	SET_BIT(SREG, 7);

	// Enable global interrupts
	sei();


}

void idelMenu(void){
	LCD_clearScreen(atm_lcd);
	// Display "WELCOME" in the middle of the first row
	LCD_displayStringRowColumn(atm_lcd, 0, 5, "WELCOME");

	// Delay for 1 second
	Timer0_Delay(1000);

	// Clear the LCD screen
	LCD_clearScreen(atm_lcd);

	// Display "Insert a Card" on the LCD
	LCD_displayString(atm_lcd, "Insert a Card");

	
}

// Function for reading a number from the keypad and zero enter button
void readNumber(ST_KPD_t a_kpd, ST_PBTN_t a_zero_enter_btn, uint8 *a_key){
	// Variables to store the values read from the keypad and zero enter button
	uint8 kpd_value, btn_value;

	// Read the pressed key from the keypad
	KPD_get_pressed_key(a_kpd, &kpd_value);
	Timer0_Delay(50);

	// Read the status of the zero enter button
	BUTTON_read_zero_enter(a_zero_enter_btn, &btn_value);
	Timer0_Delay(20);

	// Wait until a key or the zero enter button is pressed
	while(kpd_value == KPD_NO_KEY_PRESSED && btn_value == BTN_NO_PRESS){
		// Read the pressed key from the keypad
		KPD_get_pressed_key(a_kpd, &kpd_value);
		Timer0_Delay(50);
	
		// Read the status of the zero enter button
		BUTTON_read_zero_enter(a_zero_enter_btn, &btn_value);
		Timer0_Delay(10);
	}

	// If a key is pressed on the keypad, store the key value
	if (kpd_value != KPD_NO_KEY_PRESSED){
		*a_key = kpd_value;
	}
	// If the zero enter button is pressed, store the corresponding key value
	else if (btn_value != BTN_NO_PRESS){
		*a_key = (btn_value == BTN_ZERO_PRESSED ? 0 : BTN_ENTER_PRESSED);
	}

}



// read PIN from User
void readPIN(uint8 *pin[]){
	// Temporary array to store the PIN digits
	uint8 pin_temp[PIN_LENTH];
	// Display "ENTER YOUR PIN" on the LCD
	LCD_clearScreen(atm_lcd);
	LCD_displayStringRowColumn(atm_lcd, 0, 0, "ENTER YOUR PIN");

	// Read the PIN digits
	for (uint8 i = 0; i < PIN_LENTH; i++){
		readNumber(kpd, zero_enter_btn, &pin_temp[i]);
		LCD_displayStringRowColumn(atm_lcd, 1, (5 + i), "X");
	}

	// Wait for the enter button to be pressed
	readNumber(kpd, zero_enter_btn, &btn_value_temp);
	while (btn_value_temp != BTN_ENTER_PRESSED){
		readNumber(kpd, zero_enter_btn, &btn_value_temp);
	}

	// Assign the PIN to the provided pointer
	*pin = pin_temp;

}

// Function for checking the card information
uint8 checkCardInfo(ST_transaction_t *card, uint8 *pin, ST_accountsDB_t *accRef) {
	uint8 count = 0;
	uint8 length;
	
	// Check if the entered PIN matches the card's PIN
	if (strcmp((const char *)card->pin, (const char *)pin) != 0) {
		return INVALID_PIN;
	}

	length = strlen((const char *)card->PAN);

	// Iterate through the accounts database to find a matching PAN
	for (int x = 0; x < ACCOUNTS_DB_SIZE; x++) {
		// Compare the card's PAN with the PAN in the accounts database
		if (strcmp((const char *)card->PAN, (const char *)accRef[x].primaryAccountNumber) == 0) {
			// If a matching PAN is found, assign the account details to the provided pointer
			*accRef = accRef[x];
			return ACC_FOUND;
		}
	}

	// If no matching PAN is found, return ACC_NOT_FOUNT
	return ACC_NOT_FOUNT;

}



// Function for reading the card information
void readCardInfo(ST_transaction_t *card){
	uint8 str_pan[PAN_size] = {0};
	uint8 str_pin[PIN_LENTH] = {0};
	uint8 str_length = 0;
	uint8 i = 0;
	uint8 key = 0;
	// Receive PAN
	while(!str_length){
		str_length = SPI_sendReceiveByte(0xAA);
	}

	for(i = 0; i < str_length; i++){
		str_pan[i] = SPI_SlaveReceive();
		Timer0_Delay(10);
	}

	str_pan[i] = '\0';

	// Receive PIN
	while(key != 0xBB){
		key = SPI_sendReceiveByte(0xFF);
		Timer0_Delay(10);
	}

	for(i = 0; i < PIN_LENTH; i++){
		str_pin[i] = SPI_SlaveReceive();
		Timer0_Delay(10);
	}

	str_pin[i] = '\0';

	// Copy the received PAN and PIN to the card structure
	strncpy((char *)card->PAN, (const char *)str_pan, str_length);
	strncpy((char *)card->pin, (const char *)str_pin, PIN_LENTH);

}

// Function for reading the amount
void readAmount(float *amount){
	uint8 amount_display[8] = "0000.00";
	uint8 num;
	// Clear the LCD screen
	LCD_clearScreen(atm_lcd);

	// Display "ENTER AMOUNT" on the LCD
	LCD_displayStringRowColumn(atm_lcd, 0, 3, "ENTER AMOUNT");
	LCD_displayStringRowColumn(atm_lcd, 1, 3, amount_display);

	// Read each digit of the amount
	for(uint8 i = 0; i <= 6; i++){
		// Skip the position of the decimal point
		if (i == 4){
			i++;
		}
	
		// Read a number from the keypad
		readNumber(kpd, zero_enter_btn, &num);
		amount_display[i] = num + '0';
	
		// Display the updated amount on the LCD
		LCD_displayStringRowColumn(atm_lcd, 1, (3 + i), amount_display);
	}

	// Convert the amount string to float and assign it to the provided pointer
	*amount = atof((const char *)amount_display);

}


// Function for starting the ATM application
void appStart(void){
	uint8 pin_temp[PIN_LENTH], card_status;
	ST_transaction_t card;
	// Check if the ATM is in blocked mode
	if (ATM_STATUS == ATM_BLOKED_MODE){
		LCD_clearScreen(atm_lcd);
		LCD_displayStringRowColumn(atm_lcd, 0, 3, "OUT FOR MAINTENANCE");
		return;
	}

	// Check if it's the first run of the ATM
	if (atm_mode == FRIST_RUN){
		idelMenu();
		atm_mode = NORMAL_MODE;
		return;
	}

	// Check if a card is inserted
	if (card_trigger_signal == CARD_INSERTED){
		LCD_clearScreen(atm_lcd);
		LCD_displayStringRowColumn(atm_lcd, 0, 3, "CARD Detected");
		LCD_displayStringRowColumn(atm_lcd, 1, 0, "READING ...");
		
		// Read card information
		readCardInfo(&card);
		LCD_clearScreen(atm_lcd);
		LCD_displayStringRowColumn(atm_lcd, 0, 3, "OK...");
		Timer0_Delay(1000);
		
		// Read PIN
		counter1 = 0;
		card_status = VALID_PIN;
		do {
			if (card_status == INVALID_PIN && counter1 != 0){
				LCD_clearScreen(atm_lcd);
				LCD_displayStringRowColumn(atm_lcd, 0, 0, "INVALID PIN");
				Timer0_Delay(2000);
			}
			
			// Read PIN
			readPIN(pin_temp);
			
			// Check if PIN is correct
			card_status = checkCardInfo(&card, pin_temp, &accountRefrence);
			counter1++;
			
		} while ((counter1 < 2) && !card_status);
		
		// Check if PIN entered twice wrong
		if (counter1 >= 2){
			// Turn Alarm ON
			LCD_clearScreen(atm_lcd);
			LCD_displayStringRowColumn(atm_lcd, 0, 3, "ATM BLOCKED");
			LCD_displayStringRowColumn(atm_lcd, 1, 0, "INVALID TRIES");
			Timer0_Delay(1000);
			buzzer_digitalwrite(buzzer, DIO_HIGH);
			ATM_STATUS = ATM_BLOKED_MODE;
			return;
		}
		
		if (card_status == ACC_NOT_FOUNT){
			LCD_clearScreen(atm_lcd);
			LCD_displayStringRowColumn(atm_lcd, 0, 0, "This is a fraud card");
			// Start ALARM
			buzzer_digitalwrite(buzzer, DIO_HIGH);
			ATM_STATUS = ATM_BLOKED_MODE;
			return;
		}
		
		if (accountRefrence.en_state == BLOCKED){
			LCD_clearScreen(atm_lcd);
			LCD_displayStringRowColumn(atm_lcd, 0, 0, "This card is stolen");
			// Start ALARM
			buzzer_digitalwrite(buzzer, DIO_HIGH);
			ATM_STATUS = ATM_BLOKED_MODE;
			return;
		}
		
		float amount;
		// Read amount
		readAmount(&amount);
		
		// Check if there is sufficient balance
		if (accountRefrence.balance < amount){
			LCD_clearScreen(atm_lcd);
			LCD_displayStringRowColumn(atm_lcd, 0, 0, "Insufficient funds");
			return;
		}
		
		// Check if the amount exceeds the maximum limit
		if (amount > MAX_AMOUNT){
			LCD_clearScreen(atm_lcd);
			LCD_displayStringRowColumn(atm_lcd, 0, 0, "Maximum limit is exceeded");
			return;
		}
		
		accountRefrence.balance -= amount;
		LCD_clearScreen(atm_lcd);
		LCD_displayStringRowColumn(atm_lcd, 0, 0, "Approved Transaction");
		Timer0_Delay(1000);
		LCD_clearScreen(atm_lcd);
		LCD_displayStringRowColumn(atm_lcd, 0, 0, "Ejecting Card");
		Timer0_Delay(1000);
		card_trigger_signal = CARD_REMOVED;
	}

}



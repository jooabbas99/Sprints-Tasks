/*
 * ATM_project.c
 *
 * Created: 2023-05-04 8:11:51 AM
 * Author : HAZEM-PC
 */ 

/**********FILE INCLUSION**********/
#include "Application/app.h"


/**********MAIN CODE**********/
int main(void)
{
	uint8 u8_iteration_count=0;		//flag indicate Number of iterations for password
	uint8 u8_cardstate;				//used to store the state value of CARD password
	uint8 arr_PAN[PAN_SIZE];
	uint8 arr_PIN1[PIN_SIZE];
	uint8 arr_PIN2[PIN_SIZE];
	uint8 u8_sizePAN=0;				//hold actual PAN size
	uint8 u8_sizePIN1=0;			//hold actual PIN size of first input
	uint8 u8_sizePIN2=0;			//hold actual PIN size of second input
	uint8 u8_i,u8_system_mode=0;

	APP_system_init();

	//check if password_flag set or not
	EEPROM_readByte(CARD_STATE_ADDRESS, &u8_cardstate);
	if(u8_cardstate == PASS_NOT_SET)
	{
		//run programming mode
		APP_check_PAN_number(arr_PAN, &u8_sizePAN,"enter PAN number",MIN_PAN_SIZE,MAX_PAN_SIZE);
		do
		{
			APP_check_PIN_number(arr_PIN1, &u8_sizePIN1, "enter PIN number",MAX_PIN_SIZE);
			APP_check_PIN_number(arr_PIN2, &u8_sizePIN2, "re_enter PIN number",MAX_PIN_SIZE);
			if(APP_compare_PIN(arr_PIN1, arr_PIN2, u8_sizePIN1))
			{
				UART_sendString("password match");
				/* save to EEPROM */
				EEPROM_writeByte(PAN_BASE_ADDRESS-1, u8_sizePAN);				//save PAN size
				Timer0_Delay(10);
				for(u8_i=0;u8_i<u8_sizePAN;u8_i++)								//save PAN number
				{
					EEPROM_writeByte(PAN_BASE_ADDRESS+u8_i, arr_PAN[u8_i]);	
					Timer0_Delay(10);
				}
				EEPROM_writeByte(PIN_BASE_ADDRESS-1, u8_sizePIN1);				//save PIN size
				Timer0_Delay(10);
				for(u8_i=0;u8_i<u8_sizePIN1;u8_i++)								//save PIN number
				{
					EEPROM_writeByte(PIN_BASE_ADDRESS+u8_i, arr_PIN1[u8_i]);
					Timer0_Delay(10);
				}
				EEPROM_writeByte(CARD_STATE_ADDRESS, PASS_SET);					//set password flag
				Timer0_Delay(10);
				GPIO_writePort(PORTA_ID,SYSTEM_SAVE_PASSWORD);					//indicate password is set
				/*RUN USER MODE*/
				APP_Trigger_signal();
				APP_user_mode();
				break;
			}
			else
			{
				UART_sendString("password not match");
				u8_iteration_count++;											//flag indicate iteration count
			}
			UART_sendByte(NEW_LINE);
		}while(u8_iteration_count < NO_OF_ITERATIONS);
		if(u8_iteration_count==NO_OF_ITERATIONS)								//lock state
			GPIO_writePort(PORTA_ID,SYSEM_LOCK_STATE);							//indicate system in LOCK state
	}
	else
	{
		//call system menu
		GPIO_writePort(PORTA_ID,SYSTEM_MENU_STATE);
		APP_system_menu();
		do
		{
			u8_system_mode=UART_recieveByte();
			switch (u8_system_mode)
			{
			case PROGRAMMING_MODE:
				/*run programming mode*/
			{
				APP_check_PAN_number(arr_PAN, &u8_sizePAN,"enter PAN number",MIN_PAN_SIZE,MAX_PAN_SIZE);
				do
				{
					APP_check_PIN_number(arr_PIN1, &u8_sizePIN1, "enter PIN number",MAX_PIN_SIZE);
					APP_check_PIN_number(arr_PIN2, &u8_sizePIN2, "re_enter PIN number",MAX_PIN_SIZE);
					if(APP_compare_PIN(arr_PIN1, arr_PIN2, u8_sizePIN1))
					{
						UART_sendString("password match");
						u8_iteration_count=0;											//flag indicate iteration count
						EEPROM_writeByte(PAN_BASE_ADDRESS-1, u8_sizePAN);				//save PAN size
						Timer0_Delay(10);
						for(u8_i=0;u8_i<u8_sizePAN;u8_i++)								//save to EEPROM
						{
							EEPROM_writeByte(PAN_BASE_ADDRESS+u8_i, arr_PAN[u8_i]);
							Timer0_Delay(10);
						}
						EEPROM_writeByte(PIN_BASE_ADDRESS-1, u8_sizePIN1);				//save PIN size
						Timer0_Delay(10);
						for(u8_i=0;u8_i<u8_sizePIN1;u8_i++)
						{
							EEPROM_writeByte(PIN_BASE_ADDRESS+u8_i, arr_PIN1[u8_i]);
							Timer0_Delay(10);
						}
						EEPROM_writeByte(CARD_STATE_ADDRESS, PASS_SET);					//set password flag
						Timer0_Delay(10);
						GPIO_writePort(PORTA_ID,SYSTEM_SAVE_PASSWORD);					//indicate password is set
						/*RUN USER MODE*/
						APP_Trigger_signal();
						APP_user_mode();
						break;
					}
					else
					{
						UART_sendString("password not match");
						u8_iteration_count++;											//flag indicate iteration count
					}
					UART_sendByte(NEW_LINE);
				}while(u8_iteration_count<NO_OF_ITERATIONS);
				if(u8_iteration_count==NO_OF_ITERATIONS)								//lock state
					GPIO_writePort(PORTA_ID,SYSEM_LOCK_STATE);							//indicate system in LOCK state
			}
			break;
			case USER_MODE:
			{
				/*RUN USER MODE*/
				GPIO_writePort(PORTA_ID,SYSTEM_USER_STATE);								//indicate system in USER mode
				APP_Trigger_signal();
				APP_user_mode();
			}
			break;
			default:
				//wrong input mode
				UART_sendString("wrong input");
				UART_sendByte(NEW_LINE);
				break;
			}
		}while(u8_system_mode != PROGRAMMING_MODE || u8_system_mode != USER_MODE);
	}
}

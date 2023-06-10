/*
 * app.c
 *
 * Created: 2023-05-13 2:56:04 AM
 *  Author: HAZEM-PC
 */ 


#include "app.h"

/*
Description :used to get PAN number from terminal using UART send/receive
Inputs:
arr:array to save PAN number
a_size: size of the array
str: string to display into terminal using UART_sendString
min: minimum size of the PAN number
max maximum size of the PAN number
*/
void APP_check_PAN_number(uint8 arr[],uint8* a_size,uint8* str,uint8 min,uint8 max)
{
	uint8 P_flag=FALSE;										//PAN flag
	uint8 i,j;
	while(!P_flag)
	{
		UART_sendString(str);        						/* Re-send the string to Terminal2 */
		UART_receiveString(arr);   							/* Receive String from Terminal */
		UART_sendByte(NEW_LINE);							//enter ASCII value
		UART_sendString(arr);
		UART_sendByte(NEW_LINE);
		for(j=0;arr[j] != '\0';j++);						//calculate size of the string
		for(i=0;i<j;i++)									//check for numeric numbers only
		{
			if(arr[i] >= '0' && arr[i] <= '9')
			P_flag=TRUE;
			else
			{
				P_flag=FALSE;
				UART_sendString("enter numeric number");
				UART_sendByte(NEW_LINE);
				break;
			}
		}
		if(j >= min && j <= max && P_flag)					//check for input size
		{
			P_flag=TRUE;
		}
		else
		{
			P_flag=FALSE;
			UART_sendString("enter 16-19 digit number");
			UART_sendByte(NEW_LINE);
		}
	}
	*a_size=j;
}

/*
Description :used to get PIN number from terminal using UART send/receive
Inputs:
arr:array to save PIN number
a_size: size of the array
str: string to display into terminal using UART_sendString
max maximum size of the PIN number
*/
void APP_check_PIN_number(uint8 arr[],uint8* a_size,uint8* str,uint8 max)
{
	uint8 P_flag=FALSE;										//PIN flag
	uint8 i,j;
	while(!P_flag)
	{
		UART_sendString(str);        						/* Re-send the string to Terminal2 */
		UART_receiveString(arr);   							/* Receive String from Terminal */
		UART_sendByte(NEW_LINE);								//enter ASCII value
		UART_sendString(arr);
		UART_sendByte(NEW_LINE);
		for(j=0;arr[j] != '\0';j++);						//calculate size of the string
		for(i=0;i<j;i++)									//check for numeric numbers only
		{
			if(arr[i] >= '0' && arr[i] <= '9')
			P_flag=TRUE;
			else
			{
				P_flag=FALSE;
				UART_sendString("enter numeric number");
				UART_sendByte(NEW_LINE);
				break;
			}
		}
		if(j == max && P_flag)								//check for input size
		{
			P_flag=TRUE;
		}
		else
		{
			P_flag=FALSE;
			UART_sendString("enter 4 digit number");
			UART_sendByte(NEW_LINE);
		}
	}
	*a_size=j;
}

/*
Description :used to compare PIN numbers
Inputs:
pin_1:first pin number
pin_2:second pin number
pin_size: size of the PIN number
return:
TRUE: compare match
FALSE: compare not match
*/
uint8 APP_compare_PIN (uint8* pin_1,uint8* pin_2,uint8 pin_size)
{
	uint8 i,flag;
	for(i=0;i<pin_size;i++)
	{
		if(pin_1[i]==pin_2[i])
		flag=TRUE;
		else
		{
			flag=FALSE;
			break;
		}
	}
	return flag;
}

//trigger signal low to high (rising edge)
void APP_Trigger_signal(void)
{
	GPIO_writePin(PORTB_ID,PIN0,Low);
	Timer0_Delay(10);
	GPIO_writePin(PORTB_ID,PIN0,High);
}

void APP_user_mode(void)
{
	uint8 PAN[PAN_SIZE];
	uint8 PIN_1[PIN_SIZE];
	uint8 PIN_2[PIN_SIZE];
	uint8 key=0,i;
	uint8 size_PAN=0;		//hold actual PAN size
	uint8 size_PIN_1=0;		//hold actual PIN size of first input
	uint8 size_PIN_2=0;		//hold actual PIN size of second input
	
	EEPROM_readByte(PAN_BASE_ADDRESS-1, &size_PAN);				//read PAN size
	Timer0_Delay(10);
	for(i=0;i<size_PAN;i++)
	{
		EEPROM_readByte(PAN_BASE_ADDRESS+i, &PAN[i]);
		Timer0_Delay(10);
	}
	EEPROM_readByte(PIN_BASE_ADDRESS-1, &size_PIN_1);			//read PIN size
	_delay_ms(10);
	for(i=0;i<size_PIN_1;i++)
	{
		EEPROM_readByte(PIN_BASE_ADDRESS+i, &PIN_1[i]);
		Timer0_Delay(10);
	}
	
	/*send PAN & PIN numbers using SPI*/
	//first send PAN size
	while(key != 0xAA)
	{
		key=SPI_sendReceiveByte(size_PAN);
		Timer0_Delay(10);
	}
	
	//send PAN number
	key=0;
	
	for(i=0;i<size_PAN;i++)
	{
		key=SPI_sendReceiveByte(PAN[i]);
		Timer0_Delay(10);
	}
	Timer0_Delay(10);
	key=0;
	//send PIN number
	while(key != 0xFF)
	{
		key=SPI_sendReceiveByte(0xBB);
		Timer0_Delay(10);
	}
	for(i=0;i<size_PIN_1;i++)
	{
		SPI_sendReceiveByte(PIN_1[i]);
		Timer0_Delay(10);
	}

}

void APP_system_menu(void)
{
	UART_sendString("system menu");
	UART_sendByte(NEW_LINE);
	UART_sendString("1-programming mode");
	UART_sendByte(NEW_LINE);
	UART_sendString("2-user mode");
	UART_sendByte(NEW_LINE);
}

void APP_system_init(void)
{
	UART_init(9600);								//initialize UART driver with Baud-rate = 9600 bits/sec 
	TWI_init();										//initialize I2C driver
	SPI_initMaster();								//initialize SPI driver
		
	GPIO_setPortDirection(PORTA_ID,PORT_OUTPUT); 	// All PORTD pins are o/p pins used for LED as indication
	GPIO_writePort(PORTA_ID,SYSTEM_INIT);
		
	GPIO_setPinDirection(PORTB_ID,PIN0,PIN_OUTPUT);	//trigger pin direction initialize to output
	GPIO_writePin(PORTB_ID,PIN0,Low);				//trigger pin value initialize to LOW
}
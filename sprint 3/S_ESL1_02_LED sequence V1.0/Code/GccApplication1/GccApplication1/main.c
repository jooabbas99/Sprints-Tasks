/*
 * GccApplication1.c
 *
 * Created: 4/6/2023 11:48:54 AM
 * Author : youss
 */ 

//#include <avr/io.h>

//#include "Utilities/registers.h"
//#include "ECUAL/LED/led.h"

#include "Applicaiton/application.h"
int main(void)
{
    /* Replace with your application code */
	
	// set pin direction 
	// DDRA |= (1<<0);
	//DIO_init(PORT_A,PIN4,OUT);
	//DIO_init(PORT_B,PIN3,OUT);
	
	//LED_init(PORT_A,PIN4);
	AppInit();
    while (1) 
    {
		// make pin high 
		//PORTA |= (1<<0);
		//DIO_write(PORT_A,PIN4,HIGH);
		//DIO_write(PORT_B,PIN3,LOW);
		//LED_on(PORT_A,PIN4);
		
		AppStart();
	
    }
}


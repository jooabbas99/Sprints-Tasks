/*
 * ADV.c
 *
 * Created: 4/24/2023 9:27:01 PM
 * Author : youss
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	// output 
	DDRC = 1;
	DDRD = 1;
	
	// ADC init 
	DDRA &= ~(1<<0);
	
	// channel 0 , single ended , AVCC Ref , R Adjust 
	
	ADMUX |= (1<<6);
	
	// enable ADC with Prescaller , no interrupt 
	ADCSRA |= (1<<7); 
	

    while (1) 
    {
		PORTC = 0;
		PORTD = 0;
		// choose channel to read 
		ADMUX |= (0&0x0F);
		
		// start converstion 
		ADCSRA |= (1<<6);
		// wait for converstion complete flag 
		while ((ADCSRA&(1<<4)) == 0);
		
		//read value 
		PORTC = ADCL;
		PORTD = ADCH;
		
		// convert 
		
		_delay_ms(100);

				
    }
}


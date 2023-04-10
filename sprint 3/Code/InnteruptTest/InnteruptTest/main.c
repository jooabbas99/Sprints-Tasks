/*
 * InnteruptTest.c
 *
 * Created: 4/9/2023 9:59:45 PM
 * Author : youss
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#define NUMBER_OF_LEDS 3 
uint8_t led_number = 0;

int main(void)
{
    /* Replace with your application code */
	// set direction for button interrupt 
	DDRD |= (1<<PIND2);
	
	// set all LED pin To Output
	
	DDRA |= (1<<PINA0);
	DDRA |= (1<<PINA1);
	DDRA |= (1<<PINA2);
	
	// enable global interrupt
	
	sei();
	
	// set to The rising edge of INT0 generates an interrupt request.
	
	MCUCR |= (1<<ISC01) | (1<<ISC00);
	
	// enable GICR
	GICR |= (1<<INT0);
	
	
    while (1) 
    {
		switch(led_number){
			case 0:
				// turn all led's off
				PORTA &= ~(1<<PORTA0);
				PORTA &= ~(1<<PORTA1);
				PORTA &= ~(1<<PORTA2);
				break;
			case 1:
				PORTA |= (1<<PORTA0);
				break;
			case 2:
				PORTA |= (1<<PORTA1);
				break;
			case 3:
				PORTA |= (1<<PORTA2);
				break;
			default:
				// nothing
				break;
				
		}
	}
	
}
ISR(INT0_vect){
	if(led_number < NUMBER_OF_LEDS)
		led_number ++;
	else 
		led_number = 0;
	
}

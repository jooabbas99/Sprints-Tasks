

#define F_CPU 16000000UL
/*============= FILE INCLUSION =============*/
#include "HAL/KEYPAD/keypad.h"
#include "HAL/LCD/lcd.h"
#include "HAL/Temp_sensor/LM35.h"
#include "HAL/LED/LED.h"
#include "MCAL/TIMER_0/TIMER_0.h"
#include "Application/Application.h"


/*============= MAIN CODE =============*/
int main()
{
	AppInit();
	
	while (1)
	{
		AppStart();
	
	}
	
}


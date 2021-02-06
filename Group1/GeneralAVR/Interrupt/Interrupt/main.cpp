/*
 * Interrupt.cpp
 *
 * Created: 19-Jun-17 12:25:44 PM
 * Author : Emancipator
 */ 

#define F_CPU 12000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRC = 0xFF;
	PORTC = 0x00;
	
	//sei();
	//GICR = (1<<INT0);
	
    /* Replace with your application code */
    while (1) 
    {
		PORTC = 0xFF;
		_delay_ms(500);
		PORTC = 0x00;
		_delay_ms(500);
	}
}

/*ISR(INT0_vect)
{
	PORTC = 0xFF;
	_delay_ms(2000);
	PORTC = 0x00;
}*/
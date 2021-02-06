/*
 * PWM0.cpp
 *
 * Created: 08-May-17 7:55:33 PM
 * Author : Emancipator
 */ 
#define F_CPU 12000000
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB  = 0x08;
	PORTB = 0x00;
	
	//      |    Fast PWM mode      |          47KHz        | Inverted
	TCCR0 = (1<<WGM01) | (1<<WGM00) | (0<<CS00) | (1<<CS02) | (1<<COM01);
	
    /* Replace with your application code */
    while (1) 
    {
		// increasing brightness
		for (uint8_t i=0;i<255;i++)
		{
			OCR0 = i;
			_delay_ms(10);
		}
		
		//decreasing brightness
		for (uint8_t j=255;j>0;j--)
		{
			OCR0 = j;
			_delay_ms(10);
		}
    }
}


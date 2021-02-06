/*
 * PIRtest1.cpp
 *
 * Created: 25-Jul-17 11:45:09 AM
 * Author : Emancipator
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


int main(void)
{
	DDRA  = 0xFF;
	PORTA = 0x00;
	
	MCUCR |= (1<<ISC10)|(1<<ISC11);//Rising edge triggered interrupt
	GICR  |= (1<<INT1);            //Interrupt 1
	sei();                         //Enable Global Interrupt
	
    /* Replace with your application code */
    while (1) 
    {
		PORTA = 0x00; 
		_delay_ms(10);
    }
}

ISR(INT1_vect)
{
	PORTA = 0xFF;
	_delay_ms(2000);
}
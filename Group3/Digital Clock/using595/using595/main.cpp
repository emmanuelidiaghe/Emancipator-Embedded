/*
 * using595.cpp
 *
 * Created: 27-Dec-17 1:21:07 PM
 * Author : Emancipator
 */ 
#define F_CPU 16000000
#include <avr/io.h>

#define usingGeneralAVR
#define usingShiftRegister
#define DefaultSet
#define NumOfReg 4

#include "C://Emancipator/Emancipator.h"

HC595 shift;

uint8_t led_pattern[10] = {63,6,91,79,102,109,125,7,127,111};
	
int main(void)
{
	shift.init();
	_delay_ms(200);
	
    /* Replace with your application code */
    while (1) 
    {
		shift.HC595WRITE(led_pattern[5],led_pattern[3],led_pattern[1],led_pattern[6]);
    }
}


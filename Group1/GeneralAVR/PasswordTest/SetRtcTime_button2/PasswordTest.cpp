/*
 * SetRtcTime_button2.cpp
 *
 * Created: 20-Jul-17 10:33:19 AM
 * Author : Emancipator
 */ 
#define F_CPU 16000000
#include <avr/io.h>


/***************************
******LCD_CONGIGURATION*****
***************************/
#define lcdD4Dir DDRA_B0
#define lcdD5Dir DDRA_B1
#define lcdD6Dir DDRA_B2
#define lcdD7Dir DDRA_B3
#define lcdEnDir DDRA_B5
#define lcdRsDir DDRA_B7

#define lcdD4 PORTA_B0
#define lcdD5 PORTA_B1
#define lcdD6 PORTA_B2
#define lcdD7 PORTA_B3
#define lcdEn PORTA_B5
#define lcdRs PORTA_B7

#define usingPort
#define usingLcd
#define usingKeypad4X4

/***************************
****KEYPAD_CONGIGURATION****
***************************/
#define keypadPort           PORTC
#define keypadPortDirection  DDRC

#define keypadRow0 PINC_B0
#define keypadRow1 PINC_B1
#define keypadRow2 PINC_B2
#define keypadRow3 PINC_B3
#define keypadCol0 PINC_B4
#define keypadCol1 PINC_B5
#define keypadCol2 PINC_B6
#define keypadCol3 PINC_B7


#include "C://afrouno/afrouno.h"

lcd display (16, 2);

int key;
char press[20];

char keyPadCode[17] = "123A456B789C*0#D";


int main(void)
{
	delay_ms(50);
	display.init();
	display.clear();
	
	display.writeText(0, 0, "INITIALIZING...");
	display.writeText(1, 0, "Please Wait");
	delay_ms(1500);
	display.clear();
	
    /* Replace with your application code */
    while (1) 
    {
	    display.writeText(0, 1, "KEYPAD TEST...");
	    
	    key = readKeypad4X4();
	    if (key != 255)
		{
		    press[0] = keyPadCode[key];
	
			    display.writeText(1, 0, "pressed:");
			    display.write(1, 9, press[0]);
		    
	    }
    }
}
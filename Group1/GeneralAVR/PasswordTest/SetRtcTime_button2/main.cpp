/*
 * SetRtcTime_button1.cpp
 *
 * Created: 20-Jul-17 10:33:19 AM
 * Author : Emancipator
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <string.h>


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


#define usingLcd
#define usingKeypad4X4
#define usingGeneralAVR

/***************************
****KEYPAD_CONGIGURATION****
***************************/
//0-7 from left to right

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

#include "C://Emancipator/Emancipator.h"

lcd display (16,2);
/***************************
****VARIABLE DECLARATION****
****************************/
int key;
char press;
uint8_t i = 0;
char keyPadCode[17] = "123A456B789C*0#D";
char user[16] = "2017";
char test[16] = "";

int main(void)
{
	delay_ms(50);
	display.init();
	display.clear();
	
	display.writeText(0, 0, "INITIALIZING...");
	display.writeText(1, 0, "Password Test");
	delay_ms(2000);
	display.clear();
	
    /* Replace with your application code */
    while (1) 
    { 
		display.writeText(0,0,"ENTER PASSWORD:");
		key = readKeypad4X4(); 
		 
		if(key != 255)    //If a key on the keypad is pressed
		{
			display.writeText(1,i+6,"*");
			press = keyPadCode[key];
		    test[i] = press;
		    i++;
			_delay_ms(500);
		}
		while(strcmp(test, user)==0)   //While the user inputs the correct password
		{
			display.writeText(0,0,"VERIFYING...    ");
			display.writeText(1,6,"       ");
			for(uint8_t a=0;a<12;a++)
			{
				display.writeText(1,a,".");
				_delay_ms(200);
			}
			display.clear();
			_delay_ms(1000);
			while(1)
			{
				display.writeText(0,4,"VERIFIED");
				display.writeText(1,1,"ACCESS GRANTED!");
				_delay_ms(50);
			}
		    } 
		while(strcmp(test, user)!=0 && i == 4)   //If the user inputs an incorrect password
		{
			display.writeText(0,0,"VERIFYING...    ");
			display.writeText(1,6,"       ");
			for(uint8_t a=0;a<12;a++)
			{
				display.writeText(1,a,".");
				_delay_ms(200);
			}
			display.clear();
			_delay_ms(1000);
			while(1)
			{
				display.writeText(0,0," ACCESS DENIED!");
				display.writeText(1,0,"please reset...");
				_delay_ms(50);
			}
		}
	}
}
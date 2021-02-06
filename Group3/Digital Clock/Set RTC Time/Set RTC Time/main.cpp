/*
 * Real clock.cpp
 *
 * Created: 08-Jun-17 11:17:36 AM
 * Author : Emancipator
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

#define usingGeneralAVR
#define usingSoftI2c

/****** PIN DECLARATION OF THE
**********    RTC    ********/
#define i2cSclDir DDRD_B5
#define i2cSdaDir DDRD_B4
#define i2cSdaPin PIND_B4
#define i2cScl   PORTD_B5
#define i2cSda   PORTD_B4

#include "C:\Emancipator\Emancipator.h"

i2c rtcDs1307(0x68, I2C_8Bit);  //(Address, bit size (RTC)

/*****************************
VARIABLE DECLARATION
*****************************/

int second2, minute2, hour2, day2, date2, month2, year2;

int second1 = 00;
int minute1 = 23;
int hour1   = 18;
int day1    = 03;
int date1   = 24;
int month1  = 10;
int year1   = 17; 


/*********************  This function sets the RTC time to
  04:21:00 PM, July 16,2017  ***************************/
void SetTime(void)
{		
	/*** Converts Decimal to BCD *****/
	second2 =  ((second1/10*16) + (second1%10));       //___second
	minute2 =  ((minute1/10*16) + (minute1%10));      //___minute
	hour2   =  ((hour1/10*16)   +   (hour1%10));     //___hour
	day2    =  ((day1/10*16)    +    (day1%10));    //___day
	date2   =  ((date1/10*16)   +   (date1%10));   //___date
	month2  =  ((month1/10*16)  +  (month1%10));  //___month
	year2   =  ((year1/10*16)   +   (year1%10)); //___year


	/*** Writes time(in BCD) to the
    appropriate addresses of the RTC *****/
	rtcDs1307.writeByte(0x0000, second2);
	rtcDs1307.writeByte(0x0001, minute2);
	rtcDs1307.writeByte(0x0002, hour2);
	rtcDs1307.writeByte(0x0003, day2);
	rtcDs1307.writeByte(0x0004, date2);
	rtcDs1307.writeByte(0x0005, month2);
	rtcDs1307.writeByte(0x0006, year2);
}


int main (void)
{
	rtcDs1307.init(); //Initialize the RTC
	_delay_ms(100);
	
	SetTime();  //Set the RTC
	
	while(1)
	{
		;
	}
		
}
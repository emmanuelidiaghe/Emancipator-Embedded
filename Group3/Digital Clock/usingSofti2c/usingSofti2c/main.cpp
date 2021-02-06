/*
 * usingSofti2c.cpp
 *
 * Created: 04/05/2017 15:07:38
 * Author : YAKMOH
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>

#define usingGeneralAVR
#define usingSoftI2c
#define usingUart
#define usingLcd 

// declare DDR and PORTS of uC as slave
#define i2cSclDir DDRD_B5
#define i2cSdaDir DDRD_B4
#define i2cSdaPin PIND_B4
#define i2cScl   PORTD_B5
#define i2cSda   PORTD_B4

/********   LCD   ********/
#define lcdD4Dir DDRA_B0
#define lcdD5Dir DDRA_B1
#define lcdD6Dir DDRA_B2
#define lcdD7Dir DDRA_B3
#define lcdRsDir DDRA_B7
#define lcdEnDir DDRA_B5

#define lcdD4 PORTA_B0
#define lcdD5 PORTA_B1
#define lcdD6 PORTA_B2
#define lcdD7 PORTA_B3
#define lcdRs PORTA_B7
#define lcdEn PORTA_B5

#include "c://Emancipator/Emancipator.h"

lcd display (16, 2);
uart serial;
//i2c At24C32(0x50, I2C_16Bit); // Address, bit size (EEPROM)
i2c rtcDs1307(0x68, I2C_8Bit);  //Address, bit size (RTC)
uint8_t writeData[28] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
uint8_t readData[32];

uint8_t rtcData[7];
uint8_t rtcTime[9] = "00:00:00";

int main(void)
{
    
	//uint16_t eepromAdd = 0;
	
	display.init();
	serial.init(9600);
	Delay_ms(100);
	
	//At24C32.init();
	rtcDs1307.init();
	
	serial.writeLine("System startup....");
	display.writeText(0,0,"System startup....");
	
	/*serial.writeLine("writing data to EEPROM");
	for(uint8_t i=0; i<27; i++){
		
		At24C32.writeByte( eepromAdd+i, writeData[i]);
		serial.writeText(".");
		Delay_ms(250);
	}

	while(1)
	{
		At24C32.readBytes(eepromAdd, readData, 26 );
		serial.writeText("Read Data: ");
		serial.writeLine( (char *)readData);
		_delay_ms(1000);
	}
}*/
	  
    while (1) 
    {
		     rtcDs1307.readBytes(0x0000, rtcData, 7);
			 
			 /* Conversion steps
			 -BCD to Binary
			 -Binary to ASCII
			 */
			 rtcTime[7] =   ( rtcData[0] & 0b00001111) + 48;
			 rtcTime[6] =  (( rtcData[0] >> 4) & 0b00000111) + 48;
			 
			 rtcTime[4] = ( rtcData[1] & 0b00001111) + 48;
			 rtcTime[3] =  (( rtcData[1] >> 4) & 0b00000111) +48;
			 
			 rtcTime[1] = ( rtcData[2] & 0b00001111) + 48;
			 rtcTime[0] =  (( rtcData[2] >> 4) & 0b00000111) +48;
			 
			 //int second = ((rtcData[0]/16*10) + (rtcData[0]%16));
			 
			 serial.writeText("Time: ");
			 serial.writeLine((char*)rtcTime);
			 display.writeText(0,0,"     TIME:      ");
			 display.writeText(1,4,(char*)rtcTime);
			 //display.writeDec(1,12,second);
			 Delay_ms(1000);
			 //display.clear();
    }
}
	
	
	
	
	
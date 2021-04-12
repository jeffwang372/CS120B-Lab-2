/*	Author: jwang619
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
    /* Insert your solution below */
    	unsigned char tmpPA0 = 0x00;
	unsigned char tmpPA1 = 0x00;
        unsigned char tmpPA2 = 0x00;
	unsigned char tmpPA3 = 0x00;

	unsigned char cntAvail = 0x00;
	while (1) {
		cntAvail = 0x00;
		tmpPA0 = PINA & 0x01;
		tmpPA1 = PINA & 0x02;
		tmpPA2 = PINA & 0x04;
		tmpPA3 = PINA & 0x08;

		if(tmpPA0 == 0x01) {
			++cntAvail;
		}
		if(tmpPA1 == 0x02) {
			++cntAvail;
		}
		if(tmpPA2 == 0x04) {
			++cntAvail;
		}
		if(tmpPA3 == 0x08) {
			++cntAvail;
		}	
		PORTB = cntAvail;
	 }
    return 0;
}

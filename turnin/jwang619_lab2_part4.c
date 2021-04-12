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
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */
    	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
        unsigned char tmpC = 0x00;
	unsigned char total = 0x00;
	unsigned char tmpD = 0x00;
	unsigned char outD = 0x00;

	while (1) {
		tmpA = PINA;
		tmpB = PINB;
		tmpC = PINC;
		total = (tmpA + tmpB + tmpC);
		if(total > 0x8C) {
			tmpD = 0x01;
		}
		if(tmpA > tmpC) {
			if((tmpA - tmpC) > 0x50) {
				tmpD = tmpD | 0x02;
			}
		}
		else {
			if((tmpC - tmpA) > 0x50) {
				tmpD = tmpD | 0x02;
			}
		}
		tmpD = tmpD & 0x03;
		total = total & 0xFC;
		outD = tmpD | total;
		
		PORTD = outD;
 
	 }
    return 0;
}

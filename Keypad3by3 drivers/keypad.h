/*
 * keypad.h
 *
 *  Created on: Sep 7, 2019
 *      Author: USER
 */


// Note that this code works for 3*4 keypad
#ifndef KEYPAD_H_
#define KEYPAD_H_

#define UNINIT -1
// define the port for the seven segment used
#define KEYPAD_PORTROW1 DIO_PORTB
#define KEYPAD_PORTROW2 DIO_PORTB
#define KEYPAD_PORTROW3 DIO_PORTB
#define KEYPAD_PORTROW4 DIO_PORTB

// Inputs
#define KEYPAD_PORTCOL1 DIO_PORTB
#define KEYPAD_PORTCOL2 DIO_PORTB
#define KEYPAD_PORTCOL3 DIO_PORTB

// define the pins for the seven segment used
#define KEYPAD_PINROW1 PIN0
#define KEYPAD_PINROW2 PIN1
#define KEYPAD_PINROW3 PIN2
#define KEYPAD_PINROW4 PIN3
#define KEYPAD_PINCOL1 PIN4
#define KEYPAD_PINCOL2 PIN5
#define KEYPAD_PINCOL3 PIN6


void keypad_init(void);
U8 keypad_display(void);
#endif /* KEYPAD_H_ */

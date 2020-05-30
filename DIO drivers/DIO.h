/*
 * DIO.h
 *
 *  Created on: Aug 31, 2019
 *      Author: USER
 */

#ifndef DIO_H_
#define DIO_H_

// Defining the ports of the uC
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

// Defining the pins of the uC
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

// Defining the input and output
#define INPUT 0
#define OUTPUT 1

// Defining the high and low signal
#define HIGH 1
#define LOW 0


// Defining the functions
U8 DIO_SetPinDirection(U8 Port_number,U8 Pin_number,U8 Direction);
U8 DIO_SetPinPullUp(U8 Port_number,U8 Pin_number);
U8 DIO_SetPinValue(U8 Port_number,U8 Pin_number,U8 Value);
U8 DIO_GetPinValue(U8 Port_number,U8 Pin_number);
U8 DIO_SetPortDirection(U8 Port_number,U8 Direction);
U8 DIO_SetPortPullUp(U8 Port_number,U8 Value);
U8 DIO_SetPortValue(U8 Port_number,U8 Value);
U8 DIO_GetPortValue(U8 Port_number);

#endif /* DIO_H_ */

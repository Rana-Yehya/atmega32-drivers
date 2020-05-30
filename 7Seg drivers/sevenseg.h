/*
 * sevenseg.h
 *
 *  Created on: Sep 6, 2019
 *      Author: USER
 */

#ifndef SEVENSEG_H_
#define SEVENSEG_H_

#define UNINIT -1
#define SEVENSEG_decoder HIGH

#if (SEVENSEG_decoder==LOW)

	// define the port for the seven segment used
	#define SEVENSEG_PORTa UNINIT
	#define SEVENSEG_PORTb UNINIT
	#define SEVENSEG_PORTc UNINIT
	#define SEVENSEG_PORTd UNINIT
	#define SEVENSEG_PORTe UNINIT
	#define SEVENSEG_PORTf UNINIT
	#define SEVENSEG_PORTg UNINIT

	// define the pins for the seven segment used
	#define SEVENSEG_PINa UNINIT
	#define SEVENSEG_PINb UNINIT
	#define SEVENSEG_PINc UNINIT
	#define SEVENSEG_PINd UNINIT
	#define SEVENSEG_PINe UNINIT
	#define SEVENSEG_PINf UNINIT
	#define SEVENSEG_PINg UNINIT

#else
	// define the port for the seven segment used
	#define SEVENSEG_Decoder_PORTA DIO_PORTC
	#define SEVENSEG_Decoder_PORTB DIO_PORTC
	#define SEVENSEG_Decoder_PORTC DIO_PORTC
	#define SEVENSEG_Decoder_PORTD DIO_PORTC

	// define the pins for the seven segment used
	#define SEVENSEG_Decoder_PINA PIN4
	#define SEVENSEG_Decoder_PINB PIN5
	#define SEVENSEG_Decoder_PINC PIN6
	#define SEVENSEG_Decoder_PIND PIN7
	// 0 defines the 1st segment
	// 1 defines the 2st segment
	#define SEVENSEG_PORTEN DIO_PORTC
	#define SEVENSEG_PINEN PIN3

#endif

void sevenseg_init(void);
void sevenseg_display(U8 integer);

#endif /* SEVENSEG_H_ */

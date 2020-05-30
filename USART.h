/*
 * USART.h
 *
 *  Created on: Oct 19, 2019
 *      Author: USER
 */

#ifndef USART_H_
#define USART_H_

//define the mode of operation
#define USART_Asyn 0
#define USART_Syn 1
#define USART_Mode_Select USART_Asyn
#if(USART_Mode_Select == USART_Asyn)
	//define the baud rate in Hz
	/*
	 * 	4800
		9600
		14.4k
		19.2k
		28.8k
		38.4k
		57.6k
		76.8k
		115.2k
		230.4k
		250k
		0.5M
		1M
	*
	*/
	#define USART_Baud_Rate 9600
#else
	// for rising edge in TX and falling edge in RX
	#define USART_Rise_Fall 0
	// for falling edge in TX and rising edge in RX
	#define USART_Fall_Rise 1

	#define USART_Syn_Mode USART_Rise_Fall
#endif

//define if it is Receiver or Transmitter
#define USART_TX 0
#define USART_RX 1
#define USART_Device_Op USART_TX
//#if (USART_Device_Op == USART_TX)
	//define the parity mode
	#define USART_Par_Disable 00
	#define USART_Par_Even 10
	#define USART_Par_Odd 11
	#define USART_Par_Check USART_Par_Disable
	//define the number of stop bit
	#define USART_1_Stop_Bit 0
	#define USART_2_Stop_Bit 1
	#define USART_Stop_Bit USART_1_Stop_Bit
//#endif

// Character size
// 5, 6, 7, 8 or 9 bits
#define USART_Char_Bits 8

//#if (USART_Device_Op == USART_TX)

// Declaring functions

//#endif

void USART_Init();
void USART_Transmit( U8 data );
void USART_Transmit_9_bits( U16 data );
U8 USART_Receive();
U16 USART_Receive_9_bit();


#endif /* USART_H_ */

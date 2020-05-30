/*
 * USART.c
 *
 *  Created on: Oct 19, 2019
 *      Author: USER
 */
#include "Std_types.h"
#include "Register.h"
#include "BitOperation.h"
#include "USART.h"
void USART_Init()
{
	#if(!((USART_Mode_Select==USART_Asyn) || (USART_Mode_Select==USART_Syn)))
	{
		#error"Error in Mode Select for USART"
	}
	#elif(!((USART_Device_Op==USART_TX) || (USART_Device_Op==USART_RX)))
	{
		#error"Error in Selecting TX or RX of USART"
	}
	#elif(!((USART_Char_Bits==5) || (USART_Char_Bits==6)||(USART_Char_Bits==7)||(USART_Char_Bits==8) ||(USART_Char_Bits==9)))
	{
		#error"Error in USART Character bits number"
	}
	#elif(!((USART_Par_Check==USART_Par_Disable) || (USART_Par_Check==USART_Par_Even)|| (USART_Par_Check==USART_Par_Odd)))
	{
		#error"Error in USART Parity Check"
	}
	#elif(!((USART_Stop_Bit==USART_1_Stop_Bit) || (USART_Stop_Bit==USART_2_Stop_Bit)))
	{
		#error"Error in USART Stop bits number"
	}
	#elif((USART_Mode_Select!=USART_Syn)&& (!((USART_Baud_Rate==4800) || (USART_Baud_Rate==9600) || (USART_Baud_Rate==144000) || (USART_Baud_Rate==192000) || (USART_Baud_Rate==288000) || (USART_Baud_Rate== 384000) || (USART_Baud_Rate== 576000) || (USART_Baud_Rate==768000) || (USART_Baud_Rate==115200) || (USART_Baud_Rate==230400) || (USART_Baud_Rate==250000) || (USART_Baud_Rate==500000) || (USART_Baud_Rate==1000000))))
	{
		#error"Error in USART Baud Rate"
	}
	#elif((USART_Mode_Select!=USART_Asyn)&& (!((USART_Syn_Mode==USART_Fall_Rise) || (USART_Syn_Mode==USART_Rise_Fall))))
	{
		#error"Error in USART Clock Edge Declaration"
	}
	#else
	{

		#if(USART_Mode_Select==USART_Asyn)
		{
			SETBIT(UCSRC,7);
			CLRBIT(UCSRC,6);
			CLRBIT(UCSRC,7);
			UBRRL = ((F_CPU)/(USART_Baud_Rate*16)-1);
			UBRRH = ((F_CPU)/(USART_Baud_Rate*16)-1)>>8;
		}
		#else
		{
			SETBIT(UCSRC,7);
			SETBIT(UCSRC,6);
			#if(USART_Syn_Mode==USART_Fall_Rise)
			{
				SETBIT(UCSRC,0);
			}
			#else
			{
				CLRBIT(UCSRC,0);
			}
			#endif
			CLRBIT(UCSRC,7);
			UBRRL = (U8)((F_CPU)/(USART_Baud_Rate*2)-1);
			UBRRH = ((F_CPU)/(USART_Baud_Rate*2)-1)>>8;
		}
		#endif
		SETBIT(UCSRC,7);
		#if (USART_Par_Check==USART_Par_Disable)
		{
			CLRBIT(UCSRC,4);
			CLRBIT(UCSRC,5);
		}
		#elif(USART_Par_Check==USART_Par_Even)
		{
			CLRBIT(UCSRC,4);
			SETBIT(UCSRC,5);
		}
		#else
		{
			SETBIT(UCSRC,4);
			SETBIT(UCSRC,5);
		}
		#endif
		#if (USART_Stop_Bit==USART_1_Stop_Bit)
		{
			CLRBIT(UCSRC,3);
		}
		#else
		{
			SETBIT(UCSRC,3);
		}
		#endif
		#if(USART_Char_Bits==5)
		{
			CLRBIT(UCSRC,1);
			CLRBIT(UCSRC,2);
			CLRBIT(UCSRB,2);

		}
		#elif(USART_Char_Bits==6)
		{
			SETBIT(UCSRC,1);
			CLRBIT(UCSRC,2);
			CLRBIT(UCSRB,2);
		}
		#elif(USART_Char_Bits==7)
		{
			CLRBIT(UCSRC,1);
			SETBIT(UCSRC,2);
			CLRBIT(UCSRB,2);
		}
		#elif(USART_Char_Bits==8)
		{
			SETBIT(UCSRC,1);
			SETBIT(UCSRC,2);
			CLRBIT(UCSRB,2);
		}
		#else
		{
			SETBIT(UCSRC,1);
			SETBIT(UCSRC,2);
			SETBIT(UCSRB,2);
		}
		#endif
		CLRBIT(UCSRC,7);
	}
	#endif
}
void USART_Transmit( U8 data )
{
	SETBIT(UCSRB,3);
	/* Wait for empty transmit buffer */
	while ( !( GETBIT(UCSRA ,5)));
	/* Put data into buffer, sends the data */
	UDR = data;
}
void USART_Transmit_9_bits( U16 data )
{
	SETBIT(UCSRB,3);
	/* Wait for empty transmit buffer */
	// while ( !( UCSRA & (1<<UDRE))) )
	while ( !( GETBIT(UCSRA ,5)));
	/* Copy 9th bit to TXB8 */
	// UCSRB &= ~(1<<TXB8);
	CLRBIT(UCSRB ,0);
	if ( data & 0x0100 )
		SETBIT(UCSRB ,0);
	/* Put data into buffer, sends the data */
	UDR = data;
}
U8 USART_Receive()
{
	SETBIT(UCSRB,4);
	/* Wait for data to be received */
	while ( !( GETBIT(UCSRA ,7)));
	/* Get and return received data from buffer */
	return UDR;
}
U16 USART_Receive_9_bit()
{
	SETBIT(UCSRB,4);
	/* Wait for data to be received */
	while ( !( GETBIT(UCSRA ,7)));
	/* If error, return -1 */
	// if ( status & (1<<FE)|(1<<DOR)|(1<<PE) )
	if ( ( GETBIT(UCSRA ,4))||( GETBIT(UCSRA ,3))||( GETBIT(UCSRA ,2)) )
		return -1;
	/* Filter the 9th bit, then return */
	return ((((UCSRB >> 1) & 0x01) << 8) | UDR);
}

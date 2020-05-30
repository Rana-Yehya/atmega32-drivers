/*
 * sevenseg.c
 *
 *  Created on: Sep 6, 2019
 *      Author: USER
 */
#include "Std_types.h"
#include "Register.h"
#include "BitOperation.h"
#include "DIO.h"
#include "sevenseg.h"
void sevenseg_init(void)
{
#if (SEVENSEG_decoder== LOW)
{
	#if ((SEVENSEG_PORTa==UNINIT)|| (SEVENSEG_PORTb==UNINIT) || (SEVENSEG_PORTc==UNINIT) || (SEVENSEG_PORTd==UNINIT) || (SEVENSEG_PORTe==UNINIT) || (SEVENSEG_PORTf==UNINIT) || (SEVENSEG_PORTg==UNINIT))
	{
		#error"Error in output port declaration"
	}
	#elif((SEVENSEG_PINa==UNINIT)|| (SEVENSEG_PINb==UNINIT) || (SEVENSEG_PINc==UNINIT) || (SEVENSEG_PINd==UNINIT) || (SEVENSEG_PINe==UNINIT) || (SEVENSEG_PINf==UNINIT) || (SEVENSEG_PINg==UNINIT))
	{
		#error"Error in output pin declaration"
	}
	#else
	{
		// Set the directions of the seven segment to output
		DIO_SetPinDirection(SEVENSEG_PORTa,SEVENSEG_PINa,OUTPUT);
		DIO_SetPinDirection(SEVENSEG_PORTb,SEVENSEG_PINb,OUTPUT);
		DIO_SetPinDirection(SEVENSEG_PORTc,SEVENSEG_PINc,OUTPUT);
		DIO_SetPinDirection(SEVENSEG_PORTd,SEVENSEG_PINd,OUTPUT);
		DIO_SetPinDirection(SEVENSEG_PORTe,SEVENSEG_PINe,OUTPUT);
		DIO_SetPinDirection(SEVENSEG_PORTf,SEVENSEG_PINf,OUTPUT);
		DIO_SetPinDirection(SEVENSEG_PORTg,SEVENSEG_PINg,OUTPUT);
	}

	#endif
}
#elif (SEVENSEG_decoder==HIGH)
{
	#if ((SEVENSEG_Decoder_PORTA==UNINIT)|| (SEVENSEG_Decoder_PORTB==UNINIT) || (SEVENSEG_Decoder_PORTC==UNINIT) || (SEVENSEG_Decoder_PORTD==UNINIT))
	{
		#error"Error in output port declaration"
	}
	#elif((SEVENSEG_Decoder_PINA==UNINIT)|| (SEVENSEG_Decoder_PINB==UNINIT) || (SEVENSEG_Decoder_PINC==UNINIT) || (SEVENSEG_Decoder_PIND==UNINIT))
	{
		#error"Error in output pin declaration"
	}
	#elif((SEVENSEG_PORTEN==UNINIT) || (SEVENSEG_PINEN == UNINIT))
	{
		#error"Error in enabling the segment"
	}
	#else
	{
		// Set the directions of the seven segment to output
		DIO_SetPinDirection(SEVENSEG_Decoder_PORTA,SEVENSEG_Decoder_PINA,OUTPUT);
		DIO_SetPinDirection(SEVENSEG_Decoder_PORTB,SEVENSEG_Decoder_PINB,OUTPUT);
		DIO_SetPinDirection(SEVENSEG_Decoder_PORTC,SEVENSEG_Decoder_PINC,OUTPUT);
		DIO_SetPinDirection(SEVENSEG_Decoder_PORTD,SEVENSEG_Decoder_PIND,OUTPUT);

		// Set the enable of the seven segment to output
		DIO_SetPinDirection(SEVENSEG_PORTEN,SEVENSEG_PINEN,OUTPUT);
		DIO_SetPinValue(SEVENSEG_PORTEN,SEVENSEG_PINEN,HIGH);
	}
	#endif
}
#else
	#error "Error in decoder deceleration"
#endif
}

void sevenseg_display(U8 integer)
{
	switch(integer){
		case 0:
		{
			#if (SEVENSEG_decoder==LOW)
			{
				// From a to g
				DIO_SetPinValue(SEVENSEG_PORTa,SEVENSEG_PINa,HIGH);			//a
				DIO_SetPinValue(SEVENSEG_PORTb,SEVENSEG_PINb,HIGH);			//b
				DIO_SetPinValue(SEVENSEG_PORTc,SEVENSEG_PINc,HIGH);			//c
				DIO_SetPinValue(SEVENSEG_PORTd,SEVENSEG_PINd,HIGH);			//d
				DIO_SetPinValue(SEVENSEG_PORTe,SEVENSEG_PINe,HIGH);			//e
				DIO_SetPinValue(SEVENSEG_PORTf,SEVENSEG_PINf,HIGH);			//f
				DIO_SetPinValue(SEVENSEG_PORTg,SEVENSEG_PINg,LOW);			//g
				//DIO_SetPortValue(PORT0,0b01111110);
				break;
			}
			#else
			{
				DIO_SetPinValue(SEVENSEG_Decoder_PORTA,SEVENSEG_Decoder_PINA,LOW);			//a
				DIO_SetPinValue(SEVENSEG_Decoder_PORTB,SEVENSEG_Decoder_PINB,LOW);			//b
				DIO_SetPinValue(SEVENSEG_Decoder_PORTC,SEVENSEG_Decoder_PINC,LOW);			//c
				DIO_SetPinValue(SEVENSEG_Decoder_PORTD,SEVENSEG_Decoder_PIND,LOW);			//d
				break;
			}
			#endif

		}
		case 1:
		{
			#if(SEVENSEG_decoder==LOW)
			{
				// From a to g
				DIO_SetPinValue(SEVENSEG_PORTa,SEVENSEG_PINa,LOW);			//a
				DIO_SetPinValue(SEVENSEG_PORTb,SEVENSEG_PINb,HIGH);			//b
				DIO_SetPinValue(SEVENSEG_PORTc,SEVENSEG_PINc,HIGH);			//c
				DIO_SetPinValue(SEVENSEG_PORTd,SEVENSEG_PINd,LOW);			//d
				DIO_SetPinValue(SEVENSEG_PORTe,SEVENSEG_PINe,LOW);			//e
				DIO_SetPinValue(SEVENSEG_PORTf,SEVENSEG_PINf,LOW);			//f
				DIO_SetPinValue(SEVENSEG_PORTg,SEVENSEG_PINg,LOW);			//g
				//DIO_SetPortValue(PORT0,0b00110000);
				break;
			}
			#else
			{
				DIO_SetPinValue(SEVENSEG_Decoder_PORTA,SEVENSEG_Decoder_PINA,HIGH);			//a
				DIO_SetPinValue(SEVENSEG_Decoder_PORTB,SEVENSEG_Decoder_PINB,LOW);			//b
				DIO_SetPinValue(SEVENSEG_Decoder_PORTC,SEVENSEG_Decoder_PINC,LOW);			//c
				DIO_SetPinValue(SEVENSEG_Decoder_PORTD,SEVENSEG_Decoder_PIND,LOW);			//d
				break;
			}
			#endif


		}
		case 2:
		{
			#if(SEVENSEG_decoder==LOW)
			{
				// From a to g
				DIO_SetPinValue(SEVENSEG_PORTa,SEVENSEG_PINa,HIGH);			//a
				DIO_SetPinValue(SEVENSEG_PORTb,SEVENSEG_PINb,HIGH);			//b
				DIO_SetPinValue(SEVENSEG_PORTc,SEVENSEG_PINc,LOW);			//c
				DIO_SetPinValue(SEVENSEG_PORTd,SEVENSEG_PINd,HIGH);			//d
				DIO_SetPinValue(SEVENSEG_PORTe,SEVENSEG_PINe,HIGH);			//e
				DIO_SetPinValue(SEVENSEG_PORTf,SEVENSEG_PINf,LOW);			//f
				DIO_SetPinValue(SEVENSEG_PORTg,SEVENSEG_PINg,HIGH);			//g
				//DIO_SetPortValue(PORT0,0b01101101);
				break;
			}
			#else
			{
				DIO_SetPinValue(SEVENSEG_Decoder_PORTA,SEVENSEG_Decoder_PINA,LOW);			//a
				DIO_SetPinValue(SEVENSEG_Decoder_PORTB,SEVENSEG_Decoder_PINB,HIGH);			//b
				DIO_SetPinValue(SEVENSEG_Decoder_PORTC,SEVENSEG_Decoder_PINC,LOW);			//c
				DIO_SetPinValue(SEVENSEG_Decoder_PORTD,SEVENSEG_Decoder_PIND,LOW);			//d
				break;
			}
			#endif


		}
		case 3:
		{
			#if(SEVENSEG_decoder==LOW)
			{
				// From a to g
				DIO_SetPinValue(SEVENSEG_PORTa,SEVENSEG_PINa,HIGH);			//a
				DIO_SetPinValue(SEVENSEG_PORTb,SEVENSEG_PINb,HIGH);			//b
				DIO_SetPinValue(SEVENSEG_PORTc,SEVENSEG_PINc,HIGH);			//c
				DIO_SetPinValue(SEVENSEG_PORTd,SEVENSEG_PINd,HIGH);			//d
				DIO_SetPinValue(SEVENSEG_PORTe,SEVENSEG_PINe,LOW);			//e
				DIO_SetPinValue(SEVENSEG_PORTf,SEVENSEG_PINf,LOW);			//f
				DIO_SetPinValue(SEVENSEG_PORTg,SEVENSEG_PINg,HIGH);			//g
				//DIO_SetPortValue(PORT0,0b01111001);
				break;
			}
			#else
			{
				DIO_SetPinValue(SEVENSEG_Decoder_PORTA,SEVENSEG_Decoder_PINA,HIGH);			//a
				DIO_SetPinValue(SEVENSEG_Decoder_PORTB,SEVENSEG_Decoder_PINB,HIGH);			//b
				DIO_SetPinValue(SEVENSEG_Decoder_PORTC,SEVENSEG_Decoder_PINC,LOW);			//c
				DIO_SetPinValue(SEVENSEG_Decoder_PORTD,SEVENSEG_Decoder_PIND,LOW);			//d
				break;
			}
			#endif


		}

		case 4:
		{
			#if(SEVENSEG_decoder==LOW)
			{
				// From a to g
				DIO_SetPinValue(SEVENSEG_PORTa,SEVENSEG_PINa,LOW);			//a
				DIO_SetPinValue(SEVENSEG_PORTb,SEVENSEG_PINb,HIGH);			//b
				DIO_SetPinValue(SEVENSEG_PORTc,SEVENSEG_PINc,HIGH);			//c
				DIO_SetPinValue(SEVENSEG_PORTd,SEVENSEG_PINd,LOW);			//d
				DIO_SetPinValue(SEVENSEG_PORTe,SEVENSEG_PINe,LOW);			//e
				DIO_SetPinValue(SEVENSEG_PORTf,SEVENSEG_PINf,HIGH);			//f
				DIO_SetPinValue(SEVENSEG_PORTg,SEVENSEG_PINg,HIGH);			//g
				//DIO_SetPortValue(PORT0,0b00110011);
				break;
			}
			#else
			{
				DIO_SetPinValue(SEVENSEG_Decoder_PORTA,SEVENSEG_Decoder_PINA,LOW);			//a
				DIO_SetPinValue(SEVENSEG_Decoder_PORTB,SEVENSEG_Decoder_PINB,LOW);			//b
				DIO_SetPinValue(SEVENSEG_Decoder_PORTC,SEVENSEG_Decoder_PINC,HIGH);			//c
				DIO_SetPinValue(SEVENSEG_Decoder_PORTD,SEVENSEG_Decoder_PIND,LOW);			//d
				break;
			}
			#endif

		}
		case 5:
		{
			#if(SEVENSEG_decoder==LOW)
			{
				// From a to g
				DIO_SetPinValue(SEVENSEG_PORTa,SEVENSEG_PINa,HIGH);			//a
				DIO_SetPinValue(SEVENSEG_PORTb,SEVENSEG_PINb,LOW);			//b
				DIO_SetPinValue(SEVENSEG_PORTc,SEVENSEG_PINc,HIGH);			//c
				DIO_SetPinValue(SEVENSEG_PORTd,SEVENSEG_PINd,HIGH);			//d
				DIO_SetPinValue(SEVENSEG_PORTe,SEVENSEG_PINe,LOW);			//e
				DIO_SetPinValue(SEVENSEG_PORTf,SEVENSEG_PINf,HIGH);			//f
				DIO_SetPinValue(SEVENSEG_PORTg,SEVENSEG_PINg,HIGH);			//g
				//DIO_SetPortValue(PORT0,0b01011011);
				break;
			}
			#else
			{
				DIO_SetPinValue(SEVENSEG_Decoder_PORTA,SEVENSEG_Decoder_PINA,HIGH);			//a
				DIO_SetPinValue(SEVENSEG_Decoder_PORTB,SEVENSEG_Decoder_PINB,LOW);			//b
				DIO_SetPinValue(SEVENSEG_Decoder_PORTC,SEVENSEG_Decoder_PINC,HIGH);			//c
				DIO_SetPinValue(SEVENSEG_Decoder_PORTD,SEVENSEG_Decoder_PIND,LOW);			//d
				break;
			}
			#endif

		}
		case 6:
		{
			#if(SEVENSEG_decoder==LOW)
			{
				// From a to g
				DIO_SetPinValue(SEVENSEG_PORTa,SEVENSEG_PINa,HIGH);			//a
				DIO_SetPinValue(SEVENSEG_PORTb,SEVENSEG_PINb,LOW);			//b
				DIO_SetPinValue(SEVENSEG_PORTc,SEVENSEG_PINc,HIGH);			//c
				DIO_SetPinValue(SEVENSEG_PORTd,SEVENSEG_PINd,HIGH);			//d
				DIO_SetPinValue(SEVENSEG_PORTe,SEVENSEG_PINe,HIGH);			//e
				DIO_SetPinValue(SEVENSEG_PORTf,SEVENSEG_PINf,HIGH);			//f
				DIO_SetPinValue(SEVENSEG_PORTg,SEVENSEG_PINg,HIGH);			//g
				//DIO_SetPortValue(PORT0,0b01011111);
				break;
			}
			#else
			{
				DIO_SetPinValue(SEVENSEG_Decoder_PORTA,SEVENSEG_Decoder_PINA,LOW);			//a
				DIO_SetPinValue(SEVENSEG_Decoder_PORTB,SEVENSEG_Decoder_PINB,HIGH);			//b
				DIO_SetPinValue(SEVENSEG_Decoder_PORTC,SEVENSEG_Decoder_PINC,HIGH);			//c
				DIO_SetPinValue(SEVENSEG_Decoder_PORTD,SEVENSEG_Decoder_PIND,LOW);			//d
				break;
			}
			#endif

		}
		case 7:
		{
			#if(SEVENSEG_decoder==LOW)
			{
				// From a to g
				DIO_SetPinValue(SEVENSEG_PORTa,SEVENSEG_PINa,HIGH);			//a
				DIO_SetPinValue(SEVENSEG_PORTb,SEVENSEG_PINb,HIGH);			//b
				DIO_SetPinValue(SEVENSEG_PORTc,SEVENSEG_PINc,HIGH);			//c
				DIO_SetPinValue(SEVENSEG_PORTd,SEVENSEG_PINd,LOW);			//d
				DIO_SetPinValue(SEVENSEG_PORTe,SEVENSEG_PINe,LOW);			//e
				DIO_SetPinValue(SEVENSEG_PORTf,SEVENSEG_PINf,LOW);			//f
				DIO_SetPinValue(SEVENSEG_PORTg,SEVENSEG_PINg,LOW);			//g
				//DIO_SetPortValue(PORT0,0b01110000);
				break;
			}
			#else
			{
				DIO_SetPinValue(SEVENSEG_Decoder_PORTA,SEVENSEG_Decoder_PINA,HIGH);			//a
				DIO_SetPinValue(SEVENSEG_Decoder_PORTB,SEVENSEG_Decoder_PINB,HIGH);			//b
				DIO_SetPinValue(SEVENSEG_Decoder_PORTC,SEVENSEG_Decoder_PINC,HIGH);			//c
				DIO_SetPinValue(SEVENSEG_Decoder_PORTD,SEVENSEG_Decoder_PIND,LOW);			//d
				break;
			}
			#endif

		}
		case 8:
		{
			#if(SEVENSEG_decoder==LOW)
			{
				// From a to g
				DIO_SetPinValue(SEVENSEG_PORTa,SEVENSEG_PINa,HIGH);			//a
				DIO_SetPinValue(SEVENSEG_PORTb,SEVENSEG_PINb,HIGH);			//b
				DIO_SetPinValue(SEVENSEG_PORTc,SEVENSEG_PINc,HIGH);			//c
				DIO_SetPinValue(SEVENSEG_PORTd,SEVENSEG_PINd,HIGH);			//d
				DIO_SetPinValue(SEVENSEG_PORTe,SEVENSEG_PINe,HIGH);			//e
				DIO_SetPinValue(SEVENSEG_PORTf,SEVENSEG_PINf,HIGH);			//f
				DIO_SetPinValue(SEVENSEG_PORTg,SEVENSEG_PINg,HIGH);			//g
				//DIO_SetPortValue(PORT0,0b01111111);
				break;
			}
			#else
			{
				DIO_SetPinValue(SEVENSEG_Decoder_PORTA,SEVENSEG_Decoder_PINA,LOW);			//a
				DIO_SetPinValue(SEVENSEG_Decoder_PORTB,SEVENSEG_Decoder_PINB,LOW);			//b
				DIO_SetPinValue(SEVENSEG_Decoder_PORTC,SEVENSEG_Decoder_PINC,LOW);			//c
				DIO_SetPinValue(SEVENSEG_Decoder_PORTD,SEVENSEG_Decoder_PIND,HIGH);			//d
				break;
			}
			#endif

		}
		case 9:
		{
			#if(SEVENSEG_decoder==LOW)
			{
				// From a to g
				DIO_SetPinValue(SEVENSEG_PORTa,SEVENSEG_PINa,HIGH);			//a
				DIO_SetPinValue(SEVENSEG_PORTb,SEVENSEG_PINb,HIGH);			//b
				DIO_SetPinValue(SEVENSEG_PORTc,SEVENSEG_PINc,HIGH);			//c
				DIO_SetPinValue(SEVENSEG_PORTd,SEVENSEG_PINd,LOW);			//d
				DIO_SetPinValue(SEVENSEG_PORTe,SEVENSEG_PINe,LOW);			//e
				DIO_SetPinValue(SEVENSEG_PORTf,SEVENSEG_PINf,HIGH);			//f
				DIO_SetPinValue(SEVENSEG_PORTg,SEVENSEG_PINg,HIGH);			//g
				//DIO_SetPortValue(PORT0,0b01110011);
				break;
			}
			#else
			{
				DIO_SetPinValue(SEVENSEG_Decoder_PORTA,SEVENSEG_Decoder_PINA,HIGH);			//a
				DIO_SetPinValue(SEVENSEG_Decoder_PORTB,SEVENSEG_Decoder_PINB,LOW);			//b
				DIO_SetPinValue(SEVENSEG_Decoder_PORTC,SEVENSEG_Decoder_PINC,LOW);			//c
				DIO_SetPinValue(SEVENSEG_Decoder_PORTD,SEVENSEG_Decoder_PIND,HIGH);			//d
				break;
			}
			#endif

		}
		default:
		{
			#if(SEVENSEG_decoder==LOW)
			{
				// From a to g
				DIO_SetPinValue(SEVENSEG_PORTa,SEVENSEG_PINa,LOW);			//a
				DIO_SetPinValue(SEVENSEG_PORTb,SEVENSEG_PINb,LOW);			//b
				DIO_SetPinValue(SEVENSEG_PORTc,SEVENSEG_PINc,LOW);			//c
				DIO_SetPinValue(SEVENSEG_PORTd,SEVENSEG_PINd,LOW);			//d
				DIO_SetPinValue(SEVENSEG_PORTe,SEVENSEG_PINe,LOW);			//e
				DIO_SetPinValue(SEVENSEG_PORTf,SEVENSEG_PINf,LOW);			//f
				DIO_SetPinValue(SEVENSEG_PORTg,SEVENSEG_PINg,LOW);			//g

				break;
			}
			#else
			{
				DIO_SetPinValue(SEVENSEG_Decoder_PORTA,SEVENSEG_Decoder_PINA,LOW);			//a
				DIO_SetPinValue(SEVENSEG_Decoder_PORTB,SEVENSEG_Decoder_PINB,LOW);			//b
				DIO_SetPinValue(SEVENSEG_Decoder_PORTC,SEVENSEG_Decoder_PINC,LOW);			//c
				DIO_SetPinValue(SEVENSEG_Decoder_PORTD,SEVENSEG_Decoder_PIND,LOW);			//d
				break;
			}
			#endif

		}
	}
}

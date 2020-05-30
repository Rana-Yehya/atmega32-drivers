/*
 * DIO.c
 *
 *  Created on: Aug 31, 2019
 *      Author: USER
 */

#ifndef DIO_C_
#define DIO_C_

#include "Std_types.h"
#include "DIO.h"
#include "Register.h"
#include "BitOperation.h"

/*
 *	Port Number : 0(A) 1(B) 2(C) 3(D)
 * 	Pin Number : 0 1 2 3 4 5 6 7
 * 	Direction : 0(INPUT) 1(OUTPUT)
 */

U8 DIO_SetPinDirection(U8 Port_number,U8 Pin_number,U8 Direction)
{
	switch (Port_number)
	{
		case DIO_PORTA:
		{
			if(Direction)
			{
				SETBIT(DDRA,Pin_number);
			}
			else
			{
				CLRBIT(DDRA,Pin_number);
			}
			break;
		}
		case DIO_PORTB:
		{
			if(Direction)
			{
				SETBIT(DDRB,Pin_number);
			}
			else
			{
				CLRBIT(DDRB,Pin_number);
			}
			break;
		}
		case DIO_PORTC:
		{
			if(Direction)
			{
				SETBIT(DDRC,Pin_number);
			}
			else
			{
				CLRBIT(DDRC,Pin_number);
			}
			break;
		}
		case DIO_PORTD:
		{
			if(Direction)
			{
				SETBIT(DDRD,Pin_number);
			}
			else
			{
				CLRBIT(DDRD,Pin_number);
			}
			break;
		}
		default : return 0;
	}
	return 1;
}

U8 DIO_SetPinPullUp(U8 Port_number,U8 Pin_number)
{
	CLRBIT(SFIOR,2);
	switch (Port_number)
	{
		case DIO_PORTA:
		{
			SETBIT(PORTA,Pin_number);
			break;
		}
		case DIO_PORTB:
		{
			SETBIT(PORTB,Pin_number);
			break;
		}
		case DIO_PORTC:
		{
			SETBIT(PORTC,Pin_number);
			break;
		}
		case DIO_PORTD:
		{
			SETBIT(PORTD,Pin_number);
			break;
		}
		default : return 0;
	}
	return 1;
}


U8 DIO_SetPinValue(U8 Port_number,U8 Pin_number,U8 Value)
{
	if(!(Value == 1 || Value == 0))
	{
		return 0;
	}
	switch (Port_number)
	{
		case DIO_PORTA:
		{
			if(Value)
			{
				SETBIT(PORTA,Pin_number);
			}
			else
			{
				CLRBIT(PORTA,Pin_number);
			}
			break;
		}
		case DIO_PORTB:
		{
			if(Value)
			{
				SETBIT(PORTB,Pin_number);
			}
			else
			{
				CLRBIT(PORTB,Pin_number);
			}
			break;
		}
		case DIO_PORTC:
		{
			if(Value)
			{
				SETBIT(PORTC,Pin_number);
			}
			else
			{
				CLRBIT(PORTC,Pin_number);
			}
			break;
		}
		case DIO_PORTD:
		{
			if(Value)
			{
				SETBIT(PORTD,Pin_number);
			}
			else
			{
				CLRBIT(PORTD,Pin_number);
			}
			break;
		}
		default : return 0;
	}
	return 1;
}

U8 DIO_GetPinValue(U8 Port_number,U8 Pin_number)
{
	U8 retval=0;
	switch (Port_number)
	{
		case DIO_PORTA:
		{
			retval = GETBIT(PINA,Pin_number);
			break;
		}
		case DIO_PORTB:
		{
			retval = GETBIT(PINB,Pin_number);
			break;
		}
		case DIO_PORTC:
		{
			retval = GETBIT(PINC,Pin_number);
			break;
		}
		case DIO_PORTD:
		{
			retval =GETBIT(PIND,Pin_number);
			break;
		}
		default : return 1;

	}
	return retval;
}
U8 DIO_SetPortDirection(U8 Port_number,U8 Direction)
{
	switch (Port_number)
	{
		case DIO_PORTA:
		{
			DDRA = Direction;
			break;
		}
		case DIO_PORTB:
		{
			DDRB = Direction;
			break;
		}
		case DIO_PORTC:
		{
			DDRC = Direction;
			break;
		}
		case DIO_PORTD:
		{
			DDRD = Direction;
			break;
		}
		default : return 0;
	}
	return 1;
}
U8 DIO_SetPortPullUp(U8 Port_number,U8 Value)
{
	CLRBIT(SFIOR,2);
	switch (Port_number)
	{
		case DIO_PORTA:
		{
			PORTA = Value;
			break;
		}
		case DIO_PORTB:
		{
			PORTB = Value;
			break;
		}
		case DIO_PORTC:
		{
			PORTC = Value;
			break;
		}
		case DIO_PORTD:
		{
			PORTD = Value;
			break;
		}
		default : return 0;
	}
	return 1;
}

U8 DIO_SetPortValue(U8 Port_number,U8 Value)
{
	switch (Port_number)
	{
		case DIO_PORTA:
		{
			//SETBIT(num,bit)
			//SETBIT(num,bit)
			PORTA = Value;
			break;
		}
		case DIO_PORTB:
		{
			PORTB = Value;
			break;
		}
		case DIO_PORTC:
		{
			PORTC = Value;
			break;
		}
		case DIO_PORTD:
		{
			PORTD = Value;
			break;
		}
		default : return 0;
	}
	return 1;
}

U8 DIO_GetPortValue(U8 Port_number)
{
	switch (Port_number)
	{
		case DIO_PORTA:
		{
			return PINA;
			break;
		}
		case DIO_PORTB:
		{
			return PINB;
			break;
		}
		case DIO_PORTC:
		{
			return PINC;
			break;
		}
		case DIO_PORTD:
		{
			return PIND;
			break;
		}
		default : return 0;
	}

}
#endif /* DIO_C_ */

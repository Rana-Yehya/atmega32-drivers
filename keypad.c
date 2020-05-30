/*
 * keypad.c
 *
 *  Created on: Sep 7, 2019
 *      Author: USER
 */
#include "Std_types.h"
#include "BitOperation.h"
#include "DIO.h"
#include "keypad.h"

void keypad_init(void)
{
	#if((KEYPAD_PORTROW1==UNINIT)|| (KEYPAD_PORTROW2==UNINIT) || (KEYPAD_PORTROW3==UNINIT) || (KEYPAD_PORTROW4==UNINIT) || (KEYPAD_PORTCOL1==UNINIT) || (KEYPAD_PORTCOL2==UNINIT) || (KEYPAD_PORTCOL3==UNINIT))
	{
		#error "Error in output port declaration"
	}
	#elif((KEYPAD_PINROW1==UNINIT)|| (KEYPAD_PINROW2==UNINIT) || (KEYPAD_PINROW3==UNINIT) || (KEYPAD_PINROW4==UNINIT) || (KEYPAD_PINCOL1==UNINIT) || (KEYPAD_PINCOL2==UNINIT) || (KEYPAD_PINCOL3==UNINIT))
	{
		#error "Error in output pin declaration"
	}
	#else
	{
		// Set the directions of the seven segment to output
		DIO_SetPinDirection(KEYPAD_PORTROW1,KEYPAD_PINROW1,OUTPUT);
		DIO_SetPinDirection(KEYPAD_PORTROW2,KEYPAD_PINROW2,OUTPUT);
		DIO_SetPinDirection(KEYPAD_PORTROW3,KEYPAD_PINROW3,OUTPUT);
		DIO_SetPinDirection(KEYPAD_PORTROW4,KEYPAD_PINROW4,OUTPUT);

		DIO_SetPinDirection(KEYPAD_PORTCOL1,KEYPAD_PINCOL1,INPUT);
		DIO_SetPinDirection(KEYPAD_PORTCOL2,KEYPAD_PINCOL2,INPUT);
		DIO_SetPinDirection(KEYPAD_PORTCOL3,KEYPAD_PINCOL3,INPUT);


		DIO_SetPinPullUp(KEYPAD_PORTCOL1,KEYPAD_PINCOL1);
		DIO_SetPinPullUp(KEYPAD_PORTCOL2,KEYPAD_PINCOL2);
		DIO_SetPinPullUp(KEYPAD_PORTCOL3,KEYPAD_PINCOL3);
	#endif
	}
}
U8 keypad_display(void)
{
	U8 i = 0, j = 0;
	U8 ROWS[4] = {KEYPAD_PORTROW1,KEYPAD_PORTROW2,KEYPAD_PORTROW3,KEYPAD_PORTROW4};
	U8 COLS[3] = {KEYPAD_PORTCOL1,KEYPAD_PORTCOL2,KEYPAD_PORTCOL3};
	DIO_SetPinValue(KEYPAD_PORTROW2,KEYPAD_PINROW2,HIGH);
	DIO_SetPinValue(KEYPAD_PORTROW3,KEYPAD_PINROW3,HIGH);
	DIO_SetPinValue(KEYPAD_PORTROW4,KEYPAD_PINROW4,HIGH);
	DIO_SetPinValue(KEYPAD_PORTROW1,KEYPAD_PINROW1,HIGH);
	for(i = 0; i < 4; i++)
	{
		DIO_SetPinValue(ROWS[i],i,LOW);
		for(j = 0; j < 3; j++)
		{
			if(DIO_GetPinValue(COLS[j],j+4) == LOW)
			{
				DIO_SetPinValue(ROWS[i],i,HIGH);
				return i*3 + j + 1;
			}
		}
		DIO_SetPinValue(ROWS[i],i,HIGH);
	}
	return 100;

// Another way to implement the keypad
/*
		DIO_SetPinValue(KEYPAD_PORTROW2,KEYPAD_PINROW2,1);
		DIO_SetPinValue(KEYPAD_PORTROW3,KEYPAD_PINROW3,1);
		DIO_SetPinValue(KEYPAD_PORTROW4,KEYPAD_PINROW4,1);
		DIO_SetPinValue(KEYPAD_PORTROW1,KEYPAD_PINROW1,1);

		DIO_SetPinValue(KEYPAD_PORTROW1,KEYPAD_PINROW1,0);
		if(DIO_GetPinValue(KEYPAD_PORTCOL1,KEYPAD_PINCOL1) == LOW){
			DIO_SetPinValue(KEYPAD_PORTROW1,KEYPAD_PINROW1,HIGH);
			return 1;
		}
		else if(DIO_GetPinValue(KEYPAD_PORTCOL2,KEYPAD_PINCOL2) == LOW)
		{
			DIO_SetPinValue(KEYPAD_PORTROW1,KEYPAD_PINROW1,HIGH);
			return 2;
		}
		else if(DIO_GetPinValue(KEYPAD_PORTCOL3,KEYPAD_PINCOL3) == LOW)
		{
			DIO_SetPinValue(KEYPAD_PORTROW1,KEYPAD_PINROW1,HIGH);
			return 3;
		}
		else
		{
			DIO_SetPinValue(KEYPAD_PORTROW1,KEYPAD_PINROW1,HIGH);

		}
		return 0;

		// And the same for the three remaining rows
*/
}

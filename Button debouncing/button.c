/*
 * button.c
 *
 *  Created on: Sep 14, 2019
 *      Author: USER
 */
#include "Std_types.h"
#include "BitOperation.h"
#include "DIO.h"



U8 button(U8 PORT,U8 PIN,U16 MAX)
{
	static U8 val=0;
	static U8 state=0;
	static U16 count=0;
	switch(state)
	{
		// Released
		case 0:
		{
			val = state;
			if(DIO_GetPinValue(PORT,PIN)==1)
			{
				// Pre-pressed
				state = 1;
			}
			break;
		}
		case 1:
		{
			val = state;
			if(DIO_GetPinValue(PORT,PIN)==0)
			{
				// Released
				count = 0;
				state = 0;
			}
			else
			{
				if(count >= MAX)
				{
					// Pressed
					count = 0;
					state = 2;
				}
				else
				{
					count++;
				}
			}

			break;
		}

		case 2:
		{
			val = state;
			if(DIO_GetPinValue(PORT,PIN)==0)
			{
				// Pre-released
				state = 3;
			}
			count++;
			break;
		}
		case 3:
		{
			val = state;
			count = 0;
			if(DIO_GetPinValue(PORT,PIN)==0 && count <MAX)
			{
				// Pressed
				count++;
			}
			else if(count >= MAX)
			{
				// Released
				count = 0;
				state = 0;
			}
			else
			{
				state=2;
			}
			break;
		}

	}
	if(count>0 && state == 2)
	{
		return -1;
	}
	else
	{
		return val;
	}

}

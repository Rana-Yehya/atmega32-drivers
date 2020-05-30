/*
 * LCD.c
 *
 *  Created on: Sep 7, 2019
 *      Author: USER
 */

#include "Std_types.h"
#include "BitOperation.h"
#include "Register.h"
#include "DIO.h"
#include "LCD.h"
#include <util\delay.h>
void LCD_init(void)
{
	#if (PORTDATA == UNINIT)
	{
		#error "Error in data port"
	}
	#elif ( (PORTRS == UNINIT) || (PORTEN == UNINIT) || (PORTRW == UNINIT))
	{
		#error "Error in control ports"
	}
	#elif ( (PINRS == UNINIT) || (PINEN == UNINIT) || (PINRW == UNINIT))
	{
		#error "Error in control pins"
	}
	#else
	{
		DIO_SetPortDirection(PORTDATA,OUTPUT);
		DIO_SetPinDirection(PORTRS,PINRS,OUTPUT);
		DIO_SetPinDirection(PORTEN,PINEN,OUTPUT);
		DIO_SetPinDirection(PORTRW,PINRW,OUTPUT);
		DIO_SetPortDirection(PORTDATA,0xFF);
	}
	#endif
	LCD_init_4bit();

}

void LCD_send_command(U8 command)
{
	//CLRBIT(PORTRS,PINRS);
	DIO_SetPinValue(PORTRS,PINRS,LOW);
	//CLRBIT(PORTRW,PINRW);
	DIO_SetPinValue(PORTRW,PINRW,LOW);
	_delay_ms(2);
	//SETBIT(PORTEN,PINEN);
	DIO_SetPinValue(PORTEN,PINEN,HIGH);
	_delay_ms(2);
	DIO_SetPortValue(PORTDATA,command);
	_delay_ms(2);
	//CLRBIT(PORTEN,PINEN);
	DIO_SetPinValue(PORTEN,PINEN,LOW);
	_delay_ms(2);
	DIO_SetPinValue(PORTRS,PINRS,LOW);
	//CLRBIT(PORTRW,PINRW);
	DIO_SetPinValue(PORTRW,PINRW,LOW);
	_delay_ms(2);
	//SETBIT(PORTEN,PINEN);
	DIO_SetPinValue(PORTEN,PINEN,HIGH);
	_delay_ms(2);
	DIO_SetPortValue(PORTDATA,command<<4);
	_delay_ms(2);
	//CLRBIT(PORTEN,PINEN);
	DIO_SetPinValue(PORTEN,PINEN,LOW);
	_delay_ms(2);
}
void LCD_init_4bit(void)
{/*
	// Clear Display
	LCD_send_command(clear_display & 0xF0);
	LCD_send_command((clear_display<<4) & 0xF0);

	// Return Home
	LCD_send_command(return_home & 0xF0);
	LCD_send_command((return_home<<4) & 0xF0);


*/
	LCD_send_command(0x03);
	_delay_ms(5);

	LCD_send_command(0x03);
	_delay_ms(1);

	LCD_send_command(0x03);
	_delay_ms(5);

	LCD_send_command(LCD_COMMAND_4BIT);
	LCD_send_command(LCD_COMMAND_4BIT_2LINES_5X8);
	LCD_send_command(LCD_COMMAND_CLEARDISP);
	LCD_send_command(LCD_COMMAND_INCADDR_NOSHIFT);
	LCD_send_command(LCD_COMMAND_LCDON_CURSOROF_BLINKOFF);
}
void LCD_send_data(char Char)
{
	//SETBIT(PORTRS,PINRS);
	DIO_SetPinValue(PORTRS,PINRS,1);
	//CLRBIT(PORTRW,PINRW);
	DIO_SetPinValue(PORTRW,PINRW,0);
	_delay_ms(2);
	//SETBIT(PORTEN,PINEN);
	DIO_SetPinValue(PORTEN,PINEN,1);
	_delay_ms(2);
	DIO_SetPortValue(PORTDATA,Char);
	_delay_ms(2);
	//CLRBIT(PORTEN,PINEN);
	DIO_SetPinValue(PORTEN,PINEN,0);
	_delay_ms(2);

	//SETBIT(PORTRS,PINRS);
		DIO_SetPinValue(PORTRS,PINRS,1);
		//CLRBIT(PORTRW,PINRW);
		DIO_SetPinValue(PORTRW,PINRW,0);
		_delay_ms(2);
		//SETBIT(PORTEN,PINEN);
		DIO_SetPinValue(PORTEN,PINEN,1);
		_delay_ms(2);
		DIO_SetPortValue(PORTDATA,Char<<4);
		_delay_ms(2);
		//CLRBIT(PORTEN,PINEN);
		DIO_SetPinValue(PORTEN,PINEN,0);
		_delay_ms(2);
}
void LCD_print_string(char *str)
{
	U16 i=0;
	while(str[i] != '\0')
	{
		LCD_send_data(str[i]);
		i++;
	}
}



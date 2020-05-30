/*
 * LCD.h
 *
 *  Created on: Sep 7, 2019
 *      Author: USER
 */

#ifndef LCD_H_
#define LCD_H_
#include "Std_types.h"
#define UNINIT -1

#define mode 0
// PORT Control
#define PORTRS DIO_PORTB
#define PORTEN DIO_PORTB
#define PORTRW DIO_PORTB

// PIN Control
#define PINRS PIN1
#define PINEN PIN3
#define PINRW PIN2

// Data port
#if mode==0
	#define PORTDATA DIO_PORTA
#else
	#define PORTD4 UNINIT
	#define PORTD5 UNINIT
	#define PORTD6 UNINIT
	#define PORTD7 UNINIT
#endif


#define clear_display 0x01
#define return_home 0x02
#define function_set 0x38
#define display_on 0x0E
#define entry_mode 0x06
#define DDRAM_address 0x00

#define LCD_COMMAND_CLEARDISP 0x01
#define LCD_COMMAND_8BIT_2LINES_5X8	0x38
#define LCD_COMMAND_LCDON_CURSORON_BLINKON 	0x0F
#define LCD_COMMAND_INCADDR_NOSHIFT	0x06

#define LCD_COMMAND_4BIT	0x02
#define LCD_COMMAND_4BIT_2LINES_5X8	0x08
#define LCD_COMMAND_LCDON_CURSOROF_BLINKOFF 0x0C
#define LCD_COMMAND_2ND_LINE	0xC0

void LCD_init(void);

void LCD_send_command(U8 command);

void LCD_send_data(char Char);
void LCD_print_string(char *str);
void LCD_init_4bit(void);

#endif /* LCD_H_ */

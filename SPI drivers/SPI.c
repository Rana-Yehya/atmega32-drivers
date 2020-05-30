/*
 * SPI.c
 *
 *  Created on: Oct 19, 2019
 *      Author: USER
 */
#include "Std_types.h"
#include "Register.h"
#include "BitOperation.h"
#include "DIO.h"
#include "SPI.h"


void SPI_Init(U8 define_the_state_of_controller)
{
	#if(!((SPI_Data_Order==LSB)||(SPI_Data_Order==MSB)))
		#error "Error in Defining the SPI Data Order Declaration"
	#elif(!((SPI_Clock_Rate==4)||(SPI_Clock_Rate==16)||(SPI_Clock_Rate==64)||(SPI_Clock_Rate==128)||(SPI_Clock_Rate==2)||(SPI_Clock_Rate==8)||(SPI_Clock_Rate==32)))
		#error "Error in Defining the SPI Clock Rate Declaration"
	#elif(!((SPI_Mode==00)||(SPI_Mode==01)||(SPI_Mode==10)||(SPI_Mode==11)))
		#error "Error in Defining the SPI Mode Declaration"
	#else
		#if(SPI_Mode==00)
			// Rising or falling
			CLRBIT(SPCR,4);
			// Sample or setup
			CLRBIT(SPCR,3);
		#elif(SPI_Mode==01)
			// Rising or falling
			CLRBIT(SPCR,4);
			// Sample or setup
			SETBIT(SPCR,3);
		#elif(SPI_Mode==10)
			// Rising or falling
			SETBIT(SPCR,4);
			// Sample or setup
			CLRBIT(SPCR,3);
		#else
			// Rising or falling
			SETBIT(SPCR,4);
			// Sample or setup
			SETBIT(SPCR,3);
		#endif
		if(define_the_state_of_controller)
		{
			// Clock Settings
			if(SPI_Clock_Rate==4)
			{
				CLRBIT(SPCR,0);
				CLRBIT(SPCR,1);
				CLRBIT(SPSR,0);
			}
			else if(SPI_Clock_Rate==16)
			{
				SETBIT(SPCR,0);
				CLRBIT(SPCR,1);
				CLRBIT(SPSR,0);
			}
			else if(SPI_Clock_Rate==64)
			{
				CLRBIT(SPCR,0);
				SETBIT(SPCR,1);
				CLRBIT(SPSR,0);
			}
			else if(SPI_Clock_Rate==128)
			{
				SETBIT(SPCR,0);
				SETBIT(SPCR,1);
				CLRBIT(SPSR,0);
			}
			else if(SPI_Clock_Rate==2)
			{
				CLRBIT(SPCR,0);
				CLRBIT(SPCR,1);
				SETBIT(SPSR,0);
			}
			else if(SPI_Clock_Rate==8)
			{
				SETBIT(SPCR,0);
				CLRBIT(SPCR,1);
				SETBIT(SPSR,0);
			}
			else
			{
				CLRBIT(SPCR,0);
				SETBIT(SPCR,1);
				SETBIT(SPSR,0);
			}
			// Enable SPI, Master, set clock rate fck/16
			#if(SPI_DataOrder==LSB)
				SETBIT(SPCR,5);
			#else
				CLRBIT(SPCR,5);
			#endif
			// MOSI
			DIO_SetPinDirection(DIO_PORTB,PIN5,OUTPUT);
			// Clock
			DIO_SetPinDirection(DIO_PORTB,PIN7,OUTPUT);
			// SS
			//DIO_SetPinDirection(DIO_PORTB,PIN4,OUTPUT);
			//DIO_SetPinValue(DIO_PORTB,PIN4,LOW);
			// Master select
			SETBIT(SPCR,4);
			// Enable
			SETBIT(SPCR,6);
		}
		else
		{
			// MISO
			DIO_SetPinDirection(DIO_PORTB,PIN6,OUTPUT);
			// If the controller is slave, then this pin(SS) will be input
			DIO_SetPinDirection(DIO_PORTB,PIN4,INPUT);
			// Enable
			SETBIT(SPCR,6);
		}

	#endif
}

U8 SPI_TransmitReceive(U8 Char, U8 define_the_state_of_controller)
{
	if(define_the_state_of_controller)
	{
		// If the controller is master, then this pin will be output
		DIO_SetPinDirection(DIO_PORTB,PIN4,OUTPUT);
		DIO_SetPinValue(DIO_PORTB,PIN4,LOW);
		SPDR = Char;
		while(!(GETBIT(SPSR,7)));
	}
	else
	{
		DIO_SetPinDirection(DIO_PORTB,PIN4,INPUT);
		while(!(GETBIT(SPSR,7)));
	}
	return SPDR;
}



/*
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define ACK 0x7E
#define LONG_TIME 10000

//Initialize SPI Master Device
void spi_init_master (void)
{
    DDRB = (1<<5)|(1<<3);              //Set MOSI, SCK as Output
    SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0); //Enable SPI, Set as Master
                                       //Prescaler: Fosc/16, Enable Interrupts
}

//Function to send and receive data
unsigned char spi_tranceiver (unsigned char data)
{
    SPDR = data;                       //Load data into the buffer
    while(!(SPSR & (1<<SPIF) ));       //Wait until transmission complete
    return(SPDR);                      //Return received data
}

//Function to blink LED
void led_blink (uint16_t i)
{
    //Blink LED "i" number of times
    for (; i>0; --i)
    {
        PORTD|=(1<<0);
        _delay_ms(100);
        PORTD=(0<<0);
        _delay_ms(100);
    }
}

//Main
int main(void)
{
    spi_init_master();                  //Initialize SPI Master
    DDRD |= 0x01;                       //PD0 as Output

    unsigned char data;                 //Received data stored here
    uint8_t x = 0;                      //Counter value which is sent

    while(1)
    {
        data = 0x00;                    //Reset ACK in "data"
        data = spi_tranceiver(++x);     //Send "x", receive ACK in "data"
        if(data == ACK) {               //Check condition
            //If received data is the same as ACK, blink LED "x" number of times
            led_blink(x);
        }
        else {
            //If received data is not ACK, then blink LED for a long time so as to determine error
            led_blink(LONG_TIME);
        }
        _delay_ms(500);                 //Wait
    }
}
 */


/*
 #ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "lcd.h"

#define ACK 0x7E

void spi_init_slave (void)
{
    DDRB=(1<<6);                                  //MISO as OUTPUT
    SPCR=(1<<SPE);                                //Enable SPI
}

//Function to send and receive data
unsigned char spi_tranceiver (unsigned char data)
{
    SPDR = data;                                  //Load data into buffer
    while(!(SPSR & (1<<SPIF) ));                  //Wait until transmission complete
    return(SPDR);                                 //Return received data
}

int main(void)
{
    lcd_init(LCD_DISP_ON_CURSOR_BLINK);           //Initialize LCD
    spi_init_slave();                             //Initialize slave SPI
    unsigned char data, buffer[10];
    DDRA  = 0x00;                                 //Initialize PORTA as INPUT
    PORTA = 0xFF;                                 //Enable Pull-Up Resistors
    while(1)
    {
        lcd_clrscr();                             //LCD Clear screen
        lcd_home();                               //LCD move cursor to home
        lcd_puts("Testing");
        lcd_gotoxy(0,1);
        data = spi_tranceiver(ACK);               //Receive data, send ACK
        itoa(data, buffer, 10);                   //Convert integer into string
        lcd_puts(buffer);                         //Display received data
        _delay_ms(20);                            //Wait
    }
}
 */

/*
 * Register.h
 *
 *  Created on: Aug 30, 2019
 *      Author: USER
 */

#ifndef REGISTER_H_
#define REGISTER_H_

#define PORTA (*((volatile U8*)(0x3B)))
#define PORTB (*((volatile U8*)(0x38)))
#define PORTC (*((volatile U8*)(0x35)))
#define PORTD (*((volatile U8*)(0x32)))

#define DDRA (*((volatile U8*)(0x3A)))
#define DDRB (*((volatile U8*)(0x37)))
#define DDRC (*((volatile U8*)(0x34)))
#define DDRD (*((volatile U8*)(0x31)))

#define PINA (*((volatile U8*)(0x39)))
#define PINB (*((volatile U8*)(0x36)))
#define PINC (*((volatile U8*)(0x33)))
#define PIND (*((volatile U8*)(0x30)))

#define SFIOR (*((volatile U8*)(0x50)))



// Interrupts

#define SREG (*((volatile U8*)(0x5F)))
#define MCUCR (*((volatile U8*)(0x55)))
#define MCUCSR (*((volatile U8*)(0x54)))
#define GICR (*((volatile U8*)(0x5B)))
#define GIFR (*((volatile U8*)(0x5A)))

// Timers
#define OCR0 (*((volatile U8*)(0x5C)))
#define TIMSK (*((volatile U8*)(0x59)))
#define TIFR (*((volatile U8*)(0x58)))
#define MCUCR (*((volatile U8*)(0x55)))
#define MCUCSR (*((volatile U8*)(0x54)))
#define TCCR0 (*((volatile U8*)(0x53)))
#define TCNT0 (*((volatile U8*)(0x52)))
#define TCCR1A (*((volatile U8*)(0x4F)))
#define TCCR1B (*((volatile U8*)(0x4E)))
#define TCNT1H (*((volatile U8*)(0x4D)))
#define TCNT1L (*((volatile U8*)(0x4C)))
#define OCR1AH (*((volatile U8*)(0x4B)))
#define OCR1AL (*((volatile U8*)(0x4A)))
#define OCR1BH (*((volatile U8*)(0x49)))
#define OCR1BL (*((volatile U8*)(0x48)))
#define ICR1H (*((volatile U8*)(0x47)))
#define ICR1L (*((volatile U8*)(0x46)))
#define TCCR2 (*((volatile U8*)(0x45)))
#define TCNT2 (*((volatile U8*)(0x44)))
#define OCR2 (*((volatile U8*)(0x43)))


// SPI
#define SPDR (*((volatile U8*)(0x2F)))
#define SPSR (*((volatile U8*)(0x2E)))
#define SPCR (*((volatile U8*)(0x2D)))

// USART
#define UDR (*((volatile U8*)(0x2C)))
#define UCSRA (*((volatile U8*)(0x2B)))
#define UCSRB (*((volatile U8*)(0x2A)))
#define UCSRC (*((volatile U8*)(0x40)))
#define UBRRL (*((volatile U8*)(0x29)))
#define UBRRH (*((volatile U8*)(0x40)))
#endif /* REGISTER_H_ */

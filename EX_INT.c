/*
 * EX_INT.c
 *
 *  Created on: Sep 14, 2019
 *      Author: USER
 */
#include <avr/interrupt.h>
#include "Std_types.h"
#include "Register.h"
#include "BitOperation.h"
#include "EX_INT.h"
#if ((EX_INT_0_MODE==UNINIT) || (EX_INT_1_MODE==UNINIT) || (EX_INT_2_MODE==UNINIT))
	#error "Error in mode declaration"
#elif!((EX_INT_0_MODE==low_level) || (EX_INT_0_MODE==logic_change) || (EX_INT_0_MODE==falling_edge) || (EX_INT_0_MODE==rising_edge))
	#error "Error in mode 0 declaration"
#elif!((EX_INT_1_MODE==low_level) || (EX_INT_1_MODE==logic_change) || (EX_INT_1_MODE==falling_edge) || (EX_INT_1_MODE==rising_edge))
	#error "Error in mode 1 declaration"
#elif!((EX_INT_2_MODE==0) || (EX_INT_2_MODE==1))
	#error "Error in mode 0 declaration"
#else

	#if (EX_INT_NUM == 0)
		static void (*EX_INT_0_Gptr)(void);
		void EX_INT_0_SetISR(void(*ptr)(void))
		{
			EX_INT_0_Gptr = ptr;
		}
		void EX_INT_0_init(void)
		{
			SETBIT(SREG ,7);
			MCUCR |= EX_INT_0_MODE;
			SETBIT(GICR ,6);
		}
		ISR(INT0_vect)
		{
			EX_INT_0_Gptr();
		}
	#elif (EX_INT_NUM == 1)
		static void (*EX_INT_0_Gptr)(void);
				void EX_INT_0_SetISR(void(*ptr)(void))
				{
					EX_INT_0_Gptr = ptr;
				}
				void EX_INT_0_init(void)
				{
					SETBIT(SREG ,7);
					MCUCR |= EX_INT_0_MODE;
					SETBIT(GICR ,6);
				}
				ISR(INT0_vect)
				{
					EX_INT_0_Gptr();
				}
				static void (*EX_INT_1_Gptr)(void);
				void EX_INT_1_SetISR(void(*ptr)(void))
				{
					EX_INT_1_Gptr =ptr;
				}
				void EX_INT_1_init(void)
				{
					SETBIT(SREG ,7);
					MCUCR |= (EX_INT_1_MODE<<2);
					SETBIT(GICR ,7);
				}
				ISR(INT1_vect)
				{
					EX_INT_1_Gptr();
				}
	#elif(EX_INT_NUM == 2)
		static void (*EX_INT_0_Gptr)(void);
		void EX_INT_0_SetISR(void(*ptr)(void))
		{
			EX_INT_0_Gptr = ptr;
		}
		void EX_INT_0_init(void)
		{
			SETBIT(SREG ,7);
			MCUCR |= EX_INT_0_MODE;
			SETBIT(GICR ,6);
		}
		ISR(INT0_vect)
		{
			EX_INT_0_Gptr();
		}
		static void (*EX_INT_1_Gptr)(void);
		void EX_INT_1_SetISR(void(*ptr)(void))
		{
			EX_INT_1_Gptr =ptr;
		}
		void EX_INT_1_init(void)
		{
			SETBIT(SREG ,7);
			MCUCR |= (EX_INT_1_MODE<<2);
			SETBIT(GICR ,7);
		}
		ISR(INT1_vect)
		{
			EX_INT_1_Gptr();
		}
		static void (*EX_INT_2_Gptr)(void);
		void EX_INT_2_SetISR(void(*ptr)(void))
		{
			EX_INT_2_Gptr = ptr;
		}
		void EX_INT_2_init(void)
		{
			SETBIT(SREG ,7);
			if(EX_INT_2_MODE)
			{
				SETBIT(MCUCSR ,6);
			}
			else
			{
				CLRBIT(MCUCSR ,6);
			}
			SETBIT(GICR ,5);
		}
		ISR(INT2_vect)
		{
			EX_INT_2_Gptr();
		}
	#else
		#error "Error in defining the external interrupts"
	#endif
#endif

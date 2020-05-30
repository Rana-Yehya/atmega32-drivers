/*
 * EX_INT.h
 *
 *  Created on: Sep 14, 2019
 *      Author: USER
 */

#ifndef EX_INT_H_
#define EX_INT_H_

#define UNINIT -1
// 0 for enabling interrupt (INT0) only
// 1 for enabling interrupt (INT0) and (INT1) only
// 2 for enabling all the interrupts
#define EX_INT_NUM 2


#if (EX_INT_NUM == 0)
	#define low_level 00
	#define logic_change 01
	#define falling_edge 10
	#define rising_edge 11

	// define which mode you need for INT0
	// low_level
	// logic_change
	// falling_edge
	// rising_edge
	#define EX_INT_0_MODE falling_edge

#elif (EX_INT_NUM == 1)
	#define low_level 00
	#define logic_change 01
	#define falling_edge 10
	#define rising_edge 11

	// define which mode you need for INT0
	// low_level
	// logic_change
	// falling_edge
	// rising_edge
	#define EX_INT_0_MODE falling_edge


	// define which mode you need for INT1
	// low_level
	// logic_change
	// falling_edge
	// rising_edge
	#define EX_INT_1_MODE falling_edge

#elif(EX_INT_NUM == 2)
	#define low_level 00
	#define logic_change 01
	#define falling_edge 10
	#define rising_edge 11

	// define which mode you need for INT0
	// low_level
	// logic_change
	// falling_edge
	// rising_edge
	#define EX_INT_0_MODE falling_edge


	// define which mode you need for INT0
	// low_level
	// logic_change
	// falling_edge
	// rising_edge
	#define EX_INT_1_MODE falling_edge

	// define which mode you need for INT2
	// 0 for the falling edge
	// 1 for the rising_edge
	#define EX_INT_2_MODE 0

#else
	#error "Error in defining the external interrupts"
#endif
void EX_INT_0_SetISR(void(*ptr)(void));
void EX_INT_1_SetISR(void(*ptr)(void));
void EX_INT_2_SetISR(void(*ptr)(void));
void EX_INT_0_init(void);
void EX_INT_1_init(void);
void EX_INT_2_init(void);
#endif /* EX_INT_H_ */

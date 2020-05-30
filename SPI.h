/*
 * SPI.h
 *
 *  Created on: Oct 19, 2019
 *      Author: USER
 */

#ifndef SPI_H_
#define SPI_H_

#define SPI_Master 1
#define SPI_Slave 0

// Divide / 4 >> Type 4
// Divide / 16 >> Type 16
// Divide / 64 >> Type 64
// Divide / 128 >> Type 128
// Divide / 2 >> Type 2
// Divide / 8 >> Type 8
// Divide / 32 >> Type 32
#define SPI_Clock_Rate 4

// Data Order
// LSB of the data word is transmitted first >> Type LSB
// MSB of the data word is transmitted first >> Type MSB
#define SPI_Data_Order LSB

// Clock and Phase
// 00 >> Sample (Rising) Setup (Falling)
// 01 >> Setup (Rising) Sample (Falling)
// 10 >> Sample (Falling) Setup (Rising)
// 11 >> Setup (Falling) Sample (Rising)
#define SPI_SAMPLE_RISE_SETUP_FALL 00
#define SPI_SETUP_RISE_SAMPLE_FALL 01
#define SPI_SAMPLE_FALL_SETUP_RISE 10
#define SPI_SETUP_FALL_SAMPLE_RISE 11
#define SPI_Mode SPI_SAMPLE_RISE_SETUP_FALL
void SPI_Init(U8 define_the_state_of_controller);
U8 SPI_TransmitReceive(U8 Char, U8 define_the_state_of_controller);
#endif /* SPI_H_ */

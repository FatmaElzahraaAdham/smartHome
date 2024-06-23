/*
 * SPI.h
 *
 *  Created on: Aug 24, 2023
 *      Author: H P
 */

#ifndef SPI_H_
#define SPI_H_

#include"SPI.h"
#include"STD_Lib.h"
#include"BIT_Math.h"
#include"avr/io.h"
void SPI_VidMasterInit(void);
void SPI_VidSlaveInit(void);
u8 SPI_U8TransmitRecieve(u8 Copy_U8Data);
void SPI_U8Transmit(u8 Copy_U8Data);
u8 SPI_U8Recieve(void);
#endif /* SPI_H_ */

/***************************************************************
*  @file spi.h
*  @description declare functions for spi.c
*  @author Yue Wei
*  @date  Mar 29, 2018
****************************************************************/
#ifndef _SPI_H_
#define _SPI_H_

#include<stdint.h>
#include<stdlib.h>
#include"MKL25Z4.h"

/*********************************************************
* void SPI_Configure() - This function will configure
* 	SPI, baud rate = 38400
* Inputs:
* 	No inputs
* Return:
*   Nothing
**********************************************************/
void SPI_Configure();

/*********************************************************
* void SPI_read_byte() - This function will receive a
* 	single byte from the SPI bus.
* Inputs:
* 	byte: pointer that receives the data from SPI0_D
* Return:
*   Nothing
**********************************************************/
void SPI_read_byte(uint8_t * byte);

/*********************************************************
* void SPI_write_byte() - This function will send a
* 	single byte on the SPI bus.
* Inputs:
* 	byte: pointer that sends the data to SPI0_D
* Return:
*   Nothing
**********************************************************/
void SPI_write_byte(uint8_t * byte);

/*********************************************************
* void SPI_send_packet() - This function will send
* 	numerous SPI Bytes given a pointer to a byte array
* 	and a length of how many bytes to send.
* Inputs:
* 	p: pointer that point to the first byte
* 	length: number of bytes
* Return:
*   Nothing
**********************************************************/
void SPI_send_packet(uint8_t * p, size_t length);

/*********************************************************
* void SPI_flush() - This function will blocks until SPI
* 	transmit buffer has completed transmitting
* Inputs:
* 	Nothing
* Return:
*   Nothing
**********************************************************/
void SPI_flush();

#endif /* _SPI_H_ */

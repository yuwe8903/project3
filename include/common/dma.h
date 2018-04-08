/***************************************************************
*  @file dma.h
*  @description declare macros and functions for dma.c
*  @author Yue Wei
*  @date  Mar 22, 2018
****************************************************************/

#ifndef _DMA_H_
#define _DMA_H_
#include "MKL25Z4.h"
#include <stdint.h>
#include <stdlib.h>

/*********************************************************
* void DMA_configure() - This function will configure
* 	DMA
* Inputs:
* 	No inputs
* Return:
*   Nothing
**********************************************************/
void DMA_Configure();

/*********************************************************
* void my_memmove_dma() - This function will move memory
* 	location using DMA.
* Inputs:
* 	uint8_t * src: pointer starting byte
* 	uint8_t * dst: pointer ending byte
* 	size_t length: number of bytes to move
* 	uint8_t byte_size: 1, 2, or 4
* Return:
*   return a pointer to dst
**********************************************************/
uint8_t * my_memmove_dma(uint8_t * src, uint8_t * dst, size_t length, uint8_t byte_size);

/*********************************************************
* void my_memset_dma() - This function will set memory
* 	to a given value using DMA.
* Inputs:
* 	uint8_t * src: pointer starting byte
* 	size_t length: number of bytes to move
* 	uint8_t value: a given value
* 	uint8_t byte_size: 1, 2, or 4
* Return:
*   return a pointer to src
**********************************************************/
uint8_t * my_memset_dma(uint8_t * src, size_t length, uint8_t value, uint8_t byte_size);

/*********************************************************
* void DMA0_IRQHandler() - This function is the IRQ
* 	handler for the DMA0.
* Inputs:
* 	No inputs
* Return:
*   No return
**********************************************************/
void DMA0_IRQHandler();

#endif /* _DMA_H_ */

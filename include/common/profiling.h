/***************************************************************
*  @file profiling.h
*  @description declare macros and functions for profiling.c
*  @author Yue Wei
*  @date  Apr 2, 2018
****************************************************************/
#ifndef _PROFILING_H_
#define _PROFILING_H_

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "memory.h"
#include <time.h>
#ifdef KL25Z_PLATFORM
#include "gpio.h"
#include "dma.h"
#endif

#define SYSTICK_COUNT() (SysTick->VAL)
#define SYSTICK_ZERO() (SysTick->VAL = 0UL)
#define CORE_CLOCK (48000000)
#define SYSTICK_FREQUENCY (1000)   /*ticks per second*/

/*********************************************************
* void Systick_Configure() - This function will configure
* 	Systick
* Inputs:
* 	No inputs
* Return:
*   Nothing
**********************************************************/
void Systick_Configure();

/*********************************************************
* void profile_memmove() - This function does profiling
* 	for the Standard Library Version memmove()
* Inputs:
* 	src: source pointer
* 	dst: designation pointer
* Return:
*   Nothing
**********************************************************/
void profile_memmove(void * src, void * dst);

/*********************************************************
* void profile_my_memmove() - This function does profiling
* 	for the Non-DMA Version my_memmove()
* Inputs:
* 	src: source pointer
* 	dst: designation pointer
* Return:
*   Nothing
**********************************************************/
void profile_my_memmove(uint8_t * src,uint8_t * dst);

/*********************************************************
* void profile_memmove_dma() - This function does profiling
* 	for the DMA Version my_memmove_dma()
* Inputs:
* 	src: source pointer
* 	dst: designation pointer
* Return:
*   Nothing
**********************************************************/
#ifdef KL25Z_PLATFORM
void profile_memmove_dma(uint8_t * src,uint8_t * dst);
#endif

/*********************************************************
* void profile_memset() - This function does profiling
* 	for the Standard Library Version memset()
* Inputs:
* 	src: source pointer
* Return:
*   Nothing
**********************************************************/
void profile_memset(uint8_t * src);

/*********************************************************
* void profile_my_memset() - This function does profiling
* 	for the Non-DMA Version my_memset()
* Inputs:
* 	src: source pointer
* Return:
*   Nothing
**********************************************************/
void profile_my_memset(uint8_t * src);

/*********************************************************
* void profile_memset_dma() - This function does profiling
* 	for the DMA Version my_memset_dma()
* Inputs:
* 	src: source pointer
* Return:
*   Nothing
**********************************************************/
#ifdef KL25Z_PLATFORM
void profile_memset_dma(uint8_t * src);
#endif

/*********************************************************
* void FRDM_profile_functions() - This function will call
* 	all of the profiling functions for FRDM platform.
*	This function calls dma.c, but needs #define KL25Z
* Inputs:
* 	src: source pointer
* 	dst: designation pointer
* Return:
*   Nothing
**********************************************************/
#ifdef KL25Z_PLATFORM
void FRDM_profile_functions(uint8_t * src, uint8_t * dst);
#endif

/*********************************************************
* void BBB_profile_functions() - This function will call
* 	all of the profiling functions for BBB platform. This
* 	function contains printf(), but needs #define BBB
* Inputs:
* 	src: source pointer
* 	dst: designation pointer
* Return:
*   Nothing
**********************************************************/
#ifdef BBB_PLATFORM
void BBB_profile_functions(uint8_t * src, uint8_t * dst);
#endif

#endif /* _PROFILING_H_ */

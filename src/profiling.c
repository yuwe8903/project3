/***************************************************************
*  @file profiling.c
*  @description declare macros and functions for profiling.h
*  @author Yue Wei
*  @date  Apr 2, 2018
****************************************************************/
#include "profiling.h"

size_t bytes_size[4] = {10,100,1000,5000};
uint16_t start_systick_counter = 0, end_systick_counter= 0, difference = 0;

uint16_t memmove_result[4], my_memmove_result[4], memmove_dma_result[4];
uint16_t memset_result[4],  my_memset_result[4],  memset_dma_result[4];
uint16_t * pointer;

void Systick_Configure()
{
	SysTick->LOAD = CORE_CLOCK/SYSTICK_FREQUENCY;
	SysTick->VAL   = 0UL;							/* Reset current value CVR*/
	SysTick->CTRL  =  SysTick_CTRL_ENABLE_Msk |
					  SysTick_CTRL_CLKSOURCE_Msk |
					  SysTick_CTRL_TICKINT_Msk;		/* Enable SysTick IRQ and SysTick Timer*/
	return;
}

void profile_memmove(void * src, void * dst)
{
	pointer = memmove_result;
	for(uint8_t i=0; i<4; i++)
	{
		SYSTICK_ZERO();
		start_systick_counter = SYSTICK_COUNT();
		memmove(dst, src, bytes_size[i]);
		end_systick_counter = SYSTICK_COUNT();
		difference = start_systick_counter - end_systick_counter;
		*(pointer+i) = difference;
	}
	return;
}

void profile_my_memmove(uint8_t * src, uint8_t * dst)
{
	pointer = my_memmove_result;
	for(int i=0; i<4; i++)
	{
		SYSTICK_ZERO();
		start_systick_counter = SYSTICK_COUNT();
		my_memmove(src, dst, bytes_size[i]);
		end_systick_counter = SYSTICK_COUNT();
		difference = start_systick_counter - end_systick_counter;
		*(pointer+i) = difference;
	}
	return;
}
#ifdef KL25Z_PLATFORM
void profile_memmove_dma(uint8_t * src,uint8_t * dst)
{
	pointer = memmove_dma_result;
	for(uint8_t i = 0; i < 4; i++)
	{
		SYSTICK_ZERO();
		start_systick_counter = SYSTICK_COUNT();
		my_memmove_dma(src, dst, bytes_size[i], 1);
		end_systick_counter = SYSTICK_COUNT();
		difference = start_systick_counter - end_systick_counter; /*number of ticks*/
		*(pointer+i) = difference;
	}
	return;
}
#endif
void profile_memset(uint8_t * src)
{
	pointer = memset_result;
	for(uint8_t i = 0; i < 4; i++)
	{
		SYSTICK_ZERO();
		start_systick_counter = SYSTICK_COUNT();
		memset(src, 20, bytes_size[i]);
		end_systick_counter = SYSTICK_COUNT();
		difference = start_systick_counter - end_systick_counter;
		*(pointer+i) = difference;
	}
	return;
}


void profile_my_memset(uint8_t * src)
{

	for(uint8_t i = 0; i < 4; i++)
	{
		pointer = my_memset_result;
		SYSTICK_ZERO();
		start_systick_counter = SYSTICK_COUNT();
		my_memset(src, bytes_size[i], 20);
		end_systick_counter = SYSTICK_COUNT();
		difference = start_systick_counter - end_systick_counter;
		*(pointer+i) = difference;
	}
	return;

}
#ifdef KL25Z_PLATFORM
void profile_memset_dma(uint8_t * src)
{
	pointer = memset_dma_result;
	for(uint8_t i = 0; i < 4; i++)
	{
		SYSTICK_ZERO();
		start_systick_counter = SYSTICK_COUNT();
		my_memset_dma(src, bytes_size[i], 20, 1);
		end_systick_counter = SYSTICK_COUNT();
		difference = start_systick_counter - end_systick_counter;
		*(pointer+i) = difference;
	}
	return;
}
#endif
#ifdef KL25Z_PLATFORM
void FRDM_profile_functions(uint8_t * src, uint8_t * dst)
{
	profile_memmove(src, dst);
	profile_my_memmove(src, dst);
	profile_memmove_dma(src, dst);

	profile_memset(src);
	profile_my_memset(src);
	profile_memset_dma(src);
	return;
}
#endif
#ifdef BBB_PLATFORM
void BBB_profile_functions(uint8_t * src, uint8_t * dst)
{
	profile_memmove(src, dst);
	for(uint8_t i = 0; i < 4; i++)
	{
		printf("lib memmove[%d] is : %d \n", i, memmove_result[i]);
	}

	profile_my_memmove(src, dst);
	for(uint8_t i = 0; i < 4; i++)
	{
		printf("my_memmove[%d] is : %d \n", i, my_memmove_result[i]);
	}

	profile_memset(src);
	for(uint8_t i = 0; i < 4; i++)
	{
		printf("lib memset[%d] is : %d \n", i, memset_result[i]);
	}

	profile_my_memset(src);
	for(uint8_t i = 0; i < 4; i++)
	{
		printf("my_memset[%d] is : %d \n", i, my_memset_result[i]);
	}

	return;
}
#endif

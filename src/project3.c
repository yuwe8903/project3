/************************************************************
*  @file project3.c
*  @description This is the function defination for the
*       function declaraion in project3.h file
*  @author Yue Wei
*  @date Apr 7, 2018
*************************************************************/
#include "project3.h"
void project3_spi_nrf_interface()
{
#ifdef KL25Z_PLATFORM
	SPI_Configure();
	nrf_read_status();
#endif
	return;
}

void project3_profile_demo()
{
	Systick_Configure();
	uint8_t * src = malloc(5000);
	uint8_t * dst = malloc(5000);
#ifdef KL25Z_PLATFORM
	DMA_Configure();
	FRDM_profile_functions(src, dst);
#endif

#ifdef BBB_PLATFORM
	BBB_profile_functions(src, dst);
#endif
	free(src);
	free(dst);
	return;
}

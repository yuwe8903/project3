/************************************************************
*  @file project3.c
*  @description This is the function defination for the
*       function declaraion in project3.h file
*  @author Yue Wei
*  @date Apr 7, 2018
*************************************************************/
#include "project3.h"
void spi_nrf_interface()
{
	SPI_Configure();
	nrf_read_status();
	return;
}

void profile_demo()
{
	uint8_t * src = malloc(5000);
	uint8_t * dst = malloc(5000);
	FRDM_profile_functions(src, dst);
#ifdef BBB
	BBB_profile_functions(src, dst);
#endif
	return;
}

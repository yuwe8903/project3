
/***************************************************************
*  @file project3.h
*  @description declare macros and functions for project3.c
*  @author Yue Wei
*  @date  Apr 7, 2018
****************************************************************/
#ifndef _PROJECT3_H_
#define _PROJECT3_H_

#include<stdlib.h>
#include<stdio.h>
#include "profiling.h"
#ifdef KL25Z_PLATFORM
#include "spi.h"
#include "nordic.h"
#endif

/***************************************************************
* void project3_spi_nrf_interface() - This function will test
* 	spi and nrf interface.
* Inputs:
* 	Nothing
* Return:
*   	Nothing
****************************************************************/
void project3_spi_nrf_interface();

/***************************************************************
* void project3_profile_demo() - This function will test profile
* 	functions.
* Inputs:
* 	Nothing
* Return:
*   	Nothing
****************************************************************/
void project3_profile_demo();

#endif /* _PROJECT3_H_ */

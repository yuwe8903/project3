
/***************************************************************
*  @file project3.h
*  @description declare macros and functions for project3.c
*  @author Yue Wei
*  @date  Apr 7, 2018
****************************************************************/
#ifndef _PROJECT3_H_
#define _PROJECT3_H_

#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>

#include "memory.h"
#include "profiling.h"

#include "dma.h"
#include "spi.h"
#include "nordic.h"
#include "gpio.h"
void project3_spi_nrf_interface();
void project3_profile_demo();

#endif /* _PROJECT3_H_ */

/************************************************************
*  @file gpio.c
*  @description These are function definations for all of the
*       function declaraion in gpio.h file
*  @authour Yue Wei
*  @date Feb 13 2018
*************************************************************/
#include "gpio.h"
#include "MKL25Z4.h"
void GPIO_Configure()
{
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK; /*enable gate clock for portB*/
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK; /*enable gate clock for portD*/

	PORTB_PCR18 |= PORTB_MUX1; /*MUX 001 Alt1 for GPIO*/
	PORTB_PCR18 &= PORTB_MUX2;
	PORTB_PCR19 |= PORTB_MUX1; /*MUX 001 Alt1 for GPIO*/
	PORTB_PCR19 &= PORTB_MUX2;

	//PORTD_PCR0  |= PORT_PCR_MUX(0x1); /*MUX 001 Alt1 for GPIO*/

	GPIOB_PDDR |= RGB_RED_PIN;   /*set GPIO port direction to output*/
	GPIOB_PDDR |= RGB_GREEN_PIN; /*set GPIO port direction to output*/
	//GPIOD_PDDR |= RGB_BLUE_PIN;  /*set GPIO port direction to output*/

	RGB_RED_OFF();   /*initialize RED LED to Zero*/
	RGB_GREEN_OFF(); /*initialize GREEN LED to Zero*/
	RGB_BLUE_OFF();  /*initialize BLUE LED to Zero*/
	return;
}

void Toggle_Red_LED()
{
	GPIOB_PTOR |= RGB_RED_PIN;
	return;
}
void PORTB_Set(uint32_t bit_num)
{
	GPIOB_PSOR |= bit_num;
	return;
}
void PORTD_Set(uint8_t bit_num)
{
	GPIOD_PSOR |= bit_num;
	return;
}
void PORTB_Clear(uint32_t bit_num)
{
	GPIOB_PCOR |= bit_num;
	return;
}
void PORTD_Clear(uint8_t bit_num)
{
	GPIOD_PCOR |= bit_num;
	return;
}
void PORTB_Toggle(uint32_t bit_num)
{
	GPIOB_PTOR |= bit_num;
	return;
}
void PORTD_Toggle(uint8_t bit_num)
{
	GPIOD_PTOR |= bit_num;
	return;
}


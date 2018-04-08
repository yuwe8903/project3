/************************************************************
*  @file gpio.h
*  @Author Yue Wei
*  @date Feb 13 2018
*************************************************************/
#ifndef _GPIO_H_
#define _GPIO_H_
#include "MKL25Z4.h"
#include <stdint.h>


/*macro declaration for the LED RGB pins*/
#define RGB_RED_PIN (0x40000)   /*pin 18 for red*/
#define RGB_GREEN_PIN (0x80000) /*pin 19 for green*/
#define RGB_BLUE_PIN (0x02)     /*pin  1 for blue*/

/*macro declaration for the the MUX to select Alt1*/
#define PORTB_MUX1 (0x100)      /*MUX 8 bit to 1, Alt1 for GPIO*/
#define PORTB_MUX2 (0xFFFFF9FF) /*MUX 9&10 bits to 0 for GPIO*/

/*macro declaration RED LED ,ON, OFF, TOGGLE*/
#define RGB_RED_ON() (PORTB_Clear(RGB_RED_PIN))
#define RGB_RED_OFF() (PORTB_Set(RGB_RED_PIN))
#define RGB_RED_TOGGLE() (PORTB_Toggle(RGB_RED_PIN))

/*macro declaration GREEN LED ,ON, OFF, TOGGLE*/
#define RGB_GREEN_ON() (PORTB_Clear(RGB_GREEN_PIN))
#define RGB_GREEN_OFF() (PORTB_Set(RGB_GREEN_PIN))
#define RGB_GREEN_TOGGLE() (PORTB_Toggle(RGB_GREEN_PIN))

/*macro declaration BLUE LED ,ON, OFF, TOGGLE*/
#define RGB_BLUE_ON() (PORTD_Clear(RGB_BLUE_PIN))
#define RGB_BLUE_OFF() (PORTD_Set(RGB_BLUE_PIN))
#define RGB_BLUE_TOGGLE() (PORTD_Toggle(RGB_BLUE_PIN))



/************************************************************
*  GPIO_Configure() - Configure LEDs to be output with
*  		initial value of zeros, enable gate clock for the
*  		port b and d
*  Inputs:
*       No inputs
*  Return: Nothing
*************************************************************/
void GPIO_Configure();

/************************************************************
*  Toggle_Red_LED() - Toggle RED LED state. on to off, or
*  		off to on.
*  Inputs:
*       No inputs
*  Return: Nothing
*************************************************************/
void Toggle_Red_LED();

/************************************************************
*  PORTB_Set() - Set LED state in portB, which turns off LEDs.
*  Inputs:
*       The type of LEDs, red, green.
*  Return: Nothing
*************************************************************/
void PORTB_Set(uint32_t bit_num);

/************************************************************
*  PORTD_Set() - Set LED state in portD, which turns off LEDs.
*  Inputs:
*       The type of LEDs, blue.
*  Return: Nothing
*************************************************************/
void PORTD_Set(uint8_t bit_num);

/************************************************************
*  PORTB_Clear() - Clear LED state in portB, which turns on
*  		LEDs.
*  Inputs:
*       The type of LEDs, red, green.
*  Return: Nothing
*************************************************************/
void PORTB_Clear(uint32_t bit_num);

/************************************************************
*  PORTD_Clear() - Clear LED state in portD, which turns on
*  		LEDs.
*  Inputs:
*       The type of LEDs, blue.
*  Return: Nothing
*************************************************************/
void PORTD_Clear(uint8_t bit_num);

/************************************************************
*  PORTB_Toggle() - Toggle LED states in portB. On to Off,
*  		or Off to On.
*  Inputs:
*       The type of LEDs, red, green.
*  Return: Nothing
*************************************************************/
void PORTB_Toggle(uint32_t bit_num);

/************************************************************
*  PORTD_Toggle() - Toggle LED states in portD. On to Off,
*  		or Off to On.
*  Inputs:
*       The type of LEDs, blue.
*  Return: Nothing
*************************************************************/
void PORTD_Toggle(uint8_t bit_num);


#endif /*_GPIO_H_*/


/************************************************************
*  @file uart.c
*  @description This is the function defination for the
*       function declaraion in uart.h file
*  @author Yue Wei
*  @date Feb 19 2018
*************************************************************/
#include "uart.h"
#include "circbuf.h"
#include <stdint.h>
#include "MKL25Z4.h"
/*Create storage variables*/
static uint8_t TX_data_storage[sizeof(CB_t)];
static uint8_t RX_data_storage[sizeof(CB_t)];
static uint8_t * TX_pointer = (uint8_t *) &TX_data_storage;
static uint8_t * RX_pointer = (uint8_t *) &RX_data_storage;

void UART_configure()
{
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK; /*enable gate clock for portA*/
	SIM_SCGC4 |= SIM_SCGC4_UART0_MASK; /*enable gate clock for uart0*/

	/*select Alt2 for UART0_RX and TX*/
	PORTA_PCR1 |= PORTA_MUX1; //UART0_RX
	PORTA_PCR1 &= PORTA_MUX2; //UART0_RX
	PORTA_PCR2 |= PORTA_MUX1; //UART0_TX
	PORTA_PCR2 &= PORTA_MUX2; //UART0_TX

	/*Select clock source PLL/FLL clock */
	SIM_SOPT2 &= ~(SIM_SOPT2_UART0SRC_MASK);
	SIM_SOPT2 |= UART0SRC_MASK;
	SIM_SOPT2 &= ~(SIM_SOPT2_PLLFLLSEL_MASK); /*PLL or FLL select, 0 is FLL*/
	//SIM_SOPT2 |= SIM_SOPT2_PLLFLLSEL_MASK;  /*PLL or FLL select, 1 is PLL/2 */

	/*Set up baud rate = 38400,
	 * if OSR+1 =  5x(00100) then SBR = 250 = 0b1111_1010 = 0xFA
	 * if OSR+1 = 10x(01001) then SBR = 125 = 0b0111_1101 = 0x7D
	 * if OSR+1 = 25x(11000) then SBR =  50 = 0b0011_0010 = 0x32
	 */
	UART0_BDH &= ~UARTLP_BDH_SBR_MASK; /*clear SRB bits, MASK = 0x1F*/
	UART0_BDH &= UART_STOP_BIT_MASK;   /*clear STOP bit, MASK = 0b1101_1111*/
	UART0_BDL &= ~UARTLP_BDL_SBR_MASK; /*clear SRB bits, MASK = 0xFF*/
	UART0_BDL |= 0x7D;
	UART0_C4 &= ~UARTLP_C4_OSR_MASK;   /*clear OSR bits, MASK = 0x1F*/
	UART0_C4 |= OVER_SAMPLE_MASK;      /*set OSR bits, MASK = 0b01001*/

	UART0_C1 &= 0x00;                  /*clear all C1 register bits, which included disable parity bit
	 	 	 	 	 	 	 	 	 	*and RX and TX using 8 bit data.
	 	 	 	 	 	 	 	 	 	* */

	UART0_C2 |= UARTLP_C2_RE_MASK | UARTLP_C2_TE_MASK;   /*enable RX and TX*/

	UART0_S2 &= UART_LSB_MASK;          /*start with Least Significant Bit*/

	__enable_irq();
	NVIC_EnableIRQ(UART0_IRQn);
	return;
}

void UART_send(uint8_t * ptr)
{
	*TX_pointer = *ptr;
	UART0_C2 |= UART_C2_TIE_MASK; /*enable TX interrupt for TDRE*/
	while((UART0_S1 & UARTLP_S1_TC_MASK) == 0){}  /*if complete Flag is empty*/
	return;

}
void UART_send_n(uint8_t * ptr, size_t length)
{
	for(uint8_t i = 0; i<length; i++)
	{
		*TX_pointer = *ptr;
		UART0_C2 |= UART_C2_TIE_MASK;
		while((UART0_S1 & UARTLP_S1_TC_MASK) == 0){} /*if complete Flag is empty*/
		TX_pointer++;
		ptr++;
	}
	return;
}

int8_t UART_receive(uint8_t * ptr)
{
	//UART0_C2 |= UART_C2_RIE_MASK;
	*ptr = *RX_pointer;
	return 0;
}


int32_t UART_receive_n(uint8_t * ptr, size_t length)
{
	for(uint8_t i = 0; i<length; i++)
	{
		UART0_C2 |= UART_C2_RIE_MASK;
		if((UART0_S1 & UARTLP_S1_IDLE_MASK) != 0) /*if iddle FLag is full, 1 is full*/
		{
			*ptr = *RX_pointer;
			RX_pointer++;
			ptr++;
		}

	}
	return 0;
}


void UART0_IRQHandler()
{
	NVIC_DisableIRQ(UART0_IRQn);
	//__disable_irq();
	__DSB();
	__ISB();
	if((UART0_S1 & UARTLP_S1_TDRE_MASK) != 0)  /*if TDRE Flag is empty, 1 is empty*/
	{
		UART0->D = *TX_pointer;	    /*TDRE Flag is full now*/
	}
	else if((UART0_S1 & UARTLP_S1_RDRF_MASK) != 0) /*if RDRF FLag is full, 1 is full*/
	{
		*RX_pointer = UART0_D;		/*RDRF Flag is empty now*/
		//some is received
	}
	//__enable_irq();
	NVIC_EnableIRQ(UART0_IRQn);
	return;
}

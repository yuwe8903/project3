/************************************************************
*  @file dma.c
*  @description This is the function defination for the
*       function declaraion in dma.h file
*  @author Yue Wei
*  @date Mar 22, 2018
*************************************************************/
#include "dma.h"

uint8_t memory_buf[100];

void DMA_Configure()
{
	SIM_SCGC6|=SIM_SCGC6_DMAMUX_MASK;/*Enable the DMAMUX bit to 1 in the (SIM_SCGC6)*/
	SIM_SCGC7|=SIM_SCGC7_DMA_MASK;   /*Enable the DMA bit to 1 in the (SIM_SCGC7)*/
	/*Disable DMA MUX channel first*/
	DMAMUX0_CHCFG0 &= 0x00;
	DMAMUX0_CHCFG1 &= 0x00;
	DMAMUX0_CHCFG2 &= 0x00;
	DMAMUX0_CHCFG3 &= 0x00;

	DMA_DSR0 |= DMA_DSR_BCR_DONE_MASK; /*Clear pending errors by writing one to DONE bit*/

	DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;
	NVIC_ClearPendingIRQ(DMA0_IRQn); /*Clear pending DMA interrupts from NVIC ICPR register*/
	NVIC_EnableIRQ(DMA0_IRQn);		 /*Enable DMA interrupt in NVIC ISER*/
	DMA_DCR0|=DMA_DCR_EINT_MASK;
	return;
}

uint8_t * my_memmove_dma(uint8_t * src, uint8_t * dst, size_t length, uint8_t byte_size){

	if(src!=NULL && dst!=NULL && length>0) // Check for NULL pointer and valid length
	{
		DMA_SAR0 = (uint32_t)src; //DMA Source register to src value
		DMA_DAR0 = (uint32_t)dst; //DMA destination register to dst value
		DMA_DSR_BCR0 = DMA_DSR_BCR_BCR(length); //length of data to be transferred to BCR
		DMA_DCR0 |= (DMA_DCR_AA_MASK | DMA_DCR_SINC_MASK | DMA_DCR_DINC_MASK);
		if(byte_size==1)
		{
			DMA_DCR0 |= DMA_DCR_SSIZE(1);
			DMA_DCR0 |= DMA_DCR_DSIZE(1);
		}
		else if(byte_size==2)
		{
			DMA_DCR0 |= DMA_DCR_SSIZE(2);
			DMA_DCR0 |= DMA_DCR_DSIZE(2);
		}
		else if(byte_size==4)
		{
			DMA_DCR0 |= DMA_DCR_SSIZE(0);
			DMA_DCR0 |= DMA_DCR_DSIZE(0);
		}
		NVIC_EnableIRQ(DMA0_IRQn);
		DMA_DCR0 |= DMA_DCR_START_MASK; // Start DMA transfer
		return dst;
	}
	else
	{
		return 0;  // return 0 for NULL pointer
	}
}

uint8_t * my_memset_dma(uint8_t * src, size_t length, uint8_t value, uint8_t byte_size){

	if(src!=NULL && length>0)   /*Check for NULL pointer*/
	{
		DMA_SAR0 = (uint32_t)&value;
		DMA_DAR0 = *(uint32_t*)src; //DMA Source register to src value
		DMA_DSR_BCR0 = DMA_DSR_BCR_BCR(length); //length of data to be transferred to BCR
		DMA_DCR0 |= (DMA_DCR_SINC_MASK   | DMA_DCR_DINC_MASK);
		if(byte_size==1)
		{
			DMA_DCR0 |= DMA_DCR_SSIZE(1);
			DMA_DCR0 |= DMA_DCR_DSIZE(1);
		}
		else if(byte_size==2)
		{
			DMA_DCR0 |= DMA_DCR_SSIZE(2);
			DMA_DCR0 |= DMA_DCR_DSIZE(2);
		}
		else if(byte_size==4)
		{
			DMA_DCR0 |= DMA_DCR_SSIZE(0);
			DMA_DCR0 |= DMA_DCR_DSIZE(0);
		}

		NVIC_EnableIRQ(DMA0_IRQn);
		DMA_DCR0 |= DMA_DCR_START_MASK; 		/* Start DMA transfer*/
		return src;
	}
		else
		{
			return 0; // return 0 for NULL pointer
		}
}


void DMA0_IRQHandler(){
	NVIC_DisableIRQ(DMA0_IRQn);
	DMA_DSR_BCR0 |= DMA_DSR_BCR_DONE_MASK;
	NVIC_EnableIRQ(DMA0_IRQn);
}

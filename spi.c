/************************************************************
*  @file spi.c
*  @description This is the function defination for the
*       function declaraion in spi.h file
*  @author Yue Wei
*  @date Mar 29, 2018
*************************************************************/
#include"spi.h"
void SPI_Configure()
{
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK; /*enable gate clock for portC*/
	SIM_SCGC4 |= SIM_SCGC4_SPI0_MASK;  /*enable gate clock for SPI0*/

	PORTD_PCR0 |= PORT_PCR_MUX(0x1);    /*MUX 001 Alt1 for GPIO*/
	PORTD_PCR1 |= PORT_PCR_MUX(0x2);    /*select ALT2 to enable the SPI_SCK */
	PORTD_PCR2 |= PORT_PCR_MUX(0x2);    /*select ALT2 to enable the SPI_MOSI*/
	PORTD_PCR3 |= PORT_PCR_MUX(0x2);    /*select ALT2 to enable the SPI_MISO*/
	GPIOD_PDDR |= 0x01;
	/*Configure C1*/
	SPI0_C1 |= (SPI_C1_SPE_MASK  |		/*SPI system enabled*/
				SPI_C1_MSTR_MASK |		/*SPI module configured as a master SPI device*/
				SPI_C1_CPHA_MASK);		/*First edge on SPSCK occurs at the start*/

	SPI0_C1 &= ~(SPI_C1_SPIE_MASK |  	/*SPI interrupt disabled*/
				 SPI_C1_SPTIE_MASK|		/*SPI transmit interrupt disabled*/
				 SPI_C1_CPOL_MASK |		/*Active-high SPI clock (idles low)*/
				 SPI_C1_SSOE_MASK |		/*master SS pin acts as the mode fault input*/
				 SPI_C1_LSBFE_MASK);	/*SPI serial data transfers start with most significant bit*/
	/*Configure C2*/
	SPI0_C2 |= (SPI_C2_MODFEN_MASK );	/*Master mode-fault function enabled
	 	 	 	 	 	 	 	 	 	  master SS pin acts as the mode fault input
	 	 	 	 	 	 	 	 	 	  or the slave select output*/
	SPI0_C2 &= ~(SPI_C2_SPMIE_MASK  |	/*SPI match interrupt disabled*/
				 SPI_C2_TXDMAE_MASK |	/*Transmit DMA disabled*/
				 SPI_C2_BIDIROE_MASK|	/*Bidirectional mode output disabled*/
				 SPI_C2_RXDMAE_MASK |	/*Receive DMA disabled*/
				 SPI_C2_SPISWAI_MASK|	/*SPI clocks continue to operate in wait mode*/
				 SPI_C2_SPC0_MASK  );	/*pin mode is normal: */

	SPI0_BR = (SPI_BR_SPPR(0x1) | SPI_BR_SPR(0x0));
	//NVIC_EnableIRQ(SPI0_IRQn);
	return;
}

void SPI_read_byte(uint8_t* byte)
{
	if(byte != NULL)
	{
        while((SPI0_S & SPI_S_SPRF_MASK) != 0)/*SPRF is 1, data is available*/
        {
        	*byte = SPI0_D;
        }
	}
	return;
}

void SPI_write_byte(uint8_t* byte)
{
	if(byte != NULL)
	{
      while((SPI0_S & SPI_S_SPTEF_MASK) != 0)/*SPTEF is 1, buffer is empty*/
      {
    	  SPI0_D = *byte;
      }
	}
	return;
}

void SPI_send_packet(uint8_t * p, size_t length)
{
	if(p != NULL && length > 0)
	{
		for(uint8_t i = 0; i < length; i++)
		{
			SPI_write_byte((p+i));
		}

	}
	return;
}


void SPI_flush()
{
	SPI0_C1 &= ~SPI_C1_SPE_MASK;
	SPI_Configure();
	return;
}


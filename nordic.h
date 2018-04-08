/***************************************************************
*  @file nordic.h
*  @description declare macros and functions for nordic.c
*  @author Yue Wei
*  @date  Mar 30, 2018
****************************************************************/
#ifndef _NORDIC_H_
#define _NORDIC_H_
#include<stdint.h>
#include<stdlib.h>
#include"spi.h"
#include"MKL25Z4.h"

#define NRF_CONFIG_REG      (0x00)
#define NRF_EN_AA_REG       (0x01)
#define NRF_EN_RXADDR_REG   (0x02)
#define NRF_SETUP_AW_REG    (0x03)
#define NRF_SETUP_RETR_REG  (0x04)
#define NRF_RF_CH_REG       (0x05)
#define NRF_RF_SETUP_REG    (0x06)
#define NRF_STATUS_REG      (0x07)
#define NRF_OBSERVE_TX_REG  (0x08)
#define NRF_CD_REG          (0x09)
#define NRF_RX_ADDR_P0_REG  (0x0A)
#define NRF_RX_ADDR_P1_REG  (0x0B)
#define NRF_RX_ADDR_P2_REG  (0x0C)
#define NRF_RX_ADDR_P3_REG  (0x0D)
#define NRF_RX_ADDR_P4_REG  (0x0E)
#define NRF_RX_ADDR_P5_REG  (0x0F)
#define NRF_TX_ADDR_REG     (0x10)
#define NRF_RX_PW_P0_REG    (0x11)
#define NRF_RX_PW_P1_REG    (0x12)
#define NRF_RX_PW_P2_REG    (0x13)
#define NRF_RX_PW_P3_REG    (0x14)
#define NRF_RX_PW_P4_REG    (0x15)
#define NRF_RX_PW_P5_REG    (0x16)
#define NRF_FIFO_STATUS_REG (0x17)
#define NRF_DYNPD_REG       (0x1C)
#define NRF_FEATURE_REG     (0x1D)

#define R_REGISTER          (0x00)
#define W_REGISTER          (0x20)
#define R_RX_PAYLOAD        (0x61)
#define W_TX_PAYLOAD        (0xA0)
#define FLUSH_TX      		(0xE1)
#define FLUSH_RX      		(0xE2)
#define REUSE_TX_PL   		(0xE3)
#define ACTIVATE   			(0x50)
#define R_RX_PL_WID   		(0x60)
#define W_ACK_PAYLOAD  		(0xA8)
#define W_TX_PAYLOAD_NOACK	(0xB0)
#define NOP           		(0xFF)

#define NRF_POWER_UP      (1)
#define NRF_POWER_DOWN    (0)
#define NRF_PRIM_RX_MASK  (1)
#define NRF_POWER_UP_MASK (0x02)

/*********************************************************
* int8_t nrf_read_register() - This function will read
* 	the register and return the value
* Inputs:
* 	uint8_t reg: register
* Return:
*   the register value
**********************************************************/
uint8_t nrf_read_register(uint8_t reg);


/*********************************************************
* void nrf_write_register() - This function will write to
* 	the given register with the data
* Inputs:
* 	uint8_t reg: register
* 	uint8_t value: data to be written to the register
* Return:
*   Nothing
**********************************************************/
void nrf_write_register(uint8_t reg, uint8_t value);


/*********************************************************
* uint8_t nrf_read_status() - This function will read
* 	the STATUS register and return the value
* Inputs:
* 	Nothing
* Return:
*   the STATUS register value
**********************************************************/
uint8_t nrf_read_status();


/*********************************************************
* void nrf_write_config() - This function will write to
* 	the CONFIG register with the data
* Inputs:
* 	uint8_t config: data
* Return:
*   Nothing
**********************************************************/
void nrf_write_config(uint8_t config);


/*********************************************************
* uint8_t nrf_read_config() - This function will read
* 	the CONFIG register and return the value
* Inputs:
* 	Nothing
* Return:
*   the CONFIG register value
**********************************************************/
uint8_t nrf_read_config();


/*********************************************************
* uint8_t nrf_read_rf_setup() - This function will read
* 	the RF_SETUP register and return the value
* Inputs:
* 	Nothing
* Return:
*   the RF_SETUP register value
**********************************************************/
uint8_t nrf_read_rf_setup();


/*********************************************************
* void nrf_write_rf_setup() - This function will write to
* 	the RF_SETUP register with the data
* Inputs:
* 	uint8_t config: data
* Return:
*   Nothing
**********************************************************/
void nrf_write_rf_setup(uint8_t config);


/*********************************************************
* uint8_t nrf_read_rf_ch() - This function will read
* 	the RF_CH register and return the value
* Inputs:
* 	Nothing
* Return:
*   the RF_CH register value
**********************************************************/
uint8_t nrf_read_rf_ch();


/*********************************************************
* void nrf_write_rf_ch() - This function will write to
* 	the RF_CH register with the data
* Inputs:
* 	uint8_t channel: data
* Return:
*   Nothing
**********************************************************/
void nrf_write_rf_ch(uint8_t channel);


/*********************************************************
* void nrf_read_TX_ADDR() - This function will read the
* 	5 bytes of TX_ADDR register and return the value
* Inputs:
* 	uint8_t * address: TX_ADDR register
* Return:
*   Nothing
**********************************************************/
void nrf_read_TX_ADDR(uint8_t * address);


/*********************************************************
* void nrf_write_TX_ADDR() - This function will write the
* 	5 byte TX_ADDR register with the data
* Inputs:
* 	uint8_t * tx_addr: data
* Return:
*   Nothing
**********************************************************/
void nrf_write_TX_ADDR(uint8_t * tx_addr);


/*********************************************************
* uint8_t nrf_read_fifo_status() - This function will read
* 	the FIFO_STATUS register and return the value
* Inputs:
* 	Nothing
* Return:
*   the FIFO_STATUS register value
**********************************************************/
uint8_t nrf_read_fifo_status();


/*********************************************************
* void nrf_flush_tx_fifo() - This function will send the
* 	command FLUSH_TX
* Inputs:
* 	Nothing
* Return:
*   Nothing
**********************************************************/
void nrf_flush_tx_fifo();


/*********************************************************
* void nrf_flush_rx_fifo() - This function will send the
* 	command FLUSH_RX
* Inputs:
* 	Nothing
* Return:
*   Nothing
**********************************************************/
void nrf_flush_rx_fifo();


/************************************************************
*  void nrf_chip_enable() - cs enable.
*  Inputs:
*       Nothing
*  Return:
*		Nothing
*************************************************************/
__attribute__((always_inline)) inline void nrf_chip_enable()
{
	GPIOD_PCOR |= 0x1;
	return;
}


/************************************************************
*  void nrf_chip_disable() - cs disable.
*  Inputs:
*       Nothing
*  Return:
*		Nothing
*************************************************************/
__attribute__((always_inline)) inline void nrf_chip_disable()
{
	GPIOD_PSOR |= 0x1;
	return;
}


/************************************************************
*  void nrf_transmit_enable() - transmit enable.
*  Inputs:
*       Nothing
*  Return:
*		Nothing
*************************************************************/
__attribute__((always_inline)) inline void nrf_transmit_enable()
{
	GPIOD_PCOR |= 0x20;
	return;
}


/************************************************************
*  void nrf_transmit_disable() - transmit disable.
*  Inputs:
*       Nothing
*  Return:
*		Nothing
*************************************************************/
__attribute__((always_inline)) inline void nrf_transmit_disable()
{
	GPIOD_PSOR |= 0x20;
	return;
}
#endif /* _NORDIC_H_ */

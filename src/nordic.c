/************************************************************
*  @file nordic.c
*  @description This is the function defination for the
*       function declaraion in spi.h file
*  @author Yue Wei
*  @date Mar 30, 2018
*************************************************************/
#include"nordic.h"

uint8_t nrf_read_register(uint8_t reg)
{
	nrf_chip_enable();
	uint8_t * ptr_write = (uint8_t*)(R_REGISTER  | reg);
	uint8_t * ptr_read;
	SPI_write_byte(ptr_write);		/*write the command*/
	SPI_read_byte(ptr_read);		/*read the status, don't need to know this value*/
	ptr_write = (uint8_t*)NOP;
	SPI_write_byte(ptr_write);		/*write the NOP*/
	SPI_read_byte(ptr_read);		/*read the register*/
	nrf_chip_disable();
	return  *ptr_read;				/*return the read register*/
}
void nrf_write_register(uint8_t reg, uint8_t value)
{
	nrf_chip_enable();
	uint8_t * ptr_write = (uint8_t*)(W_REGISTER  | reg);
	uint8_t * ptr_read;
	SPI_write_byte(ptr_write);		/*write the command*/
	SPI_read_byte(ptr_read);		/*read the status, don't need to know this value*/
	ptr_write = &value;
	SPI_write_byte(ptr_write);		/*write the value to the register*/
	SPI_read_byte(ptr_read);		/*read the status, don't need to know this value*/
	nrf_chip_disable();
	return;
}
uint8_t nrf_read_status()
{
	return nrf_read_register(NRF_STATUS_REG);
}
void nrf_write_config(uint8_t config)
{
	nrf_write_register(NRF_CONFIG_REG, config);
	return;
}
uint8_t nrf_read_config()
{
	return nrf_read_register(NRF_CONFIG_REG);
}
uint8_t nrf_read_rf_setup()
{
	return nrf_read_register(NRF_RF_SETUP_REG);
}
void nrf_write_rf_setup(uint8_t config)
{
	nrf_write_register(NRF_RF_SETUP_REG, config);
	return;
}
uint8_t nrf_read_rf_ch()
{
	return nrf_read_register(NRF_RF_CH_REG);
}
void nrf_write_rf_ch(uint8_t channel)
{
	nrf_write_register(NRF_RF_CH_REG, channel);
	return;
}
void nrf_read_TX_ADDR(uint8_t * address)
{
	nrf_chip_enable();
	uint8_t * ptr_write = (uint8_t*)(R_REGISTER | NRF_TX_ADDR_REG);
	uint8_t * ptr_read;
	SPI_write_byte(ptr_write);		/*write the command*/
	SPI_read_byte(ptr_read);		/*read the status, don't need to know this value*/
	ptr_write = (uint8_t*)NOP;
	for(uint8_t i = 0; i < 5; i++)
	{
		SPI_write_byte(ptr_write);	/*write the NOP*/
		SPI_read_byte((address+i));	/*read the register*/
	}
	nrf_chip_disable();
	return;
}
void nrf_write_TX_ADDR(uint8_t * tx_addr)
{
	nrf_chip_enable();
	uint8_t * ptr_write = (uint8_t*)(W_REGISTER  | NRF_TX_ADDR_REG);
	uint8_t * ptr_read;
	SPI_write_byte(ptr_write);		/*write the command*/
	SPI_read_byte(ptr_read);		/*read the status, don't need to know this value*/
	for(uint8_t i = 0; i < 5; i++)
	{
		SPI_write_byte((tx_addr+i));/*write the value pointed by tx_addr to the register*/
		SPI_read_byte(ptr_read);	/*read the status, don't need to know this value*/
	}
	nrf_chip_disable();
	return;
}
uint8_t nrf_read_fifo_status()
{
	return nrf_read_register(NRF_FIFO_STATUS_REG);
}
void nrf_flush_tx_fifo()
{
	nrf_chip_enable();
	uint8_t * ptr_write = (uint8_t*)(FLUSH_TX);
	uint8_t * ptr_read;
	SPI_write_byte(ptr_write);
	SPI_read_byte(ptr_read);
	nrf_chip_disable();
	return;
}
void nrf_flush_rx_fifo()
{
	nrf_chip_enable();
	uint8_t * ptr_write = (uint8_t*)(FLUSH_RX);
	uint8_t * ptr_read;
	SPI_write_byte(ptr_write);
	SPI_read_byte(ptr_read);
	nrf_chip_disable();
	return;
}






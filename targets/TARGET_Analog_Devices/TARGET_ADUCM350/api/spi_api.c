#include <stddef.h>
#include "spi_api.h"
#include "PeripheralNames.h"
#include "ADuCM350.h"

#define spi_t pADI_SPI0_Type

void spi_init(spi_t *obj, PinName mosi, PinName miso, PinName sclk, PinName ssel){
	
}

void spi_free(spi_t *obj){
	
}

void spi_format(spi_t *obj, int bits, int mode, int slave){
	
}

void spi_frequency(spi_t *obj, int hz){
	
}

int  spi_master_write(spi_t *obj, int value){
	return 0;
}

int spi_master_block_write(spi_t *obj, const char *tx_buffer, int tx_length, char *rx_buffer, int rx_length, char write_fill){
	return 0;
}

int  spi_slave_receive(spi_t *obj){
	return 0;
}

int  spi_slave_read(spi_t *obj){
	return 0;
}

void spi_slave_write(spi_t *obj, int value){
	
}

int  spi_busy(spi_t *obj){
	return 0;
}

uint8_t spi_get_module(spi_t *obj){
	return 0;
}

void spi_master_transfer(spi_t *obj, const void *tx, size_t tx_length, void *rx, size_t rx_length, uint8_t bit_width, uint32_t handler, uint32_t event, DMAUsage hint){
	
}


uint32_t spi_irq_handler_asynch(spi_t *obj){
		return 0;
}

uint8_t spi_active(spi_t *obj){
 return 0;
}

void spi_abort_asynch(spi_t *obj){
	
}
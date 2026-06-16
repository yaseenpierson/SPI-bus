/*
 * spi_atmega.c
 *
 * Created: 15-06-2026 16:57:44
 * Author : ACER
 */ 
#define f_CPU 16000000UL
#include <avr/io.h>
#include "master.h"

void spi_init()
{
	//pin definitions
	DDRB |= (1<<DDB3);  // MOSI output
	DDRB |= (1<<DDB5);  // SCK output
	DDRB |= (1<<DDB2);  // SS output

	DDRB &= ~(1<<DDB4); // MISO input
	
	//spi enable master configuration
	
	SPCR |= (1<<SPE)|(1<<MSTR)|(1<<SPR0);
	SPCR &= ~(1<<SPR1)|(1<<CPOL)|(1<<CPHA);

	//spi2x =0
	SPSR &= ~(1<<SPI2X);
}


uint16_t spi_transfer(uint16_t data){
		SPDR = data;
    while (!(SPSR&(1<<SPIF))) //CHECKS FLAG
    {
		
	}
	return SPDR;
}


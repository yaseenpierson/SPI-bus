/*
 * main.c
 *
 * Created: 16-06-2026 11:50:12
 *  Author: ACER
 */ 
#define f_CPU 16000000UL
#include <avr/io.h>
#include "master.h"

int main(void){
	
	void spi_init();
	
	
	//defining button input pin
	
	DDRD |=(1<<PD2);
	// NOTE ; in this code am not setting internal pull up (ddrd = 0 & port 2 =1) as external pull up is added in hardware 
	
	//using edge detection
	uint16_t pre_state = 0 ;
	
 while(1){
	 
	 uint16_t current_state = (PIND & (1<<PD2)); // PINX READS current state of button
	 
	 if(current_state && !pre_state){ //checks edge condition
		 PORTB &=~(1<<PB2); //SELECT SLAVE A
		 spi_transfer(0X01); //TRANSFERS 1
		 PORTB |= (1<<PB2); //DESELCT SLAVE A 
	}
		 pre_state = current_state ; // important inorder to prevent spi from contineous transmission , ie while holding down the button the if loop becomes false and traansfer stops 
}
 }

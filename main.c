#define F_CPU 1000000UL			/* Define CPU Frequency 8MHz */
#include <stdio.h>
#include <stdlib.h>
#include "avr/io.h"
#include "util/delay.h"
#include "micro_config.h"
#include "std_types.h"
#include "gpio.h"
#include "lcd.h"
#include "spi.h"
#include "pwm.h"
#include "TC72_Tempr.h"
#include "SPI_2.h"

typedef unsigned char uint8_t;	
int main(void) {
	StartTimer();
    SetPollingTime(500);
    StartPolling();
    initPWM();
	LCD_init();

	/* Initialize the SPI driver as Slave */
	SPI_initMaster();
	
	/* Display the received string on the LCD display */
	LCD_displayString("temp is:");
	
	//make ss =0 no select slave
	PORTB = PORTB & (~(1<<4));
	
	
	int temprMSB,temprLSB;
	float signal;
	int accTemp=0;
	while(1){
		
		_delay_ms(300);
		LCD_clearScreen();
		Poll();
	
		_delay_ms(300);
		//make ss =1 select slave
		PORTB = PORTB | (1<<4);
		SPI_sendReceiveByte(CONTROL_REG);
		SPI_sendReceiveByte(START_CONV);      //Continous conversion
		//make ss =0 no select slave
		PORTB = PORTB & (~(1<<4));
		_delay_ms(300);
		
		
		//make ss =1 select slave
		PORTB = PORTB | (1<<4);
		SPI_sendReceiveByte(TEMPR_REG);                  //Access Tempr register for reading
		temprMSB = SPI_sendReceiveByte(SPI_DEFAULT_DATA_VALUE);
		temprLSB = SPI_sendReceiveByte(SPI_DEFAULT_DATA_VALUE);
		//make ss =0 no select slave
		PORTB = PORTB & (~(1<<4));
		
		
		 accTemp=accTemp+(30-(temprMSB*2));
         signal=((0.1*(30-(temprMSB*2)))+(0.01*(accTemp)));
		  
		 Timer0_PWM_Init((signal/13)*186);

		//LCD_displayString("temp is :");
		//LCD_intgerToString(temprMSB);

        LCD_displayString("diff is :");
		//LCD_intgerToString((temprMSB<<8) + temprLSB);
		LCD_intgerToString(30-(temprMSB*2));
		_delay_ms(3000);
		LCD_clearScreen();
        LCD_displayString("error is :");

		LCD_intgerToString(signal*10);

		_delay_ms(3000);

	return 0;
}
}

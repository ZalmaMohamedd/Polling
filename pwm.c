#include "pwm.h"
#include "avr/io.h"


void initPWM(void)
{
	
	DDRD|=(uint8_t)(((uint8_t)1)<<DDD4);
	DDRD&=(uint8_t)~(uint8_t)(((uint8_t)1)<<DDD0);
	TCCR1B|=(uint8_t)((((uint8_t)1)<<WGM12)|((uint8_t)1<<CS10)); /*CS10 n=1 no prescaler fast pwm*/
	OCR1B=(uint8_t)0;
	return;

}
void Timer0_PWM_Init(float set_duty_cycle)
{
    TCNT0 = 0; // Set Timer Initial Value to 0


    OCR1B  = set_duty_cycle;

}


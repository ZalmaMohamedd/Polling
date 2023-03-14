/*
 * PollingDataClient.c
 *
 *  Created on: Dec 5, 2022
 *      Author: lenovo
 */
#include "PollingDataClient.h"
#include "std_types.h"
#include "lcd.h"


void Handle_data(float data)
{
	 LCD_displayString("Tempr: ");
	 LCD_displayCharacter((uint8)data);

	 for(int i =0; i< 10000000; i++);
	 LCD_sendCommand(LCD_CLEAR_COMMAND);

}

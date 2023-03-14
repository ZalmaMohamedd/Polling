/*
 * Poller.c
 *
 *  Created on: Dec 5, 2022
 *      Author: lenovo
 */
#include "Poller.h"
#include "TC72_Tempr.h"
#include "PollingDataClient.h"

int polling_enabled= 1;
int polling_counter= 1;
int counter = 0 ;

void Poll(void)
{
	if(polling_enabled && (!counter))
	{
		signed int data;
		data = TC72_ReadTempr();
		data = GetData( data);
		Handle_data(data);

	}
	counter++;
	counter = counter%polling_counter;
}

void StartPolling(void)
{
	polling_enabled=1;
}

void StopPolling(void)
{
	polling_enabled=0;
}

void SetPollingTime(int polling_time)
{
	polling_counter = polling_time/100;
}


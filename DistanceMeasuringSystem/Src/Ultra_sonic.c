/*
 ============================================================================
 Name        : GPIO_interface.h
 Author      : MOHAMED MOSTAFA
 Description : Header file for UltraSonic Driver
 Date        : 21/10/2023
 ============================================================================
 */



#include "../Inc/Ultra_sonic.h"
#include "../Inc/icu.h"
#include "../Inc/GPIO_interface.h"
#include "../Inc/GPIO_private.h"
#include <util/delay.h>

static u8  global_edgeCount = 0;
static u16 global_timeHigh = 0;
static u16 global_timePeriod = 0;
static u16 global_timePeriodPlusHigh = 0;

void Ultrasonic_init(void)
{
	ICU_ConfigType conf = {F_CPU_8,RAISING};
	GPIO_setupPinDirection(PORTB_ID, PIN5_ID, PIN_OUTPUT);
	ICU_setCallBack(Ultrasonic_edgeProcessing);
	ICU_init(&conf);
}

void Ultrasonic_Trigger(void)
{

	GPIO_writePin(PORTB_ID, PIN5_ID, 1);
	_delay_us(10);
	GPIO_writePin(PORTB_ID, PIN5_ID, 0);
}

u16 Ultrasonic_readDistance(void)
{
	u8 distance_measured = 0;
	Ultrasonic_Trigger();
	distance_measured = ceil( global_timeHigh/58.8);
	return distance_measured;

}

void Ultrasonic_edgeProcessing(void)
{
	global_edgeCount++;
	if(global_edgeCount == 1)
	{
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(FALLING);
	}
	else if(global_edgeCount == 2)
	{
		ICU_setEdgeDetectionType(RAISING);
	}
	else if(global_edgeCount == 3)
	{
		global_timePeriod = ICU_getInputCaptureValue();
		ICU_setEdgeDetectionType(FALLING);
	}
	else if(global_edgeCount == 4)
	{
		global_timePeriodPlusHigh = ICU_getInputCaptureValue();

		global_timeHigh = (global_timePeriodPlusHigh - global_timePeriod);

		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(RAISING);
		global_edgeCount = 0;
	}
}

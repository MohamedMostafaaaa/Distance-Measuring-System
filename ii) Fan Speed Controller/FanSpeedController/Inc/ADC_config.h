/*
 ============================================================================
 Name        : ADC_interface.h
 Author      : MOHAMED MOSTAFA
 Description : Interface Header file for ADC Driver
 Date        : 13/10/2023
 ============================================================================
 */
 
#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/*Options:
 *1-ADC_AREF_OFF    :AREF, Internal Vref turned off
 *2-ADC_AVCC		:AVCC with external capacitor at AREF pin
 *3-ADC_INTERNAL	:Internal 2.56V Voltage Reference with external capacitor at AREF pin
*/
#define ADC_VR		ADC_INTERNAL


/*	Time out for the busy loop in the Asynch function	*/
#define ADC_TimeOut		5000

#endif


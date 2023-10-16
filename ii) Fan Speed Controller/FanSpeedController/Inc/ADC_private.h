/*
 ============================================================================
 Name        : ADC_private.h
 Author      : MOHAMED MOSTAFA
 Description : Private Header file for ADC Driver
 Date        : 13/10/2023
 ============================================================================
 */
 
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/*******************************************************************************
 *                                  Registers                                  *
 *******************************************************************************/
 
#define	ADMUX	(*(volatile u8 * const)0x0027)
#define	ADCSRA	(*(volatile u8 * const)0x0026)
#define	ADCH	(*(volatile const u8 * const)0x0025)
#define	ADCL	(*(volatile const u8 * const)0x0024)
#define	ADC		(*(volatile const u16 * const)0x0024) /*Accessing the ADCL & ADCH together*/

 
 
 
#define Idle			200
#define	Busy			201
 
 
 
#endif

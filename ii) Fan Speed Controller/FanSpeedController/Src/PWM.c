/*
 ============================================================================
 Name        : ADC_private.h
 Author      : MOHAMED MOSTAFA
 Description : Program file for PWM Driver
 Date        : 13/10/2023
 ============================================================================
 */

#include "../Inc/STD_TYPES.h"
#include "../Inc/BIT_MATH.h"
#include "../Inc/GPIO_private.h"
#include "../Inc/GPIO_interface.h"
#include "../Inc/PWM.h"


void PWM_Timer0_Start(u8 duty_cycle)
{
	/*Set PWM as output pin*/
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);

	/*Initialize the timer*/
	TCNT0 = 0 ;

	/*Compare value to adjust duty cycle*/
	OCR0 = (u8)(((u16)duty_cycle * 255UL )/100UL) ;

	/*Non-inverting Mode*/
	SET_BIT(TCCR0,5);
	CLR_BIT(TCCR0,4);

	/*Ensuring operating in a PWM mode*/
	CLR_BIT(TCCR0,7);

	/*Waveform Generation Fast PWM-mode*/
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);


	/*Prescalar = 8*/
	CLR_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);

}


/*
 ============================================================================
 Name        : ADC_private.h
 Author      : MOHAMED MOSTAFA
 Description : Header file for PWM Driver
 Date        : 13/10/2023
 ============================================================================
 */

#ifndef PWM_H_
#define PWM_H_

/*******************************************************************************
 *                                  Registers                                  *
 *******************************************************************************/

#define TCCR0 		(*(volatile u8 *)0x0053)
#define TCNT0		(*(volatile u8 *)0x0054)
#define OCR0		(*(volatile u8 *)0x005C)
#define TIMSK		(*(volatile u8 *)0x0059)
#define TIFR		(*(volatile u8 *)0x0058)


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/


/*Description:
 * The function responsible for trigger the Timer0 with the PWM Mode.
 * Setup the PWM mode with Non-Inverting.
 * Setup the prescalar with F_CPU/8.
 * Setup the compare value based on the required input duty cycle
 * Setup the direction for OC0 as output pin through the GPIO driver.
 * The generated PWM signal frequency will be 500Hz to control the DC Motor speed.
 * Inputs:
     1- duty_cycle: The required duty cycle percentage of the generated PWM signal.
     Its value should be from 0 → 100
* Return: None
*/
void PWM_Timer0_Start(u8 duty_cycle);


#endif /* PWM_H_ */

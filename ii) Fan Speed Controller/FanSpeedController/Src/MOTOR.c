/*
 ============================================================================
 Name        : MOTOR.c
 Author      : MOHAMED MOSTAFA
 Description : Program file for DC-Motor Driver
 Date        : 14/10/2023
 ============================================================================
 */

#include "../Inc/STD_TYPES.h"
#include "../Inc/BIT_MATH.h"
#include "../Inc/GPIO_private.h"
#include "../Inc/GPIO_interface.h"
#include "../Inc/PWM.h"
#include "../Inc/MOTOR.h"


void DcMotor_Init(void)
{
	/*Configure the motor pins to be output pins*/
	GPIO_setupPinDirection(PORTB_ID, PIN0_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN1_ID, PIN_OUTPUT);

	/*Initialize the motor to be at steady state in the beginning*/
	GPIO_writePin(PORTB_ID, PIN0_ID, PIN_LOW) ;
	GPIO_writePin(PORTB_ID, PIN1_ID, PIN_LOW) ;
}

void DcMotor_Rotate(DcMotor_State state,u8 speed)
{

	PWM_Timer0_Start(speed);

	if (state == STOP )
	{
		GPIO_writePin(PORTB_ID, PIN0_ID, PIN_LOW) ;
		GPIO_writePin(PORTB_ID, PIN1_ID, PIN_LOW) ;
	}
	else if (state == CW)
	{
		GPIO_writePin(PORTB_ID, PIN0_ID, PIN_LOW) ;
		GPIO_writePin(PORTB_ID, PIN1_ID, PIN_HIGH) ;
	}
	else if (state == ACW)
	{
		GPIO_writePin(PORTB_ID, PIN0_ID, PIN_HIGH) ;
		GPIO_writePin(PORTB_ID, PIN1_ID, PIN_LOW) ;
	}


}


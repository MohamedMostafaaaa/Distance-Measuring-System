/*
 ============================================================================
 Name        : Fan Speed Controller
 Author      : MOHAMED MOSTAFA
 Description : Controls the speed of fan motor using PWM depending on the temperature of the room
 Date        : 14/10/2023
 ============================================================================
 */

/***************************************Includes***************************************/

#include <util/delay.h>
#include "../Inc/STD_TYPES.h"
#include "../Inc/BIT_MATH.h"
#include "../Inc/ADC_private.h"
#include "../Inc/ADC_interface.h"
#include "../Inc/ADC_config.h"
#include "../Inc/GPIO_private.h"
#include "../Inc/GPIO_interface.h"
#include "../Inc/PWM.h"
#include "../Inc/lcd.h"
#include "../Inc/MOTOR.h"


/**********************************Global variables**********************************/
u16 App_pu16Reading    = 0;
u8  App_MilliVolt      = 0 ;
u8  ADC_AppErrorState  = OK;

void main(void)
{
	/*****************************Initialize peripherals*****************************/
	ADC_voidInit(DIV_16,RIGHT_ADJUST);
	DcMotor_Init();
	LCD_init();

	/*Configure the ADC pin to be input pin*/
	GPIO_setupPinDirection(PORTA_ID, PIN0_ID, PIN_INPUT);


	/*Super Loop*/
	while(1)
	{
		/*	Move cursor to initial state	*/
		LCD_moveCursor(0,0);

		/*	Display temperature string on the LCD	*/
		LCD_displayString("Temperature: ");

		/*	Move cursor to the second row	*/
		LCD_moveCursor(1,0);

		/*	Display state string on the LCD	*/
		LCD_displayString("State: ");

		/*	ADC start conversion  */
		ADC_AppErrorState = ADC_u8StartConversionSynch(ADC0,&App_pu16Reading);

		/* Calculate the temperature from the ADC value*/
		App_MilliVolt = (u8)( ((u32) App_pu16Reading * 150 *2.6  ) / (1023*1.5) );

		/*	Move cursor to first row column 13 	*/
		LCD_moveCursor(0,13);

		/*	Display temperature state on the LCD  */
		LCD_intgerToString(App_MilliVolt);


		/*	Clean the extra character on the LCD  */
		if(App_MilliVolt < 100)
		{
			LCD_displayCharacter(' ');
		}

		/*	Move cursor to second row column 8	*/
		LCD_moveCursor(1,8);

		/*	Display motor state on the LCD  */
		if(App_MilliVolt <= 30)
		{
			LCD_displayString("OFF");
		}
		else
		{
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
		}


		/*	Control the motor speed based on the temperature value	*/
		if(App_MilliVolt <= 30)
		{
			/*	Motor stops   */
			DcMotor_Rotate(STOP,0);
		}
		else if((30 < App_MilliVolt)&&(App_MilliVolt <= 60))
		{
			/*	Motor Rotates CW with 25% duty cycle	*/
			DcMotor_Rotate(CW,25);
		}
		else if((60 < App_MilliVolt)&&(App_MilliVolt <= 90))
		{
			/*	Motor Rotates CW with 50% duty cycle	*/
			DcMotor_Rotate(CW,50);
		}
		else if((90 < App_MilliVolt)&&(App_MilliVolt <= 120))
		{
			/*	Motor Rotates CW with 75% duty cycle	*/
			DcMotor_Rotate(CW,75);
		}
		else if(App_MilliVolt > 120)
		{
			/*	Motor Rotates CW with 100% duty cycle	*/
			DcMotor_Rotate(CW,100);
		}
	}
}

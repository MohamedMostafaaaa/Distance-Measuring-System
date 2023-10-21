/*
 ============================================================================
 Name        : Distance Measuring System
 Author      : MOHAMED MOSTAFA
 Description : A system which measures the distance using UltraSonic sensor
 Date        : 21/10/2023
 ============================================================================
 */

/***************************************Includes***************************************/
#include <util/delay.h>
#include "../Inc/STD_TYPES.h"
#include "../Inc/BIT_MATH.h"
#include "../Inc/GPIO_private.h"
#include "../Inc/GPIO_interface.h"
#include "../Inc/lcd.h"
#include "../Inc/icu.h"
#include "../Inc/Ultra_sonic.h"
#include "../Inc/Global_Interrupt.h"


/**********************************Global variables**********************************/
u8 distance = 0;

void main(void)
{
/*******************************Initialize peripherals*******************************/
	GIE_Init();
	LCD_init();
	Ultrasonic_init();
	LCD_displayString("Distance = ");

	while(1)
	{
		distance = Ultrasonic_readDistance();
		LCD_moveCursor(0, 12);
		LCD_intgerToString(distance);
		LCD_displayString("cm");
	}

}

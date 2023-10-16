/*
 ============================================================================
 Name        : ADC_interface.h
 Author      : MOHAMED MOSTAFA
 Description : Program file for ADC Driver
 Date        : 13/10/2023
 ============================================================================
 */
 
#include "../Inc/STD_TYPES.h"
#include "../Inc/BIT_MATH.h"
#include "../Inc/ADC_private.h"
#include "../Inc/ADC_interface.h"
#include "../Inc/ADC_config.h"


static u16* ADC_pu16Reading = NULL ;
static void (*ADC_pvCallBackNotificationFunc)(void) = NULL ;
static u8 Global_u8BusyState = Idle ;

void ADC_voidInit(ADC_Prescalar copy_Prescalar, ADC_Adjusting copy_Adjust)
{
	
	/*Voltage Reference Selections*/
	ADMUX &= 0b00111111;
	ADMUX |= (ADC_VR << 6);
	
	/*ADC Adjusting*/
	ADMUX &= 0b11011111;
	ADMUX |= (copy_Adjust<<5) ;
		
	/*ADC Prescalar*/
	ADCSRA &= 0b00011111;
	ADCSRA |= copy_Prescalar ;
	
	/*ADC Enable*/
	SET_BIT(ADCSRA,7);
	
}


u8 ADC_u8StartConversionSynch(u8 copy_u8Channel, u16 *copy_pu16Reading)
{
	u32 Local_u32Counter = 0 ;
	u8 Local_u8ErrorState = OK ;
	
	
	/*	Check the pointers not equal NULL  */
	if(copy_pu16Reading == NULL)
	{
		Local_u8ErrorState = NULL_POINTER ;
	}
	else
	{
		/*	ADC Input channel bits	*/
		ADMUX &= 0b11100000;
		ADMUX |= copy_u8Channel ;
	
		/*	ADC Start conversion  */
		SET_BIT(ADCSRA,6);
	
		/*	Polling until the conversion flag is raised or time out is reached  */
		while((GET_BIT(ADCSRA,4)==0 )&&(Local_u32Counter != ADC_TimeOut))
		{
			Local_u32Counter ++;
		}
		if(Local_u32Counter == ADC_TimeOut)
		{
			/*Loop is broken because time out is reached*/
			Local_u8ErrorState = NOK ;
		}
		else
		{
			/*Loop is broken because flag is raised*/
			SET_BIT(ADCSRA,4) ;
		
			/*Right adjust case*/
			if(GET_BIT(ADMUX,5)==0)
			{
				/*	The values are in the LSB of ADC register, no need to shift	*/
				*copy_pu16Reading = ADC;
			}
			/*Left adjust case*/
			else
			{
				/*	The values are in the MSB of ADC register, so shifting right is needed  */
				*copy_pu16Reading = (ADC>>6);
			}
		
		}	
	
	}
	return Local_u8ErrorState ;
}

u8 ADC_u8StartConversionAsynch(u8 copy_u8Channel, u16 *copy_pu16Reading, void(*copy_pvCallBackNotificationFunc)(void))
{

	u8 Local_u8ErrorState = OK ;
	
	/*Busy check to avoid overwriting */
	if(Global_u8BusyState == Idle)
	{
		/*	Check the pointers not equal NULL  */
		if( (copy_pu16Reading == NULL)||(copy_pvCallBackNotificationFunc == NULL))
		{
			Local_u8ErrorState = NULL_POINTER ;
		}
		else
		{
			Global_u8BusyState = Busy ;
			/*Initialize the reading variable globally*/
			ADC_pu16Reading = copy_pu16Reading ;
		
			/*Initialize the call back notification function globally*/
			ADC_pvCallBackNotificationFunc = copy_pvCallBackNotificationFunc ;
		
			/*	ADC Input channel bits	*/
			ADMUX &= 0b11100000;
			ADMUX |= copy_u8Channel ;
	
			/*	Enable Interrupt	*/
			SET_BIT(ADCSRA,3);
	
			/*ADC Start conversion*/
			SET_BIT(ADCSRA,6);
		}
	}
	else
	{
		Local_u8ErrorState = BUSY_STATE ;
	}
	return Local_u8ErrorState ;
}


ISR(ADC_vect)
{
	/*Read the ADC Register*/
	
	/*Right adjust case*/
	if(GET_BIT(ADMUX,5)==0)
	{
		/*	The values are in the LSB of ADC register, no need to shift	*/
		*ADC_pu16Reading = ADC ;
	}
	/*Left adjust case*/
	else
	{
		/*	The values are in the MSB of ADC register, so shifting right is needed  */
		*ADC_pu16Reading = (ADC>>6);
	}
	
	/*	Make ADC idle  */
	Global_u8BusyState = Idle ;
	
	/*Invoke the call back notification function*/
	ADC_pvCallBackNotificationFunc();
	
	/*	Disable Interrupt	*/
	CLR_BIT(ADCSRA,3);
}

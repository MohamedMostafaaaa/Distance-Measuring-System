/*
 ============================================================================
 Name        : GPIO_program.h
 Author      : MOHAMED MOSTAFA
 Description : Program file for GPIO Driver
 Date        : 10/10/2023
 ============================================================================
 */
#include "../Inc/STD_TYPES.h"
#include "../Inc/BIT_MATH.h"
#include "../Inc/GPIO_private.h"
#include "../Inc/GPIO_interface.h"

int x =0;

void GPIO_setupPinDirection(u8 GPIO_PORT_ID, u8 GPIO_PIN_ID, GPIO_PinDirectionType direction)
{
	/* Range Check on PORT and PIN ID	*/
	if( (GPIO_PORT_ID < NUM_OF_PORTS)&& (GPIO_PIN_ID < NUM_OF_PINS_PER_PORT))
	{
		switch(GPIO_PORT_ID)
		{
		case PORTA_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRA, GPIO_PIN_ID);

			}
			else if (direction == PIN_INPUT)
			{
				CLR_BIT(DDRA, GPIO_PIN_ID);
			}
			else
			{
				/*	Do Nothing	*/
			}

			break;

		case PORTB_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRB,GPIO_PIN_ID);
			}
			else if (direction == PIN_INPUT)
			{
				CLR_BIT(DDRB,GPIO_PIN_ID);
			}
			else
			{
				/*	Do Nothing	*/
			}
			break;

		case PORTC_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRC,GPIO_PIN_ID);
			}
			else if (direction == PIN_INPUT)
			{
				CLR_BIT(DDRC,GPIO_PIN_ID);
			}
			else
			{
				/*	Do Nothing	*/
			}
			break;

		case PORTD_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRD,GPIO_PIN_ID);
			}
			else if (direction == PIN_INPUT)
			{
				CLR_BIT(DDRD,GPIO_PIN_ID);
			}
			else
			{
				/*	Do Nothing	*/
			}
			break;
		}

	}
	else
	{

	}
}
void GPIO_writePin(u8 GPIO_PORT_ID, u8 GPIO_PIN_ID, GPIO_PinValue Value)
{	
	/* Range Check on PORT and PIN ID	*/
	if( (GPIO_PORT_ID < NUM_OF_PORTS)&& (GPIO_PIN_ID < NUM_OF_PINS_PER_PORT))
	{
		switch(GPIO_PORT_ID)
		{
		case PORTA_ID:
			if(Value == PIN_HIGH)
			{
				SET_BIT(PORTA,GPIO_PIN_ID);
			}
			else if(Value == PIN_LOW)
			{
				CLR_BIT(PORTA,GPIO_PIN_ID);
			}

			break;

		case PORTB_ID:
			if(Value == PIN_HIGH)
			{
				SET_BIT(PORTB,GPIO_PIN_ID);
			}
			else if(Value == PIN_LOW)
			{
				CLR_BIT(PORTB,GPIO_PIN_ID);
			}
			break;

		case PORTC_ID:
			if(Value == PIN_HIGH)
			{
				SET_BIT(PORTC,GPIO_PIN_ID);
			}
			else if(Value == PIN_LOW)
			{
				CLR_BIT(PORTC,GPIO_PIN_ID);
			}
			break;

		case PORTD_ID:
			if(Value == PIN_HIGH)
			{
				SET_BIT(PORTD,GPIO_PIN_ID);
			}
			else if(Value == PIN_LOW)
			{
				CLR_BIT(PORTD,GPIO_PIN_ID);
			}
			break;
		}
	}
	else
	{

	}
}
u8 GPIO_readPin(u8 GPIO_PORT_ID, u8 GPIO_PIN_ID)
{
	u8 Pinread = 0xFF ;

	/* Range Check on PORT and PIN ID	*/
	if( (GPIO_PORT_ID < NUM_OF_PORTS)&& (GPIO_PIN_ID < NUM_OF_PINS_PER_PORT))
	{
		switch(GPIO_PORT_ID)
		{
		case PORTA_ID:
			Pinread = GET_BIT(PINA,GPIO_PIN_ID);
			break;

		case PORTB_ID:
			Pinread = GET_BIT(PINB,GPIO_PIN_ID);
			break;

		case PORTC_ID:
			Pinread = GET_BIT(PINC,GPIO_PIN_ID);
			break;

		case PORTD_ID:
			Pinread = GET_BIT(PIND,GPIO_PIN_ID);
			break;
		}
	}
	else
	{
		/*Do nothing*/
	}
	return Pinread;
}

void GPIO_setupPortDirection(u8 GPIO_PORT_ID, GPIO_PinDirectionType direction)
{
	/* Range Check on PORT ID	*/
	if(GPIO_PORT_ID < NUM_OF_PORTS)
	{
		switch(GPIO_PORT_ID)
		{
		case PORTA_ID:
			if(direction == PIN_OUTPUT)
			{
				DDRA = 0xFF;

			}
			else if (direction == PIN_INPUT)
			{
				DDRA = 0x00;
			}
			else
			{
				/*	Do Nothing	*/
			}

			break;

		case PORTB_ID:
			if(direction == PIN_OUTPUT)
			{
				DDRB = 0xFF;
			}
			else if (direction == PIN_INPUT)
			{
				DDRB = 0x00;
			}
			else
			{
				/*	Do Nothing	*/
			}
			break;

		case PORTC_ID:
			if(direction == PIN_OUTPUT)
			{
				DDRC = 0xFF;
			}
			else if (direction == PIN_INPUT)
			{
				DDRC = 0x00;
			}
			else
			{
				/*	Do Nothing	*/
			}
			break;

		case PORTD_ID:
			if(direction == PIN_OUTPUT)
			{
				DDRD = 0xFF;
			}
			else if (direction == PIN_INPUT)
			{
				DDRD = 0x00;
			}
			else
			{
				/*	Do Nothing	*/
			}
			break;
		}

	}
	else
	{

	}
}

void GPIO_writePort(u8 GPIO_PORT_ID, GPIO_PinValue Value)
{
	/* Range Check on PORT ID	*/
	if(GPIO_PORT_ID < NUM_OF_PORTS)
	{
		switch(GPIO_PORT_ID)
		{
		case PORTA_ID:

			PORTA = Value;

			break;

		case PORTB_ID:

			PORTB = Value;

			break;

		case PORTC_ID:

			PORTC = Value;

			break;

		case PORTD_ID:

			PORTD = Value;

			break;
		}
	}
	else
	{

	}
}

u8 GPIO_readPort(u8 GPIO_PORT_ID)
{
	u8 Portread = 0xFF ;

	/* Range Check on PORT ID	*/
	if(GPIO_PORT_ID < NUM_OF_PORTS)
	{
		switch(GPIO_PORT_ID)
		{
		case PORTA_ID:
			Portread =PINA;
			break;

		case PORTB_ID:
			Portread =PINB;
			break;

		case PORTC_ID:
			Portread =PINC;
			break;

		case PORTD_ID:
			Portread =PIND;
			break;
		}
	}
	else
	{
		/*Do nothing*/
	}
	return Portread;
}

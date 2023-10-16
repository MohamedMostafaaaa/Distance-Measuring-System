/*
 ============================================================================
 Name        : GPIO_interface.h
 Author      : MOHAMED MOSTAFA
 Description : Interface Header file for GPIO Driver
 Date        : 10/10/2023
 ============================================================================
 */
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H
 

 /*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define NUM_OF_PORTS           4
#define NUM_OF_PINS_PER_PORT   8

#define PORTA_ID               0
#define PORTB_ID               1
#define PORTC_ID               2
#define PORTD_ID               3

#define PIN0_ID                0
#define PIN1_ID                1
#define PIN2_ID                2
#define PIN3_ID                3
#define PIN4_ID                4
#define PIN5_ID                5
#define PIN6_ID                6
#define PIN7_ID                7

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	PIN_INPUT,PIN_OUTPUT
}GPIO_PinDirectionType;

typedef enum
{
	PIN_LOW,PIN_HIGH
}GPIO_PinValue;



/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 *Arguments Options:
 *port_num :	PORTA_ID	PORTB_ID	PORTC_ID	PORTD_ID	
 *pin_num:		PIN0_ID		PIN1_ID		PIN2_ID		PIN3_ID		PIN4_ID		PIN5_ID		PIN6_ID		PIN7_ID
 *direction:	PIN_INPUT	PIN_OUTPUT
*/

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void GPIO_setupPinDirection(u8 GPIO_PORT_ID, u8 GPIO_PIN_ID, GPIO_PinDirectionType direction);


/*
 *Arguments Options:
 *port_num :	PORTA_ID	PORTB_ID	PORTC_ID	PORTD_ID	
 *pin_num:		PIN0_ID		PIN1_ID		PIN2_ID		PIN3_ID		PIN4_ID		PIN5_ID		PIN6_ID		PIN7_ID
 *value:		PIN_LOW		PIN_HIGH
*/

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void GPIO_writePin(u8 GPIO_PORT_ID, u8 GPIO_PIN_ID, GPIO_PinValue Value);


/*
 *Arguments Options:
 *port_num :	PORTA_ID	PORTB_ID	PORTC_ID	PORTD_ID	
 *pin_num:		PIN0_ID		PIN1_ID		PIN2_ID		PIN3_ID		PIN4_ID		PIN5_ID		PIN6_ID		PIN7_ID
*/

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
u8 GPIO_readPin(u8 GPIO_PORT_ID, u8 GPIO_PIN_ID);



/*
 *Arguments Options:
 *port_num :	PORTA_ID	PORTB_ID	PORTC_ID	PORTD_ID
 *direction:	PIN_INPUT	PIN_OUTPUT
*/

/*
 * Description :
 * Setup the direction of the required port input/output.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_setupPortDirection(u8 GPIO_PORT_ID, GPIO_PinDirectionType direction);



/*
 *Arguments Options:
 *port_num :	PORTA_ID	PORTB_ID	PORTC_ID	PORTD_ID	
 *value:		PIN_LOW		PIN_HIGH
*/

/*
 * Description :
 * Write the value Logic High or Logic Low on the required port.
 * If the input port number is not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void GPIO_writePort(u8 GPIO_PORT_ID, GPIO_PinValue Value);



/*
 *Arguments Options:
 *port_num :	PORTA_ID	PORTB_ID	PORTC_ID	PORTD_ID
*/

/*
 * Description :
 * Read and return the value for the required port, it should be Logic High or Logic Low.
 * If the input port number is not correct, The function will return Logic Low.
 */
u8 GPIO_readPort(u8 GPIO_PORT_ID);


#endif

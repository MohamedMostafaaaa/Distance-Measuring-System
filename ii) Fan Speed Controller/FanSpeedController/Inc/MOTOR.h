/*
 ============================================================================
 Name        : MOTOR.h
 Author      : MOHAMED MOSTAFA
 Description : Header file for DC-Motor Driver
 Date        : 14/10/2023
 ============================================================================
 */

#ifndef MOTOR_H_
#define MOTOR_H_

/*DcMotor_State data type
 * Options:
 * 1- STOP:	Motor stops
 * 2-   CW: Motor rotates clockwise
 * 3-  ACW: Motor rotates Anti-clockwise
 * */
typedef enum
{
	STOP,CW,ACW
}DcMotor_State;


/*Description:
 * The Function responsible for setup the direction for the two motor pins through the GPIO driver.
 * Stop at the DC-Motor at the beginning through the GPIO driver.
 * Inputs: None
 * Return: None
*/
void DcMotor_Init(void);




/*Description:
 * The function responsible for rotate the DC Motor CW/ or A-CW or stop the motor based
   on the state input state value.
 * Send the required duty cycle to the PWM driver based on the required speed value.
 * Inputs:
         1-state: The required DC Motor state, it should be CW or A-CW or stop.
         DcMotor_State data type are declared as enum.
         2-speed: decimal value for the required motor speed, it should be from 0 → 100.
          For example, if the input is 50, The motor should rotate with 50% of its maximum speed.
 * Return: None
*/
void DcMotor_Rotate(DcMotor_State state,u8 speed);

#endif /* MOTOR_H_ */

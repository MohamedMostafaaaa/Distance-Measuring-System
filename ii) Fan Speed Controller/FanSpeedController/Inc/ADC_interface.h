/*
 ============================================================================
 Name        : ADC_interface.h
 Author      : MOHAMED MOSTAFA
 Description : Interface Header file for ADC Driver
 Date        : 13/10/2023
 ============================================================================
 */
 
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define	ADC_AREF_OFF	0
#define	ADC_AVCC		1
#define ADC_INTERNAL	3


#define OK				1
#define NOK				2
#define NULL_POINTER	3
#define BUSY_STATE		4


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	ADC0,                 	/*	Single ended input on ADC Channel '0'	*/
	ADC1,                 	/*	Single ended input on ADC Channel '1'	*/
	ADC2,                 	/*	Single ended input on ADC Channel '2'	*/
	ADC3,                 	/*	Single ended input on ADC Channel '3'	*/
	ADC4,                 	/*	Single ended input on ADC Channel '4'	*/
	ADC5,                 	/*	Single ended input on ADC Channel '5'	*/
	ADC6,                 	/*	Single ended input on ADC Channel '6'	*/
	ADC7,                 	/*	Single ended input on ADC Channel '7'	*/
	ADC0_ADC0_10,           /*	PDI on ADC Channel '0' & NDI on ADC Channel '0'	& Gain '10'   */
	ADC1_ADC0_10,           /*	PDI on ADC Channel '1' & NDI on ADC Channel '0'	& Gain '10'   */
	ADC0_ADC0_200,          /*	PDI on ADC Channel '0' & NDI on ADC Channel '0'	& Gain '200'  */
	ADC1_ADC0_200,          /*	PDI on ADC Channel '1' & NDI on ADC Channel '0'	& Gain '200'  */
	ADC2_ADC2_10,           /*	PDI on ADC Channel '2' & NDI on ADC Channel '0'	& Gain '10'   */
	ADC3_ADC2_10,           /*	PDI on ADC Channel '3' & NDI on ADC Channel '0'	& Gain '10'   */
	ADC2_ADC2_200,          /*	PDI on ADC Channel '2' & NDI on ADC Channel '0'	& Gain '200'  */
	ADC3_ADC2_200,          /*	PDI on ADC Channel '3' & NDI on ADC Channel '0'	& Gain '200'  */
	ADC0_ADC1_1,            /*	PDI on ADC Channel '0' & NDI on ADC Channel '1'	& Gain '1'    */
	ADC1_ADC1_1,            /*	PDI on ADC Channel '1' & NDI on ADC Channel '1'	& Gain '1'    */
	ADC2_ADC1_1,            /*	PDI on ADC Channel '2' & NDI on ADC Channel '1'	& Gain '1'    */
	ADC3_ADC1_1,            /*	PDI on ADC Channel '3' & NDI on ADC Channel '1'	& Gain '1'    */
	ADC4_ADC1_1,            /*	PDI on ADC Channel '4' & NDI on ADC Channel '1'	& Gain '1'    */
	ADC5_ADC1_1,            /*	PDI on ADC Channel '5' & NDI on ADC Channel '1'	& Gain '1'    */
	ADC6_ADC1_1,            /*	PDI on ADC Channel '6' & NDI on ADC Channel '1'	& Gain '1'    */
	ADC7_ADC1_1,            /*	PDI on ADC Channel '7' & NDI on ADC Channel '1'	& Gain '1'    */
	ADC0_ADC2_1,            /*	PDI on ADC Channel '0' & NDI on ADC Channel '2'	& Gain '1'    */
	ADC1_ADC2_1,            /*	PDI on ADC Channel '1' & NDI on ADC Channel '2'	& Gain '1'    */
	ADC2_ADC2_1,            /*	PDI on ADC Channel '2' & NDI on ADC Channel '2'	& Gain '1'    */
	ADC3_ADC2_1,            /*	PDI on ADC Channel '3' & NDI on ADC Channel '2'	& Gain '1'    */
	ADC4_ADC2_1,            /*	PDI on ADC Channel '4' & NDI on ADC Channel '2'	& Gain '1'    */
	ADC5_ADC2_1             /*	PDI on ADC Channel '5' & NDI on ADC Channel '2'	& Gain '1'    */
}ADC_InputChannel;
 
typedef enum
{
	DIV_2,					/*	Divide the CPU Clock by 2    */
	DIV_4,					/*	Divide the CPU Clock by 4    */
	DIV_8,					/*	Divide the CPU Clock by 8    */
	DIV_16,					/*	Divide the CPU Clock by 16   */
	DIV_32,					/*	Divide the CPU Clock by 32   */
	DIV_64,					/*	Divide the CPU Clock by 64   */
	DIV_128			        /*	Divide the CPU Clock by 128  */
}ADC_Prescalar;

typedef enum
{
	RIGHT_ADJUST,			    /*	Right adjusting   */
	LEFT_ADJUST					/*	Left adjusting    */

}ADC_Adjusting;
 
/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/ 
 
void ADC_voidInit(ADC_Prescalar copy_Prescalar, ADC_Adjusting copy_Adjusting);
u8 ADC_u8StartConversionSynch(u8 copy_u8Channel, u16 *copy_pu16Reading);
u8 ADC_u8StartConversionAsynch(u8 copy_u8Channel, u16 *copy_pu16Reading, void(*copy_pvCallBackNotificationFunc)(void));


#endif

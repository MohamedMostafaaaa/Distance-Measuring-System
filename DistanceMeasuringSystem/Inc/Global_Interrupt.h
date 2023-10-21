/*
 ============================================================================
 Name        : Global_Interrupt.h
 Author      : Mohamed Mostafa
 Description : Header file for Global Interrupt Enable
 Date        : 13/10/2023
 ============================================================================
 */
 
#ifndef	GLOBAL_INTERRUPT_H
#define	GLOBAL_INTERRUPT_H

 /*******************************************************************************
 *                               	  Registers                                 *
 *******************************************************************************/

#define SREG	(*(volatile u8 *const)0x005F)

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
 
 
/*Description:
 * Function to enable the global interrupt 
 */
 
void GIE_Init(void);
 
 
#endif
/*
 ============================================================================
 Name        : Global_Interrupt.h
 Author      : Mohamed Mostafa
 Description : Program file for Global Interrupt Enable
 Date        : 13/10/2023
 ============================================================================
 */
 
#include "../Inc/STD_TYPES.h"
#include "../Inc/BIT_MATH.h"
#include "../Inc/Global_Interrupt.h"
 
 

 void GIE_Init(void)
 {
	 SET_BIT(SREG,7); 
 }

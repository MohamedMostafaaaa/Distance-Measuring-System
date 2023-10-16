/*
 ============================================================================
 Name        : GPIO_private.h
 Author      : MOHAMED MOSTAFA
 Description : Private Header file for GPIO Driver
 Date        : 10/10/2023
 ============================================================================
 */
 
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H
 
 
 /* Definition for PORTA Registers */
#define PORTA	(*(volatile u8 * const)0x003B)
#define DDRA	(*(volatile u8 * const)0x003A)
#define PINA 	(*(volatile const u8 * const)0x0039)

/* Definition for PORTB Registers */
#define PORTB	(*(volatile u8 * const)0x0038)
#define DDRB	(*(volatile u8 * const)0x0037)
#define PINB 	(*(volatile const u8 * const)0x0036)

/* Definition for PORTC Registers */
#define PORTC	(*(volatile u8 * const)0x0035)
#define DDRC	(*(volatile u8 * const)0x0034)
#define PINC 	(*(volatile const u8 * const)0x0033)

/* Definition for PORTD Registers */
#define PORTD	(*(volatile u8 * const)0x0032)
#define DDRD	(*(volatile u8 * const)0x0031)
#define PIND 	(*(volatile const u8 * const)0x0030)




#endif

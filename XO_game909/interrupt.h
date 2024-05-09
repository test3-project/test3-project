

/**********************************************************************************************************
 * File Name: gpio.c
 *
 * Team Members : Toqa Sameh - Mariam Reda - Nermeen Ahmed - Amna Ali - Bassant Ehab - Rawan Mohamed 
 *********************************************************************************************************/
 
#ifndef INTERRUPT_H_
#define INTERRUPT_H_
 
#include "./images/Types.h"
#include "tm4c123gh6pm11.h" 

 /************************************************************************************
 * function Name : NVIC_Enable
 * Parameters   : InterruptNumber
 * Return value : None
 * Description  : function to  enable interrupts
 ************************************************************************************/
 void NVIC_Enable( uint8 InterruptNumber);


 /************************************************************************************
 * function Name : NVIC_Enable
 * Parameters   : InterruptNumber
 * Return value : None
 * Description  : function to Disenable interrupts
 ************************************************************************************/
void NVIC_Disable(uint8 InterruptNumber);

void NVIC_ClearPendingFlag(uint8 InterruptNumber);
void NVIC_SetPendingFlag(uint8 InterruptNumber);

#endif

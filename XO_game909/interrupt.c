
/**********************************************************************************************************
 * File Name: gpio.c
 *
 * Team Members : Toqa Sameh - Mariam Reda - Nermeen Ahmed - Amna Ali - Bassant Ehab - Rawan Mohamed 
 *********************************************************************************************************/
 
 #include "interrupt.h"
 
 /************************************************************************************
 * function Name : NVIC_Enable
 * Parameters   : InterruptNumber
 * Return value : None
 * Description  : function to  enable interrupts
 ************************************************************************************/
 
 void NVIC_Enable( uint8 InterruptNumber)
{
    if(InterruptNumber <= 31)
    {
        NVIC_EN0_R = (1 << InterruptNumber);
    }
    else if(InterruptNumber <= 63)
    {
        InterruptNumber -= 32;
        NVIC_EN1_R = (1 << InterruptNumber);
    }
		 else if(InterruptNumber <= 95)
    {
        InterruptNumber -= (2*32);
        NVIC_EN2_R = (1 << InterruptNumber);
    }
		
		 else if(InterruptNumber <= 127)
    {
        InterruptNumber -= (3*32);
        NVIC_EN3_R = (1 << InterruptNumber);
    }
		
}

 /************************************************************************************
 * function Name : NVIC_Enable
 * Parameters   : InterruptNumber
 * Return value : None
 * Description  : function to Disenable interrupts
 ************************************************************************************/
void NVIC_Disable(uint8 InterruptNumber)
{
    if(InterruptNumber <= 31)
    {
        NVIC_DIS0_R = (1 << InterruptNumber);
    }
    else if(InterruptNumber <= 63)
    {
        InterruptNumber -= 32;
        NVIC_DIS1_R = (1 << InterruptNumber);
    }
		
		else if(InterruptNumber <= 95)
    {
        InterruptNumber -= (2*32);
        NVIC_DIS2_R = (1 << InterruptNumber);
    }
		
		else if(InterruptNumber <= 127)
    {
        InterruptNumber -= (3*32);
        NVIC_DIS3_R = (1 << InterruptNumber);
    }
		
}

void NVIC_SetPendingFlag(uint8 InterruptNumber)
{
    if(InterruptNumber <= 31)
    {
        NVIC_PEND0_R = (1 << InterruptNumber);
    }
    else if(InterruptNumber <= 63)
    {
        InterruptNumber -= 32;
       NVIC_PEND1_R= (1 << InterruptNumber);
    }
}

void NVIC_ClearPendingFlag(uint8 InterruptNumber)
{
    if(InterruptNumber <= 31)
    {
        NVIC_UNPEND0_R = (1 << InterruptNumber);
    }
    else if(InterruptNumber <= 63)
    {
        InterruptNumber -= 32;
       NVIC_UNPEND1_R = (1 << InterruptNumber);
    }
}

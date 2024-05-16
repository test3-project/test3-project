
/**********************************************************************************************************
 * File Name: gpio.c
 *
 * Team Members : Toqa Sameh - Mariam Reda - Nermeen Ahmed - Amna Ali - Bassant Ehab - Rawan Mohamed 
 *********************************************************************************************************/
/* File Guarding */
#ifndef GPIO_H_
#define GPIO_H_
/********************* INCLUDES ****************************************************************************/
#include "./images/types.h"
#include "tm4c123gh6pm11.h"

typedef enum
{
    GPIOA = 0,
    GPIOB,
    GPIOC,
    GPIOD,
    GPIOE,
    GPIOF
}GPIO_PORT;

typedef enum
{
    PIN0 = 0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7 
}GPIO_PIN;

typedef enum
{
    INPUT = 0,
    OUTPUT
}PIN_DIRECTION;

typedef enum
{
    LOW = 0,
    HIGH
}PIN_VALUE;

typedef enum
{
   DISABLE =0 ,
   ENABLE
}Digital_Enable;

typedef enum
{
   PULL__DISABLE =0 ,
   PULL_ENABLE
}PULL_Enable;

typedef enum
{
   SENSE_EDGE =0 ,
   SENSE_LEVEL
}SENSE_SELECT;

typedef enum
{
   FALLING_EDGE =0 ,
   RISING_EDGE
}EDGE_SELECT;


typedef enum
{
    SINGLE_EDGE =0 ,
    BOTH_EDGE
}BOTH_EDGE_SELECT;

/******************* Functions ProtoTypes *******************************************/

 /************************************************************************************
 * function Name : GPIO_SetPinDirection
 * Parameters   : Port - PinNumber - Direction (INPUT - OUTPUT)
 * Return value : None
 * Description  : function to set the direction of pins
 ************************************************************************************/
void GPIO_SetPinDirection( GPIO_PORT portNum, GPIO_PIN pinNum,PIN_DIRECTION pinDirection);


/************************************************************************************
 * Function Name  : GPIO_writePin
 * Parameters (in): Port - PinNumber - PinValue (LOW - HIGH )
 * Return value   : None
 * Description    : function to set the the value of pins
 ************************************************************************************/
void GPIO_writePin( GPIO_PORT portNum, GPIO_PIN pinNum, PIN_VALUE pinValue);


/************************************************************************************
 * Function Name  : GPIO_ReadPin
 * Parameters     : Port - PinNumber 
 * Return value   : uint8 PinValue
 * Description    : function to get the value of pins
 ************************************************************************************/
 uint8 GPIO_ReadPinValue( GPIO_PORT portNum, GPIO_PIN pinNum );
 

 /************************************************************************************
 * Function Name :GPIO_vidSetPinDigEnable
 * Parameters    : Port - PinNumber - DigEnable (ENABLE - DISABLE )
 * Return value  : None
 * Description   : function to set digital pins
 ************************************************************************************/
void GPIO_DigitalEnable(GPIO_PORT portNum, GPIO_PIN pinNum, Digital_Enable DigitalEnable );


/************************************************************************************
 * Function Name   :GPIO_PullUp
 * Parameters (in): Port - PinNumber - PURConfig (ENABLE - DISABLE)
 * Return value   : None
 * Description    : function to set pull up resistors for pins
 ************************************************************************************/
void GPIO_PullUp(GPIO_PORT portNum, GPIO_PIN pinNum, uint8  PU_Config);


/************************************************************************************
 * Function Name   :GPIO_PullDown
 * Parameters (in): Port - PinNumber - PURConfig (ENABLE - DISABLE)
 * Return value   : None
 * Description    : function to set pull Down resistors for pins
 ************************************************************************************/
void GPIO_PullDown(GPIO_PORT portNum, GPIO_PIN pinNum, uint8  PD_Config);

 /************************************************************************************
 * Function Name : GPIO_SelectAlterFunction
 * Parameters    : Port - PinNumber 
 * Return value  : None
 * Description   : function to set the alternate function for pins
 ************************************************************************************/
void GPIO_SelectAlterFunction(GPIO_PORT portNum, GPIO_PIN pinNum);

/************************************************************************************
 * Function Name  :GPIO_EnableInterrupt
 * Parameters    : Port - PinNumber
 * Return value  : None
 * Description   : function to enable interrupts for pins
 ************************************************************************************/
void GPIO_EnableInterrupt(GPIO_PORT portNum, GPIO_PIN pinNum);

/************************************************************************************
 * Function Name  :GPIO_DisableInterrupt
 * Parameters    : Port - PinNumber
 * Return value  : None
 * Description   : function to Disable interrupts for pins
 ************************************************************************************/
void GPIO_DisableInterrupt(GPIO_PORT portNum, GPIO_PIN pinNum);

/************************************************************************************
 * Function Name   : GPIO_SelectInterruptSense
 * Parameters      : Port - PinNumber - Sense (EGGE - LEVEL)
 * Return value    : None
 * Description     : function to select interrupt detection mechanism for pins
 ************************************************************************************/
void GPIO_SelectInterruptSense(GPIO_PORT portNum, GPIO_PIN pinNum, uint8 Sense);

/************************************************************************************
 * Function Name :GPIO_ClearInterrupts
 * Parameters   : Port - PinNumber 
 * Return value : None
 * Description  : function to Clear Interrups for pins
 ************************************************************************************/
void GPIO_ClearInterrupt(GPIO_PORT portNum, GPIO_PIN pinNum);

/************************************************************************************
 * Function Name:GPIO_SelectInterruptEvent
 * Parameters   : Port - PinNumber 
 * Return value : None
 * Description  : function to Select Interrup Event for pins
 ************************************************************************************/
void GPIO_SelectInterruptEvent(GPIO_PORT portNum, GPIO_PIN pinNum, uint8 Event);
 
 /************************************************************************************
 * Function Name:GPIO_InterruptBothEdges
 * Parameters   : Port - PinNumber - uint8 BothEdges
 * Return value : None
 * Description  : function to Select Interrupt BothEdges for pins
 ************************************************************************************/
void GPIO_InterruptBothEdges(GPIO_PORT portNum, GPIO_PIN pinNum, uint8 BothEdges);
void EnableInterrupts(void);  // Enable interrupts
void PortB_Init(void);
void PortF_Init(void);

#endif

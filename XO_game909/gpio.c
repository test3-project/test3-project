/*********************************INCLUDES*****************************/
#include "GPIO.h"
#include "MACROS.h"
/*********************************Global Variabels*****************************/
volatile unsigned long delay;
/*********************************Functions_Description *****************************/
 /************************************************************************************
 * function Name : GPIO_SetPinDirection
 * Parameters   : Port - PinNumber - Direction (INPUT - OUTPUT)
 * Return value : None
 * Description  : function to set the direction of pins
 ************************************************************************************/
void GPIO_SetPinDirection( GPIO_PORT portNum, GPIO_PIN pinNum,PIN_DIRECTION pinDirection) {
	switch (portNum) {
		case GPIOA:
			if (pinDirection == OUTPUT) {
				SET_BIT(GPIO_PORTA_DIR_R,pinNum);	
			}
			else {
				CLEAR_BIT(GPIO_PORTA_DIR_R,pinNum);
			}
			break;
			
		case GPIOB:
		if (pinDirection == OUTPUT) {
				SET_BIT(GPIO_PORTB_DIR_R,pinNum);	
		    	}
			else {
				CLEAR_BIT(GPIO_PORTB_DIR_R,pinNum);
			}
			break;
			
		case GPIOC:
		if (pinDirection == OUTPUT) {
				SET_BIT(GPIO_PORTC_DIR_R,pinNum);	
			}
			else {
				CLEAR_BIT(GPIO_PORTC_DIR_R,pinNum);
			}
			break;
			
		case GPIOD:
		if (pinDirection == OUTPUT) {
				SET_BIT(GPIO_PORTD_DIR_R,pinNum);	
			}
			else {
				CLEAR_BIT(GPIO_PORTD_DIR_R,pinNum);
			}break;
			
		case GPIOE:
			if (pinDirection == OUTPUT) {
				SET_BIT(GPIO_PORTE_DIR_R,pinNum);	
			}
			else {
				CLEAR_BIT(GPIO_PORTE_DIR_R,pinNum);
			}
			break;
			
		case GPIOF:
		if (pinDirection == OUTPUT) {
				SET_BIT(GPIO_PORTF_DIR_R,pinNum);	
			}
			else {
				CLEAR_BIT(GPIO_PORTF_DIR_R,pinNum);
			}
			break;
	}

}


/************************************************************************************
 * Function Name  : GPIO_writePin
 * Parameters (in): Port - PinNumber - PinValue (LOW - HIGH )
 * Return value   : None
 * Description    : function to set the the value of pins
 ************************************************************************************/
void GPIO_writePin( GPIO_PORT portNum, GPIO_PIN pinNum, PIN_VALUE pinValue) {
	switch (portNum) {
		case GPIOA:
			if (pinValue == HIGH) {
				SET_BIT(GPIO_PORTA_DATA_R,pinNum);	
			}
			else {
				CLEAR_BIT(GPIO_PORTA_DATA_R,pinNum);
			}
			break;
			
		case GPIOB:
			if (pinValue == HIGH) {
						SET_BIT(GPIO_PORTA_DATA_R,pinNum);	
		    	}
			else {
				CLEAR_BIT(GPIO_PORTA_DATA_R,pinNum);
			}
			break;
			
		case GPIOC:
			if (pinValue == HIGH) {
				SET_BIT(GPIO_PORTA_DATA_R,pinNum);	
		    	}
			else {
				CLEAR_BIT(GPIO_PORTA_DATA_R,pinNum);
			}
			break;
			
		case GPIOD:
			if (pinValue == HIGH) {
				SET_BIT(GPIO_PORTA_DATA_R,pinNum);	
		    	}
			else {
				CLEAR_BIT(GPIO_PORTA_DATA_R,pinNum);
			}
			break;
			
		case GPIOE:
			if (pinValue == HIGH) {
				SET_BIT(GPIO_PORTA_DATA_R,pinNum);	
		    	}
			else {
				CLEAR_BIT(GPIO_PORTA_DATA_R,pinNum);
			}
			break;
			
		case GPIOF:
			if (pinValue == HIGH) {
				SET_BIT(GPIO_PORTA_DATA_R,pinNum);	
		    	}
			else {
				CLEAR_BIT(GPIO_PORTA_DATA_R,pinNum);
			}
			break;
	}
}


/************************************************************************************
 * Function Name  : GPIO_ReadPin
 * Parameters     : Port - PinNumber 
 * Return value   : uint8 PinValue
 * Description    : function to get the value of pins
 ************************************************************************************/
 uint8 GPIO_ReadPinValue( GPIO_PORT portNum, GPIO_PIN pinNum )
{
     uint8 returned_val=0;

	switch(portNum)
	{
		case GPIOA:
			returned_val = GET_BIT(GPIO_PORTA_DATA_R,pinNum);
			break;
		case GPIOB:
			returned_val = GET_BIT(GPIO_PORTB_DATA_R,pinNum);
			break;
		case GPIOC:
			returned_val = GET_BIT(GPIO_PORTC_DATA_R,pinNum);
			break;
		case GPIOD:
			returned_val = GET_BIT(GPIO_PORTD_DATA_R,pinNum);
			break;
		case GPIOE:
			returned_val = GET_BIT(GPIO_PORTE_DATA_R,pinNum);
			break;
		case GPIOF:
			returned_val = GET_BIT(GPIO_PORTF_DATA_R,pinNum);
			break;
	}
	return returned_val;
}

/************************************************************************************
 * Function Name :GPIO_vidSetPinDigEnable
 * Parameters    : Port - PinNumber - DigEnable (ENABLE - DISABLE )
 * Return value  : None
 * Description   : function to set digital pins
 ************************************************************************************/
void GPIO_DigitalEnable(GPIO_PORT portNum, GPIO_PIN pinNum, Digital_Enable DigitalEnable ) {
	switch (portNum) {
		case GPIOA:
			if (DigitalEnable == ENABLE) {
				SET_BIT(GPIO_PORTA_DEN_R,pinNum);	
			}
			else {
				CLEAR_BIT(GPIO_PORTA_DEN_R,pinNum);
			}
			break;
			
		case GPIOB:
			if (DigitalEnable == ENABLE) {
				SET_BIT(GPIO_PORTA_DEN_R,pinNum);	
			}
			else {
				CLEAR_BIT(GPIO_PORTA_DEN_R,pinNum);
			}
				break;
			
		case GPIOC:
			if (DigitalEnable == ENABLE) {
				SET_BIT(GPIO_PORTA_DEN_R,pinNum);	
			}
			else {
				CLEAR_BIT(GPIO_PORTA_DEN_R,pinNum);
			}
				break;
			
		case GPIOD:
			if (DigitalEnable == ENABLE) {
				SET_BIT(GPIO_PORTA_DEN_R,pinNum);	
			}
			else {
				CLEAR_BIT(GPIO_PORTA_DEN_R,pinNum);
			}
		case GPIOE:
			if (DigitalEnable == ENABLE) {
				SET_BIT(GPIO_PORTA_DEN_R,pinNum);	
			}
			else {
				CLEAR_BIT(GPIO_PORTA_DEN_R,pinNum);
	          }
				break;
						
	    case GPIOF:
			if (DigitalEnable == ENABLE) {
				SET_BIT(GPIO_PORTA_DEN_R,pinNum);	
			}
			else {
				CLEAR_BIT(GPIO_PORTA_DEN_R,pinNum);
	          }
			break;
			}
}


/************************************************************************************
 * Function Name   :GPIO_PullUp
 * Parameters (in): Port - PinNumber - PURConfig (ENABLE - DISABLE)
 * Return value   : None
 * Description    : function to set pull up resistors for pins
 ************************************************************************************/
void GPIO_PullUp(GPIO_PORT portNum, GPIO_PIN pinNum, uint8  PU_Config)
{
switch (portNum) {
		case GPIOA:
			if (PU_Config == PULL_ENABLE) {
				SET_BIT(GPIO_PORTA_PUR_R, pinNum);	
			}
			else {
				CLEAR_BIT(GPIO_PORTA_PUR_R, pinNum);
			}
			break;
			
		case GPIOB:
			if (PU_Config == PULL_ENABLE) {
				SET_BIT(GPIO_PORTB_PUR_R, pinNum);	
			}
			else {
				CLEAR_BIT(GPIO_PORTB_PUR_R, pinNum);
			}
			break;
			
		case GPIOC:
			if (PU_Config == PULL_ENABLE) {
				SET_BIT(GPIO_PORTC_PUR_R, pinNum);	
			}
			else {
				CLEAR_BIT(GPIO_PORTC_PUR_R, pinNum);
			}
			break;
			
		case GPIOD:
			if (PU_Config == PULL_ENABLE) {
				SET_BIT(GPIO_PORTD_PUR_R, pinNum);
			}
			else {
				CLEAR_BIT(GPIO_PORTD_PUR_R, pinNum);
			}
			break;
			
		case GPIOE:
			if (PU_Config == PULL_ENABLE) {
				SET_BIT(GPIO_PORTE_PUR_R, pinNum);
			}
			else {
				CLEAR_BIT(GPIO_PORTE_PUR_R, pinNum);
			}
			break;
			
		case GPIOF:
			if (PU_Config == PULL_ENABLE) {
				SET_BIT(GPIO_PORTF_PUR_R, pinNum);
			}
			else {
				CLEAR_BIT(GPIO_PORTF_PUR_R, pinNum);
			}
			break;
	}
}


/************************************************************************************
 * Function Name   :GPIO_PullDown
 * Parameters (in): Port - PinNumber - PURConfig (ENABLE - DISABLE)
 * Return value   : None
 * Description    : function to set pull up resistors for pins
 ************************************************************************************/
void GPIO_PullDown(GPIO_PORT portNum, GPIO_PIN pinNum, uint8  PD_Config)
{
switch (portNum) {
		case GPIOA:
			if (PD_Config == PULL_ENABLE) {
				SET_BIT(GPIO_PORTA_PDR_R, pinNum);	
			}
			else {
				CLEAR_BIT(GPIO_PORTA_PDR_R, pinNum);
			}
			break;
			
		case GPIOB:
			if (PD_Config == PULL_ENABLE) {
				SET_BIT(GPIO_PORTB_PDR_R, pinNum);	
			}
			else {
				CLEAR_BIT(GPIO_PORTB_PDR_R, pinNum);
			}
			break;
			
		case GPIOC:
			if (PD_Config == PULL_ENABLE) {
				SET_BIT(GPIO_PORTC_PDR_R, pinNum);	
			}
			else {
				CLEAR_BIT(GPIO_PORTC_PDR_R, pinNum);
			}
			break;
			
		case GPIOD:
			if (PD_Config == PULL_ENABLE) {
				SET_BIT(GPIO_PORTD_PDR_R, pinNum);
			}
			else {
				CLEAR_BIT(GPIO_PORTD_PDR_R, pinNum);
			}
			break;
			
		case GPIOE:
			if (PD_Config == PULL_ENABLE) {
				SET_BIT(GPIO_PORTE_PDR_R, pinNum);
			}
			else {
				CLEAR_BIT(GPIO_PORTE_PDR_R, pinNum);
			}
			break;
			
		case GPIOF:
			if (PD_Config == PULL_ENABLE) {
				SET_BIT(GPIO_PORTF_PDR_R, pinNum);
			}
			else {
				CLEAR_BIT(GPIO_PORTF_PDR_R, pinNum);
			}
			break;
	}
}


/************************************************************************************
 * Function Name : GPIO_SelectAlterFunction
 * Parameters    : Port - PinNumber 
 * Return value  : None
 * Description   : function to set the alternate function for pins
 ************************************************************************************/
void GPIO_SelectAlterFunction(GPIO_PORT portNum, GPIO_PIN pinNum)
 {
	switch(portNum) {
		case GPIOA:
			SET_BIT(GPIO_PORTA_AFSEL_R, pinNum);
			break;
		case GPIOB:
			SET_BIT(GPIO_PORTB_AFSEL_R, pinNum);
			break;
		case GPIOC:
			SET_BIT(GPIO_PORTC_AFSEL_R, pinNum);
			break;
		case GPIOD:
			SET_BIT(GPIO_PORTD_AFSEL_R, pinNum);
			break;
		case GPIOE:
			SET_BIT(GPIO_PORTE_AFSEL_R, pinNum);
			break;
		case GPIOF:
			SET_BIT(GPIO_PORTF_AFSEL_R, pinNum);
			break;
	}
}
 

/************************************************************************************
 * Function Name  :GPIO_EnableInterrupt
 * Parameters    : Port - PinNumber
 * Return value  : None
 * Description   : function to enable interrupts for pins
 ************************************************************************************/
void GPIO_EnableInterrupt(GPIO_PORT portNum, GPIO_PIN pinNum)
{
switch(portNum) {
		case GPIOA:
			SET_BIT(GPIO_PORTA_IM_R, pinNum);
			break;
		case GPIOB:
			SET_BIT(GPIO_PORTB_IM_R, pinNum);
			break;
		case GPIOC:
			SET_BIT(GPIO_PORTC_IM_R, pinNum);
			break;
		case GPIOD:
			SET_BIT(GPIO_PORTD_IM_R, pinNum);
			break;
		case GPIOE:
			SET_BIT(GPIO_PORTE_IM_R, pinNum);
			break;
		case GPIOF:
			SET_BIT(GPIO_PORTF_IM_R,pinNum);
			break;
	}
}


/************************************************************************************
 * Function Name  :GPIO_DisableInterrupt
 * Parameters    : Port - PinNumber
 * Return value  : None
 * Description   : function to Disable interrupts for pins
 ************************************************************************************/
void GPIO_DisableInterrupt(GPIO_PORT portNum, GPIO_PIN pinNum)
{
switch(portNum) {
		case GPIOA:
			CLEAR_BIT(GPIO_PORTA_IM_R, pinNum);
			break;
		case GPIOB:
			CLEAR_BIT(GPIO_PORTB_IM_R, pinNum);
			break;
		case GPIOC:
			CLEAR_BIT(GPIO_PORTC_IM_R, pinNum);
			break;
		case GPIOD:
			CLEAR_BIT(GPIO_PORTD_IM_R, pinNum);
			break;
		case GPIOE:
			CLEAR_BIT(GPIO_PORTE_IM_R, pinNum);
			break;
		case GPIOF:
			CLEAR_BIT(GPIO_PORTF_IM_R,pinNum);
			break;
	}
}



/************************************************************************************
 * Function Name   : GPIO_SelectInterruptSense
 * Parameters      : Port - PinNumber - Sense (EGGE - LEVEL)
 * Return value    : None
 * Description     : function to select interrupt detection mechanism for pins
 ************************************************************************************/
void GPIO_SelectInterruptSense(GPIO_PORT portNum, GPIO_PIN pinNum, uint8 Sense)
{
	switch (portNum)
	{
		case GPIOA:
			if (Sense == SENSE_EDGE)
			{
				CLEAR_BIT(GPIO_PORTA_IS_R, pinNum);
			}
			else
			{
				SET_BIT(GPIO_PORTA_IS_R,pinNum);
			}
			break;
		case GPIOB:
			if (Sense == SENSE_EDGE)
			{
				CLEAR_BIT(GPIO_PORTB_IS_R, pinNum);
			}
			else
			{
				SET_BIT(GPIO_PORTB_IS_R,pinNum);
			}
			break;
		case GPIOC:
			if (Sense == SENSE_EDGE)
			{
				CLEAR_BIT(GPIO_PORTC_IS_R , pinNum);
			}
			else
			{
				SET_BIT(GPIO_PORTC_IS_R ,pinNum);
			}
			break;
		case GPIOD:
			if (Sense == SENSE_EDGE)
			{
				CLEAR_BIT(GPIO_PORTD_IS_R , pinNum);
			}
			else
			{
				SET_BIT(GPIO_PORTD_IS_R ,pinNum);
			}
			break;
		case GPIOE:
			if (Sense == SENSE_EDGE)
			{
				CLEAR_BIT(GPIO_PORTE_IS_R , pinNum);
			}
			else
			{
				SET_BIT(GPIO_PORTE_IS_R ,pinNum);
			}
			break;
    	case GPIOF:
			if (Sense == SENSE_EDGE)
			{
				CLEAR_BIT(GPIO_PORTF_IS_R , pinNum);
			}
			else
			{
				SET_BIT(GPIO_PORTF_IS_R,pinNum);
			}
			break;
	}

}


/************************************************************************************
 * Function Name :GPIO_ClearInterrupts
 * Parameters   : Port - PinNumber 
 * Return value : None
 * Description  : function to Clear Interrups for pins
 ************************************************************************************/
void GPIO_ClearInterrupt(GPIO_PORT portNum, GPIO_PIN pinNum)
{
	switch(portNum)
	{
		case GPIOA:
			SET_BIT(GPIO_PORTA_ICR_R, pinNum);
			break;
		case GPIOB:
			SET_BIT(GPIO_PORTB_ICR_R, pinNum);
			break;
		case GPIOC:
			SET_BIT(GPIO_PORTC_ICR_R, pinNum);
			break;
		case GPIOD:
			SET_BIT(GPIO_PORTD_ICR_R, pinNum);
			break;
		case GPIOE:
			SET_BIT(GPIO_PORTE_ICR_R, pinNum);
			break;
		case GPIOF:
			SET_BIT(GPIO_PORTF_ICR_R, pinNum);
			break;
	}
}

/************************************************************************************
 * Function Name:GPIO_SelectInterruptEvent
 * Parameters   : Port - PinNumber - uint8 Event
 * Return value : None
 * Description  : function to Select Interrupt Event for pins
 ************************************************************************************/
void GPIO_SelectInterruptEvent(GPIO_PORT portNum, GPIO_PIN pinNum, uint8 Event)
{
	switch(portNum)
	{
		case GPIOA:
			if (Event == RISING_EDGE)
			{
				SET_BIT(GPIO_PORTA_IEV_R,pinNum);
			}
			else
			{
				CLEAR_BIT(GPIO_PORTA_IEV_R, pinNum);
			}
			break;
		case GPIOB:
			if (Event == RISING_EDGE)
			{
				SET_BIT(GPIO_PORTA_IEV_R,pinNum);
			}
			else
			{
				CLEAR_BIT(GPIO_PORTA_IEV_R, pinNum);
			}
			break;
		case GPIOC:
			if (Event == RISING_EDGE)
			{
				SET_BIT(GPIO_PORTA_IEV_R,pinNum);
			}
			else
			{
				CLEAR_BIT(GPIO_PORTA_IEV_R, pinNum);
			}
			break;
		case GPIOD:
			if (Event == RISING_EDGE)
			{
				SET_BIT(GPIO_PORTA_IEV_R,pinNum);
			}
			else
			{
				CLEAR_BIT(GPIO_PORTA_IEV_R, pinNum);
			}
			break;
		case GPIOE:
			if (Event == RISING_EDGE)
			{
				SET_BIT(GPIO_PORTA_IEV_R,pinNum);
			}
			else
			{
				CLEAR_BIT(GPIO_PORTA_IEV_R, pinNum);
			}
			break;
		case GPIOF:
			if (Event == RISING_EDGE)
			{
				SET_BIT(GPIO_PORTA_IEV_R,pinNum);
			}
			else
			{
				CLEAR_BIT(GPIO_PORTA_IEV_R, pinNum);
			}
			break;
	}
}



/************************************************************************************
 * Function Name:GPIO_InterruptBothEdges
 * Parameters   : Port - PinNumber - uint8 BothEdges
 * Return value : None
 * Description  : function to Select Interrupt BothEdges for pins
 ************************************************************************************/
void GPIO_InterruptBothEdges(GPIO_PORT portNum, GPIO_PIN pinNum, uint8 BothEdges)
{
	switch(portNum)
	{
		case GPIOA:
			if (BothEdges == BOTH_EDGE)
			{
				SET_BIT(GPIO_PORTA_IBE_R,pinNum);
			}
			else
			{
				CLEAR_BIT(GPIO_PORTA_IBE_R, pinNum);
			}
			break;
		case GPIOB:
			if (BothEdges == BOTH_EDGE)
			{
				SET_BIT(GPIO_PORTA_IBE_R,pinNum);
			}
			else
			{
				CLEAR_BIT(GPIO_PORTA_IBE_R, pinNum);
			}
			break;
		case GPIOC:
			if (BothEdges == BOTH_EDGE)
			{
				SET_BIT(GPIO_PORTA_IBE_R,pinNum);
			}
			else
			{
				CLEAR_BIT(GPIO_PORTA_IBE_R, pinNum);
			}
			break;
		case GPIOD:
			if (BothEdges == BOTH_EDGE)
			{
				SET_BIT(GPIO_PORTA_IBE_R,pinNum);
			}
			else
			{
				CLEAR_BIT(GPIO_PORTA_IBE_R, pinNum);
			}
			break;
		case GPIOE:
			if (BothEdges == BOTH_EDGE)
			{
				SET_BIT(GPIO_PORTA_IBE_R,pinNum);
			}
			else
			{
				CLEAR_BIT(GPIO_PORTA_IBE_R, pinNum);
			}
			break;
		case GPIOF:
			if (BothEdges == BOTH_EDGE)
			{
				SET_BIT(GPIO_PORTA_IBE_R,pinNum);
			}
			else
			{
				CLEAR_BIT(GPIO_PORTA_IBE_R, pinNum);
			}
			break;
	}
}
/************************************************************************************
 * Function Name: PORTF Initialization 
 * Parameters   : None
 * Return value : None
 * Description  : function to initialize Portf
 ************************************************************************************/
void PortF_Init(void)
{ 

  SYSCTL_RCGC2_R |= 0x00000021;   // 1) F clock
  delay = SYSCTL_RCGC2_R;         // delay
  GPIO_PORTF_LOCK_R = 0x4C4F434B;
  GPIO_PORTF_CR_R = 0x1F;         // allow changes to PF4-0
  GPIO_PORTF_AMSEL_R = 0x00;      // 3) disable analog function
  GPIO_PORTF_PCTL_R = 0x00000000; // 4) GPIO clear bit PCTL
  GPIO_PORTF_AFSEL_R = 0x00;      // 6) no alternate function
  NVIC_PRI7_R = (NVIC_PRI7_R & 0xff00ffff) | 0x00A00000;
}
/************************************************************************************
 * Function Name: PORTB Initialization 
 * Parameters   : None
 * Return value : None
 * Description  : function to initialize PortB
 ************************************************************************************/
void PortB_Init(void)
{

  SYSCTL_RCGC2_R |= 0x00000002;   // 1) B clock
  delay = SYSCTL_RCGCGPIO_R;      // delay
  GPIO_PORTB_LOCK_R = 0x4C4F434B; // 2)unlock GPIO of PORTB
  GPIO_PORTB_CR_R = 0x01;         // Enable commit
  GPIO_PORTB_AMSEL_R = 0x00;      // 3) disable analog function
  GPIO_PORTB_PCTL_R = 0x00000000; // 4) GPIO clear bit PCTL
  GPIO_PORTB_DIR_R = 0x3F ;        // 5) PORT output
  GPIO_PORTB_AFSEL_R = 0x00;      // 6) no alternate function
  GPIO_PORTB_DEN_R = 0xFF;        // 7) enable digital pins PF4-PF0

}



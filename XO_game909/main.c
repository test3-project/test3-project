// SpaceInvaders.c
// Runs on LM4F120/TM4C123

// ******* Required Hardware I/O connections*******************
// enter button connected to PF0
// up button connected to PF2
// down button connected to PF1
// left button connected to PF3
// right button connected to PF4

// LED1 on PB1  WHITE
// LED2 on PB2  GREEN
// LED3 on PB3  RED
// buzzer on PB4


// Blue Nokia 5110
// ---------------
// Signal        (Nokia 5110) LaunchPad pin
// Reset         (RST, pin 1) connected to PA7
// SSI0Fss       (CE,  pin 2) connected to PA3
// Data/Command  (DC,  pin 3) connected to PA6
// SSI0Tx        (Din, pin 4) connected to PA5
// SSI0Clk       (Clk, pin 5) connected to PA2
// 3.3V          (Vcc, pin 6) power
// back light    (BL,  pin 7) not connected, consists of 4 white LEDs which draw ~80mA total
// Ground        (Gnd, pin 8) ground


#include "Random.h"
#include "./images/TExaS.h"
//#include "GAME.h"
#include "./images/GAME.h"
#include "uart.h"
#include "interrupt.h"
#include "timer.h"

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
void Timer2_Init(unsigned long period);
void Delay100ms(unsigned long count); // time delay in 0.1 seconds
unsigned long TimerCount;
unsigned long Semaphore;

uint8 uart =0,right=0,left=0,up=0,down=0,flag=0;
char n;

int main(void){
  TExaS_Init(SSI0_Real_Nokia5110_Scope);  // set system clock to 80 MHz
  Random_Init(1);
	
	PortF_Init(); 
	PortB_Init();
	ButtonsInit();
	Led_Init();
	
  UART_Init();
  Nokia5110_Init();
	Nokia5110_ClearBuffer(); 
	Nokia5110_DisplayBuffer(); 

  Welcome(); 
  select_Mode();
	Reset(); 
	matrix(); 
	
	while (1)
	{
		  Start(); 

     if(!GPIO_ReadPinValue(GPIOF,PIN4))
			 {
			NVIC_Enable(30);
     // NVIC_SetPendingFlag(30);
		 }

		
		if(!GPIO_ReadPinValue(GPIOF,PIN3)){
			NVIC_Enable(30);
      //NVIC_SetPendingFlag(30);
		}
		
		if(!GPIO_ReadPinValue(GPIOF,PIN2)){
			 NVIC_Enable(30);
      // NVIC_SetPendingFlag(30);
		}
		
		if(!GPIO_ReadPinValue(GPIOF,PIN1)){
			 NVIC_Enable(30);
     //  NVIC_SetPendingFlag(30);
		}
		
			if(!GPIO_ReadPinValue(GPIOF,PIN0)){
			 NVIC_Enable(30);
      // NVIC_SetPendingFlag(30);
		}

		if(uart==1){
			
		UART_OutString("\n\r W-> Up  S-> Down  D->Right  A-> Left  X-> Play: ");
    n = UART_InChar();
   	UART_OutChar(n);
		UART_OutString("\n\r");
		switch(n){
			
			case 'd':
				right=1;
			break;
			
			case 'a':
				left=1;
			break;
			
			case 'w':
				up=1;
			break;
			
			case 's':
				down=1;
			break;
			
			case 'x':
				flag=1;
			break;
		
		}
		}

	}

}

/************************************************************************************
 * Function Name: GPIOPortF_Handler
 * Function Inputs : none
 * Description: Function to handle the interrupts of switchs
 ************************************************************************************/
void GPIOPortF_Handler(void)
{
  while (GPIO_PORTF_MIS_R != 0)
  {
		
	 if (GPIO_PORTF_MIS_R & 0x01) 
    {                                 
      Timer2_delay(5);
      if (!(GPIO_ReadPinValue(GPIOF, PIN0)))
      {
        flag = 1;
        GPIO_ClearInterrupt(GPIOF, PIN0);
      }
    }
    if (GPIO_PORTF_MIS_R & 0x10) 
    {                      
      Timer2_delay(5);
      if (!(GPIO_ReadPinValue(GPIOF, PIN4)))
      {
        right = 1;
        GPIO_ClearInterrupt(GPIOF, PIN4);
      }
    }
		
		if (GPIO_PORTF_MIS_R & 0x08) 
    {                            
 
      Timer2_delay(5);
      if (!(GPIO_ReadPinValue(GPIOF, PIN3)))
      {
        left = 1;
        GPIO_ClearInterrupt(GPIOF, PIN3);
      }
    }
		
		 if (GPIO_PORTF_MIS_R & 0x04) 
    {                            

      Timer2_delay(5);
      if (!(GPIO_ReadPinValue(GPIOF, PIN2)))
      {
        up = 1;
        GPIO_ClearInterrupt(GPIOF, PIN2);
      }
    }
		
		 if (GPIO_PORTF_MIS_R & 0x02) 
    {                           
      Timer2_delay(5);
      if (!(GPIO_ReadPinValue(GPIOF, PIN1)))
      {
        down = 1;
       GPIO_ClearInterrupt(GPIOF, PIN1);
      }
    }

    else
    { 
      GPIO_PORTF_ICR_R = GPIO_PORTF_MIS_R;
    }
  }
}
	




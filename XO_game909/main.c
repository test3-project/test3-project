

/**********************************************************************************************************
 * File Name: main.c
 *
 * Team Members : Toqa Sameh - Mariam Reda - Nermeen Ahmed - Amna Ali - Bassant Ehab - Rawan Mohamed 
 *********************************************************************************************************/
 

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
#include "./images/GAME.h"
#include "uart.h"
#include "interrupt.h"
#include "timer.h"

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts

uint8 uart =0,right=0,left=0,up=0,down=0,flag=0;
char n;

int main(void){
  TExaS_Init(SSI0_Real_Nokia5110_Scope);  // set system clock to 80 MHz
  Random_Init(1);
	
	/* Initialize all Moduls  */
	PortF_Init();  
	PortB_Init();
	ButtonsInit();
  NVIC_Enable(30);   /* enable interrupt to port F*/ 
	EnableInterrupts();/* (i) Clears the I bit == Enable the I-bit*/
	Led_Init();
  UART_Init();
  Nokia5110_Init();
	
	Nokia5110_ClearBuffer(); 
	Nokia5110_DisplayBuffer(); 
  Welcome(); /* Display welcome messege*/
  select_Mode(); /* select Buttons or UART */ 
	Reset();  /* Initialize the game to X-player */
	matrix();  /* Draw Grid */
	
	while (1)
	{
		  Start();  /* start game */

		if(uart==1){ /* case if we select UART */
			
		UART_OutString("\n\r W-> Up  S-> Down  D->Right  A-> Left  X-> Play: "); /* print messege on terminal */
    n = UART_InChar(); /* take input from user */
   	UART_OutChar(n); /* print char on terminal */
		UART_OutString("\n\r");
		switch(n){
			
			case 'd': /* if user pressed 'd' */
				right=1; /* set right flag */
			break;
			
			case 'a': /* if user pressed 'a' */
				left=1; /* set left flag */
			break;
			
			case 'w': /* if user pressed 'w' */
				up=1; /* set up flag */
			break;
			
			case 's': /* if user pressed 's' */
				down=1; /* set down flag */
			break;
			
			case 'x': /* if user pressed 'x' */
				flag=1; /* set flag to switch player */
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
  while (GPIO_PORTF_MIS_R != 0) /* check if any switch is pressed*/
  {
		
	 if (GPIO_PORTF_MIS_R & 0x01) /* if ENTER button pressed to switch player  */
    {                                 
      Timer2_delay(1);		 /*to avoid debouncing */
      if (!(GPIO_ReadPinValue(GPIOF, PIN0)))
      {
        flag = 1; /* set flag to switch player  */
        GPIO_ClearInterrupt(GPIOF, PIN0); /* clear interrupt on pin0 */
      }
    }
		
    if (GPIO_PORTF_MIS_R & 0x10) /* if right button pressed   */
    {                      
      Timer2_delay(1); /*to avoid debouncing */
      if (!(GPIO_ReadPinValue(GPIOF, PIN4)))
      {
        right = 1; /* set right flag   */
        GPIO_ClearInterrupt(GPIOF, PIN4); /* clear interrupt on pin4 */
      }
    }
		
		if (GPIO_PORTF_MIS_R & 0x08)  /* if left button pressed   */
    {                            
 
      Timer2_delay(1); /*to avoid debouncing */
      if (!(GPIO_ReadPinValue(GPIOF, PIN3)))
      {
        left = 1; /* set left flag   */
        GPIO_ClearInterrupt(GPIOF, PIN3);  /* clear interrupt on pin3 */
      }
    }
		
		 if (GPIO_PORTF_MIS_R & 0x04) /* if Up button pressed  */
    {                            

      Timer2_delay(1); /*to avoid debouncing */
      if (!(GPIO_ReadPinValue(GPIOF, PIN2)))
      {
        up = 1; /* set up flag   */
        GPIO_ClearInterrupt(GPIOF, PIN2);  /* clear interrupt on pin2 */
      }
    }
		
		 if (GPIO_PORTF_MIS_R & 0x02)  /* if down button pressed  */
    {                           
      Timer2_delay(1); /*to avoid debouncing */
      if (!(GPIO_ReadPinValue(GPIOF, PIN1)))
      {
        down = 1; /* set down flag   */
       GPIO_ClearInterrupt(GPIOF, PIN1); /* clear interrupt on pin1 */
      }
    }

    else
    { 
      GPIO_PORTF_ICR_R = GPIO_PORTF_MIS_R; /* acknowledge interrupt flag */
    }
  }
}
	

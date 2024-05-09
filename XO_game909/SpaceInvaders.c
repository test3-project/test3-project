// SpaceInvaders.c
// Runs on LM4F120/TM4C123

// ******* Required Hardware I/O connections*******************
// Slide pot pin 1 connected to ground
// Slide pot pin 2 connected to PE2/AIN1
// Slide pot pin 3 connected to +3.3V 
// fire button connected to PE0
// special weapon fire button connected to PE1
// 8*R resistor DAC bit 0 on PB0 (least significant bit)
// 4*R resistor DAC bit 1 on PB1
// 2*R resistor DAC bit 2 on PB2
// 1*R resistor DAC bit 3 on PB3 (most significant bit)
// LED on PB4
// LED on PB5

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
#include "TExaS.h"
#include "GAME.h"
#include "uart.h"
#include "interrupt.h"

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
void Timer2_Init(unsigned long period);
void Delay100ms(unsigned long count); // time delay in 0.1 seconds
unsigned long TimerCount;
unsigned long Semaphore;

uint8 uart =0,right,left,up,down,flag;
char n;

int main(void){
  TExaS_Init(SSI0_Real_Nokia5110_Scope);  // set system clock to 80 MHz
  Random_Init(1);
  Nokia5110_Init();
  PortF_Init(); 
	PortA_Init();
  UART_Init();
	ButtonsInit();
	 
	Nokia5110_ClearBuffer(); 
	Nokia5110_DisplayBuffer(); 
  Welcome(); 
  select_Mode();
	Reset(); 
	matrix(); 
	

	while (1)
	{
		if(!GPIO_ReadPinValue(GPIOF,PIN4)){
			NVIC_Enable(30);
      //GPIO_SetPendingFlag(30);
		}

		
		if(!GPIO_ReadPinValue(GPIOF,PIN3)){
			NVIC_Enable(30);
      //NVIC_vidSetPendingFlag(30);
		}
		
		if(!GPIO_ReadPinValue(GPIOF,PIN2)){
			 NVIC_Enable(30);
       //NVIC_vidSetPendingFlag(30);
		}
		
		if(!GPIO_ReadPinValue(GPIOF,PIN1)){
			 NVIC_Enable(30);
       //NVIC_vidSetPendingFlag(30);
		}
		
			if(!GPIO_ReadPinValue(GPIOF,PIN0)){
			 NVIC_Enable(30);
       //NVIC_vidSetPendingFlag(30);
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

		Welcome(); 
	}

}




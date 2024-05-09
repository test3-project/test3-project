

/**********************************************************************************************************
 * File Name: timer.c
 *
 * Team Members : Toqa Sameh - Mariam Reda - Nermeen Ahmed - Amna Ali - Bassant Ehab - Rawan Mohamed 
 *********************************************************************************************************/
 
 #include "timer.h"
 
  
 
unsigned long TimerCountt;
unsigned long Semaphoree;

void Timer2_delay(unsigned long period){ 
	int i;
  unsigned long volatile delay;
  SYSCTL_RCGCTIMER_R |= 0x04;   // 0) activate timer2
  //delay = SYSCTL_RCGCTIMER_R;
  TimerCountt = 0;
  Semaphoree = 0;
  TIMER2_CTL_R &=~0x00000000;    // 1) disable timer2A during setup
  TIMER2_CFG_R  = 0x00000000;    // 2) configure for 32-bit mode
  TIMER2_TAMR_R = 0x00000002;   // 3) configure for periodic mode, default down-count settings
  TIMER2_TAILR_R = 1600000-1;    // 4) reload value
	
	TIMER2_ICR_R = 0x00000001;    // 6) clear timer2A timeout flag
             // 9) enable IRQ 23 in NVIC
  TIMER2_CTL_R |= 0x00000001;    // 10) enable timer2A
	
	 for(i = 0; i < period; i++) { while ((TIMER2_RIS_R & 0x1) == 0) ;      /* wait for TimerA timeout flag */
        TIMER2_ICR_R = 0x1;      /* clear the TimerA timeout flag */
  }
}



/**********************************************************************************************************
 * File Name: timer.c
 *
 * Team Members : Toqa Sameh - Mariam Reda - Nermeen Ahmed - Amna Ali - Bassant Ehab - Rawan Mohamed 
 *********************************************************************************************************/
 
 #include "timer.h"
/************************************************************************************
 * function Name : Timer2_Init
 * Parameters   : period
 * Return value : None
 * Description  : function to initialize timer2
 ************************************************************************************/
void Timer2_delay(unsigned long period){ 
	int i;
  unsigned long volatile delay;
  SYSCTL_RCGCTIMER_R |= 0x04;   // 0) activate timer2
  //delay = SYSCTL_RCGCTIMER_R;
  TIMER2_CTL_R &=~0x00000000;    // 1) disable timer2A during setup
  TIMER2_CFG_R  = 0x00000000;    // 2) configure for 32-bit mode
  TIMER2_TAMR_R = 0x00000002;   // 3) configure for periodic mode, default down-count settings
  TIMER2_TAILR_R = 8000000-1;    // 4) reload value
	TIMER2_ICR_R = 0x00000001;    // 5) clear timer2A timeout flag
  TIMER2_CTL_R |= 0x00000001;    // 6) enable timer2A
	
	 for(i = 0; i < period; i++) { 
		 while ((TIMER2_RIS_R & 0x1) == 0); /* wait for TimerA timeout flag */
        TIMER2_ICR_R = 0x1;      /* clear the TimerA timeout flag */
      }
}

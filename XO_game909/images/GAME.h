/**********************************************************************************************************
 * File Name: GAME.h
 *
 * Team Members : Toqa Sameh - Mariam Reda - Nermeen Ahmed - Amna Ali - Bassant Ehab - Rawan Mohamed 
 *********************************************************************************************************/
 
#ifndef  GAME_H_
#define  GAME_H_
 
#include "Types.h"
#include "tm4c123gh6pm11.h" 
#include "../gpio.h"
#include "../Nokia5110.h"


void Welcome(void);
void Reset(void);
void Start(void);
int  Who_Wins(char player);
void Display_Who_wins(char player);
void equality(void);
void player_turn(void);
int  Again(void);
void EndGame(void);
void matrix(void);
int select_Mode(void);
void ButtonsInit(void);
//void Delay100ms(unsigned long count);
void Led_Init(void);
#endif


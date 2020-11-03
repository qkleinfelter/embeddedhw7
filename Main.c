// *******************************************************************
// main.s
// Author: Quinn Kleinfelter
// Date Created: 11/03/2020
// Last Modified: 11/03/2020
// Section Number: 001 / 003
// Instructor: Devinder Kaur
// Homework Number: 7
// Includes the functions and assembly subroutines
// that implements the functionality required by
// homework #7.
// *******************************************************************

#include <stdint.h>

#define NVIC_ST_CTRL_R		(*((volatile uint32_t *)0xE000E010)) 
#define NVIC_ST_RELOAD_R	(*((volatile uint32_t *)0xE000E014)) 
#define NVIC_ST_CURRENT_R	(*((volatile uint32_t *)0xE000E018))
#define NVIC_SYS_PRI3_R		(*((volatile uint32_t *)0xE000ED20))

void SystemInit() {
}

void q1_systick_init() {
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_RELOAD_R = 0x00FFFFFF;
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R = 0x00000005;
}
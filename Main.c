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

// Adapted from page 215 in the textbook
void q1_systick_wait1ms() {
	NVIC_ST_RELOAD_R = 50000 - 1; // Number of counts to wait - clock cycles in 1 ms (assuming 50MHz clock) 50000*20ns = 1ms
	NVIC_ST_CURRENT_R = 0; // any value written to CURRENT clears
	while ((NVIC_ST_CTRL_R & 0x00010000) == 0) {
		// wait for count flag
	}
}

void q1_EnableInterrupts() {
}

void q1_systick_100us_interrupts() {
	NVIC_ST_CTRL_R = 0; // disable SysTick during init
	NVIC_ST_RELOAD_R = 7999; // assuming 80MHz, 12.5ns * 8000 (from 7999+1) = 100000ns or 100us
	NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R & 0x00FFFFFF) | 0x20000000; // priority 1
	NVIC_ST_CURRENT_R = 0; // clear flag
	NVIC_ST_CTRL_R = 0x07; // arm and enable systick with interrupts
	q1_EnableInterrupts(); // Enable interrupts
}
	
#define SIZE 64

struct Student {
	unsigned long id;
	unsigned long score;
	unsigned char grade; // either 'P' or 'F'
};

typedef struct Student STyp;

unsigned long Grades(STyp class[SIZE]) {
	unsigned int i; // counter for the loop
	
	unsigned long sumOfScores = 0; // keep track of total scores
	
	for (i = 0; i < SIZE; i++) {
		STyp* student = &class[i];
		
		// Make the students grade passing or failing depending on the score (handles a)
		student->grade = student->score >= 75 ? 'P' : 'F';
		
		sumOfScores += student->score; // add it to the total score tracker
	}
	
	return sumOfScores / SIZE; // Average the class score and return it (handles b)
}

// question 3 testing init
STyp class[SIZE];
unsigned long j; // will iterate through students
unsigned long mean;

// question 5 testing init
extern void strcpy(char* destination, char* source);
char src[25] = "Hello!";
char dst[25];

// question 6 testing init
extern void remove_occurrences(char* str, char toRemove);

char str[] = "The Quick Brown Fox Jumps Over a Lazy Dog";

// question 7 testing init
extern void string_swap(char** str1, char** str2);
char* str1 = "Testing string 1";
char* str2 = "Testing string 2";

// question 8 testing init
extern signed int max4(signed int num1, signed int num2, signed int num3, signed int num4);
signed int result = 0;

int main(void) {
	// Question1
	//q1_systick_init();
	//q1_systick_wait1ms();
	//q1_systick_100us_interrupts();
	
	// Question3 testing
	for (j = 0; j < SIZE; j++) {
		STyp* student = &class[j];
		
		// Initialize student id's
		student->id = j;
		
		// pick a score of 74 or 76 depending on where we are in the loop
		if (j < SIZE / 2) {
			student->score = 74;
		} else {
			student->score = 76;
		}
	}
	// Now everyone should have an id and a score
	// If we average 74 (32 times) and 76 (32 times), we get 75
	mean = Grades(class); // 75 is the average we get so its good!
	
	// Question5 testing
	strcpy(dst, src);
	
	// Question6 testing
	remove_occurrences(str, 'o');
	
	// Question7 testing
	string_swap(&str1, &str2);
	
	// Question8 testing
	result = max4(1,2,3,4);
	result = max4(1,2,4,3);
	result = max4(1,4,2,3);
	result = max4(4,1,2,3);
	
}


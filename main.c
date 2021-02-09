/**********************************************************************
* LED flashing routine.
* © James D. Broesch, 2021
* 
* This version uses interrupts to free up the processor. 
* FileName:        main.c
* Dependencies:    Header (.h) files if applicable, see below
* Processor:       dsPIC33FJ256GP506
* Compiler:        MPLAB® C30 v3.00 or higher
*
************************************************************************/
#include <xc.h>
#include "DSCInit.h"
#include "sask.h"
#include "timer.h"


// Declare the timer count that is available in the timer driver.
extern unsigned int timer1Count;

int main(void)
{
	// Initialize the DSC.
	DSCInit();

	// Initialize the board and the drivers
	SASKInit();

	// Use timer 1 as a real time clock.
	// 1 tick = 15,625 * 256 clock cycles = 100ms.
	timer1Init(15625);

	while (1)
	{
		// Working code goes here.
	}

return(0); // Go home.
}

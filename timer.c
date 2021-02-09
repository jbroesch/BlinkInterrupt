#include "timer.h"
#include "sask.h"
#include <xc.h>

volatile unsigned int timer1Count = 0;
// LED State.
volatile int flagLED = 0;

// Interrupt handler for timer 0.
void __attribute__((__interrupt__,no_auto_psv)) _T1Interrupt(void)
{

	if (timer1Count++ == 10)
	{
		if (flagLED == 1)
		{
			RED_LED = SASK_LED_OFF; // Turn off the LED.
			flagLED = 0;
		}
	
		else // Then the flag must be 0.
		{
			RED_LED = SASK_LED_ON; // Turn on the LED.	
			flagLED = 1;
		}

		// Reset the timer count.
		timer1Count = 0;
	}
		
	IFS0 = IFS0 & 0xFFF7;   // Clear the interrupt flag.
}

void timer1Init(unsigned int count)
{
	// Timer 1 setup.
	IPC0  = IPC0 | 0b0001000000000000;  // Priority level is 1.
	IEC0  = IEC0 | 0b0000000000001000;  // Timer1 interrupt enabled.
	PR1   = count;          			// Interrupt period.
	T1CON = 0b1000000000110000;         // Timer1 enabled, clock divider = 256.
}

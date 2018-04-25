// ***** 0. Documentation Section *****
// SwitchLEDInterface.c for Lab 8
// Runs on LM4F120/TM4C123
// Use simple programming structures in C to toggle an LED
// while a button is pressed and turn the LED on when the
// button is released.  This lab requires external hardware
// to be wired to the LaunchPad using the prototyping board.
// January 15, 2016
//      Jon Valvano and Ramesh Yerraballi

// ***** 1. Pre-processor Directives Section *****
#include "TExaS.h"
#include "tm4c123gh6pm.h"

// ***** 2. Global Declarations Section *****

// FUNCTION PROTOTYPES: Each subroutine defined
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts

void Init(void);
void ToggleLED(void);
void Delay1ms(unsigned long msec);

// ***** 3. Subroutines Section *****

// PE0, PB0, or PA2 connected to positive logic momentary switch using 10k ohm pull down resistor
// PE1, PB1, or PA3 connected to positive logic LED through 470 ohm current limiting resistor
// To avoid damaging your hardware, ensure that your circuits match the schematic
// shown in Lab8_artist.sch (PCB Artist schematic file) or 
// Lab8_artist.pdf (compatible with many various readers like Adobe Acrobat).
int main(void){ 
//**********************************************************************
// The following version tests input on PE0 and output on PE1
//**********************************************************************
  volatile unsigned long input;
	
	TExaS_Init(SW_PIN_PE0, LED_PIN_PE1, ScopeOn);  // activate grader and set system clock to 80 MHz
  
	
  EnableInterrupts();           // enable interrupts for the grader
	Init();
	
  while(1)
	{
    input= GPIO_PORTE_DATA_R & 0x01;
		if (input)
		{
			ToggleLED();
		}
		else
		{
			GPIO_PORTE_DATA_R |= 0x02;
		}
		Delay1ms(100);
  }
  
}

// Subroutine to initialize port E
// Inputs: None
// Outputs: None
// Notes: Should be called only once, at the beginning of our main function
void Init()
{
	volatile unsigned long delay;
	SYSCTL_RCGC2_R |= 0x00000010;      // 1) E clock
  delay = SYSCTL_RCGC2_R;            // delay to allow clock to stabilize     
  GPIO_PORTE_AMSEL_R &= 0x00;        // 2) disable analog function
  GPIO_PORTE_PCTL_R &= 0x00000000;   // 3) GPIO clear bit PCTL  
  GPIO_PORTE_DIR_R &= ~0x01;         // 4.1) PE0 input,
  GPIO_PORTE_DIR_R |= 0x02;          // 4.2) PE1 output  
  GPIO_PORTE_AFSEL_R &= 0x00;        // 5) no alternate function     
  GPIO_PORTE_DEN_R |= 0x03;          // 6) enable digital pins PE1-PE0
	GPIO_PORTE_DATA_R |= 0x02;				 // 7) initialize the LED to be on
	
}
// Subroutine to toggle our LED
// Inputs: None
// Outputs: None
// Notes: It is just switching the LED to the opposit state

void ToggleLED()
{
	GPIO_PORTE_DATA_R = GPIO_PORTE_DATA_R^0x02;
}

// Subroutine to delay in units of milliseconds
// Inputs:  Number of milliseconds to delay
// Outputs: None
// Notes:   assumes 80 MHz clock
void Delay1ms(unsigned long msec){
// write this function
	unsigned long count;
	while(msec>0)
	{
	count=15385;
		while (count>0)
		{
			count--;
		}
		msec--;
	}

}

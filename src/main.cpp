/*
 * File: main.cpp
 * Description: An example file to test library PushButtonLib
 * Description: See URL for full details.
 * URL: https://github.com/gavinlyonsrepo/PushButtonLib_PICO
 */

// Section :: Include the Library
#include <stdio.h>
#include "pico/stdlib.h"
#include "pushbutton/push_button.hpp"

// Section :: Defines
#define INIT_DELAY 500 // mS
#define MY_DEBOUNCE_DELAY 10 // mS

// Section :: globals define the Push Button Objects
// Connect your button between the GPIO pin and GND
// Library uses internal pullup resistors of PICO
PushButton button1(7, MY_DEBOUNCE_DELAY); 
PushButton button2(6, MY_DEBOUNCE_DELAY); 
PushButton button3(5, MY_DEBOUNCE_DELAY);

int main(){
	
	stdio_init_all(); // Initialize chosen serial port
	busy_wait_ms(INIT_DELAY);
	printf("pushButtonLib : Start!\r\n");
	button1.Init();
	button2.Init();
	button3.Init();

	while(1)
	{
	if (button1.IsPressed())
		printf("Button 1 pressed\r\n");
	
	if (button2.IsReleased())
		printf("Button 2 released\r\n");
	
	if (button3.Toggled()) {
		if (button3.ReadButton() == PushButton::PRESSED)
			printf("Button 3 has been pressed\r\n");
		else
			printf("Button 3 has been released\r\n");
	}

	} // end of infinite while loop
} // end of main

// === EOF ===

/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"


// Blinking rate in milliseconds
#define BLINKING_RATE     500ms


int main()
{
    // Initialise the digital pin LED1 as an output
    DigitalOut conveyor(D3);
    DigitalOut motor(D11);


    motor = 0;
    conveyor = 0;
    ThisThread::sleep_for(5000);
    motor = 1;
    ThisThread::sleep_for(2000);
    conveyor = 1;
    ThisThread::sleep_for(1000);
    motor = 0;
    conveyor = 0;

    ThisThread::sleep_for(5000);

    motor = 1;
    ThisThread::sleep_for(2000);
    conveyor = 1;
    ThisThread::sleep_for(1000);
    motor = 0;
    conveyor = 0;

 
}

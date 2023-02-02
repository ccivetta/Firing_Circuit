/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "MotCon.h"



 // Hi Evan

int main()
{
    // Initialise the digital pin LED1 as an output
    DigitalOut conveyor(D3);
    DigitalOut motor(D11);


    MotCon yaw(A5, A3, A4); //positive = CW; negative = CCW
    MotCon pitch(A1, A2, A0); //postiive = up; negative = down

    char control;
    printf("\n Ready to begin \n");
    while (1){
            pitch.mot_control(0);
            yaw.mot_control(0);
            scanf("%c", &control);
            if (control == 'w' || control == 'W'){
                pitch.mot_control(.5);
                ThisThread::sleep_for(300);
            } else if (control == 's' || control == 'S'){
                pitch.mot_control(-.5);
                ThisThread::sleep_for(300);
            } else if (control == 'a' || control == 'A'){
                yaw.mot_control(-.75);
                motor = 1;
                ThisThread::sleep_for(1000);
                conveyor = 1;
                ThisThread::sleep_for(500);
                motor = 0;
                conveyor = 0;
            } else if (control == 'd' || control == 'D'){
                yaw.mot_control(.5);
                ThisThread::sleep_for(300);
            } else {
                pitch.mot_control(0);
                yaw.mot_control(0);
                ThisThread::sleep_for(300);
            }

    }

    // yaw.mot_control(-.5);
    // ThisThread::sleep_for(300);
    // yaw.mot_control(0);
    // pitch.mot_control(-.5);
    // ThisThread::sleep_for(300);
    // pitch.mot_control(0);
    
    char hey [10]; 
    printf("Enter a name:");
    scanf("%s", hey);
    printf("%s", hey);

    // motor = 0;
    // conveyor = 0;
    // ThisThread::sleep_for(5000);
    // motor = 1;
    // ThisThread::sleep_for(2000);
    // conveyor = 1;
    // ThisThread::sleep_for(500);
    // motor = 0;
    // conveyor = 0;

    // ThisThread::sleep_for(5000);

    // motor = 1;
    // ThisThread::sleep_for(2000);
    // conveyor = 1;
    // ThisThread::sleep_for(500);
    // motor = 0;
    // conveyor = 0;   
 
}

/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "MotCon.h"
#include "BNO055.h"



 // Hi Evan

int main()
{
    // Initialise the digital pin LED1 as an output
    DigitalOut conveyor(D3);
    DigitalOut motor(D11);


    MotCon yaw(A5, A3, A4); //positive = CW; negative = CCW
    MotCon pitch(A1, A2, A0); //postiive = up; negative = down

    BNO055 imu(D0,D1);
  
    imu.reset();

    imu.setmode(OPERATION_MODE_IMUPLUS); //Set Mode to IMU with relative Heading
    imu.set_angle_units(RADIANS); // Set Angle Units to radians
    imu.set_anglerate_units(RAD_PER_SEC); //Set Gyro units to rad/s



    char control;
    printf("\n Ready to begin \n");
    while (control != 'x'){
            if (control == 'w' || control == 'W'){
                pitch.mot_control(.5);
                imu.get_angles();
                imu.get_gyro();
                printf("%f, %f, %f, %f \n\r",imu.euler.pitch,imu.euler.yaw,imu.gyro.y,imu.gyro.z);
                ThisThread::sleep_for(300);
            } else if (control == 's' || control == 'S'){
                pitch.mot_control(-.5);
                imu.get_angles();
                imu.get_gyro();
                printf("%f, %f, %f, %f \n\r",imu.euler.pitch,imu.euler.yaw,imu.gyro.y,imu.gyro.z);
                ThisThread::sleep_for(300);
            } else if (control == 'a' || control == 'A'){
                yaw.mot_control(-.5);
                imu.get_angles();
                imu.get_gyro();
                printf("%f, %f, %f, %f \n\r",imu.euler.pitch,imu.euler.yaw,imu.gyro.y,imu.gyro.z);
                ThisThread::sleep_for(300);
            } else if (control == 'd' || control == 'D'){
                yaw.mot_control(.5);
                imu.get_angles();
                imu.get_gyro();
                printf("%f, %f, %f, %f \n\r",imu.euler.pitch,imu.euler.yaw,imu.gyro.y,imu.gyro.z);
                ThisThread::sleep_for(300);
            } else if (control == 'f' || control == 'F'){
                motor = 1;
                ThisThread::sleep_for(2000);
                conveyor = 1;
                ThisThread::sleep_for(500);
                motor = 0;
                conveyor = 0;   
            } else {
                pitch.mot_control(0);
                yaw.mot_control(0);
                ThisThread::sleep_for(300);
            }
            pitch.mot_control(0);
            yaw.mot_control(0);
            scanf("%c", &control);
    }
    printf("Testing Ended");
}

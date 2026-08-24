#ifndef JOYSTICK_H
#define JOYSTICK_H

#define SW_pin 33 // digital pin connected to switch output
#define X_pin 34 // analog pin connected to X output
#define Y_pin 35
#define MAX_POS 4095
#define MIN_POS 0

void readJoystick();
void readDigital();

//X and Y values
extern int stick_x;
extern int stick_y;

#endif
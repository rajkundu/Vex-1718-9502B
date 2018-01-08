/**
 * @file controllerLib.h
 * @brief wrapper for PROS controller interface
 */

//Begin header guards
#ifndef _CONTROLLERLIB_H
#define _CONTROLLERLIB_H

//Deadzone/deadband on joystick input; threshold at & below which input is
//neglected and getJoy() function returns 0
char deadZone = 16;

typedef enum {main = 1, partner = 2} controller;
typedef enum {rightX = 1, rightY = 2, leftY = 3, leftX = 4} joyChannel;
typedef enum {Btn5D, Btn5U, Btn6D, Btn6U, Btn7D, Btn7L, Btn7U, Btn7R, Btn8D,
  Btn8L, Btn8U, Btn8R} button;
typedef enum {U = 4, D = 1, L = 2, R = 8} buttonDirection;

signed char getJoy(controller controllerName, joyChannel channel);
bool btnDown(controller controllerName, button buttonName);

//End header guards
#endif

/**
 * @file auto.c
 * @brief File for autonomous code
 *
 * This file should contain the user autonomous() function and any functions
 * related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "9502Lib/autonSelector.h"
#include "9502Lib/autonomousRoutines.h"

/**
 * Array of strings (char[])s for lcd to show names of autonomous routines -
 * each string should correspond to an autonomous routine/method
 */
char routineNames[][17] =
{
	"   Do Nothing   ",
	"  Routine  One  ",
	"  Routine  Two  ",
	" Routine  Three ",
	"  TEST PROGRAM  "
};

/*
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. If the robot is disabled or communications is lost, the autonomous task
 * will be stopped by the kernel. Re-enabling the robot will restart the task,
 * not re-start it from where it left off.
 *
 * Code running in the autonomous task cannot access information from the VEX
 * Joystick. However, the autonomous function can be invoked from another task
 * if a VEX Competition Switch is not available, and it can access joystick
 * information if called in this way.
 *
 * The autonomous task may exit, unlike operatorControl() which should never
 * exit. If it does so, the robot will await a switch to another mode or
 * disable/enable cycle.
 */
void autonomous()
{
    //Replace/delete routineOne(), routineTwo(), etc. with routines
    switch(routineNum)
    {
        case 0:
        {
            //Do nothing
            break;
        }
        case 1:
        {
            routineOne();
            break;
        }
        case 2:
        {
            routineTwo();
            break;
        }
        case 3:
        {
            routineThree();
            break;
        }
        case 4:
        {
            testProgram();
        }
        default:
        {
            break;
        }
    }
}

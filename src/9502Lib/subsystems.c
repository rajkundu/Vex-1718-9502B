/**
 * @file subsystems.c
 * @brief contains subsystem code for individual parts of robot
 */

#include <API.h>
#include "9502Lib/subsystems.h"

TaskHandle autonSelectorTask = NULL;

void displayInt(char lineNum, int intToDisplay)
{
    char stringFromInt[17];
    sprintf(stringFromInt, "%d", intToDisplay);
    lcdSetText(lcdPort, lineNum, stringFromInt);
}
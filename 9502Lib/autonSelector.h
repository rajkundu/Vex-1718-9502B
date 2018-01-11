/**
 * @file autonSelector.h
 * @brief contains code related to LCD autonomous selector
 */

//Begin header guard
#ifndef _AUTONSELECTOR_H
#define _AUTONSELECTOR_H

#include <API.h>
#include <string.h>

//LCD Setup
#define lcdPort uart2
#define lcdRefreshRate 20

/**
 * Array of char[] for lcd to show names of autonomous routines - one string
 * should correspond with each autonomous routine
 */
extern char routineNames[][17];
extern int numRoutines;
extern char selectString[17];
extern unsigned char routineNum;

extern void aSel();

//End header guard
#endif

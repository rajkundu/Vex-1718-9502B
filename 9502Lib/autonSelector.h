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
static unsigned char lcdRefreshRate = 20;

/**
 * Array of char[] for lcd to show names of autonomous routines - one string
 * should correspond with each autonomous routine
 */
static char routineNames[][17] =
{
	"   Do Nothing   ",
	"  Routine  One  ",
	"  Routine  Two  ",
	" Routine  Three ",
	"  TEST PROGRAM  "
};
extern int numRoutines;

extern char selectString[17];
extern short routineNum;

extern void aSel();

//End header guard
#endif

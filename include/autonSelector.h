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
static unsigned char lcdPort = 2;
static unsigned char lcdRefreshRate = 20;

extern char routineNames[][17];
extern char selectString[17];
extern int numRoutines;
extern short routineNum;

extern void autonomousSelector(void *parameter);

//End header guard
#endif

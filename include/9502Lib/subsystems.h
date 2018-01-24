/**
 * @file subsystems.h
 * @brief contains subsystem code for individual parts of robot
 */

#include <API.h>
#include <string.h>

//Begin header guard
#ifndef _SUBSYSTEMS_H
#define _SUBSYSTEMS_H

//////////////////////////////     LCD Screen     //////////////////////////////
// LCD port number
static int* lcdPort = (PROS_FILE *) 2;
// LCD refresh rate (Hz or times/second)
static const char lcdRefreshRate = 20;
/**
 * Displays text on default lcdPort as defined above
 * 
 * @param lineNum line of LCD upon which to display text
 * @param text string of text to display on LCD
 */
void setLCD(unsigned char lineNum, const char *text);
////////////////////----------------------------------------////////////////////



//////////////////////////////       Motors       //////////////////////////////
////////////////////----------------------------------------////////////////////



//////////////////////////////   Analog Sensors   //////////////////////////////
////////////////////----------------------------------------////////////////////



//////////////////////////////  Digital  Sensors  //////////////////////////////
////////////////////----------------------------------------////////////////////

//End header guard
#endif
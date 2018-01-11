/**
 * @file autonSelector.c
 * @brief contains code related to LCD autonomous selector
 */
#include "9502Lib/autonSelector.h"

char selectString[17] = "                ";
unsigned char routineNum = 0;

/**
 * Function that is run in the initialize portion of the match, before
 * autonomous; allows a user to choose the autonomous routine to run for the
 * match
 */
void autonSelector()
{
	// Turn on the LCD backlight, signifying that it needs input
	lcdSetBacklight(lcdPort, true);

	// While the robot is not in autonomous mode or is disabled...
	while(!(isAutonomous() || isEnabled()))
	{
		// Decide which arrows to show: left, right or both?
		//If on the first, leftmost routine...
		if(routineNum == 0)
		{
			//Hide the left arrow
			strcpy(selectString, "     Select    >");
		}
		//Otherwise, if on the last, rightmost routine...
		else if(routineNum == (numRoutines - 1))
		{
			//Hide the right arrow
			strcpy(selectString, "<    Select     ");
		}
		//Else, if on one of the middle routines...
		else
		{
			//Show both left and right arrows
			strcpy(selectString, "     Select     ");
		}

		//Display current autonomous routine name on the top line
		lcdSetText(lcdPort, 1, routineNames[routineNum]);
		//Display "Select" on the bottom line
		lcdSetText(lcdPort, 2, selectString);

    //If the center LCD button is pressed...
    if(lcdReadButtons(lcdPort) == 2)
    {
      //Break loop, selecting current program
      break;
    }
		//Otherwise, if (the left LCD button is pressed) and (the currently displayed routine is not the first)...
		else if(lcdReadButtons(lcdPort) == 1 && (routineNum > 0))
		{
			//Wait for button release
			while(lcdReadButtons(lcdPort) == 1)
			{
				//Do nothing
				delay(1000.0 / lcdRefreshRate);
			}
			//Go to the routine to the left
			routineNum--;
		}
		//Otherwise, if (the right LCD button is pressed) and (the currently displayed routine is not the last)...
		else if(lcdReadButtons(lcdPort) == 4 && (routineNum < (numRoutines - 1)))
		{
			//Wait for button release
			while(lcdReadButtons(lcdPort) == 4)
			{
				//Do nothing
				delay(1000.0 / lcdRefreshRate);
			}
			//Go to the routine to the right
			routineNum++;
		}
		//Else, if no LCD buttons are pressed...
		else
		{
			//Do nothing
		}

		delay(1000.0 / lcdRefreshRate);
	}

	lcdSetText(lcdPort, 2, " ^  Selected  ^ ");
	lcdSetBacklight(lcdPort, false);
	return;
}
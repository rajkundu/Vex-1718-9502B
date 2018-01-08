/**
 * @file controllerLib.c
 * @brief wrapper for PROS controller interface
 */

#include <API.h>
#include "controllerLib.h"

/**
 * Wrapper function used for getting joystick channel value on controller
 *
 * @param controller either "main" (controller 1) or "partner" (controller 2)
 * as defined in the enum "controller" in corresponding .h file
 * @param channel any memeber of enum "joyChannel" in corresponding .h file i.e.
 * leftX, leftY, rightX, or rightY
 * @return returns value in [-127, 127] for joystick channel with a deadZone
 * (aka "dead band") active as defined in corresponding .h file
 */
signed char getJoy(controller controllerName, joyChannel channel)
{
  //Retrieve joystick value
  int joyVal = joystickGetAnalog(controllerName, channel);
  //Deadzone
  if(abs(joyVal) > deadZone)
  {
    return joyVal;
  }
  else
  {
    return 0;
  }
}

/**
 * Wrapper function used for getting joystick button value on controller
 *
 * @param controller either "main" (controller 1) or "partner" (controller 2)
 * as defined in the enum "controller" in corresponding .h file
 * @param buttonName any member of enum "button" in corresponding .h file
 * @return returns true if button is pressed or false if button is not pressed
 */
bool btnDown(controller controllerName, button buttonName)
{
  int buttonGroupNum = 0;
  int buttonDirection = 0;
  switch(buttonName)
  {
    case Btn5D:
    {
      buttonGroupNum = 5;
      buttonDirection = 1;
      break;
    }
    case Btn5U:
    {
      buttonGroupNum = 5;
      buttonDirection = 4;
      break;
    }
    case Btn6D:
    {
      buttonGroupNum = 6;
      buttonDirection = 1;
      break;
    }
    case Btn6U:
    {
      buttonGroupNum = 6;
      buttonDirection = 4;
      break;
    }
    case Btn7D:
    {
      buttonGroupNum = 7;
      buttonDirection = 1;
      break;
    }
    case Btn7L:
    {
      buttonGroupNum = 7;
      buttonDirection = 2;
      break;
    }
    case Btn7U:
    {
      buttonGroupNum = 7;
      buttonDirection = 4;
      break;
    }
    case Btn7R:
    {
      buttonGroupNum = 7;
      buttonDirection = 8;
      break;
    }
    case Btn8D:
    {
      buttonGroupNum = 8;
      buttonDirection = 1;
      break;
    }
    case Btn8L:
    {
      buttonGroupNum = 8;
      buttonDirection = 2;
      break;
    }
    case Btn8U:
    {
      buttonGroupNum = 8;
      buttonDirection = 4;
      break;
    }
    case Btn8R:
    {
      buttonGroupNum = 8;
      buttonDirection = 8;
      break;
    }
    default:
    {
      break;
    }
  }
  return (joystickGetDigital(controllerName, buttonGroupNum, buttonDirection) \
    == 1);
}

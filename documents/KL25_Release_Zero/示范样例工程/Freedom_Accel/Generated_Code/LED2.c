/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : LED2.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : LED
**     Version     : Component 01.046, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2012-10-25, 01:08, # CodeGen: 0
**     Abstract    :
**
**     Settings    :
**
**     Contents    :
**         On     - void LED2_On(void);
**         Off    - void LED2_Off(void);
**         Neg    - void LED2_Neg(void);
**         Get    - byte LED2_Get(void);
**         Put    - void LED2_Put(byte val);
**         Init   - void LED2_Init(void);
**         Deinit - void LED2_Deinit(void);
**
**     License   :  Open Source (LGPL)
**     Copyright : (c) Copyright Erich Styger, 2012, all rights reserved.
**     This an open source software implementing an LED driver using Processor Expert.
**     This is a free software and is opened for education,  research and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/

/* MODULE LED2. */

#include "LED2.h"

/*
** ===================================================================
**     Method      :  LED2_On (component LED)
**
**     Description :
**         This turns the LED on.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LED2_On(void)
{
  GPIO1_ClearPortBits(NULL, GPIO1_LED_G_MASK);
}

/*
** ===================================================================
**     Method      :  LED2_Off (component LED)
**
**     Description :
**         This turns the LED off.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LED2_Off(void)
{
  GPIO1_SetPortBits(NULL, GPIO1_LED_G_MASK);
}

/*
** ===================================================================
**     Method      :  LED2_Neg (component LED)
**
**     Description :
**         This negates/toggles the LED
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LED2_Neg(void)
{
  GPIO1_TogglePortBits(NULL, GPIO1_LED_G_MASK);
}

/*
** ===================================================================
**     Method      :  LED2_Get (component LED)
**
**     Description :
**         This returns logical 1 in case the LED is on, 0 otherwise.
**     Parameters  : None
**     Returns     :
**         ---             - Status of the LED (on or off)
** ===================================================================
*/
byte LED2_Get(void)
{
  return (byte)!((GPIO1_GetPortValue(NULL)&GPIO1_LED_G_MASK)!=0);
}

/*
** ===================================================================
**     Method      :  LED2_Init (component LED)
**
**     Description :
**         Performs the LED driver initialization.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LED2_Init(void)
{
  LED2_Off();
}

/*
** ===================================================================
**     Method      :  LED2_Put (component LED)
**
**     Description :
**         Turns the LED on or off.
**     Parameters  :
**         NAME            - DESCRIPTION
**         val             - value to define if the LED has to be on or
**                           off.
**     Returns     : Nothing
** ===================================================================
*/
void LED2_Put(byte val)
{
  if(val) {
    LED2_On();
  } else {
    LED2_Off();
  }
}

/*
** ===================================================================
**     Method      :  LED2_Deinit (component LED)
**
**     Description :
**         Deinitializes the driver
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LED2_Deinit(void)
{
  GPIO1_Deinit(NULL);
}

/* END LED2. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/

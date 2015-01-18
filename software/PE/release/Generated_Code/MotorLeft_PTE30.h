/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : MotorLeft_PTE30.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : PWM
**     Version     : Component 02.238, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-05-17, 16:57, # CodeGen: 60
**     Abstract    :
**         This component implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
**     Settings    :
**         Used output pin             : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       22            |  DAC0_OUT/ADC0_SE23/CMP0_IN4/PTE30/TPM0_CH3/TPM_CLKIN1
**             ----------------------------------------------------
**
**         Timer name                  : TPM0_CNT [16-bit]
**         Counter                     : TPM0_CNT  [0x40038004]
**         Mode register               : TPM0_SC   [0x40038000]
**         Run register                : TPM0_SC   [0x40038000]
**         Prescaler                   : TPM0_SC   [0x40038000]
**         Compare register            : TPM0_C3V  [0x40038028]
**         Flip-flop register          : TPM0_C3SC [0x40038024]
**
**         User handling procedure     : not specified
**
**         Port name                   : PTE
**         Bit number (in port)        : 30
**         Bit mask of the port        : 0x40000000
**         Port data register          : GPIOE_PDOR [0x400FF100]
**         Port control register       : GPIOE_PDDR [0x400FF114]
**
**         Initialization:
**              Output level           : low
**              Timer                  : Enabled
**              Event                  : Enabled
**         High speed mode
**             Prescaler               : divide-by-[driven by slave component]
**             Clock                   : [driven by slave component] Hz
**           Initial value of            period     pulse width
**             Xtal ticks              : ---        ---
**             microseconds            : ---        ---
**             milliseconds            : 2          1
**             seconds                 : ---        ---
**             seconds (real)          : 2          1
**
**     Contents    :
**         SetRatio16 - byte MotorLeft_PTE30_SetRatio16(word Ratio);
**         SetDutyUS  - byte MotorLeft_PTE30_SetDutyUS(word Time);
**         SetDutyMS  - byte MotorLeft_PTE30_SetDutyMS(word Time);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __MotorLeft_PTE30_H
#define __MotorLeft_PTE30_H

/* MODULE MotorLeft_PTE30. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "PwmLdd3.h"

#include "Cpu.h"


#define MotorLeft_PTE30_PERIOD_VALUE PwmLdd3_PERIOD_VALUE /* Initial period value in ticks of the timer. It is available only if the bean is enabled in high speed mode. */
#define MotorLeft_PTE30_PERIOD_VALUE_HIGH PwmLdd3_PERIOD_VALUE_0 /* Period value in ticks of the timer in high speed mode. It is available only if the bean is enabled in high speed mode. */


/*
** ===================================================================
**     Method      :  MotorLeft_PTE30_SetRatio16 (component PWM)
**
**     Description :
**         This method sets a new duty-cycle ratio. Ratio is expressed
**         as a 16-bit unsigned integer number. 0 - FFFF value is
**         proportional to ratio 0 - 100%. The method is available
**         only if it is not selected list of predefined values in
**         <Starting pulse width> property. 
**         Note: Calculated duty depends on the timer possibilities and
**         on the selected period.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Ratio           - Ratio to set. 0 - 65535 value is
**                           proportional to ratio 0 - 100%
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
#define MotorLeft_PTE30_SetRatio16(Ratio) (PwmLdd3_SetRatio16(PwmLdd3_DeviceData, Ratio))

/*
** ===================================================================
**     Method      :  MotorLeft_PTE30_SetDutyUS (component PWM)
**
**     Description :
**         This method sets the new duty value of the output signal.
**         The duty is expressed in microseconds as a 16-bit
**         unsigned integer number.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Time            - Duty to set [in microseconds]
**                      (0 to --- us in high speed mode)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
#define MotorLeft_PTE30_SetDutyUS(Time) (PwmLdd3_SetDutyUS(PwmLdd3_DeviceData, Time))

/*
** ===================================================================
**     Method      :  MotorLeft_PTE30_SetDutyMS (component PWM)
**
**     Description :
**         This method sets the new duty value of the output signal.
**         The duty is expressed in milliseconds as a 16-bit
**         unsigned integer number.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Time            - Duty to set [in milliseconds]
**                      (0 to 2 ms in high speed mode)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
#define MotorLeft_PTE30_SetDutyMS(Time) (PwmLdd3_SetDutyMS(PwmLdd3_DeviceData, Time))

/* END MotorLeft_PTE30. */

#endif 
/* ifndef __MotorLeft_PTE30_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/

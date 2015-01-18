/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : TU3.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : TimerUnit_LDD
**     Version     : Component 01.139, Driver 01.09, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-05-20, 15:22, # CodeGen: 73
**     Abstract    :
**          This TimerUnit component provides a low level API for unified hardware access across
**          various timer devices using the Prescaler-Counter-Compare-Capture timer structure.
**     Settings    :
**          Component name                                 : TU3
**          Module name                                    : TPM2
**          Counter                                        : TPM2_CNT
**          Counter direction                              : Up
**          Counter width                                  : 16 bits
**          Value type                                     : Optimal
**          Input clock source                             : Internal
**            Counter frequency                            : 3 MHz
**          Counter restart                                : On-match
**            Period device                                : TPM2_MOD
**            Period                                       : 80 ?s
**            Interrupt                                    : Enabled
**              Interrupt                                  : INT_TPM2
**              Interrupt priority                         : high priority
**          Channel list                                   : 0
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnCounterRestart                           : Enabled
**              OnChannel0                                 : Disabled
**              OnChannel1                                 : Disabled
**              OnChannel2                                 : Disabled
**              OnChannel3                                 : Disabled
**              OnChannel4                                 : Disabled
**              OnChannel5                                 : Disabled
**              OnChannel6                                 : Disabled
**              OnChannel7                                 : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**     Contents    :
**         Init   - LDD_TDeviceData* TU3_Init(LDD_TUserData *UserDataPtr);
**         Deinit - void TU3_Deinit(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __TU3_H
#define __TU3_H

/* MODULE TU3. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "PE_LDD.h"
#include "TPM_PDD.h"
#include "Cpu.h"


#ifndef __BWUserType_TU3_TValueType
#define __BWUserType_TU3_TValueType
  typedef uint32_t TU3_TValueType ;    /* Type for data parameters of methods */
#endif
#define TU3_CNT_INP_FREQ_U_0 0x002DC6C0UL /* Counter input frequency in Hz */
#define TU3_CNT_INP_FREQ_R_0 3000003.000003F /* Counter input frequency in Hz */
#define TU3_CNT_INP_FREQ_COUNT 0U      /* Count of predefined counter input frequencies */
#define TU3_PERIOD_TICKS   0xF0UL      /* Initialization value of period in 'counter ticks' */
#define TU3_NUMBER_OF_CHANNELS 0x00U   /* Count of predefined channels */
#define TU3_COUNTER_WIDTH  0x10U       /* Counter width in bits  */
#define TU3_COUNTER_DIR    DIR_UP      /* Direction of counting */
/* Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define TU3_PRPH_BASE_ADDRESS  0x4003A000U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define TU3_Init_METHOD_ENABLED
#define TU3_Deinit_METHOD_ENABLED

/* Events configuration constants - generated for all enabled component's events */
#define TU3_OnCounterRestart_EVENT_ENABLED



LDD_TDeviceData* TU3_Init(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  TU3_Init (component TimerUnit_LDD)
**
**     Description :
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the
**         property <"Enable in init. code"> is set to "yes" value then
**         the device is also enabled (see the description of the
**         <Enable> method). In this case the <Enable> method is not
**         necessary and needn't to be generated. This method can be
**         called only once. Before the second call of Init the <Deinit>
**         must be called first.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     Returns     :
**         ---             - Pointer to the dynamically allocated
**                           private structure or NULL if there was an
**                           error.
** ===================================================================
*/

void TU3_Deinit(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  TU3_Deinit (component TimerUnit_LDD)
**
**     Description :
**         Deinitializes the device. Switches off the device, frees the
**         device data structure memory, interrupts vectors, etc.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by Init method
**     Returns     : Nothing
** ===================================================================
*/

/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(TU3_Interrupt);
/*
** ===================================================================
**     Method      :  TU3_Interrupt (component TimerUnit_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END TU3. */

#endif
/* ifndef __TU3_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/

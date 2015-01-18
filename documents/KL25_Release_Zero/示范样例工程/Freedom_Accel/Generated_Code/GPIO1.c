/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : GPIO1.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : GPIO_LDD
**     Version     : Component 01.126, Driver 01.06, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2012-10-25, 01:23, # CodeGen: 2
**     Abstract    :
**         The HAL GPIO component will provide a low level API for unified
**         access to general purpose digital input/output pins across
**         various device designs.
**
**         RTOS drivers using HAL GPIO API will be simpler and more
**         portable to various microprocessors.
**     Settings    :
**          Component name                                 : GPIO1
**          Port                                           : PTE
**          Port width                                     : 32 bits
**          Mask of allocated pins                         : 700000
**          Interrupt service/event                        : Disabled
**          Bit fields                                     : 3
**            Bit field                                    : 
**              Field name                                 : LED_R
**              Pins                                       : 1
**                Pin                                      : 
**                  Pin                                    : ADC0_DP0/ADC0_SE0/PTE20/TPM1_CH0/UART0_TX
**                  Pin signal                             : LED_R
**                  Initial pin direction                  : Output
**                    Initial output state                 : 0
**                  Initial pin event                      : Disabled
**            Bit field                                    : 
**              Field name                                 : LED_G
**              Pins                                       : 1
**                Pin                                      : 
**                  Pin                                    : ADC0_DM0/ADC0_SE4a/PTE21/TPM1_CH1/UART0_RX
**                  Pin signal                             : LED_G
**                  Initial pin direction                  : Output
**                    Initial output state                 : 0
**                  Initial pin event                      : Disabled
**            Bit field                                    : 
**              Field name                                 : LED_B
**              Pins                                       : 1
**                Pin                                      : 
**                  Pin                                    : ADC0_DP3/ADC0_SE3/PTE22/TPM2_CH0/UART2_TX
**                  Pin signal                             : 
**                  Initial pin direction                  : Output
**                    Initial output state                 : 0
**                  Initial pin event                      : Disabled
**          Initialization                                 : 
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnPortEvent                                : Disabled
**     Contents    :
**         Init                    - LDD_TDeviceData* GPIO1_Init(LDD_TUserData *UserDataPtr);
**         Deinit                  - void GPIO1_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         GetPortValue            - GPIO1_TPortValue GPIO1_GetPortValue(LDD_TDeviceData *DeviceDataPtr);
**         ClearPortBits           - void GPIO1_ClearPortBits(LDD_TDeviceData *DeviceDataPtr, GPIO1_TPortValue Mask);
**         SetPortBits             - void GPIO1_SetPortBits(LDD_TDeviceData *DeviceDataPtr, GPIO1_TPortValue Mask);
**         TogglePortBits          - void GPIO1_TogglePortBits(LDD_TDeviceData *DeviceDataPtr, GPIO1_TPortValue...
**         SetFieldValue           - void GPIO1_SetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField...
**         GetFieldValue           - GPIO1_TFieldValue GPIO1_GetFieldValue(LDD_TDeviceData *DeviceDataPtr,...
**         ClearFieldBits          - void GPIO1_ClearFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField...
**         SetFieldBits            - void GPIO1_SetFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField...
**         ToggleFieldBits         - void GPIO1_ToggleFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField...
**         SetFieldInputDirection  - void GPIO1_SetFieldInputDirection(LDD_TDeviceData *DeviceDataPtr,...
**         SetFieldOutputDirection - void GPIO1_SetFieldOutputDirection(LDD_TDeviceData *DeviceDataPtr,...
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE GPIO1. */

#include "GPIO1.h"
/* {Default RTOS Adapter} No RTOS includes */
#include "IO_Map.h"

typedef struct {
  LDD_TUserData *UserData;             /* RTOS device data structure */
} GPIO1_TDeviceData, *GPIO1_TDeviceDataPtr; /* Device data structure type */
/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static GPIO1_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;
/*
** ===================================================================
**     Method      :  GPIO1_Init (component GPIO_LDD)
**
**     Description :
**         This method initializes the associated peripheral(s) and the
**         component internal variables. The method is called
**         automatically as a part of the application initialization
**         code.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the RTOS device
**                           structure. This pointer will be passed to
**                           all events as parameter.
**     Returns     :
**         ---             - Pointer to the dynamically allocated
**                           private structure or NULL if there was an
**                           error.
** ===================================================================
*/
LDD_TDeviceData* GPIO1_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate LDD device structure */
  GPIO1_TDeviceData *DeviceDataPrv;

  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;
  /* Save RTOS Device structure */
  DeviceDataPrv->UserData = UserDataPtr; /* Store the RTOS device structure */
  /* GPIOE_PDOR: PDO&=~0x00700000 */
  GPIOE_PDOR &= (uint32_t)~(uint32_t)(GPIO_PDOR_PDO(0x00700000));                                                   
  /* GPIOE_PDDR: PDD|=0x00700000 */
  GPIOE_PDDR |= GPIO_PDDR_PDD(0x00700000);                                                   
  /* Initialization of Port Control registers */
  /* PORTE_PCR20: ISF=0,MUX=1 */
  PORTE_PCR20 = (uint32_t)((PORTE_PCR20 & (uint32_t)~(uint32_t)(
                 PORT_PCR_ISF_MASK |
                 PORT_PCR_MUX(0x06)
                )) | (uint32_t)(
                 PORT_PCR_MUX(0x01)
                ));                                                  
  /* PORTE_PCR21: ISF=0,MUX=1 */
  PORTE_PCR21 = (uint32_t)((PORTE_PCR21 & (uint32_t)~(uint32_t)(
                 PORT_PCR_ISF_MASK |
                 PORT_PCR_MUX(0x06)
                )) | (uint32_t)(
                 PORT_PCR_MUX(0x01)
                ));                                                  
  /* PORTE_PCR22: ISF=0,MUX=1 */
  PORTE_PCR22 = (uint32_t)((PORTE_PCR22 & (uint32_t)~(uint32_t)(
                 PORT_PCR_ISF_MASK |
                 PORT_PCR_MUX(0x06)
                )) | (uint32_t)(
                 PORT_PCR_MUX(0x01)
                ));                                                  
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_GPIO1_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv);
}

/*
** ===================================================================
**     Method      :  GPIO1_Deinit (component GPIO_LDD)
**
**     Description :
**         This method disables the device and frees the device data
**         structure memory.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Pointer to device data
**                           structure pointer.
**     Returns     : Nothing
** ===================================================================
*/
void GPIO1_Deinit(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  /* PORTE_PCR20: IRQC=0 */
  PORTE_PCR20 &= (uint32_t)~(uint32_t)(PORT_PCR_IRQC(0x0F));                                                   
  /* PORTE_PCR21: IRQC=0 */
  PORTE_PCR21 &= (uint32_t)~(uint32_t)(PORT_PCR_IRQC(0x0F));                                                   
  /* PORTE_PCR22: IRQC=0 */
  PORTE_PCR22 &= (uint32_t)~(uint32_t)(PORT_PCR_IRQC(0x0F));                                                   
  /* GPIOE_PDDR: PDD&=~0x00700000 */
  GPIOE_PDDR &= (uint32_t)~(uint32_t)(GPIO_PDDR_PDD(0x00700000));                                                   
  /* Unregistration of the device structure */
  PE_LDD_UnregisterDeviceStructure(PE_LDD_COMPONENT_GPIO1_ID);
  /* Deallocation of the device structure */
  /* {Default RTOS Adapter} Driver memory deallocation: Dynamic allocation is simulated, no deallocation code is generated */
}

/*
** ===================================================================
**     Method      :  GPIO1_GetPortValue (component GPIO_LDD)
**
**     Description :
**         This method returns the current port input data value. Only
**         configured pins (through all of bit fields in this component)
**         are returned.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Unaligned current port input data value
**                           masked for allocated pins of the port. The
**                           bit 0 corresponds with the pin which has
**                           index 0 within the port, the bit 1
**                           corresponds with the pin which has index 1
**                           within the port, etc. Only configured pins
**                           (through all of bit fields in this
**                           component) are returned. The others are
**                           zeros.
** ===================================================================
*/
GPIO1_TPortValue GPIO1_GetPortValue(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  return (GPIO1_TPortValue)(GPIO_PDD_GetPortDataInput(GPIO1_MODULE_BASE_ADDRESS)
    & ((GPIO1_TPortValue)GPIO1_ALLOCATED_PINS_MASK));
}

/*
** ===================================================================
**     Method      :  GPIO1_ClearPortBits (component GPIO_LDD)
**
**     Description :
**         This method drives the specified bits of the port to the
**         inactive level. Only configured pins (through all of bit
**         fields in this component) are affected.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Mask            - Unaligned mask of bits to setting the
**                           inactive level. Each port pin has
**                           corresponding bit in the mask. Bit value 0
**                           means not selected bit, bit value 1 means
**                           selected bit. The bit 0 corresponds with
**                           the pin which has index 0 within the port,
**                           the bit 1 corresponds with the pin which
**                           has index 1 within the port, etc. Only
**                           configured pins (through all of bit fields
**                           in this component) are affected.
**     Returns     : Nothing
** ===================================================================
*/
void GPIO1_ClearPortBits(LDD_TDeviceData *DeviceDataPtr, GPIO1_TPortValue Mask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  GPIO_PDD_ClearPortDataOutputMask(GPIO1_MODULE_BASE_ADDRESS,
    ((GPIO1_TPortValue)(((GPIO1_TPortValue)GPIO1_ALLOCATED_PINS_MASK) & ((GPIO1_TPortValue)(Mask)))));
}

/*
** ===================================================================
**     Method      :  GPIO1_SetPortBits (component GPIO_LDD)
**
**     Description :
**         This method drives the specified bits of the port to the
**         active level. Only configured pins (through all of bit
**         fields in this component) are affected.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Mask            - Unaligned mask of bits to setting the
**                           active level. Each port pin has
**                           corresponding bit in the mask. Bit value 0
**                           means not selected bit, bit value 1 means
**                           selected bit. The bit 0 corresponds with
**                           the pin which has index 0 within the port,
**                           the bit 1 corresponds with the pin which
**                           has index 1 within the port, etc. Only
**                           configured pins (through all of bit fields
**                           in this component) are affected.
**     Returns     : Nothing
** ===================================================================
*/
void GPIO1_SetPortBits(LDD_TDeviceData *DeviceDataPtr, GPIO1_TPortValue Mask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  GPIO_PDD_SetPortDataOutputMask(GPIO1_MODULE_BASE_ADDRESS,
    ((GPIO1_TPortValue)(((GPIO1_TPortValue)GPIO1_ALLOCATED_PINS_MASK) & ((GPIO1_TPortValue)(Mask)))));
}

/*
** ===================================================================
**     Method      :  GPIO1_TogglePortBits (component GPIO_LDD)
**
**     Description :
**         This method inverts the specified bits of the port to
**         another level. Only configured pins (through all of bit
**         fields in this component) are affected.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Mask            - Unaligned mask of bits to inverting the
**                           current level. Each port pin has
**                           corresponding bit in the mask. Bit value 0
**                           means not selected bit, bit value 1 means
**                           selected bit. The bit 0 corresponds with
**                           the pin which has index 0 within the port,
**                           the bit 1 corresponds with the pin which
**                           has index 1 within the port, etc. Only
**                           configured pins (through all of bit fields
**                           in this component) are affected.
**     Returns     : Nothing
** ===================================================================
*/
void GPIO1_TogglePortBits(LDD_TDeviceData *DeviceDataPtr, GPIO1_TPortValue Mask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  GPIO_PDD_TogglePortDataOutputMask(GPIO1_MODULE_BASE_ADDRESS,
    ((GPIO1_TPortValue)(((GPIO1_TPortValue)GPIO1_ALLOCATED_PINS_MASK) & ((GPIO1_TPortValue)(Mask)))));
}

/*
** ===================================================================
**     Method      :  GPIO1_SetFieldValue (component GPIO_LDD)
**
**     Description :
**         This method sets the output data value of the specified bit
**         field.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**         Value           - Aligned data value to writting to the
**                           specified bit field. The bit 0 corresponds
**                           with the pin which has index 0 within the
**                           given bit field, the bit 1 corresponds with
**                           the pin which has index 1 within the given
**                           bit field, etc.
**     Returns     : Nothing
** ===================================================================
*/
void GPIO1_SetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, GPIO1_TFieldValue Value)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case LED_R: {                      /* bit field #0 */
      GPIO_PDD_SetPortDataOutput(GPIO1_MODULE_BASE_ADDRESS,
        (
          GPIO_PDD_GetPortDataOutput(GPIO1_MODULE_BASE_ADDRESS)
          & ((GPIO1_TPortValue)(~((GPIO1_TPortValue)GPIO1_LED_R_MASK)))
        )
        | (
          ((GPIO1_TPortValue)(Value << GPIO1_LED_R_START_BIT))
          & ((GPIO1_TPortValue)GPIO1_LED_R_MASK)
        )
      );
      break;
    }
    case LED_G: {                      /* bit field #1 */
      GPIO_PDD_SetPortDataOutput(GPIO1_MODULE_BASE_ADDRESS,
        (
          GPIO_PDD_GetPortDataOutput(GPIO1_MODULE_BASE_ADDRESS)
          & ((GPIO1_TPortValue)(~((GPIO1_TPortValue)GPIO1_LED_G_MASK)))
        )
        | (
          ((GPIO1_TPortValue)(Value << GPIO1_LED_G_START_BIT))
          & ((GPIO1_TPortValue)GPIO1_LED_G_MASK)
        )
      );
      break;
    }
    case LED_B: {                      /* bit field #2 */
      GPIO_PDD_SetPortDataOutput(GPIO1_MODULE_BASE_ADDRESS,
        (
          GPIO_PDD_GetPortDataOutput(GPIO1_MODULE_BASE_ADDRESS)
          & ((GPIO1_TPortValue)(~((GPIO1_TPortValue)GPIO1_LED_B_MASK)))
        )
        | (
          ((GPIO1_TPortValue)(Value << GPIO1_LED_B_START_BIT))
          & ((GPIO1_TPortValue)GPIO1_LED_B_MASK)
        )
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  GPIO1_GetFieldValue (component GPIO_LDD)
**
**     Description :
**         This method returns the current input data of the specified
**         field.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Field           - Bit field to reading. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**     Returns     :
**         ---             - Aligned current port input value masked
**                           for allocated pins of the field. The bit 0
**                           corresponds with the pin which has index 0
**                           within the given bit field, the bit 1
**                           corresponds with the pin which has index 1
**                           within the given bit field, etc.
** ===================================================================
*/
GPIO1_TFieldValue GPIO1_GetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case LED_R: {                      /* bit field #0 */
      return
        (GPIO1_TFieldValue)(
          (
            GPIO_PDD_GetPortDataInput(GPIO1_MODULE_BASE_ADDRESS)
            & (GPIO1_TPortValue)GPIO1_LED_R_MASK
          )
          >> GPIO1_LED_R_START_BIT
        );
    }
    case LED_G: {                      /* bit field #1 */
      return
        (GPIO1_TFieldValue)(
          (
            GPIO_PDD_GetPortDataInput(GPIO1_MODULE_BASE_ADDRESS)
            & (GPIO1_TPortValue)GPIO1_LED_G_MASK
          )
          >> GPIO1_LED_G_START_BIT
        );
    }
    case LED_B: {                      /* bit field #2 */
      return
        (GPIO1_TFieldValue)(
          (
            GPIO_PDD_GetPortDataInput(GPIO1_MODULE_BASE_ADDRESS)
            & (GPIO1_TPortValue)GPIO1_LED_B_MASK
          )
          >> GPIO1_LED_B_START_BIT
        );
    }
    default:
      break;                           /* Invalid BitField is not treated, result is undefined */
  } /* switch (Field) */
  return (GPIO1_TFieldValue)0U;
}

/*
** ===================================================================
**     Method      :  GPIO1_ClearFieldBits (component GPIO_LDD)
**
**     Description :
**         This method drives the specified bits of the specified bit
**         field to the inactive level.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**         Mask            - Aligned mask of bits to setting the
**                           inactive level. Each field pin has
**                           corresponding bit in the mask. Bit value 0
**                           means not selected bit, bit value 1 means
**                           selected bit. The bit 0 corresponds with
**                           the pin which has index 0 within the given
**                           bit field, the bit 1 corresponds with the
**                           pin which has index 1 within the given bit
**                           field, etc.
**     Returns     : Nothing
** ===================================================================
*/
void GPIO1_ClearFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, GPIO1_TFieldValue Mask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case LED_R: {                      /* bit field #0 */
      GPIO_PDD_ClearPortDataOutputMask(GPIO1_MODULE_BASE_ADDRESS,
        ((GPIO1_TPortValue)GPIO1_LED_R_MASK)
        & ((GPIO1_TPortValue)(Mask << GPIO1_LED_R_START_BIT))
      );
      break;
    }
    case LED_G: {                      /* bit field #1 */
      GPIO_PDD_ClearPortDataOutputMask(GPIO1_MODULE_BASE_ADDRESS,
        ((GPIO1_TPortValue)GPIO1_LED_G_MASK)
        & ((GPIO1_TPortValue)(Mask << GPIO1_LED_G_START_BIT))
      );
      break;
    }
    case LED_B: {                      /* bit field #2 */
      GPIO_PDD_ClearPortDataOutputMask(GPIO1_MODULE_BASE_ADDRESS,
        ((GPIO1_TPortValue)GPIO1_LED_B_MASK)
        & ((GPIO1_TPortValue)(Mask << GPIO1_LED_B_START_BIT))
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  GPIO1_SetFieldBits (component GPIO_LDD)
**
**     Description :
**         This method drives the specified bits of the specified bit
**         field to the active level.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**         Mask            - Aligned mask of bits to setting the
**                           active level. Each field pin has
**                           corresponding bit in the mask. Bit value 0
**                           means not selected bit, bit value 1 means
**                           selected bit. The bit 0 corresponds with
**                           the pin which has index 0 within the given
**                           bit field, the bit 1 corresponds with the
**                           pin which has index 1 within the given bit
**                           field, etc.
**     Returns     : Nothing
** ===================================================================
*/
void GPIO1_SetFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, GPIO1_TFieldValue Mask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case LED_R: {                      /* bit field #0 */
      GPIO_PDD_SetPortDataOutputMask(GPIO1_MODULE_BASE_ADDRESS,
        ((GPIO1_TPortValue)GPIO1_LED_R_MASK)
        & ((GPIO1_TPortValue)(Mask << GPIO1_LED_R_START_BIT))
      );
      break;
    }
    case LED_G: {                      /* bit field #1 */
      GPIO_PDD_SetPortDataOutputMask(GPIO1_MODULE_BASE_ADDRESS,
        ((GPIO1_TPortValue)GPIO1_LED_G_MASK)
        & ((GPIO1_TPortValue)(Mask << GPIO1_LED_G_START_BIT))
      );
      break;
    }
    case LED_B: {                      /* bit field #2 */
      GPIO_PDD_SetPortDataOutputMask(GPIO1_MODULE_BASE_ADDRESS,
        ((GPIO1_TPortValue)GPIO1_LED_B_MASK)
        & ((GPIO1_TPortValue)(Mask << GPIO1_LED_B_START_BIT))
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  GPIO1_ToggleFieldBits (component GPIO_LDD)
**
**     Description :
**         This method inverts the specified bits of the specified bit
**         field to other level.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**         Mask            - Aligned mask of bits to inverting the
**                           current level. Each field pin has
**                           corresponding bit in the mask. Bit value 0
**                           means not selected bit, bit value 1 means
**                           selected bit. The bit 0 corresponds with
**                           the pin which has index 0 within the given
**                           bit field, the bit 1 corresponds with the
**                           pin which has index 1 within the given bit
**                           field, etc.
**     Returns     : Nothing
** ===================================================================
*/
void GPIO1_ToggleFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, GPIO1_TFieldValue Mask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case LED_R: {                      /* bit field #0 */
      GPIO_PDD_TogglePortDataOutputMask(GPIO1_MODULE_BASE_ADDRESS,
        ((GPIO1_TPortValue)GPIO1_LED_R_MASK)
        & ((GPIO1_TPortValue)(Mask << GPIO1_LED_R_START_BIT))
      );
      break;
    }
    case LED_G: {                      /* bit field #1 */
      GPIO_PDD_TogglePortDataOutputMask(GPIO1_MODULE_BASE_ADDRESS,
        ((GPIO1_TPortValue)GPIO1_LED_G_MASK)
        & ((GPIO1_TPortValue)(Mask << GPIO1_LED_G_START_BIT))
      );
      break;
    }
    case LED_B: {                      /* bit field #2 */
      GPIO_PDD_TogglePortDataOutputMask(GPIO1_MODULE_BASE_ADDRESS,
        ((GPIO1_TPortValue)GPIO1_LED_B_MASK)
        & ((GPIO1_TPortValue)(Mask << GPIO1_LED_B_START_BIT))
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  GPIO1_SetFieldInputDirection (component GPIO_LDD)
**
**     Description :
**         This method sets all pins of the field to the input
**         direction.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**     Returns     : Nothing
** ===================================================================
*/
void GPIO1_SetFieldInputDirection(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case LED_R: {                      /* bit field #0 */
      GPIO_PDD_SetPortInputDirectionMask(GPIO1_MODULE_BASE_ADDRESS,
        GPIO1_LED_R_MASK
      );
      break;
    }
    case LED_G: {                      /* bit field #1 */
      GPIO_PDD_SetPortInputDirectionMask(GPIO1_MODULE_BASE_ADDRESS,
        GPIO1_LED_G_MASK
      );
      break;
    }
    case LED_B: {                      /* bit field #2 */
      GPIO_PDD_SetPortInputDirectionMask(GPIO1_MODULE_BASE_ADDRESS,
        GPIO1_LED_B_MASK
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  GPIO1_SetFieldOutputDirection (component GPIO_LDD)
**
**     Description :
**         This method sets all pins of the field to the output
**         direction.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Field           - Bit field to set to the output
**                           direction. Bit fields are defined during
**                           design time and for each bit field there is
**                           a generated constant.
**         Value           - Aligned data value to appear on the
**                           bit field pins after they have been
**                           switched to the output direction.
**     Returns     : Nothing
** ===================================================================
*/
void GPIO1_SetFieldOutputDirection(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, GPIO1_TFieldValue Value)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case LED_R: {                      /* bit field #0 */
      GPIO_PDD_SetPortDataOutput(GPIO1_MODULE_BASE_ADDRESS,
        ((GPIO1_TPortValue)(
          GPIO_PDD_GetPortDataOutput(GPIO1_MODULE_BASE_ADDRESS)
          & ((GPIO1_TPortValue)(
            ~((GPIO1_TPortValue)GPIO1_LED_R_MASK)
          ))
        ))
        | (
          ((GPIO1_TPortValue)(Value << GPIO1_LED_R_START_BIT))
          & ((GPIO1_TPortValue)GPIO1_LED_R_MASK)
        )
      );
      GPIO_PDD_SetPortOutputDirectionMask(GPIO1_MODULE_BASE_ADDRESS,
        GPIO1_LED_R_MASK
      );
      break;
    }
    case LED_G: {                      /* bit field #1 */
      GPIO_PDD_SetPortDataOutput(GPIO1_MODULE_BASE_ADDRESS,
        ((GPIO1_TPortValue)(
          GPIO_PDD_GetPortDataOutput(GPIO1_MODULE_BASE_ADDRESS)
          & ((GPIO1_TPortValue)(
            ~((GPIO1_TPortValue)GPIO1_LED_G_MASK)
          ))
        ))
        | (
          ((GPIO1_TPortValue)(Value << GPIO1_LED_G_START_BIT))
          & ((GPIO1_TPortValue)GPIO1_LED_G_MASK)
        )
      );
      GPIO_PDD_SetPortOutputDirectionMask(GPIO1_MODULE_BASE_ADDRESS,
        GPIO1_LED_G_MASK
      );
      break;
    }
    case LED_B: {                      /* bit field #2 */
      GPIO_PDD_SetPortDataOutput(GPIO1_MODULE_BASE_ADDRESS,
        ((GPIO1_TPortValue)(
          GPIO_PDD_GetPortDataOutput(GPIO1_MODULE_BASE_ADDRESS)
          & ((GPIO1_TPortValue)(
            ~((GPIO1_TPortValue)GPIO1_LED_B_MASK)
          ))
        ))
        | (
          ((GPIO1_TPortValue)(Value << GPIO1_LED_B_START_BIT))
          & ((GPIO1_TPortValue)GPIO1_LED_B_MASK)
        )
      );
      GPIO_PDD_SetPortOutputDirectionMask(GPIO1_MODULE_BASE_ADDRESS,
        GPIO1_LED_B_MASK
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/* END GPIO1. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/

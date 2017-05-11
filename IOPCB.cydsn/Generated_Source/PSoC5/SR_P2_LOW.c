/*******************************************************************************
* File Name: SR_P2_LOW.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware to read the value of a Status 
*  Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "SR_P2_LOW.h"

#if !defined(SR_P2_LOW_sts_sts_reg__REMOVED) /* Check for removal by optimization */


/*******************************************************************************
* Function Name: SR_P2_LOW_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The current value in the Status Register.
*
*******************************************************************************/
uint8 SR_P2_LOW_Read(void) 
{ 
    return SR_P2_LOW_Status;
}


/*******************************************************************************
* Function Name: SR_P2_LOW_InterruptEnable
********************************************************************************
*
* Summary:
*  Enables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SR_P2_LOW_InterruptEnable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    SR_P2_LOW_Status_Aux_Ctrl |= SR_P2_LOW_STATUS_INTR_ENBL;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: SR_P2_LOW_InterruptDisable
********************************************************************************
*
* Summary:
*  Disables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SR_P2_LOW_InterruptDisable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    SR_P2_LOW_Status_Aux_Ctrl &= (uint8)(~SR_P2_LOW_STATUS_INTR_ENBL);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: SR_P2_LOW_WriteMask
********************************************************************************
*
* Summary:
*  Writes the current mask value assigned to the Status Register.
*
* Parameters:
*  mask:  Value to write into the mask register.
*
* Return:
*  None.
*
*******************************************************************************/
void SR_P2_LOW_WriteMask(uint8 mask) 
{
    #if(SR_P2_LOW_INPUTS < 8u)
    	mask &= ((uint8)(1u << SR_P2_LOW_INPUTS) - 1u);
	#endif /* End SR_P2_LOW_INPUTS < 8u */
    SR_P2_LOW_Status_Mask = mask;
}


/*******************************************************************************
* Function Name: SR_P2_LOW_ReadMask
********************************************************************************
*
* Summary:
*  Reads the current interrupt mask assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The value of the interrupt mask of the Status Register.
*
*******************************************************************************/
uint8 SR_P2_LOW_ReadMask(void) 
{
    return SR_P2_LOW_Status_Mask;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */

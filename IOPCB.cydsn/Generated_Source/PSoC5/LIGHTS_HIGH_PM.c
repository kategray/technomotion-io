/*******************************************************************************
* File Name: LIGHTS_HIGH_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "LIGHTS_HIGH.h"

/* Check for removal by optimization */
#if !defined(LIGHTS_HIGH_Sync_ctrl_reg__REMOVED)

static LIGHTS_HIGH_BACKUP_STRUCT  LIGHTS_HIGH_backup = {0u};

    
/*******************************************************************************
* Function Name: LIGHTS_HIGH_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LIGHTS_HIGH_SaveConfig(void) 
{
    LIGHTS_HIGH_backup.controlState = LIGHTS_HIGH_Control;
}


/*******************************************************************************
* Function Name: LIGHTS_HIGH_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void LIGHTS_HIGH_RestoreConfig(void) 
{
     LIGHTS_HIGH_Control = LIGHTS_HIGH_backup.controlState;
}


/*******************************************************************************
* Function Name: LIGHTS_HIGH_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LIGHTS_HIGH_Sleep(void) 
{
    LIGHTS_HIGH_SaveConfig();
}


/*******************************************************************************
* Function Name: LIGHTS_HIGH_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LIGHTS_HIGH_Wakeup(void)  
{
    LIGHTS_HIGH_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */

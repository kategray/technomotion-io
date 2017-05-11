/*******************************************************************************
* File Name: LIGHTS_LOW.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_LIGHTS_LOW_H) /* CY_CONTROL_REG_LIGHTS_LOW_H */
#define CY_CONTROL_REG_LIGHTS_LOW_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} LIGHTS_LOW_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    LIGHTS_LOW_Write(uint8 control) ;
uint8   LIGHTS_LOW_Read(void) ;

void LIGHTS_LOW_SaveConfig(void) ;
void LIGHTS_LOW_RestoreConfig(void) ;
void LIGHTS_LOW_Sleep(void) ; 
void LIGHTS_LOW_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define LIGHTS_LOW_Control        (* (reg8 *) LIGHTS_LOW_Sync_ctrl_reg__CONTROL_REG )
#define LIGHTS_LOW_Control_PTR    (  (reg8 *) LIGHTS_LOW_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_LIGHTS_LOW_H */


/* [] END OF FILE */

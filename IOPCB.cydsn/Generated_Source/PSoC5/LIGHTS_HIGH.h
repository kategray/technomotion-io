/*******************************************************************************
* File Name: LIGHTS_HIGH.h  
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

#if !defined(CY_CONTROL_REG_LIGHTS_HIGH_H) /* CY_CONTROL_REG_LIGHTS_HIGH_H */
#define CY_CONTROL_REG_LIGHTS_HIGH_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} LIGHTS_HIGH_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    LIGHTS_HIGH_Write(uint8 control) ;
uint8   LIGHTS_HIGH_Read(void) ;

void LIGHTS_HIGH_SaveConfig(void) ;
void LIGHTS_HIGH_RestoreConfig(void) ;
void LIGHTS_HIGH_Sleep(void) ; 
void LIGHTS_HIGH_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define LIGHTS_HIGH_Control        (* (reg8 *) LIGHTS_HIGH_Sync_ctrl_reg__CONTROL_REG )
#define LIGHTS_HIGH_Control_PTR    (  (reg8 *) LIGHTS_HIGH_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_LIGHTS_HIGH_H */


/* [] END OF FILE */

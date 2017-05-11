/*******************************************************************************
* File Name: SR_P2_LOW.h  
* Version 1.90
*
* Description:
*  This file containts Status Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_STATUS_REG_SR_P2_LOW_H) /* CY_STATUS_REG_SR_P2_LOW_H */
#define CY_STATUS_REG_SR_P2_LOW_H

#include "cytypes.h"
#include "CyLib.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 statusState;

} SR_P2_LOW_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

uint8 SR_P2_LOW_Read(void) ;
void SR_P2_LOW_InterruptEnable(void) ;
void SR_P2_LOW_InterruptDisable(void) ;
void SR_P2_LOW_WriteMask(uint8 mask) ;
uint8 SR_P2_LOW_ReadMask(void) ;


/***************************************
*           API Constants
***************************************/

#define SR_P2_LOW_STATUS_INTR_ENBL    0x10u


/***************************************
*         Parameter Constants
***************************************/

/* Status Register Inputs */
#define SR_P2_LOW_INPUTS              8


/***************************************
*             Registers
***************************************/

/* Status Register */
#define SR_P2_LOW_Status             (* (reg8 *) SR_P2_LOW_sts_sts_reg__STATUS_REG )
#define SR_P2_LOW_Status_PTR         (  (reg8 *) SR_P2_LOW_sts_sts_reg__STATUS_REG )
#define SR_P2_LOW_Status_Mask        (* (reg8 *) SR_P2_LOW_sts_sts_reg__MASK_REG )
#define SR_P2_LOW_Status_Aux_Ctrl    (* (reg8 *) SR_P2_LOW_sts_sts_reg__STATUS_AUX_CTL_REG )

#endif /* End CY_STATUS_REG_SR_P2_LOW_H */


/* [] END OF FILE */

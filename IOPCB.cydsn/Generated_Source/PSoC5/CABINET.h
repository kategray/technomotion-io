/*******************************************************************************
* File Name: CABINET.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_CABINET_H) /* Pins CABINET_H */
#define CY_PINS_CABINET_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CABINET_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CABINET__PORT == 15 && ((CABINET__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    CABINET_Write(uint8 value);
void    CABINET_SetDriveMode(uint8 mode);
uint8   CABINET_ReadDataReg(void);
uint8   CABINET_Read(void);
void    CABINET_SetInterruptMode(uint16 position, uint16 mode);
uint8   CABINET_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the CABINET_SetDriveMode() function.
     *  @{
     */
        #define CABINET_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define CABINET_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define CABINET_DM_RES_UP          PIN_DM_RES_UP
        #define CABINET_DM_RES_DWN         PIN_DM_RES_DWN
        #define CABINET_DM_OD_LO           PIN_DM_OD_LO
        #define CABINET_DM_OD_HI           PIN_DM_OD_HI
        #define CABINET_DM_STRONG          PIN_DM_STRONG
        #define CABINET_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define CABINET_MASK               CABINET__MASK
#define CABINET_SHIFT              CABINET__SHIFT
#define CABINET_WIDTH              8u

/* Interrupt constants */
#if defined(CABINET__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in CABINET_SetInterruptMode() function.
     *  @{
     */
        #define CABINET_INTR_NONE      (uint16)(0x0000u)
        #define CABINET_INTR_RISING    (uint16)(0x0001u)
        #define CABINET_INTR_FALLING   (uint16)(0x0002u)
        #define CABINET_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define CABINET_INTR_MASK      (0x01u) 
#endif /* (CABINET__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CABINET_PS                     (* (reg8 *) CABINET__PS)
/* Data Register */
#define CABINET_DR                     (* (reg8 *) CABINET__DR)
/* Port Number */
#define CABINET_PRT_NUM                (* (reg8 *) CABINET__PRT) 
/* Connect to Analog Globals */                                                  
#define CABINET_AG                     (* (reg8 *) CABINET__AG)                       
/* Analog MUX bux enable */
#define CABINET_AMUX                   (* (reg8 *) CABINET__AMUX) 
/* Bidirectional Enable */                                                        
#define CABINET_BIE                    (* (reg8 *) CABINET__BIE)
/* Bit-mask for Aliased Register Access */
#define CABINET_BIT_MASK               (* (reg8 *) CABINET__BIT_MASK)
/* Bypass Enable */
#define CABINET_BYP                    (* (reg8 *) CABINET__BYP)
/* Port wide control signals */                                                   
#define CABINET_CTL                    (* (reg8 *) CABINET__CTL)
/* Drive Modes */
#define CABINET_DM0                    (* (reg8 *) CABINET__DM0) 
#define CABINET_DM1                    (* (reg8 *) CABINET__DM1)
#define CABINET_DM2                    (* (reg8 *) CABINET__DM2) 
/* Input Buffer Disable Override */
#define CABINET_INP_DIS                (* (reg8 *) CABINET__INP_DIS)
/* LCD Common or Segment Drive */
#define CABINET_LCD_COM_SEG            (* (reg8 *) CABINET__LCD_COM_SEG)
/* Enable Segment LCD */
#define CABINET_LCD_EN                 (* (reg8 *) CABINET__LCD_EN)
/* Slew Rate Control */
#define CABINET_SLW                    (* (reg8 *) CABINET__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CABINET_PRTDSI__CAPS_SEL       (* (reg8 *) CABINET__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CABINET_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CABINET__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CABINET_PRTDSI__OE_SEL0        (* (reg8 *) CABINET__PRTDSI__OE_SEL0) 
#define CABINET_PRTDSI__OE_SEL1        (* (reg8 *) CABINET__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CABINET_PRTDSI__OUT_SEL0       (* (reg8 *) CABINET__PRTDSI__OUT_SEL0) 
#define CABINET_PRTDSI__OUT_SEL1       (* (reg8 *) CABINET__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CABINET_PRTDSI__SYNC_OUT       (* (reg8 *) CABINET__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(CABINET__SIO_CFG)
    #define CABINET_SIO_HYST_EN        (* (reg8 *) CABINET__SIO_HYST_EN)
    #define CABINET_SIO_REG_HIFREQ     (* (reg8 *) CABINET__SIO_REG_HIFREQ)
    #define CABINET_SIO_CFG            (* (reg8 *) CABINET__SIO_CFG)
    #define CABINET_SIO_DIFF           (* (reg8 *) CABINET__SIO_DIFF)
#endif /* (CABINET__SIO_CFG) */

/* Interrupt Registers */
#if defined(CABINET__INTSTAT)
    #define CABINET_INTSTAT            (* (reg8 *) CABINET__INTSTAT)
    #define CABINET_SNAP               (* (reg8 *) CABINET__SNAP)
    
	#define CABINET_0_INTTYPE_REG 		(* (reg8 *) CABINET__0__INTTYPE)
	#define CABINET_1_INTTYPE_REG 		(* (reg8 *) CABINET__1__INTTYPE)
	#define CABINET_2_INTTYPE_REG 		(* (reg8 *) CABINET__2__INTTYPE)
	#define CABINET_3_INTTYPE_REG 		(* (reg8 *) CABINET__3__INTTYPE)
	#define CABINET_4_INTTYPE_REG 		(* (reg8 *) CABINET__4__INTTYPE)
	#define CABINET_5_INTTYPE_REG 		(* (reg8 *) CABINET__5__INTTYPE)
	#define CABINET_6_INTTYPE_REG 		(* (reg8 *) CABINET__6__INTTYPE)
	#define CABINET_7_INTTYPE_REG 		(* (reg8 *) CABINET__7__INTTYPE)
#endif /* (CABINET__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CABINET_H */


/* [] END OF FILE */

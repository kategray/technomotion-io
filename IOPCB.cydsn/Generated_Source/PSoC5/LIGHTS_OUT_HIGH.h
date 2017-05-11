/*******************************************************************************
* File Name: LIGHTS_OUT_HIGH.h  
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

#if !defined(CY_PINS_LIGHTS_OUT_HIGH_H) /* Pins LIGHTS_OUT_HIGH_H */
#define CY_PINS_LIGHTS_OUT_HIGH_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LIGHTS_OUT_HIGH_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LIGHTS_OUT_HIGH__PORT == 15 && ((LIGHTS_OUT_HIGH__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    LIGHTS_OUT_HIGH_Write(uint8 value);
void    LIGHTS_OUT_HIGH_SetDriveMode(uint8 mode);
uint8   LIGHTS_OUT_HIGH_ReadDataReg(void);
uint8   LIGHTS_OUT_HIGH_Read(void);
void    LIGHTS_OUT_HIGH_SetInterruptMode(uint16 position, uint16 mode);
uint8   LIGHTS_OUT_HIGH_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the LIGHTS_OUT_HIGH_SetDriveMode() function.
     *  @{
     */
        #define LIGHTS_OUT_HIGH_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define LIGHTS_OUT_HIGH_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define LIGHTS_OUT_HIGH_DM_RES_UP          PIN_DM_RES_UP
        #define LIGHTS_OUT_HIGH_DM_RES_DWN         PIN_DM_RES_DWN
        #define LIGHTS_OUT_HIGH_DM_OD_LO           PIN_DM_OD_LO
        #define LIGHTS_OUT_HIGH_DM_OD_HI           PIN_DM_OD_HI
        #define LIGHTS_OUT_HIGH_DM_STRONG          PIN_DM_STRONG
        #define LIGHTS_OUT_HIGH_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define LIGHTS_OUT_HIGH_MASK               LIGHTS_OUT_HIGH__MASK
#define LIGHTS_OUT_HIGH_SHIFT              LIGHTS_OUT_HIGH__SHIFT
#define LIGHTS_OUT_HIGH_WIDTH              8u

/* Interrupt constants */
#if defined(LIGHTS_OUT_HIGH__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LIGHTS_OUT_HIGH_SetInterruptMode() function.
     *  @{
     */
        #define LIGHTS_OUT_HIGH_INTR_NONE      (uint16)(0x0000u)
        #define LIGHTS_OUT_HIGH_INTR_RISING    (uint16)(0x0001u)
        #define LIGHTS_OUT_HIGH_INTR_FALLING   (uint16)(0x0002u)
        #define LIGHTS_OUT_HIGH_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define LIGHTS_OUT_HIGH_INTR_MASK      (0x01u) 
#endif /* (LIGHTS_OUT_HIGH__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LIGHTS_OUT_HIGH_PS                     (* (reg8 *) LIGHTS_OUT_HIGH__PS)
/* Data Register */
#define LIGHTS_OUT_HIGH_DR                     (* (reg8 *) LIGHTS_OUT_HIGH__DR)
/* Port Number */
#define LIGHTS_OUT_HIGH_PRT_NUM                (* (reg8 *) LIGHTS_OUT_HIGH__PRT) 
/* Connect to Analog Globals */                                                  
#define LIGHTS_OUT_HIGH_AG                     (* (reg8 *) LIGHTS_OUT_HIGH__AG)                       
/* Analog MUX bux enable */
#define LIGHTS_OUT_HIGH_AMUX                   (* (reg8 *) LIGHTS_OUT_HIGH__AMUX) 
/* Bidirectional Enable */                                                        
#define LIGHTS_OUT_HIGH_BIE                    (* (reg8 *) LIGHTS_OUT_HIGH__BIE)
/* Bit-mask for Aliased Register Access */
#define LIGHTS_OUT_HIGH_BIT_MASK               (* (reg8 *) LIGHTS_OUT_HIGH__BIT_MASK)
/* Bypass Enable */
#define LIGHTS_OUT_HIGH_BYP                    (* (reg8 *) LIGHTS_OUT_HIGH__BYP)
/* Port wide control signals */                                                   
#define LIGHTS_OUT_HIGH_CTL                    (* (reg8 *) LIGHTS_OUT_HIGH__CTL)
/* Drive Modes */
#define LIGHTS_OUT_HIGH_DM0                    (* (reg8 *) LIGHTS_OUT_HIGH__DM0) 
#define LIGHTS_OUT_HIGH_DM1                    (* (reg8 *) LIGHTS_OUT_HIGH__DM1)
#define LIGHTS_OUT_HIGH_DM2                    (* (reg8 *) LIGHTS_OUT_HIGH__DM2) 
/* Input Buffer Disable Override */
#define LIGHTS_OUT_HIGH_INP_DIS                (* (reg8 *) LIGHTS_OUT_HIGH__INP_DIS)
/* LCD Common or Segment Drive */
#define LIGHTS_OUT_HIGH_LCD_COM_SEG            (* (reg8 *) LIGHTS_OUT_HIGH__LCD_COM_SEG)
/* Enable Segment LCD */
#define LIGHTS_OUT_HIGH_LCD_EN                 (* (reg8 *) LIGHTS_OUT_HIGH__LCD_EN)
/* Slew Rate Control */
#define LIGHTS_OUT_HIGH_SLW                    (* (reg8 *) LIGHTS_OUT_HIGH__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LIGHTS_OUT_HIGH_PRTDSI__CAPS_SEL       (* (reg8 *) LIGHTS_OUT_HIGH__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LIGHTS_OUT_HIGH_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LIGHTS_OUT_HIGH__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LIGHTS_OUT_HIGH_PRTDSI__OE_SEL0        (* (reg8 *) LIGHTS_OUT_HIGH__PRTDSI__OE_SEL0) 
#define LIGHTS_OUT_HIGH_PRTDSI__OE_SEL1        (* (reg8 *) LIGHTS_OUT_HIGH__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LIGHTS_OUT_HIGH_PRTDSI__OUT_SEL0       (* (reg8 *) LIGHTS_OUT_HIGH__PRTDSI__OUT_SEL0) 
#define LIGHTS_OUT_HIGH_PRTDSI__OUT_SEL1       (* (reg8 *) LIGHTS_OUT_HIGH__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LIGHTS_OUT_HIGH_PRTDSI__SYNC_OUT       (* (reg8 *) LIGHTS_OUT_HIGH__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(LIGHTS_OUT_HIGH__SIO_CFG)
    #define LIGHTS_OUT_HIGH_SIO_HYST_EN        (* (reg8 *) LIGHTS_OUT_HIGH__SIO_HYST_EN)
    #define LIGHTS_OUT_HIGH_SIO_REG_HIFREQ     (* (reg8 *) LIGHTS_OUT_HIGH__SIO_REG_HIFREQ)
    #define LIGHTS_OUT_HIGH_SIO_CFG            (* (reg8 *) LIGHTS_OUT_HIGH__SIO_CFG)
    #define LIGHTS_OUT_HIGH_SIO_DIFF           (* (reg8 *) LIGHTS_OUT_HIGH__SIO_DIFF)
#endif /* (LIGHTS_OUT_HIGH__SIO_CFG) */

/* Interrupt Registers */
#if defined(LIGHTS_OUT_HIGH__INTSTAT)
    #define LIGHTS_OUT_HIGH_INTSTAT            (* (reg8 *) LIGHTS_OUT_HIGH__INTSTAT)
    #define LIGHTS_OUT_HIGH_SNAP               (* (reg8 *) LIGHTS_OUT_HIGH__SNAP)
    
	#define LIGHTS_OUT_HIGH_0_INTTYPE_REG 		(* (reg8 *) LIGHTS_OUT_HIGH__0__INTTYPE)
	#define LIGHTS_OUT_HIGH_1_INTTYPE_REG 		(* (reg8 *) LIGHTS_OUT_HIGH__1__INTTYPE)
	#define LIGHTS_OUT_HIGH_2_INTTYPE_REG 		(* (reg8 *) LIGHTS_OUT_HIGH__2__INTTYPE)
	#define LIGHTS_OUT_HIGH_3_INTTYPE_REG 		(* (reg8 *) LIGHTS_OUT_HIGH__3__INTTYPE)
	#define LIGHTS_OUT_HIGH_4_INTTYPE_REG 		(* (reg8 *) LIGHTS_OUT_HIGH__4__INTTYPE)
	#define LIGHTS_OUT_HIGH_5_INTTYPE_REG 		(* (reg8 *) LIGHTS_OUT_HIGH__5__INTTYPE)
	#define LIGHTS_OUT_HIGH_6_INTTYPE_REG 		(* (reg8 *) LIGHTS_OUT_HIGH__6__INTTYPE)
	#define LIGHTS_OUT_HIGH_7_INTTYPE_REG 		(* (reg8 *) LIGHTS_OUT_HIGH__7__INTTYPE)
#endif /* (LIGHTS_OUT_HIGH__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LIGHTS_OUT_HIGH_H */


/* [] END OF FILE */

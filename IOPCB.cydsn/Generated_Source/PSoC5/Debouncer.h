/*******************************************************************************
* File Name: Debouncer.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Debouncer_H)
#define CY_CLOCK_Debouncer_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void Debouncer_Start(void) ;
void Debouncer_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void Debouncer_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void Debouncer_StandbyPower(uint8 state) ;
void Debouncer_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 Debouncer_GetDividerRegister(void) ;
void Debouncer_SetModeRegister(uint8 modeBitMask) ;
void Debouncer_ClearModeRegister(uint8 modeBitMask) ;
uint8 Debouncer_GetModeRegister(void) ;
void Debouncer_SetSourceRegister(uint8 clkSource) ;
uint8 Debouncer_GetSourceRegister(void) ;
#if defined(Debouncer__CFG3)
void Debouncer_SetPhaseRegister(uint8 clkPhase) ;
uint8 Debouncer_GetPhaseRegister(void) ;
#endif /* defined(Debouncer__CFG3) */

#define Debouncer_Enable()                       Debouncer_Start()
#define Debouncer_Disable()                      Debouncer_Stop()
#define Debouncer_SetDivider(clkDivider)         Debouncer_SetDividerRegister(clkDivider, 1u)
#define Debouncer_SetDividerValue(clkDivider)    Debouncer_SetDividerRegister((clkDivider) - 1u, 1u)
#define Debouncer_SetMode(clkMode)               Debouncer_SetModeRegister(clkMode)
#define Debouncer_SetSource(clkSource)           Debouncer_SetSourceRegister(clkSource)
#if defined(Debouncer__CFG3)
#define Debouncer_SetPhase(clkPhase)             Debouncer_SetPhaseRegister(clkPhase)
#define Debouncer_SetPhaseValue(clkPhase)        Debouncer_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(Debouncer__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define Debouncer_CLKEN              (* (reg8 *) Debouncer__PM_ACT_CFG)
#define Debouncer_CLKEN_PTR          ((reg8 *) Debouncer__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define Debouncer_CLKSTBY            (* (reg8 *) Debouncer__PM_STBY_CFG)
#define Debouncer_CLKSTBY_PTR        ((reg8 *) Debouncer__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define Debouncer_DIV_LSB            (* (reg8 *) Debouncer__CFG0)
#define Debouncer_DIV_LSB_PTR        ((reg8 *) Debouncer__CFG0)
#define Debouncer_DIV_PTR            ((reg16 *) Debouncer__CFG0)

/* Clock MSB divider configuration register. */
#define Debouncer_DIV_MSB            (* (reg8 *) Debouncer__CFG1)
#define Debouncer_DIV_MSB_PTR        ((reg8 *) Debouncer__CFG1)

/* Mode and source configuration register */
#define Debouncer_MOD_SRC            (* (reg8 *) Debouncer__CFG2)
#define Debouncer_MOD_SRC_PTR        ((reg8 *) Debouncer__CFG2)

#if defined(Debouncer__CFG3)
/* Analog clock phase configuration register */
#define Debouncer_PHASE              (* (reg8 *) Debouncer__CFG3)
#define Debouncer_PHASE_PTR          ((reg8 *) Debouncer__CFG3)
#endif /* defined(Debouncer__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define Debouncer_CLKEN_MASK         Debouncer__PM_ACT_MSK
#define Debouncer_CLKSTBY_MASK       Debouncer__PM_STBY_MSK

/* CFG2 field masks */
#define Debouncer_SRC_SEL_MSK        Debouncer__CFG2_SRC_SEL_MASK
#define Debouncer_MODE_MASK          (~(Debouncer_SRC_SEL_MSK))

#if defined(Debouncer__CFG3)
/* CFG3 phase mask */
#define Debouncer_PHASE_MASK         Debouncer__CFG3_PHASE_DLY_MASK
#endif /* defined(Debouncer__CFG3) */

#endif /* CY_CLOCK_Debouncer_H */


/* [] END OF FILE */

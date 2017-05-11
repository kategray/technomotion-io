/*******************************************************************************
* File Name: P1_HIGH.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_P1_HIGH_ALIASES_H) /* Pins P1_HIGH_ALIASES_H */
#define CY_PINS_P1_HIGH_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define P1_HIGH_0			(P1_HIGH__0__PC)
#define P1_HIGH_0_INTR	((uint16)((uint16)0x0001u << P1_HIGH__0__SHIFT))

#define P1_HIGH_1			(P1_HIGH__1__PC)
#define P1_HIGH_1_INTR	((uint16)((uint16)0x0001u << P1_HIGH__1__SHIFT))

#define P1_HIGH_2			(P1_HIGH__2__PC)
#define P1_HIGH_2_INTR	((uint16)((uint16)0x0001u << P1_HIGH__2__SHIFT))

#define P1_HIGH_3			(P1_HIGH__3__PC)
#define P1_HIGH_3_INTR	((uint16)((uint16)0x0001u << P1_HIGH__3__SHIFT))

#define P1_HIGH_4			(P1_HIGH__4__PC)
#define P1_HIGH_4_INTR	((uint16)((uint16)0x0001u << P1_HIGH__4__SHIFT))

#define P1_HIGH_5			(P1_HIGH__5__PC)
#define P1_HIGH_5_INTR	((uint16)((uint16)0x0001u << P1_HIGH__5__SHIFT))

#define P1_HIGH_6			(P1_HIGH__6__PC)
#define P1_HIGH_6_INTR	((uint16)((uint16)0x0001u << P1_HIGH__6__SHIFT))

#define P1_HIGH_7			(P1_HIGH__7__PC)
#define P1_HIGH_7_INTR	((uint16)((uint16)0x0001u << P1_HIGH__7__SHIFT))

#define P1_HIGH_INTR_ALL	 ((uint16)(P1_HIGH_0_INTR| P1_HIGH_1_INTR| P1_HIGH_2_INTR| P1_HIGH_3_INTR| P1_HIGH_4_INTR| P1_HIGH_5_INTR| P1_HIGH_6_INTR| P1_HIGH_7_INTR))

#endif /* End Pins P1_HIGH_ALIASES_H */


/* [] END OF FILE */

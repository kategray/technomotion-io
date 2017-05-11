/*******************************************************************************
* File Name: P2_LOW.h  
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

#if !defined(CY_PINS_P2_LOW_ALIASES_H) /* Pins P2_LOW_ALIASES_H */
#define CY_PINS_P2_LOW_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define P2_LOW_0			(P2_LOW__0__PC)
#define P2_LOW_0_INTR	((uint16)((uint16)0x0001u << P2_LOW__0__SHIFT))

#define P2_LOW_1			(P2_LOW__1__PC)
#define P2_LOW_1_INTR	((uint16)((uint16)0x0001u << P2_LOW__1__SHIFT))

#define P2_LOW_2			(P2_LOW__2__PC)
#define P2_LOW_2_INTR	((uint16)((uint16)0x0001u << P2_LOW__2__SHIFT))

#define P2_LOW_3			(P2_LOW__3__PC)
#define P2_LOW_3_INTR	((uint16)((uint16)0x0001u << P2_LOW__3__SHIFT))

#define P2_LOW_4			(P2_LOW__4__PC)
#define P2_LOW_4_INTR	((uint16)((uint16)0x0001u << P2_LOW__4__SHIFT))

#define P2_LOW_5			(P2_LOW__5__PC)
#define P2_LOW_5_INTR	((uint16)((uint16)0x0001u << P2_LOW__5__SHIFT))

#define P2_LOW_6			(P2_LOW__6__PC)
#define P2_LOW_6_INTR	((uint16)((uint16)0x0001u << P2_LOW__6__SHIFT))

#define P2_LOW_7			(P2_LOW__7__PC)
#define P2_LOW_7_INTR	((uint16)((uint16)0x0001u << P2_LOW__7__SHIFT))

#define P2_LOW_INTR_ALL	 ((uint16)(P2_LOW_0_INTR| P2_LOW_1_INTR| P2_LOW_2_INTR| P2_LOW_3_INTR| P2_LOW_4_INTR| P2_LOW_5_INTR| P2_LOW_6_INTR| P2_LOW_7_INTR))

#endif /* End Pins P2_LOW_ALIASES_H */


/* [] END OF FILE */

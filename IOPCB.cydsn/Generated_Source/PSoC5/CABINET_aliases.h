/*******************************************************************************
* File Name: CABINET.h  
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

#if !defined(CY_PINS_CABINET_ALIASES_H) /* Pins CABINET_ALIASES_H */
#define CY_PINS_CABINET_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define CABINET_0			(CABINET__0__PC)
#define CABINET_0_INTR	((uint16)((uint16)0x0001u << CABINET__0__SHIFT))

#define CABINET_1			(CABINET__1__PC)
#define CABINET_1_INTR	((uint16)((uint16)0x0001u << CABINET__1__SHIFT))

#define CABINET_2			(CABINET__2__PC)
#define CABINET_2_INTR	((uint16)((uint16)0x0001u << CABINET__2__SHIFT))

#define CABINET_3			(CABINET__3__PC)
#define CABINET_3_INTR	((uint16)((uint16)0x0001u << CABINET__3__SHIFT))

#define CABINET_4			(CABINET__4__PC)
#define CABINET_4_INTR	((uint16)((uint16)0x0001u << CABINET__4__SHIFT))

#define CABINET_5			(CABINET__5__PC)
#define CABINET_5_INTR	((uint16)((uint16)0x0001u << CABINET__5__SHIFT))

#define CABINET_6			(CABINET__6__PC)
#define CABINET_6_INTR	((uint16)((uint16)0x0001u << CABINET__6__SHIFT))

#define CABINET_7			(CABINET__7__PC)
#define CABINET_7_INTR	((uint16)((uint16)0x0001u << CABINET__7__SHIFT))

#define CABINET_INTR_ALL	 ((uint16)(CABINET_0_INTR| CABINET_1_INTR| CABINET_2_INTR| CABINET_3_INTR| CABINET_4_INTR| CABINET_5_INTR| CABINET_6_INTR| CABINET_7_INTR))

#endif /* End Pins CABINET_ALIASES_H */


/* [] END OF FILE */

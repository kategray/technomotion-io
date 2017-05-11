/*******************************************************************************
* File Name: LIGHTS_OUT_LOW.h  
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

#if !defined(CY_PINS_LIGHTS_OUT_LOW_ALIASES_H) /* Pins LIGHTS_OUT_LOW_ALIASES_H */
#define CY_PINS_LIGHTS_OUT_LOW_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define LIGHTS_OUT_LOW_0			(LIGHTS_OUT_LOW__0__PC)
#define LIGHTS_OUT_LOW_0_INTR	((uint16)((uint16)0x0001u << LIGHTS_OUT_LOW__0__SHIFT))

#define LIGHTS_OUT_LOW_1			(LIGHTS_OUT_LOW__1__PC)
#define LIGHTS_OUT_LOW_1_INTR	((uint16)((uint16)0x0001u << LIGHTS_OUT_LOW__1__SHIFT))

#define LIGHTS_OUT_LOW_2			(LIGHTS_OUT_LOW__2__PC)
#define LIGHTS_OUT_LOW_2_INTR	((uint16)((uint16)0x0001u << LIGHTS_OUT_LOW__2__SHIFT))

#define LIGHTS_OUT_LOW_3			(LIGHTS_OUT_LOW__3__PC)
#define LIGHTS_OUT_LOW_3_INTR	((uint16)((uint16)0x0001u << LIGHTS_OUT_LOW__3__SHIFT))

#define LIGHTS_OUT_LOW_4			(LIGHTS_OUT_LOW__4__PC)
#define LIGHTS_OUT_LOW_4_INTR	((uint16)((uint16)0x0001u << LIGHTS_OUT_LOW__4__SHIFT))

#define LIGHTS_OUT_LOW_5			(LIGHTS_OUT_LOW__5__PC)
#define LIGHTS_OUT_LOW_5_INTR	((uint16)((uint16)0x0001u << LIGHTS_OUT_LOW__5__SHIFT))

#define LIGHTS_OUT_LOW_6			(LIGHTS_OUT_LOW__6__PC)
#define LIGHTS_OUT_LOW_6_INTR	((uint16)((uint16)0x0001u << LIGHTS_OUT_LOW__6__SHIFT))

#define LIGHTS_OUT_LOW_7			(LIGHTS_OUT_LOW__7__PC)
#define LIGHTS_OUT_LOW_7_INTR	((uint16)((uint16)0x0001u << LIGHTS_OUT_LOW__7__SHIFT))

#define LIGHTS_OUT_LOW_INTR_ALL	 ((uint16)(LIGHTS_OUT_LOW_0_INTR| LIGHTS_OUT_LOW_1_INTR| LIGHTS_OUT_LOW_2_INTR| LIGHTS_OUT_LOW_3_INTR| LIGHTS_OUT_LOW_4_INTR| LIGHTS_OUT_LOW_5_INTR| LIGHTS_OUT_LOW_6_INTR| LIGHTS_OUT_LOW_7_INTR))

#endif /* End Pins LIGHTS_OUT_LOW_ALIASES_H */


/* [] END OF FILE */

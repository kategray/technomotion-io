/*******************************************************************************
* File Name: LIGHTS_OUT_HIGH.h  
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

#if !defined(CY_PINS_LIGHTS_OUT_HIGH_ALIASES_H) /* Pins LIGHTS_OUT_HIGH_ALIASES_H */
#define CY_PINS_LIGHTS_OUT_HIGH_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define LIGHTS_OUT_HIGH_0			(LIGHTS_OUT_HIGH__0__PC)
#define LIGHTS_OUT_HIGH_0_INTR	((uint16)((uint16)0x0001u << LIGHTS_OUT_HIGH__0__SHIFT))

#define LIGHTS_OUT_HIGH_1			(LIGHTS_OUT_HIGH__1__PC)
#define LIGHTS_OUT_HIGH_1_INTR	((uint16)((uint16)0x0001u << LIGHTS_OUT_HIGH__1__SHIFT))

#define LIGHTS_OUT_HIGH_2			(LIGHTS_OUT_HIGH__2__PC)
#define LIGHTS_OUT_HIGH_2_INTR	((uint16)((uint16)0x0001u << LIGHTS_OUT_HIGH__2__SHIFT))

#define LIGHTS_OUT_HIGH_3			(LIGHTS_OUT_HIGH__3__PC)
#define LIGHTS_OUT_HIGH_3_INTR	((uint16)((uint16)0x0001u << LIGHTS_OUT_HIGH__3__SHIFT))

#define LIGHTS_OUT_HIGH_4			(LIGHTS_OUT_HIGH__4__PC)
#define LIGHTS_OUT_HIGH_4_INTR	((uint16)((uint16)0x0001u << LIGHTS_OUT_HIGH__4__SHIFT))

#define LIGHTS_OUT_HIGH_5			(LIGHTS_OUT_HIGH__5__PC)
#define LIGHTS_OUT_HIGH_5_INTR	((uint16)((uint16)0x0001u << LIGHTS_OUT_HIGH__5__SHIFT))

#define LIGHTS_OUT_HIGH_6			(LIGHTS_OUT_HIGH__6__PC)
#define LIGHTS_OUT_HIGH_6_INTR	((uint16)((uint16)0x0001u << LIGHTS_OUT_HIGH__6__SHIFT))

#define LIGHTS_OUT_HIGH_7			(LIGHTS_OUT_HIGH__7__PC)
#define LIGHTS_OUT_HIGH_7_INTR	((uint16)((uint16)0x0001u << LIGHTS_OUT_HIGH__7__SHIFT))

#define LIGHTS_OUT_HIGH_INTR_ALL	 ((uint16)(LIGHTS_OUT_HIGH_0_INTR| LIGHTS_OUT_HIGH_1_INTR| LIGHTS_OUT_HIGH_2_INTR| LIGHTS_OUT_HIGH_3_INTR| LIGHTS_OUT_HIGH_4_INTR| LIGHTS_OUT_HIGH_5_INTR| LIGHTS_OUT_HIGH_6_INTR| LIGHTS_OUT_HIGH_7_INTR))

#endif /* End Pins LIGHTS_OUT_HIGH_ALIASES_H */


/* [] END OF FILE */

/***************************************************************************//**
* \file USBFS_descr.c
* \version 3.10
*
* \brief
*  This file contains the USB descriptors and storage.
*
********************************************************************************
* \copyright
* Copyright 2008-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "USBFS_pvt.h"


/*****************************************************************************
*  User supplied descriptors.  If you want to specify your own descriptors,
*  define USER_SUPPLIED_DESCRIPTORS below and add your descriptors.
*****************************************************************************/
/* `#START USER_DESCRIPTORS_DECLARATIONS` Place your declaration here */

/* `#END` */


/***************************************
*  USB Customizer Generated Descriptors
***************************************/

#if !defined(USER_SUPPLIED_DESCRIPTORS)
/*********************************************************************
* Device Descriptors
*********************************************************************/
const uint8 CYCODE USBFS_DEVICE0_DESCR[18u] = {
/* Descriptor Length                       */ 0x12u,
/* DescriptorType: DEVICE                  */ 0x01u,
/* bcdUSB (ver 2.0)                        */ 0x00u, 0x02u,
/* bDeviceClass                            */ 0x00u,
/* bDeviceSubClass                         */ 0x00u,
/* bDeviceProtocol                         */ 0x00u,
/* bMaxPacketSize0                         */ 0x08u,
/* idVendor                                */ 0xC0u, 0x07u,
/* idProduct                               */ 0x84u, 0x15u,
/* bcdDevice                               */ 0x00u, 0x30u,
/* iManufacturer                           */ 0x01u,
/* iProduct                                */ 0x02u,
/* iSerialNumber                           */ 0x80u,
/* bNumConfigurations                      */ 0x01u
};
/*********************************************************************
* Config Descriptor  
*********************************************************************/
const uint8 CYCODE USBFS_DEVICE0_CONFIGURATION0_DESCR[84u] = {
/*  Config Descriptor Length               */ 0x09u,
/*  DescriptorType: CONFIG                 */ 0x02u,
/*  wTotalLength                           */ 0x54u, 0x00u,
/*  bNumInterfaces                         */ 0x03u,
/*  bConfigurationValue                    */ 0x01u,
/*  iConfiguration                         */ 0x00u,
/*  bmAttributes                           */ 0x80u,
/*  bMaxPower                              */ 0x32u,
/*********************************************************************
* Interface Descriptor
*********************************************************************/
/*  Interface Descriptor Length            */ 0x09u,
/*  DescriptorType: INTERFACE              */ 0x04u,
/*  bInterfaceNumber                       */ 0x00u,
/*  bAlternateSetting                      */ 0x00u,
/*  bNumEndpoints                          */ 0x01u,
/*  bInterfaceClass                        */ 0x03u,
/*  bInterfaceSubClass                     */ 0x00u,
/*  bInterfaceProtocol                     */ 0x00u,
/*  iInterface                             */ 0x03u,
/*********************************************************************
* HID Class Descriptor
*********************************************************************/
/*  HID Class Descriptor Length            */ 0x09u,
/*  DescriptorType: HID_CLASS              */ 0x21u,
/*  bcdHID                                 */ 0x11u, 0x01u,
/*  bCountryCode                           */ 0x21u,
/*  bNumDescriptors                        */ 0x01u,
/*  bDescriptorType                        */ 0x22u,
/*  wDescriptorLength (LSB)                */ USBFS_HID_RPT_1_SIZE_LSB,
/*  wDescriptorLength (MSB)                */ USBFS_HID_RPT_1_SIZE_MSB,
/*********************************************************************
* Endpoint Descriptor
*********************************************************************/
/*  Endpoint Descriptor Length             */ 0x07u,
/*  DescriptorType: ENDPOINT               */ 0x05u,
/*  bEndpointAddress                       */ 0x81u,
/*  bmAttributes                           */ 0x03u,
/*  wMaxPacketSize                         */ 0x02u, 0x00u,
/*  bInterval                              */ 0x02u,
/*********************************************************************
* Interface Descriptor
*********************************************************************/
/*  Interface Descriptor Length            */ 0x09u,
/*  DescriptorType: INTERFACE              */ 0x04u,
/*  bInterfaceNumber                       */ 0x01u,
/*  bAlternateSetting                      */ 0x00u,
/*  bNumEndpoints                          */ 0x01u,
/*  bInterfaceClass                        */ 0x03u,
/*  bInterfaceSubClass                     */ 0x00u,
/*  bInterfaceProtocol                     */ 0x00u,
/*  iInterface                             */ 0x04u,
/*********************************************************************
* HID Class Descriptor
*********************************************************************/
/*  HID Class Descriptor Length            */ 0x09u,
/*  DescriptorType: HID_CLASS              */ 0x21u,
/*  bcdHID                                 */ 0x11u, 0x01u,
/*  bCountryCode                           */ 0x21u,
/*  bNumDescriptors                        */ 0x01u,
/*  bDescriptorType                        */ 0x22u,
/*  wDescriptorLength (LSB)                */ USBFS_HID_RPT_1_SIZE_LSB,
/*  wDescriptorLength (MSB)                */ USBFS_HID_RPT_1_SIZE_MSB,
/*********************************************************************
* Endpoint Descriptor
*********************************************************************/
/*  Endpoint Descriptor Length             */ 0x07u,
/*  DescriptorType: ENDPOINT               */ 0x05u,
/*  bEndpointAddress                       */ 0x82u,
/*  bmAttributes                           */ 0x03u,
/*  wMaxPacketSize                         */ 0x02u, 0x00u,
/*  bInterval                              */ 0x02u,
/*********************************************************************
* Interface Descriptor
*********************************************************************/
/*  Interface Descriptor Length            */ 0x09u,
/*  DescriptorType: INTERFACE              */ 0x04u,
/*  bInterfaceNumber                       */ 0x02u,
/*  bAlternateSetting                      */ 0x00u,
/*  bNumEndpoints                          */ 0x01u,
/*  bInterfaceClass                        */ 0x03u,
/*  bInterfaceSubClass                     */ 0x00u,
/*  bInterfaceProtocol                     */ 0x00u,
/*  iInterface                             */ 0x00u,
/*********************************************************************
* HID Class Descriptor
*********************************************************************/
/*  HID Class Descriptor Length            */ 0x09u,
/*  DescriptorType: HID_CLASS              */ 0x21u,
/*  bcdHID                                 */ 0x11u, 0x01u,
/*  bCountryCode                           */ 0x21u,
/*  bNumDescriptors                        */ 0x01u,
/*  bDescriptorType                        */ 0x22u,
/*  wDescriptorLength (LSB)                */ USBFS_HID_RPT_2_SIZE_LSB,
/*  wDescriptorLength (MSB)                */ USBFS_HID_RPT_2_SIZE_MSB,
/*********************************************************************
* Endpoint Descriptor
*********************************************************************/
/*  Endpoint Descriptor Length             */ 0x07u,
/*  DescriptorType: ENDPOINT               */ 0x05u,
/*  bEndpointAddress                       */ 0x03u,
/*  bmAttributes                           */ 0x03u,
/*  wMaxPacketSize                         */ 0x02u, 0x00u,
/*  bInterval                              */ 0x0Au
};

/*********************************************************************
* String Descriptor Table
*********************************************************************/
const uint8 CYCODE USBFS_STRING_DESCRIPTORS[77u] = {
/*********************************************************************
* Language ID Descriptor
*********************************************************************/
/* Descriptor Length                       */ 0x04u,
/* DescriptorType: STRING                  */ 0x03u,
/* Language Id                             */ 0x09u, 0x04u,
/*********************************************************************
* String Descriptor: "Kate Gray"
*********************************************************************/
/* Descriptor Length                       */ 0x14u,
/* DescriptorType: STRING                  */ 0x03u,
 (uint8)'K', 0u,(uint8)'a', 0u,(uint8)'t', 0u,(uint8)'e', 0u,(uint8)' ', 0u,
 (uint8)'G', 0u,(uint8)'r', 0u,(uint8)'a', 0u,(uint8)'y', 0u,
/*********************************************************************
* String Descriptor: "Kate-IO"
*********************************************************************/
/* Descriptor Length                       */ 0x10u,
/* DescriptorType: STRING                  */ 0x03u,
 (uint8)'K', 0u,(uint8)'a', 0u,(uint8)'t', 0u,(uint8)'e', 0u,(uint8)'-', 0u,
 (uint8)'I', 0u,(uint8)'O', 0u,
/*********************************************************************
* String Descriptor: "Player 1"
*********************************************************************/
/* Descriptor Length                       */ 0x12u,
/* DescriptorType: STRING                  */ 0x03u,
 (uint8)'P', 0u,(uint8)'l', 0u,(uint8)'a', 0u,(uint8)'y', 0u,(uint8)'e', 0u,
 (uint8)'r', 0u,(uint8)' ', 0u,(uint8)'1', 0u,
/*********************************************************************
* String Descriptor: "Player 2"
*********************************************************************/
/* Descriptor Length                       */ 0x12u,
/* DescriptorType: STRING                  */ 0x03u,
 (uint8)'P', 0u,(uint8)'l', 0u,(uint8)'a', 0u,(uint8)'y', 0u,(uint8)'e', 0u,
 (uint8)'r', 0u,(uint8)' ', 0u,(uint8)'2', 0u,
/*********************************************************************/
/* Marks the end of the list.              */ 0x00u};
/*********************************************************************/

/*********************************************************************
* Serial Number String Descriptor
*********************************************************************/
const uint8 CYCODE USBFS_SN_STRING_DESCRIPTOR[2] = {
/* Descriptor Length                       */ 0x02u,
/* DescriptorType: STRING                  */ 0x03u,

};

/*********************************************************************
* HID Report Descriptor: ITGIO
*********************************************************************/
const uint8 CYCODE USBFS_HIDREPORT_DESCRIPTOR1[26u] = {
/*  Descriptor Size (Not part of descriptor)*/ USBFS_HID_RPT_1_SIZE_LSB,
USBFS_HID_RPT_1_SIZE_MSB,
/* USAGE_PAGE                              */ 0x05u, 0x01u, 
/* USAGE                                   */ 0x09u, 0x05u, 
/* COLLECTION                              */ 0xA1u, 0x01u, 
/* USAGE_PAGE                              */ 0x05u, 0x09u, 
/* USAGE_MINIMUM                           */ 0x19u, 0x01u, 
/* USAGE_MAXIMUM                           */ 0x29u, 0x10u, 
/* LOGICAL_MINIMUM                         */ 0x15u, 0x00u, 
/* LOGICAL_MAXIMUM                         */ 0x25u, 0x01u, 
/* REPORT_COUNT                            */ 0x95u, 0x10u, 
/* REPORT_SIZE                             */ 0x75u, 0x01u, 
/* INPUT                                   */ 0x81u, 0x02u, 
/*********************************************************************/
/* End of the HID Report Descriptor        */ 0x00u, 0x00u};
/*********************************************************************/
/*********************************************************************
* HID Report Descriptor: LIGHTS
*********************************************************************/
const uint8 CYCODE USBFS_HIDREPORT_DESCRIPTOR2[17u] = {
/*  Descriptor Size (Not part of descriptor)*/ USBFS_HID_RPT_2_SIZE_LSB,
USBFS_HID_RPT_2_SIZE_MSB,
/* USAGE_PAGE                              */ 0x05u, 0x08u, 
/* USAGE                                   */ 0x09u, 0x4Bu, 
/* COLLECTION                              */ 0xA1u, 0x00u, 
/* REPORT_COUNT                            */ 0x95u, 0x10u, 
/* REPORT_SIZE                             */ 0x75u, 0x01u, 
/* OUTPUT                                  */ 0x91u, 0x20u, 
/* END_COLLECTION                          */ 0xC0u, 
/*********************************************************************/
/* End of the HID Report Descriptor        */ 0x00u, 0x00u};
/*********************************************************************/

#if !defined(USER_DEFINE_USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_HID_RPT_STORAGE)
/*********************************************************************
* HID Input Report Storage
*********************************************************************/
T_USBFS_XFER_STATUS_BLOCK USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_IN_RPT_SCB;
uint8 USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_IN_BUF[
            USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_IN_BUF_SIZE];

/*********************************************************************
* HID Input Report TD Table
*********************************************************************/
const T_USBFS_TD CYCODE USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_IN_RPT_TABLE[1u] = {
    {USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_IN_BUF_SIZE,
    &USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_IN_BUF[0u],
    &USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_IN_RPT_SCB},
};
/*********************************************************************
* HID Report Look Up Table         This table has four entries:
*                                        IN Report Table
*                                        OUT Report Table
*                                        Feature Report Table
*                                        HID Report Descriptor
*                                        HID Class Descriptor
*********************************************************************/
const T_USBFS_LUT CYCODE USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_TABLE[5u] = {
    {0x00u,     &USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_IN_RPT_TABLE},
    {0x00u,    NULL},
    {0x00u,    NULL},
    {0x01u,     (const void *)&USBFS_HIDREPORT_DESCRIPTOR1[0]},
    {0x01u,     (const void *)&USBFS_DEVICE0_CONFIGURATION0_DESCR[18]}
};
#endif /* USER_DEFINE_USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_HID_RPT_STORAGE */
#if !defined(USER_DEFINE_USBFS_DEVICE0_CONFIGURATION0_INTERFACE1_ALTERNATE0_HID_HID_RPT_STORAGE)
/*********************************************************************
* HID Input Report Storage
*********************************************************************/
T_USBFS_XFER_STATUS_BLOCK USBFS_DEVICE0_CONFIGURATION0_INTERFACE1_ALTERNATE0_HID_IN_RPT_SCB;
uint8 USBFS_DEVICE0_CONFIGURATION0_INTERFACE1_ALTERNATE0_HID_IN_BUF[
            USBFS_DEVICE0_CONFIGURATION0_INTERFACE1_ALTERNATE0_HID_IN_BUF_SIZE];

/*********************************************************************
* HID Input Report TD Table
*********************************************************************/
const T_USBFS_TD CYCODE USBFS_DEVICE0_CONFIGURATION0_INTERFACE1_ALTERNATE0_HID_IN_RPT_TABLE[1u] = {
    {USBFS_DEVICE0_CONFIGURATION0_INTERFACE1_ALTERNATE0_HID_IN_BUF_SIZE,
    &USBFS_DEVICE0_CONFIGURATION0_INTERFACE1_ALTERNATE0_HID_IN_BUF[0u],
    &USBFS_DEVICE0_CONFIGURATION0_INTERFACE1_ALTERNATE0_HID_IN_RPT_SCB},
};
/*********************************************************************
* HID Report Look Up Table         This table has four entries:
*                                        IN Report Table
*                                        OUT Report Table
*                                        Feature Report Table
*                                        HID Report Descriptor
*                                        HID Class Descriptor
*********************************************************************/
const T_USBFS_LUT CYCODE USBFS_DEVICE0_CONFIGURATION0_INTERFACE1_ALTERNATE0_HID_TABLE[5u] = {
    {0x00u,     &USBFS_DEVICE0_CONFIGURATION0_INTERFACE1_ALTERNATE0_HID_IN_RPT_TABLE},
    {0x00u,    NULL},
    {0x00u,    NULL},
    {0x01u,     (const void *)&USBFS_HIDREPORT_DESCRIPTOR1[0]},
    {0x01u,     (const void *)&USBFS_DEVICE0_CONFIGURATION0_DESCR[43]}
};
#endif /* USER_DEFINE_USBFS_DEVICE0_CONFIGURATION0_INTERFACE1_ALTERNATE0_HID_HID_RPT_STORAGE */
#if !defined(USER_DEFINE_USBFS_DEVICE0_CONFIGURATION0_INTERFACE2_ALTERNATE0_HID_HID_RPT_STORAGE)
/*********************************************************************
* HID Output Report Storage
*********************************************************************/
T_USBFS_XFER_STATUS_BLOCK USBFS_DEVICE0_CONFIGURATION0_INTERFACE2_ALTERNATE0_HID_OUT_RPT_SCB;
uint8 USBFS_DEVICE0_CONFIGURATION0_INTERFACE2_ALTERNATE0_HID_OUT_BUF[
            USBFS_DEVICE0_CONFIGURATION0_INTERFACE2_ALTERNATE0_HID_OUT_BUF_SIZE];

/*********************************************************************
* HID Output Report TD Table
*********************************************************************/
const T_USBFS_TD CYCODE USBFS_DEVICE0_CONFIGURATION0_INTERFACE2_ALTERNATE0_HID_OUT_RPT_TABLE[1u] = {
    {USBFS_DEVICE0_CONFIGURATION0_INTERFACE2_ALTERNATE0_HID_OUT_BUF_SIZE,
    &USBFS_DEVICE0_CONFIGURATION0_INTERFACE2_ALTERNATE0_HID_OUT_BUF[0u],
    &USBFS_DEVICE0_CONFIGURATION0_INTERFACE2_ALTERNATE0_HID_OUT_RPT_SCB},
};
/*********************************************************************
* HID Report Look Up Table         This table has four entries:
*                                        IN Report Table
*                                        OUT Report Table
*                                        Feature Report Table
*                                        HID Report Descriptor
*                                        HID Class Descriptor
*********************************************************************/
const T_USBFS_LUT CYCODE USBFS_DEVICE0_CONFIGURATION0_INTERFACE2_ALTERNATE0_HID_TABLE[5u] = {
    {0x00u,    NULL},
    {0x00u,     &USBFS_DEVICE0_CONFIGURATION0_INTERFACE2_ALTERNATE0_HID_OUT_RPT_TABLE},
    {0x00u,    NULL},
    {0x01u,     (const void *)&USBFS_HIDREPORT_DESCRIPTOR2[0]},
    {0x01u,     (const void *)&USBFS_DEVICE0_CONFIGURATION0_DESCR[68]}
};
#endif /* USER_DEFINE_USBFS_DEVICE0_CONFIGURATION0_INTERFACE2_ALTERNATE0_HID_HID_RPT_STORAGE */

/*********************************************************************
* Interface Dispatch Table -- Points to the Class Dispatch Tables
*********************************************************************/
const T_USBFS_LUT CYCODE USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_TABLE[1u] = {
    {USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_COUNT, 
    &USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_TABLE}
};
/*********************************************************************
* Interface Dispatch Table -- Points to the Class Dispatch Tables
*********************************************************************/
const T_USBFS_LUT CYCODE USBFS_DEVICE0_CONFIGURATION0_INTERFACE1_TABLE[1u] = {
    {USBFS_DEVICE0_CONFIGURATION0_INTERFACE1_ALTERNATE0_HID_COUNT, 
    &USBFS_DEVICE0_CONFIGURATION0_INTERFACE1_ALTERNATE0_HID_TABLE}
};
/*********************************************************************
* Interface Dispatch Table -- Points to the Class Dispatch Tables
*********************************************************************/
const T_USBFS_LUT CYCODE USBFS_DEVICE0_CONFIGURATION0_INTERFACE2_TABLE[1u] = {
    {USBFS_DEVICE0_CONFIGURATION0_INTERFACE2_ALTERNATE0_HID_COUNT, 
    &USBFS_DEVICE0_CONFIGURATION0_INTERFACE2_ALTERNATE0_HID_TABLE}
};
/*********************************************************************
* Endpoint Setting Table -- This table contain the endpoint setting
*                           for each endpoint in the configuration. It
*                           contains the necessary information to
*                           configure the endpoint hardware for each
*                           interface and alternate setting.
*********************************************************************/
const T_USBFS_EP_SETTINGS_BLOCK CYCODE USBFS_DEVICE0_CONFIGURATION0_EP_SETTINGS_TABLE[3u] = {
/* IFC  ALT    EPAddr bmAttr MaxPktSize Class ********************/
{0x00u, 0x00u, 0x81u, 0x03u, 0x0002u,   0x03u},
{0x01u, 0x00u, 0x82u, 0x03u, 0x0002u,   0x03u},
{0x02u, 0x00u, 0x03u, 0x03u, 0x0002u,   0x03u}
};
const uint8 CYCODE USBFS_DEVICE0_CONFIGURATION0_INTERFACE_CLASS[3u] = {
0x03u, 0x03u, 0x03u
};
/*********************************************************************
* Config Dispatch Table -- Points to the Config Descriptor and each of
*                          and endpoint setup table and to each
*                          interface table if it specifies a USB Class
*********************************************************************/
const T_USBFS_LUT CYCODE USBFS_DEVICE0_CONFIGURATION0_TABLE[6u] = {
    {0x01u,     &USBFS_DEVICE0_CONFIGURATION0_DESCR},
    {0x03u,     &USBFS_DEVICE0_CONFIGURATION0_EP_SETTINGS_TABLE},
    {0x01u,     &USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_TABLE},
    {0x01u,     &USBFS_DEVICE0_CONFIGURATION0_INTERFACE1_TABLE},
    {0x01u,     &USBFS_DEVICE0_CONFIGURATION0_INTERFACE2_TABLE},
    {0x00u,     &USBFS_DEVICE0_CONFIGURATION0_INTERFACE_CLASS}
};
/*********************************************************************
* Device Dispatch Table -- Points to the Device Descriptor and each of
*                          and Configuration Tables for this Device 
*********************************************************************/
const T_USBFS_LUT CYCODE USBFS_DEVICE0_TABLE[3u] = {
    {0x01u,     &USBFS_DEVICE0_DESCR},
    {0x00u,    NULL},
    {0x01u,     &USBFS_DEVICE0_CONFIGURATION0_TABLE}
};
/*********************************************************************
* Device Table -- Indexed by the device number.
*********************************************************************/
const T_USBFS_LUT CYCODE USBFS_TABLE[1u] = {
    {0x01u,     &USBFS_DEVICE0_TABLE}
};

#endif /* USER_SUPPLIED_DESCRIPTORS */

#if defined(USBFS_ENABLE_MSOS_STRING)

    /******************************************************************************
    *  USB Microsoft OS String Descriptor
    *  "MSFT" identifies a Microsoft host
    *  "100" specifies version 1.00
    *  USBFS_GET_EXTENDED_CONFIG_DESCRIPTOR becomes the bRequest value
    *  in a host vendor device/class request
    ******************************************************************************/

    const uint8 CYCODE USBFS_MSOS_DESCRIPTOR[USBFS_MSOS_DESCRIPTOR_LENGTH] = {
    /* Descriptor Length                       */   0x12u,
    /* DescriptorType: STRING                  */   0x03u,
    /* qwSignature - "MSFT100"                 */   (uint8)'M', 0u, (uint8)'S', 0u, (uint8)'F', 0u, (uint8)'T', 0u,
                                                    (uint8)'1', 0u, (uint8)'0', 0u, (uint8)'0', 0u,
    /* bMS_VendorCode:                         */   USBFS_GET_EXTENDED_CONFIG_DESCRIPTOR,
    /* bPad                                    */   0x00u
    };

    /* Extended Configuration Descriptor */

    const uint8 CYCODE USBFS_MSOS_CONFIGURATION_DESCR[USBFS_MSOS_CONF_DESCR_LENGTH] = {
    /*  Length of the descriptor 4 bytes       */   0x28u, 0x00u, 0x00u, 0x00u,
    /*  Version of the descriptor 2 bytes      */   0x00u, 0x01u,
    /*  wIndex - Fixed:INDEX_CONFIG_DESCRIPTOR */   0x04u, 0x00u,
    /*  bCount - Count of device functions.    */   0x01u,
    /*  Reserved : 7 bytes                     */   0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    /*  bFirstInterfaceNumber                  */   0x00u,
    /*  Reserved                               */   0x01u,
    /*  compatibleID    - "CYUSB\0\0"          */   (uint8)'C', (uint8)'Y', (uint8)'U', (uint8)'S', (uint8)'B',
                                                    0x00u, 0x00u, 0x00u,
    /*  subcompatibleID - "00001\0\0"          */   (uint8)'0', (uint8)'0', (uint8)'0', (uint8)'0', (uint8)'1',
                                                    0x00u, 0x00u, 0x00u,
    /*  Reserved : 6 bytes                     */   0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u
    };

#endif /* USBFS_ENABLE_MSOS_STRING */

/* DIE ID string descriptor for 8 bytes ID */
#if defined(USBFS_ENABLE_IDSN_STRING)
    uint8 USBFS_idSerialNumberStringDescriptor[USBFS_IDSN_DESCR_LENGTH];
#endif /* USBFS_ENABLE_IDSN_STRING */


/* [] END OF FILE */

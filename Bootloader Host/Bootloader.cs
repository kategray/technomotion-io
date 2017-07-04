using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CyUSB;

namespace Bootloader_Host
{
    public enum BootloaderStatus
    {
        NoDevice,
        Production,
        Bootloader,
        WrongProduct,
        Success
    }

    class Bootloader
    {
        const string PRODUCTION_MANUFACTURER = "Kate Gray";
        const string PRODUCTION_PRODUCT = "GHETT-iO";

        private CyHidDevice ghettIO;

        public BootloaderStatus ScanForDevices()
        {
            // List all the Cypress USB devices
            USBDeviceList usbDevices = new USBDeviceList(CyConst.DEVICES_HID);
            if (usbDevices[PRODUCTION_MANUFACTURER, PRODUCTION_PRODUCT] is CyHidDevice ghettIO)
            {
                this.ghettIO = ghettIO;
                return BootloaderStatus.Production;
            }

            return BootloaderStatus.NoDevice;
        }

        public String GetDeviceVersion()
        {
            if (this.ghettIO.Version == 0x3000)
            {
                return null;
            }
            ushort version = this.ghettIO.Version;
            byte upper = (byte)(version >> 8);
            byte lower = (byte)(version & 0xff);

            return String.Format("v{0:X}.{1:X}", upper, lower);
        }

        public BootloaderStatus SwitchToBootloader()
        {
            bool bResult = false;
            byte[] Data = new byte[ghettIO.Features.RptByteLen];

            if (ghettIO.Manufacturer != PRODUCTION_MANUFACTURER || ghettIO.Product != PRODUCTION_PRODUCT)
            {
                return BootloaderStatus.WrongProduct;
            }

            CyHidReport Features = ghettIO.Features;
            Features.Clear();

            // Data format: [Report ID] [Byte 1] [Byte 2] [Byte 3] [Byte 4]
            Features.DataBuf = new byte[] { Features.ID, 0xDE, 0xAD, 0xBE, 0xEF };            
            bResult = ghettIO.SetFeature(ghettIO.Features.ID);
            
            if (bResult)
            {
                return BootloaderStatus.NoDevice;
            }

            return BootloaderStatus.NoDevice;
            //CyHidValue BootloaderFeature = ghettIO.GetFeature()
        }
    }
}

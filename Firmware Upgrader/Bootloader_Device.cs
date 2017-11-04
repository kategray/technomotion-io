using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using CyUSB;

namespace USBBootloaderHost
{
    class Bootloader_Device
    {
        const int PRODUCTION_VID = 0x16D0;
        const int PRODUCTION_PID = 0x0D02;
        const int BOOTLOADER_VID = 0x1209;
        const int BOOTLOADER_PID = 0x4748;

        private CyHidDevice ghettio;

        public Bootloader_Device (CyHidDevice device)
        {
            // Store the device for later calls
            this.ghettio = device;
        }

        public override String ToString ()
        {
            return String.Format("Ghett-IO v{0}, {1} mode, SN:{2}", Version, Mode, SerialNumber);
        }

        public CyHidDevice Device
        {
            get
            {
                return ghettio;
            }
        }

        public String Mode
        {
            get
            {
                if ((Device.VendorID == PRODUCTION_VID) && (Device.ProductID == PRODUCTION_PID))
                {
                    return "Production";
                } else if ((Device.VendorID == BOOTLOADER_VID) && (Device.ProductID == BOOTLOADER_PID))
                {
                    return "Bootloader";
                } else
                {
                    return "Invalid";
                }
            }
        }

        public String SerialNumber
        {
            get
            {
                return Device.SerialNumber;
            }
        }

        public String Version
        {
            get
            {
                // Format the version to a string, with a period instead of a dash
                byte[] versionBits = { (byte)(ghettio.Version >> 8), (byte)(ghettio.Version & 0xff) };
                return BitConverter.ToString(versionBits).Replace("-", ".");
            }
        }

        public bool EnterBootloader ()
        {
            bool bResult = false;
            byte[] Data = new byte[Device.Features.RptByteLen];

            CyHidReport Features = Device.Features;
            Features.Clear();

            // Data format: [Report ID] [Byte 1] [Byte 2] [Byte 3] [Byte 4]
            Features.DataBuf = new byte[] { Features.ID, 0xDE, 0xAD, 0xBE, 0xEF };
            bResult = Device.SetFeature(Device.Features.ID);

            return bResult;
        }

        public static List<Bootloader_Device> getDevices ()
        {
            List<Bootloader_Device> devices = new List<Bootloader_Device>();
            USBDeviceList HidDevices = new USBDeviceList(CyConst.DEVICES_HID);

            foreach (CyHidDevice device in HidDevices)
            {
                if (device.VendorID == PRODUCTION_VID && device.ProductID == PRODUCTION_PID)
                {
                    devices.Add(new Bootloader_Device(device));
                } else if (device.VendorID == BOOTLOADER_VID && device.ProductID == BOOTLOADER_PID)
                {
                    devices.Add(new Bootloader_Device(device));
                }
            }

            return devices;
        }
    }
}

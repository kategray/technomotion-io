using CyUSB;
using System;
using System.Collections.Generic;

namespace Bootloader_Host
{
    internal class Bootloader_Device
    {
        public enum DEVICE_TYPE { BOOTLOADER, GHETT_IO, BARR_IO, GHETT_IO_LIGHTS, UNKNOWN }

        private const int GHETTIO_VID = 0x16D0;
        private const int GHETTIO_PID = 0x0D02;
        private const int BARRIO_VID = 0x1209;
        private const int BARRIO_PID = 0x4749;
        private const int BOOTLOADER_VID = 0x1209;
        private const int BOOTLOADER_PID = 0x4748;

        private CyHidDevice device;
        public DEVICE_TYPE type;

        public Bootloader_Device(CyHidDevice device)
        {
            this.device = device;
            this.type = getDeviceType(device.ProductID, device.VendorID);
        }

        public static DEVICE_TYPE getDeviceType (CyHidDevice device)
        {
            return getDeviceType(device.ProductID, device.VendorID);
        }

        public static DEVICE_TYPE getDeviceType (ushort pid, ushort vid)
        {
            if (pid == GHETTIO_PID && vid == GHETTIO_VID)
            {
                return DEVICE_TYPE.GHETT_IO;
            }
            else if (pid == BARRIO_PID && vid == BARRIO_VID)
            {
                return DEVICE_TYPE.BARR_IO;
            }
            else if (pid == BOOTLOADER_PID && vid == BOOTLOADER_VID)
            {
                return DEVICE_TYPE.BOOTLOADER;
            }
            else
            {
                return DEVICE_TYPE.UNKNOWN;
            }
        }

        public override string ToString()
        {
            switch (this.type)
            {
                case DEVICE_TYPE.GHETT_IO:
                    return string.Format("Ghett-IO v{0}, SN:{1}", (object)this.Version, (object)this.SerialNumber);
                case DEVICE_TYPE.BARR_IO:
                    return string.Format("Barr-IO v{0}, SN:{1}", (object)this.Version, (object)this.SerialNumber);
                case DEVICE_TYPE.GHETT_IO_LIGHTS:
                    return string.Format("Ghett-IO w/ Lights v{0}, SN:{1}", (object)this.Version, (object)this.SerialNumber);
                case DEVICE_TYPE.BOOTLOADER:
                    return string.Format("Bootloader, SN:{1}", (object)this.Version, (object)this.SerialNumber);
                default:
                    return "Unknown Device";
            }
        }

        public CyHidDevice Device
        {
            get
            {
                return this.device;
            }
        }

        public string Mode
        {
            get
            {
                if ((int)this.Device.VendorID == 5840 && (int)this.Device.ProductID == 3330)
                    return "Production";
                return (int)this.Device.VendorID == 4617 && (int)this.Device.ProductID == 18248 ? "Bootloader" : "Invalid";
            }
        }

        public string SerialNumber
        {
            get
            {
                return this.Device.SerialNumber;
            }
        }

        public string Version
        {
            get
            {
                return BitConverter.ToString(new byte[2]
                {
          (byte) ((uint) this.device.Version >> 8),
          (byte) ((uint) this.device.Version & (uint) byte.MaxValue)
                }).Replace("-", ".");
            }
        }

        public bool EnterBootloader()
        {
            byte[] numArray = new byte[this.Device.Features.RptByteLen];
            CyHidReport features = this.Device.Features;
            features.Clear();
            features.DataBuf = new byte[5]
            {
        features.ID,
        (byte) 222,
        (byte) 173,
        (byte) 190,
        (byte) 239
            };
            return this.Device.SetFeature((int)this.Device.Features.ID);
        }

        public static List<Bootloader_Device> getDevices()
        {
            List<Bootloader_Device> bootloaderDeviceList = new List<Bootloader_Device>();
            foreach (CyHidDevice device in new USBDeviceList(CyConst.DEVICES_HID))
            {
                if (getDeviceType(device) != DEVICE_TYPE.UNKNOWN) {
                    bootloaderDeviceList.Add(new Bootloader_Device(device));
                }
            }
            return bootloaderDeviceList;
        }
    }
}

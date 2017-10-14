using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using USBBootloaderHost;
using CyUSB;


//namespace delegated_functions
namespace USBBootloaderHost
{
    public partial class Form1 : Form
    {
        /// <summary>
        /// Success 
        /// </summary>        
        internal const int ERR_SUCCESS = 0;
        /// <summary>
        /// Error opening communication channel
        /// </summary>
        internal const int ERR_OPEN = 1;
        /// <summary>
        /// Error closing communication channel
        /// </summary>
        internal const int ERR_CLOSE = 2;
        /// <summary>
        /// Error reading data
        /// </summary>
        internal const int ERR_READ = 3;
        /// <summary>
        /// Error writing data
        /// </summary>
        internal const int ERR_WRITE = 4;


        /// <summary>
        /// Checks if the USB device is connected and opens if it is present
        /// Returns a success or failure
        /// </summary>
        public int OpenConnection()
        {
            int status = 0;
            status = GetHidDevice() ? ERR_SUCCESS : ERR_OPEN;
            return status;
        }

        /// <summary>
        /// Closes the previously opened USB device and returns the status
        /// </summary>

        public int CloseConnection()
        {
            int status = 0;
            BootloaderHIDDevice = null;
            return status;

        }

        /// <summary>
        /// Method that performs Read operation from USB Device
        /// </summary>
        /// <param name="buffer"> Pointer to an array where data read from USB device is copied to </param>
        /// <param name="size"> Size of the Buffer </param>
        /// <returns></returns>
        public int ReadData(IntPtr buffer, int size)
        {
            int status;
            bool local_status = false;
            byte[] data = new byte[size];

            //Check if USB device exists
            if (GetHidDevice())
            {
                //local_status = BootloaderHIDDevice.GetInput(BootloaderHIDDevice.Inputs.ID);
                local_status = BootloaderHIDDevice.ReadInput();
                data = BootloaderHIDDevice.Inputs.DataBuf;
                Marshal.Copy(data, 1, buffer, Math.Min(size, data.Length));
                status = local_status ? ERR_SUCCESS : ERR_READ;
            }

            else
                status = ERR_READ;

            return status;
        }


        /// <summary>
        /// Method that writes to the USB device
        /// </summary>
        /// <param name="buffer">Pointer to an array where data written to USB device is stored </param>
        /// <param name="size"> Size of the Buffer </param>
        /// <returns></returns>
        public int WriteData(IntPtr buffer, int size)
        {

            byte[] data = new byte[64];
            bool status = true;


            Marshal.Copy(buffer, data, 0, size);

            if (GetHidDevice())
            {
                //First Byte in buffer holds the Report ID
                BootloaderHIDDevice.Outputs.DataBuf[0] = BootloaderHIDDevice.Outputs.ID;

                //Load 64 bytes of data
                for (int i = 1; i <= size; i++)
                {
                    BootloaderHIDDevice.Outputs.DataBuf[i] = data[i - 1];
                }

                status = BootloaderHIDDevice.WriteOutput();

                if (status)
                    return ERR_SUCCESS;

                else
                    return ERR_WRITE;
            }

            else
                return ERR_WRITE;

        }


        /// <summary>
        /// Method that updates the progres bar
        /// </summary>
        /// <param name="arrayID"></param>
        /// <param name="rowNum"></param>
        public void ProgressUpdate(byte arrayID, ushort rowNum)
        {
            int i = 0;

            progressBarProgress += progressBarStepSize;
            i++;
            progressBar1.Value = (int)progressBarProgress;
            this.Refresh();

            if (progressBarProgress >= 100)
            {
                progressBarProgress = 0;
                progressBar1.Value = 0;
                this.Refresh();
            }

            return;
        }

        /// <summary>
        /// Method that returns the maximum transfer size
        /// </summary>

        public uint MaxTransferSize
        {
            get { return (uint)BootloaderHIDDevice.Features.RptByteLen; }
        }


    }

}
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;   // Marshal copy
using System.IO;                        // For File handling
using CyUSB;				            // For Cypress USB HID device

namespace USBBootloaderHost
{
    public partial class frmMain : Form
    {
        /// <summary>
        /// Error values
        /// </summary>
        internal const int ERR_SUCCESS = 0;
        internal const int ERR_OPEN = 1;
        internal const int ERR_CLOSE = 2;
        internal const int ERR_READ = 3;
        internal const int ERR_WRITE = 4;

        public CyHidDevice BootloaderHIDDevice;
        public USBDeviceList usbHIDDevices = null;

        // String holding the Cyacd file path/name
        string Chosen_File_Cyacd = "";
        bool Cyacd_found;

        // For checking bootloading progress
        double progressBarProgress;
        double progressBarStepSize;
        Bootloader_Utils.CyBtldr_CommunicationsData comm_data = new Bootloader_Utils.CyBtldr_CommunicationsData();

        public frmMain()
        {
            InitializeComponent();

            // Give the user a little hint
            textBox5.Text += "To begin, click \"Bootloader\" to place the GHETT-iO in bootloader mode. \r\n";

            // Pre-populate the filename, if we can.
            String targetFile = String.Format("{0}\\{1}", Directory.GetCurrentDirectory(), "GHETT-iO.hex");
            if (File.Exists(targetFile))
            {
                // Update the text box
                textBox6.Text = targetFile;

                // Save the file for programming
                Chosen_File_Cyacd = targetFile;

                // The progressbar is based on firmware length
                int lines = File.ReadAllLines(Chosen_File_Cyacd).Length - 1; //Don't count header
                progressBarStepSize = 100.0 / lines;

                // Flag the file as having been found
                Cyacd_found = true;

                textBox5.Text += "Firmware loaded. \r\n";
            }

            usbHIDDevices = new USBDeviceList(CyConst.DEVICES_HID);

            //Adding event handlers for device attachment and device removal            
            usbHIDDevices.DeviceAttached += new EventHandler(usbHIDDevices_DeviceChecker);
            usbHIDDevices.DeviceRemoved += new EventHandler(usbHIDDevices_DeviceChecker);
            UpdateDeviceList();
            GetHidDevice();

        }

        /// <summary>
        /// The GetHidDevice Method checks for the presence of a specific USB HID device and updates the status
        /// </summary>
        /// <returns>bool</returns>
        public bool GetHidDevice()
        {
            try
            {
                // Attempt to assign local HID object to HID in devices list with matching VID and PID
                Bootloader_Device blDevice = (Bootloader_Device)(lbDevices.SelectedItem);
                BootloaderHIDDevice = blDevice.Device;

                if (blDevice.Mode == "Production")
                {
                    btnBootloader.Enabled = true;
                    btnUpdate.Enabled = false;
                } else
                {
                    btnBootloader.Enabled = false;
                    btnUpdate.Enabled = true;
                }

                return (true);
            }

            catch
            {
                return (false);
            }
        }

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
        /// Method that returns the maximum transfer size
        /// </summary>
        public uint MaxTransferSize
        {
            get { return (uint)BootloaderHIDDevice.Features.RptByteLen; }
        }

        /// <summary>
        ///  This is the event handler for Device Connection event.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>           
        void usbHIDDevices_DeviceChecker(object sender, EventArgs e)
        {
            UpdateDeviceList();
            GetHidDevice();
        }

        private void UpdateDeviceList()
        {
            List<Bootloader_Device> devices = Bootloader_Device.getDevices();

            lbDevices.ValueMember = "SerialNumber";
            lbDevices.DisplayMember = "";
            lbDevices.DataSource = devices;
        }

        /// <summary>
        /// This method handles the "Load File" Button1 Click event and lets you choose the 
        /// appropriate CYACD file
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button1_Click(object sender, EventArgs e)
        {
            int lines;
            openFileDialog1.Title = "Open CYACD File";
            openFileDialog1.FileName = "";
            openFileDialog1.Filter = "cyacd file|*.cyacd";

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                Chosen_File_Cyacd = openFileDialog1.FileName;
                textBox6.Text = Chosen_File_Cyacd;

                lines = File.ReadAllLines(Chosen_File_Cyacd).Length - 1; //Don't count header
                progressBarStepSize = 100.0 / lines;
                Cyacd_found = true;
            }
        }

        /// <summary>
        /// This Method handles the "Program" Button2 Click event
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>

        private void button2_Click(object sender, EventArgs e)
        {
            // The value is allowed 1 or 2. If application is using dual image, 
            // the appID of 2nd image should be 2
            byte appID = 1;

            // The GHETT-iO doesn't use a security key
            byte[] SecurityKey = null;

            //USB dummyRead 
            USBDeviceList HidDevices = new USBDeviceList(CyConst.DEVICES_HID);
            CyHidDevice hidDev = HidDevices[0] as CyHidDevice;
            hidDev.ReadInput();

            // Setup comm_data object with our delegate functions
            comm_data.OpenConnection = OpenConnection;
            comm_data.CloseConnection = CloseConnection;
            comm_data.ReadData = ReadData;
            comm_data.WriteData = WriteData;
            comm_data.MaxTransferSize = 64;

            ReturnCodes local_status = 0;
            progressBarProgress = 0;
            progressBar1.Value = 0;
            // Create update object for use with Bootload_Utils.CyBtldr_Program function.  This object
            // is used to report updated array and row information from the PSoC.
            Bootloader_Utils.CyBtldr_ProgressUpdate update = new Bootloader_Utils.CyBtldr_ProgressUpdate(ProgressUpdate);

            // Checking a HW connection and a file exist
            if (Cyacd_found)
            {
                if (GetHidDevice())
                {
                    DateTime saveNow = DateTime.Now;
                    string time_var = saveNow.ToString();
                    textBox5.Text += " Bootload Started at " + time_var + "\r\n";

                    local_status = (ReturnCodes)Bootloader_Utils.CyBtldr_Program(Chosen_File_Cyacd, SecurityKey, appID, ref comm_data, update);
                    saveNow = DateTime.Now;

                    if (local_status == (int)ReturnCodes.CYRET_SUCCESS)
                    {
                        time_var = saveNow.ToString();
                        textBox5.Text += " Bootload successful  !! \r\n Bootload ended at " + time_var + "\r\n";
                    }
                    else
                    {
                        if (ReturnCodes.CYRET_ERR_COMM_MASK == (local_status & ReturnCodes.CYRET_ERR_COMM_MASK))
                        {
                            MessageBox.Show(" Program failed: Communication Error");
                        }
                        else
                        {
                            MessageBox.Show(" Program failed  " + local_status.ToString());
                        }
                    }
                }
                else
                {
                    textBox5.Text += "No Device Connected \r\n";
                    MessageBox.Show("No Device Connected");
                }
            }
            else
            {
                MessageBox.Show("No file chosen");
            }
        }

        /// <summary>
        /// Method that updates the progres bar
        /// </summary>
        /// <param name="arrayID"></param>
        /// <param name="rowNum"></param>
        public void ProgressUpdate(byte arrayID, ushort rowNum)
        {
            progressBarProgress += progressBarStepSize;
            progressBar1.Value = (int)(progressBarProgress);
            this.Refresh();

            return;
        }

        private void btnBootloader_Click (object sender, EventArgs e)
        {
            Bootloader_Device device = new Bootloader_Device(BootloaderHIDDevice);
            device.EnterBootloader();
            textBox5.Text += "Switched to bootloader mode. \r\n";
        }

        private void lbDevices_SelectedIndexChanged(object sender, EventArgs e)
        {
            GetHidDevice();
        }
    }
}

using CyUSB;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Bootloader_Host
{

    public partial class frmBootloader : Form
    {
        private USBDeviceList usbHIDDevices;
        private Bootloader_Device selectedDevice;

        public frmBootloader()
        {
            InitializeComponent();
            usbHIDDevices = new USBDeviceList(CyConst.DEVICES_HID);
            usbHIDDevices.DeviceAttached += new EventHandler(usbDevices_DeviceAttached);
            usbHIDDevices.DeviceRemoved += new EventHandler(usbDevices_DeviceRemoved);
            this.buildDeviceTree();
            this.GetHidDevice();
        }

        private void frmBootloader_Load (object sender, EventArgs e)
        {
            buildDeviceTree();
        }

        private void layoutMain_Paint(object sender, PaintEventArgs e)
        {

        }

        private void lbDevices_SelectedIndexChanged(object sender, EventArgs e)
        {
            GetHidDevice();
        }

        private void buildDeviceTree ()
        {
            List<Bootloader_Device> devices = Bootloader_Device.getDevices();
            this.lbDevices.ValueMember = "SerialNumber";
            this.lbDevices.DisplayMember = "";
            this.lbDevices.DataSource = (object)devices;
        }

        public bool GetHidDevice()
        {
            try
            {
                selectedDevice = (Bootloader_Device)this.lbDevices.SelectedItem;
                
                if (selectedDevice.type == Bootloader_Device.DEVICE_TYPE.BOOTLOADER)
                {
                    this.btnEnterBootloader.Enabled = false;
                    if (this.firmwarePicker.FileName != "")
                    {
                        this.btnProgram.Enabled = true;
                    } else
                    {
                        this.btnProgram.Enabled = false;
                    }
                }
                else
                {
                    this.btnEnterBootloader.Enabled = true;
                    this.btnProgram.Enabled = false;
                }
                return true;
            }
            catch
            {
                this.btnEnterBootloader.Enabled = false;
                this.btnProgram.Enabled = false;
                return false;
            }
        }

        private void usbDevices_DeviceRemoved(object sender, EventArgs e)
        {
            buildDeviceTree();
            GetHidDevice();
        }

        private void usbDevices_DeviceAttached(object sender, EventArgs e)
        {
            buildDeviceTree();
            GetHidDevice();
        }

        private void btnEnterBootloader_Click(object sender, EventArgs e)
        {
            try {
                selectedDevice.EnterBootloader();
            } catch
            {
                return;
            }
        }

        private void btnSelectFirmware_Click(object sender, EventArgs e)
        {
            this.firmwarePicker.Title = "Open CYACD File";
            this.firmwarePicker.FileName = "";
            this.firmwarePicker.Filter = "cyacd file|*.cyacd";
            if (this.firmwarePicker.ShowDialog() != DialogResult.OK)
                return;
            this.tbFilename.Text = this.firmwarePicker.FileName;

            if (this.firmwarePicker.FileName != "") {
                this.btnProgram.Enabled = true;
            }
        }

        private void btnProgram_Click(object sender, EventArgs e)
        {
            // We don't use a security key
            byte[] securityKey = (byte[])null;

            // Only one application is supported
            byte appId = 1;

            // Only devices in bootloader mode can be programmed
            if (selectedDevice.type != Bootloader_Device.DEVICE_TYPE.BOOTLOADER)
            {
                return;
            }

            // Callback for progress updates
            Bootloader_Utils.CyBtldr_ProgressUpdate update = new Bootloader_Utils.CyBtldr_ProgressUpdate(this.ProgressUpdate);

            // Handle communication callbacks
            Bootloader_Utils.CyBtldr_CommunicationsData commData = new Bootloader_Utils.CyBtldr_CommunicationsData();

            commData.OpenConnection = new Bootloader_Utils.OpenConnection_USB(this.OpenCommConnection);
            commData.CloseConnection = new Bootloader_Utils.CloseConnection_USB(this.CloseCommConnection);
            commData.ReadData = new Bootloader_Utils.ReadData_USB(this.ReadCommData);
            commData.WriteData = new Bootloader_Utils.WriteData_USB(this.WriteCommData);
            commData.MaxTransferSize = 64u;

            StatusCodes statusCode = (StatusCodes)Bootloader_Utils.CyBtldr_Program(this.firmwarePicker.FileName, securityKey, appId, ref commData, update);
            if (statusCode == StatusCodes.CYRET_SUCCESS)
            {
                string message = "Firmware programming successful.";
                MessageBox.Show(message);
            } else
            {
                string message = String.Format("Firmware programming failed. Error: %d", (int)statusCode);
                MessageBox.Show(message);
            }

            buildDeviceTree();
            GetHidDevice();
        }

        public int OpenCommConnection()
        {
            return !GetHidDevice() ? (int)StatusCodes.CYRET_ERR_FILE : (int)StatusCodes.CYRET_SUCCESS;
        }

        public int CloseCommConnection()
        {
            return (int)StatusCodes.CYRET_SUCCESS;
        }

        public int ReadCommData(IntPtr buffer, int size)
        {
            byte[] numArray = new byte[size];
            bool status = false;

            if (null != selectedDevice)
            {
                status = selectedDevice.Device.ReadInput();
                byte[] dataBuf = selectedDevice.Device.Inputs.DataBuf;
                Marshal.Copy(dataBuf, 1, buffer, Math.Min(size, dataBuf.Length));
            }

            return status ? (int)StatusCodes.CYRET_SUCCESS : (int)StatusCodes.CYRET_ERR_DATA;
        }

        public int WriteCommData(IntPtr buffer, int size)
        {
            byte[] destination = new byte[64];
            Marshal.Copy(buffer, destination, 0, size);
            if (null == selectedDevice)
            {
                return (int)StatusCodes.CYRET_ERR_DATA;
            }

            selectedDevice.Device.Outputs.DataBuf[0] = selectedDevice.Device.Outputs.ID;
            for (int index = 1; index <= size; ++index)
                selectedDevice.Device.Outputs.DataBuf[index] = destination[index - 1];
            return selectedDevice.Device.WriteOutput() ? (int)StatusCodes.CYRET_SUCCESS : (int)StatusCodes.CYRET_ERR_DATA;
        }

        public void ProgressUpdate(byte arrayID, ushort rowNum)
        {
            return;
        }
    }
}

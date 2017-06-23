using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Bootloader_Host
{

    public partial class frmBootloader : Form
    {
        public enum State
        {
            Initializing,
            Production
        }

        public frmBootloader()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            changeState(State.Initializing);
            Bootloader bl = new Bootloader();
            if (bl.ScanForDevices() == BootloaderStatus.Production)
            {
                changeState(State.Production);
                bl.SwitchToBootloader();
            }
        }

        private void changeState(State newState)
        {
            if (newState == State.Initializing)
            {
                lblStatus.Text = "Looking for GHETT-iO...";
            } else if (newState == State.Production)
            {
                lblStatus.Text = "Found a production GHETT-iO.  Rebooting it into Bootloader mode.";
            }
        }
    }
}

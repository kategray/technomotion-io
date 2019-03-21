namespace Bootloader_Host
{
    partial class frmBootloader
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.layoutMain = new System.Windows.Forms.TableLayoutPanel();
            this.lbDevices = new System.Windows.Forms.ListBox();
            this.tbFilename = new System.Windows.Forms.TextBox();
            this.flowLayoutPanel1 = new System.Windows.Forms.FlowLayoutPanel();
            this.btnEnterBootloader = new System.Windows.Forms.Button();
            this.btnSelectFirmware = new System.Windows.Forms.Button();
            this.btnProgram = new System.Windows.Forms.Button();
            this.firmwarePicker = new System.Windows.Forms.OpenFileDialog();
            this.layoutMain.SuspendLayout();
            this.flowLayoutPanel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // layoutMain
            // 
            this.layoutMain.AutoSize = true;
            this.layoutMain.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.layoutMain.ColumnCount = 1;
            this.layoutMain.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.layoutMain.Controls.Add(this.lbDevices, 0, 0);
            this.layoutMain.Controls.Add(this.tbFilename, 0, 1);
            this.layoutMain.Controls.Add(this.flowLayoutPanel1, 0, 2);
            this.layoutMain.Dock = System.Windows.Forms.DockStyle.Fill;
            this.layoutMain.Location = new System.Drawing.Point(0, 0);
            this.layoutMain.Name = "layoutMain";
            this.layoutMain.RowCount = 3;
            this.layoutMain.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 200F));
            this.layoutMain.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.layoutMain.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 50F));
            this.layoutMain.Size = new System.Drawing.Size(894, 618);
            this.layoutMain.TabIndex = 1;
            this.layoutMain.Paint += new System.Windows.Forms.PaintEventHandler(this.layoutMain_Paint);
            // 
            // lbDevices
            // 
            this.lbDevices.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lbDevices.FormattingEnabled = true;
            this.lbDevices.ItemHeight = 25;
            this.lbDevices.Location = new System.Drawing.Point(3, 3);
            this.lbDevices.Name = "lbDevices";
            this.lbDevices.Size = new System.Drawing.Size(888, 194);
            this.lbDevices.TabIndex = 0;
            this.lbDevices.SelectedIndexChanged += new System.EventHandler(this.lbDevices_SelectedIndexChanged);
            // 
            // tbFilename
            // 
            this.tbFilename.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tbFilename.Location = new System.Drawing.Point(3, 203);
            this.tbFilename.Name = "tbFilename";
            this.tbFilename.ReadOnly = true;
            this.tbFilename.Size = new System.Drawing.Size(888, 31);
            this.tbFilename.TabIndex = 3;
            // 
            // flowLayoutPanel1
            // 
            this.flowLayoutPanel1.Controls.Add(this.btnEnterBootloader);
            this.flowLayoutPanel1.Controls.Add(this.btnSelectFirmware);
            this.flowLayoutPanel1.Controls.Add(this.btnProgram);
            this.flowLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.flowLayoutPanel1.Location = new System.Drawing.Point(3, 240);
            this.flowLayoutPanel1.Name = "flowLayoutPanel1";
            this.flowLayoutPanel1.Size = new System.Drawing.Size(888, 375);
            this.flowLayoutPanel1.TabIndex = 4;
            // 
            // btnEnterBootloader
            // 
            this.btnEnterBootloader.AutoSize = true;
            this.btnEnterBootloader.Location = new System.Drawing.Point(3, 3);
            this.btnEnterBootloader.Name = "btnEnterBootloader";
            this.btnEnterBootloader.Size = new System.Drawing.Size(183, 35);
            this.btnEnterBootloader.TabIndex = 1;
            this.btnEnterBootloader.Text = "Enter Bootloader";
            this.btnEnterBootloader.UseVisualStyleBackColor = true;
            this.btnEnterBootloader.Click += new System.EventHandler(this.btnEnterBootloader_Click);
            // 
            // btnSelectFirmware
            // 
            this.btnSelectFirmware.AutoSize = true;
            this.btnSelectFirmware.Location = new System.Drawing.Point(192, 3);
            this.btnSelectFirmware.Name = "btnSelectFirmware";
            this.btnSelectFirmware.Size = new System.Drawing.Size(176, 35);
            this.btnSelectFirmware.TabIndex = 0;
            this.btnSelectFirmware.Text = "Select Firmware";
            this.btnSelectFirmware.UseVisualStyleBackColor = true;
            this.btnSelectFirmware.Click += new System.EventHandler(this.btnSelectFirmware_Click);
            // 
            // btnProgram
            // 
            this.btnProgram.AutoSize = true;
            this.btnProgram.Location = new System.Drawing.Point(374, 3);
            this.btnProgram.Name = "btnProgram";
            this.btnProgram.Size = new System.Drawing.Size(197, 35);
            this.btnProgram.TabIndex = 2;
            this.btnProgram.Text = "Program Firmware";
            this.btnProgram.UseVisualStyleBackColor = true;
            this.btnProgram.Click += new System.EventHandler(this.btnProgram_Click);
            // 
            // frmBootloader
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(894, 618);
            this.Controls.Add(this.layoutMain);
            this.Margin = new System.Windows.Forms.Padding(2);
            this.Name = "frmBootloader";
            this.Text = "Firmware Updater";
            this.Load += new System.EventHandler(this.frmBootloader_Load);
            this.layoutMain.ResumeLayout(false);
            this.layoutMain.PerformLayout();
            this.flowLayoutPanel1.ResumeLayout(false);
            this.flowLayoutPanel1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.TableLayoutPanel layoutMain;
        private System.Windows.Forms.ListBox lbDevices;
        private System.Windows.Forms.TextBox tbFilename;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel1;
        private System.Windows.Forms.Button btnSelectFirmware;
        private System.Windows.Forms.Button btnEnterBootloader;
        private System.Windows.Forms.Button btnProgram;
        private System.Windows.Forms.OpenFileDialog firmwarePicker;
    }
}


namespace USBBootloaderHost
{
    partial class frmMain
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmMain));
            this.label5 = new System.Windows.Forms.Label();
            this.textBox5 = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.btnUpdate = new System.Windows.Forms.Button();
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.textBox6 = new System.Windows.Forms.TextBox();
            this.btnBootloader = new System.Windows.Forms.Button();
            this.lbDevices = new System.Windows.Forms.ListBox();
            this.SuspendLayout();
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(79, 413);
            this.label5.Margin = new System.Windows.Forms.Padding(10, 0, 10, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(171, 37);
            this.label5.TabIndex = 4;
            this.label5.Text = "Status Log";
            // 
            // textBox5
            // 
            this.textBox5.Location = new System.Drawing.Point(89, 458);
            this.textBox5.Margin = new System.Windows.Forms.Padding(10, 9, 10, 9);
            this.textBox5.Multiline = true;
            this.textBox5.Name = "textBox5";
            this.textBox5.Size = new System.Drawing.Size(1264, 425);
            this.textBox5.TabIndex = 9;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(602, 322);
            this.button1.Margin = new System.Windows.Forms.Padding(10, 9, 10, 9);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(238, 65);
            this.button1.TabIndex = 10;
            this.button1.Text = "Load File";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // btnUpdate
            // 
            this.btnUpdate.Location = new System.Drawing.Point(1115, 322);
            this.btnUpdate.Margin = new System.Windows.Forms.Padding(10, 9, 10, 9);
            this.btnUpdate.Name = "btnUpdate";
            this.btnUpdate.Size = new System.Drawing.Size(238, 65);
            this.btnUpdate.TabIndex = 11;
            this.btnUpdate.Text = "Update FW";
            this.btnUpdate.UseVisualStyleBackColor = true;
            this.btnUpdate.Click += new System.EventHandler(this.button2_Click);
            // 
            // progressBar1
            // 
            this.progressBar1.Location = new System.Drawing.Point(89, 939);
            this.progressBar1.Margin = new System.Windows.Forms.Padding(10, 9, 10, 9);
            this.progressBar1.Name = "progressBar1";
            this.progressBar1.Size = new System.Drawing.Size(1273, 65);
            this.progressBar1.TabIndex = 12;
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // textBox6
            // 
            this.textBox6.Location = new System.Drawing.Point(86, 238);
            this.textBox6.Margin = new System.Windows.Forms.Padding(10, 9, 10, 9);
            this.textBox6.Name = "textBox6";
            this.textBox6.ReadOnly = true;
            this.textBox6.Size = new System.Drawing.Size(1264, 44);
            this.textBox6.TabIndex = 13;
            // 
            // btnBootloader
            // 
            this.btnBootloader.Location = new System.Drawing.Point(857, 322);
            this.btnBootloader.Margin = new System.Windows.Forms.Padding(10, 9, 10, 9);
            this.btnBootloader.Name = "btnBootloader";
            this.btnBootloader.Size = new System.Drawing.Size(238, 65);
            this.btnBootloader.TabIndex = 14;
            this.btnBootloader.Text = "Bootloader";
            this.btnBootloader.UseVisualStyleBackColor = true;
            this.btnBootloader.Click += new System.EventHandler(this.btnBootloader_Click);
            // 
            // lbDevices
            // 
            this.lbDevices.FormattingEnabled = true;
            this.lbDevices.ItemHeight = 37;
            this.lbDevices.Location = new System.Drawing.Point(86, 12);
            this.lbDevices.Name = "lbDevices";
            this.lbDevices.Size = new System.Drawing.Size(1248, 189);
            this.lbDevices.TabIndex = 16;
            this.lbDevices.SelectedIndexChanged += new System.EventHandler(this.lbDevices_SelectedIndexChanged);
            // 
            // frmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(19F, 37F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1449, 1097);
            this.Controls.Add(this.lbDevices);
            this.Controls.Add(this.btnBootloader);
            this.Controls.Add(this.textBox6);
            this.Controls.Add(this.progressBar1);
            this.Controls.Add(this.btnUpdate);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.textBox5);
            this.Controls.Add(this.label5);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(10, 9, 10, 9);
            this.MaximumSize = new System.Drawing.Size(1485, 1200);
            this.MinimumSize = new System.Drawing.Size(1485, 1200);
            this.Name = "frmMain";
            this.Text = "GHETT-iO Firmware Update";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox textBox5;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button btnUpdate;
        private System.Windows.Forms.ProgressBar progressBar1;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.TextBox textBox6;
        private System.Windows.Forms.Button btnBootloader;
        private System.Windows.Forms.ListBox lbDevices;
    }
}


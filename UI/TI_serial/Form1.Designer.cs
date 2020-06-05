namespace TI_serial
{
    partial class Serial_TI
    {
        /// <summary>
        /// Variável de designer necessária.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpar os recursos que estão sendo usados.
        /// </summary>
        /// <param name="disposing">true se for necessário descartar os recursos gerenciados; caso contrário, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código gerado pelo Windows Form Designer

        /// <summary>
        /// Método necessário para suporte ao Designer - não modifique 
        /// o conteúdo deste método com o editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Serial_TI));
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.progressBar2 = new System.Windows.Forms.ProgressBar();
            this.D3 = new System.Windows.Forms.Button();
            this.D2 = new System.Windows.Forms.Button();
            this.D1 = new System.Windows.Forms.Button();
            this.C1 = new System.Windows.Forms.Button();
            this.C2 = new System.Windows.Forms.Button();
            this.C3 = new System.Windows.Forms.Button();
            this.B1 = new System.Windows.Forms.Button();
            this.B2 = new System.Windows.Forms.Button();
            this.B3 = new System.Windows.Forms.Button();
            this.A2 = new System.Windows.Forms.Button();
            this.A3 = new System.Windows.Forms.Button();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.label4 = new System.Windows.Forms.Label();
            this.comboBox2 = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.Open = new System.Windows.Forms.Button();
            this.Send = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.Close = new System.Windows.Forms.Button();
            this.Read = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.label5 = new System.Windows.Forms.Label();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.Today = new System.Windows.Forms.Button();
            this.Select = new System.Windows.Forms.Button();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.comboBox3 = new System.Windows.Forms.ComboBox();
            this.Type = new System.Windows.Forms.Label();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.tabPage3.SuspendLayout();
            this.SuspendLayout();
            // 
            // tabControl1
            // 
            this.tabControl1.Appearance = System.Windows.Forms.TabAppearance.FlatButtons;
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Controls.Add(this.tabPage3);
            this.tabControl1.Location = new System.Drawing.Point(2, 1);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(728, 354);
            this.tabControl1.TabIndex = 13;
            // 
            // tabPage1
            // 
            this.tabPage1.BackColor = System.Drawing.Color.DarkCyan;
            this.tabPage1.Controls.Add(this.Type);
            this.tabPage1.Controls.Add(this.comboBox3);
            this.tabPage1.Controls.Add(this.textBox3);
            this.tabPage1.Controls.Add(this.label2);
            this.tabPage1.Controls.Add(this.progressBar2);
            this.tabPage1.Controls.Add(this.D3);
            this.tabPage1.Controls.Add(this.D2);
            this.tabPage1.Controls.Add(this.D1);
            this.tabPage1.Controls.Add(this.C1);
            this.tabPage1.Controls.Add(this.C2);
            this.tabPage1.Controls.Add(this.C3);
            this.tabPage1.Controls.Add(this.B1);
            this.tabPage1.Controls.Add(this.B2);
            this.tabPage1.Controls.Add(this.B3);
            this.tabPage1.Controls.Add(this.A2);
            this.tabPage1.Controls.Add(this.A3);
            this.tabPage1.Location = new System.Drawing.Point(4, 25);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(720, 325);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Storage";
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(298, 274);
            this.textBox3.Name = "textBox3";
            this.textBox3.ReadOnly = true;
            this.textBox3.Size = new System.Drawing.Size(100, 20);
            this.textBox3.TabIndex = 18;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(20, 186);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(74, 13);
            this.label2.TabIndex = 17;
            this.label2.Text = "Recive Status";
            // 
            // progressBar2
            // 
            this.progressBar2.Location = new System.Drawing.Point(23, 210);
            this.progressBar2.Name = "progressBar2";
            this.progressBar2.Size = new System.Drawing.Size(97, 28);
            this.progressBar2.TabIndex = 16;
            // 
            // D3
            // 
            this.D3.Enabled = false;
            this.D3.Location = new System.Drawing.Point(586, 52);
            this.D3.Name = "D3";
            this.D3.Size = new System.Drawing.Size(97, 36);
            this.D3.TabIndex = 15;
            this.D3.Text = "D3";
            this.D3.UseVisualStyleBackColor = true;
            this.D3.Click += new System.EventHandler(this.button17_Click);
            // 
            // D2
            // 
            this.D2.Enabled = false;
            this.D2.Location = new System.Drawing.Point(586, 128);
            this.D2.Name = "D2";
            this.D2.Size = new System.Drawing.Size(97, 36);
            this.D2.TabIndex = 14;
            this.D2.Text = "D2";
            this.D2.UseVisualStyleBackColor = true;
            this.D2.Click += new System.EventHandler(this.button16_Click);
            // 
            // D1
            // 
            this.D1.Enabled = false;
            this.D1.Location = new System.Drawing.Point(586, 202);
            this.D1.Name = "D1";
            this.D1.Size = new System.Drawing.Size(97, 36);
            this.D1.TabIndex = 13;
            this.D1.Text = "D1";
            this.D1.UseVisualStyleBackColor = true;
            this.D1.Click += new System.EventHandler(this.button14_Click);
            // 
            // C1
            // 
            this.C1.Enabled = false;
            this.C1.Location = new System.Drawing.Point(393, 202);
            this.C1.Name = "C1";
            this.C1.Size = new System.Drawing.Size(97, 36);
            this.C1.TabIndex = 8;
            this.C1.Text = "C1";
            this.C1.UseVisualStyleBackColor = true;
            this.C1.Click += new System.EventHandler(this.button13_Click);
            // 
            // C2
            // 
            this.C2.Enabled = false;
            this.C2.Location = new System.Drawing.Point(393, 128);
            this.C2.Name = "C2";
            this.C2.Size = new System.Drawing.Size(97, 36);
            this.C2.TabIndex = 7;
            this.C2.Text = "C2";
            this.C2.UseVisualStyleBackColor = true;
            this.C2.Click += new System.EventHandler(this.button12_Click);
            // 
            // C3
            // 
            this.C3.Enabled = false;
            this.C3.Location = new System.Drawing.Point(393, 52);
            this.C3.Name = "C3";
            this.C3.Size = new System.Drawing.Size(97, 36);
            this.C3.TabIndex = 6;
            this.C3.Text = "C3";
            this.C3.UseVisualStyleBackColor = true;
            this.C3.Click += new System.EventHandler(this.button11_Click);
            // 
            // B1
            // 
            this.B1.Enabled = false;
            this.B1.Location = new System.Drawing.Point(207, 202);
            this.B1.Name = "B1";
            this.B1.Size = new System.Drawing.Size(97, 36);
            this.B1.TabIndex = 5;
            this.B1.Text = "B1";
            this.B1.UseVisualStyleBackColor = true;
            this.B1.Click += new System.EventHandler(this.button10_Click);
            // 
            // B2
            // 
            this.B2.Enabled = false;
            this.B2.Location = new System.Drawing.Point(207, 128);
            this.B2.Name = "B2";
            this.B2.Size = new System.Drawing.Size(97, 36);
            this.B2.TabIndex = 4;
            this.B2.Text = "B2";
            this.B2.UseVisualStyleBackColor = true;
            this.B2.Click += new System.EventHandler(this.button9_Click);
            // 
            // B3
            // 
            this.B3.Enabled = false;
            this.B3.Location = new System.Drawing.Point(207, 52);
            this.B3.Name = "B3";
            this.B3.Size = new System.Drawing.Size(97, 36);
            this.B3.TabIndex = 3;
            this.B3.Text = "B3";
            this.B3.UseVisualStyleBackColor = true;
            this.B3.Click += new System.EventHandler(this.button8_Click);
            // 
            // A2
            // 
            this.A2.Enabled = false;
            this.A2.Location = new System.Drawing.Point(23, 128);
            this.A2.Name = "A2";
            this.A2.Size = new System.Drawing.Size(97, 36);
            this.A2.TabIndex = 1;
            this.A2.Text = "A2";
            this.A2.UseVisualStyleBackColor = true;
            this.A2.Click += new System.EventHandler(this.button6_Click);
            // 
            // A3
            // 
            this.A3.Enabled = false;
            this.A3.Location = new System.Drawing.Point(23, 52);
            this.A3.Name = "A3";
            this.A3.Size = new System.Drawing.Size(97, 36);
            this.A3.TabIndex = 0;
            this.A3.Text = "A3";
            this.A3.UseVisualStyleBackColor = true;
            this.A3.Click += new System.EventHandler(this.button5_Click);
            // 
            // tabPage2
            // 
            this.tabPage2.BackColor = System.Drawing.Color.DarkCyan;
            this.tabPage2.Controls.Add(this.label4);
            this.tabPage2.Controls.Add(this.comboBox2);
            this.tabPage2.Controls.Add(this.label1);
            this.tabPage2.Controls.Add(this.Open);
            this.tabPage2.Controls.Add(this.Send);
            this.tabPage2.Controls.Add(this.label3);
            this.tabPage2.Controls.Add(this.Close);
            this.tabPage2.Controls.Add(this.Read);
            this.tabPage2.Controls.Add(this.groupBox2);
            this.tabPage2.Controls.Add(this.groupBox1);
            this.tabPage2.Controls.Add(this.progressBar1);
            this.tabPage2.Controls.Add(this.comboBox1);
            this.tabPage2.Location = new System.Drawing.Point(4, 25);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(720, 325);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Port Configurations";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(570, 11);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(37, 13);
            this.label4.TabIndex = 24;
            this.label4.Text = "Status";
            // 
            // comboBox2
            // 
            this.comboBox2.FormattingEnabled = true;
            this.comboBox2.Items.AddRange(new object[] {
            "1200",
            "2400",
            "4800",
            "9600",
            "19200",
            "38400",
            "57600",
            "115200"});
            this.comboBox2.Location = new System.Drawing.Point(341, 30);
            this.comboBox2.Name = "comboBox2";
            this.comboBox2.Size = new System.Drawing.Size(121, 21);
            this.comboBox2.TabIndex = 14;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(27, 11);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(62, 13);
            this.label1.TabIndex = 22;
            this.label1.Text = "Port Names";
            // 
            // Open
            // 
            this.Open.Location = new System.Drawing.Point(573, 122);
            this.Open.Name = "Open";
            this.Open.Size = new System.Drawing.Size(121, 73);
            this.Open.TabIndex = 20;
            this.Open.Text = "Open Port";
            this.Open.UseVisualStyleBackColor = true;
            this.Open.Click += new System.EventHandler(this.button3_Click_1);
            // 
            // Send
            // 
            this.Send.Enabled = false;
            this.Send.Location = new System.Drawing.Point(68, 268);
            this.Send.Name = "Send";
            this.Send.Size = new System.Drawing.Size(121, 50);
            this.Send.TabIndex = 18;
            this.Send.Text = "Send";
            this.Send.UseVisualStyleBackColor = true;
            this.Send.Click += new System.EventHandler(this.button1_Click_1);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(341, 11);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(58, 13);
            this.label3.TabIndex = 23;
            this.label3.Text = "Baud Rate";
            // 
            // Close
            // 
            this.Close.Enabled = false;
            this.Close.Location = new System.Drawing.Point(573, 249);
            this.Close.Name = "Close";
            this.Close.Size = new System.Drawing.Size(121, 69);
            this.Close.TabIndex = 21;
            this.Close.Text = "Close Port";
            this.Close.UseVisualStyleBackColor = true;
            this.Close.Click += new System.EventHandler(this.button4_Click_1);
            // 
            // Read
            // 
            this.Read.Enabled = false;
            this.Read.Location = new System.Drawing.Point(383, 268);
            this.Read.Name = "Read";
            this.Read.Size = new System.Drawing.Size(121, 50);
            this.Read.TabIndex = 19;
            this.Read.Text = "Read";
            this.Read.UseVisualStyleBackColor = true;
            this.Read.Click += new System.EventHandler(this.button2_Click_1);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.textBox2);
            this.groupBox2.Location = new System.Drawing.Point(341, 91);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(200, 154);
            this.groupBox2.TabIndex = 17;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Received Here";
            // 
            // textBox2
            // 
            this.textBox2.Enabled = false;
            this.textBox2.Location = new System.Drawing.Point(7, 19);
            this.textBox2.Multiline = true;
            this.textBox2.Name = "textBox2";
            this.textBox2.ReadOnly = true;
            this.textBox2.Size = new System.Drawing.Size(187, 128);
            this.textBox2.TabIndex = 1;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.textBox1);
            this.groupBox1.Location = new System.Drawing.Point(27, 91);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(200, 154);
            this.groupBox1.TabIndex = 16;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Send Here";
            // 
            // textBox1
            // 
            this.textBox1.Enabled = false;
            this.textBox1.Location = new System.Drawing.Point(7, 20);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(187, 128);
            this.textBox1.TabIndex = 0;
            // 
            // progressBar1
            // 
            this.progressBar1.Location = new System.Drawing.Point(573, 30);
            this.progressBar1.Name = "progressBar1";
            this.progressBar1.Size = new System.Drawing.Size(121, 23);
            this.progressBar1.TabIndex = 15;
            // 
            // comboBox1
            // 
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Location = new System.Drawing.Point(27, 30);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(121, 21);
            this.comboBox1.TabIndex = 13;
            // 
            // tabPage3
            // 
            this.tabPage3.BackColor = System.Drawing.Color.DarkCyan;
            this.tabPage3.Controls.Add(this.Select);
            this.tabPage3.Controls.Add(this.label5);
            this.tabPage3.Controls.Add(this.textBox4);
            this.tabPage3.Controls.Add(this.Today);
            this.tabPage3.Location = new System.Drawing.Point(4, 25);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage3.Size = new System.Drawing.Size(720, 325);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "Registers";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(427, 44);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(74, 13);
            this.label5.TabIndex = 3;
            this.label5.Text = "Products Flow";
            // 
            // textBox4
            // 
            this.textBox4.Location = new System.Drawing.Point(291, 60);
            this.textBox4.Multiline = true;
            this.textBox4.Name = "textBox4";
            this.textBox4.ReadOnly = true;
            this.textBox4.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBox4.Size = new System.Drawing.Size(390, 218);
            this.textBox4.TabIndex = 2;
            // 
            // Today
            // 
            this.Today.Location = new System.Drawing.Point(79, 221);
            this.Today.Name = "Today";
            this.Today.Size = new System.Drawing.Size(125, 57);
            this.Today.TabIndex = 1;
            this.Today.Text = "Today";
            this.Today.UseVisualStyleBackColor = true;
            this.Today.Click += new System.EventHandler(this.Today_Click);
            // 
            // Select
            // 
            this.Select.Location = new System.Drawing.Point(79, 60);
            this.Select.Name = "Select";
            this.Select.Size = new System.Drawing.Size(125, 57);
            this.Select.TabIndex = 4;
            this.Select.Text = "Select a day";
            this.Select.UseVisualStyleBackColor = true;
            this.Select.Click += new System.EventHandler(this.Select_Click);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // comboBox3
            // 
            this.comboBox3.FormattingEnabled = true;
            this.comboBox3.Items.AddRange(new object[] {
            "Pick a Product",
            "Put a Product"});
            this.comboBox3.Location = new System.Drawing.Point(23, 274);
            this.comboBox3.Name = "comboBox3";
            this.comboBox3.Size = new System.Drawing.Size(121, 21);
            this.comboBox3.TabIndex = 19;
            // 
            // Type
            // 
            this.Type.AutoSize = true;
            this.Type.Location = new System.Drawing.Point(20, 258);
            this.Type.Name = "Type";
            this.Type.Size = new System.Drawing.Size(34, 13);
            this.Type.TabIndex = 20;
            this.Type.Text = "Mode";
            // 
            // Serial_TI
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.ClientSize = new System.Drawing.Size(732, 359);
            this.Controls.Add(this.tabControl1);
            this.ForeColor = System.Drawing.SystemColors.ControlText;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Serial_TI";
            this.Text = "AUTOMATED STORAGE";
            this.Load += new System.EventHandler(this.Serial_TI_Load);
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.tabPage3.ResumeLayout(false);
            this.tabPage3.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion
        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.ComboBox comboBox2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button Open;
        private System.Windows.Forms.Button Send;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button Close;
        private System.Windows.Forms.Button Read;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.ProgressBar progressBar1;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.Button C1;
        private System.Windows.Forms.Button C2;
        private System.Windows.Forms.Button C3;
        private System.Windows.Forms.Button B1;
        private System.Windows.Forms.Button B2;
        private System.Windows.Forms.Button B3;
        private System.Windows.Forms.Button A2;
        private System.Windows.Forms.Button A3;
        private System.Windows.Forms.ProgressBar progressBar2;
        private System.Windows.Forms.Button D3;
        private System.Windows.Forms.Button D2;
        private System.Windows.Forms.Button D1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.Button Today;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button Select;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.Label Type;
        private System.Windows.Forms.ComboBox comboBox3;
    }
}


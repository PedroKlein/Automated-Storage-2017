using System;
using System.IO;
using System.IO.Ports;
using System.Text;
using System.Windows.Forms;
namespace TI_serial {
    /**
     * There are three different tabs on the program.
     *  - Storage: It has eleven buttons, each one of them for a different product. There is a combo box, where the user can chose the type of order.
     *  - Port Configurations: This sections is where the user can configurate the serial port and also use the program as a serial terminal.
     *  - Registers: It is used to see all the data of the products flow.
     */
    public partial class Serial_TI : Form {
        public Serial_TI () {
            InitializeComponent ();
            GetAvaliablePorts ();
            serialPort1.ReadTimeout = 180000; //Limit time to read data from the serial port (3 minutes).
            serialPort1.WriteTimeout = 500; //Limit time to send data from the serial port (500 ms).
            textBox3.Text = "Select Port settings";
        }
        /**
         * This function get all the avaliable ports and puts them at a combo box so the user can chose wich use.
         */
        void GetAvaliablePorts () {
            String[] ports = SerialPort.GetPortNames ();
            comboBox1.Items.AddRange (ports);
        }
        /**
         * Only a function to enable all buttons from the storage tab.
         */
        void EnableButtons () {
            A3.Enabled = true;
            A2.Enabled = true;
            B3.Enabled = true;
            B2.Enabled = true;
            B1.Enabled = true;
            C3.Enabled = true;
            C2.Enabled = true;
            C1.Enabled = true;
            D1.Enabled = true;
            D2.Enabled = true;
            D3.Enabled = true;
        }
        /**
         * Only a function to disable all buttons from the storage tab.
         */
        void DisableButtons () {
            A3.Enabled = false;
            A2.Enabled = false;
            B3.Enabled = false;
            B2.Enabled = false;
            B1.Enabled = false;
            C3.Enabled = false;
            C2.Enabled = false;
            C1.Enabled = false;
            D1.Enabled = false;
            D2.Enabled = false;
            D3.Enabled = false;
        }
        /**
         * This function is called every time a product is chosen at the storage tab.
         * The parameters are the name off the product and a boolean variable that indicates what is the type of the order.
         * It disables all buttons there and puts the progress bar at 0%, showing the start of the order.
         * Then it goes to a infinite while waiting for the machine to send an "z", that indicates a successful execution, or an "y", that indicates only that the machine has ben reset or initialized.
         * If it receives an "z" than it writes on a file what product was choosen, wich type of order and at what time of the day it occurred. 
         */
        void WaitProduct (string product, bool type) {
            textBox3.Text = "Picking up...";
            DisableButtons ();
            progressBar2.Value = 0;
            while (true) {
                if (serialPort1.ReadByte () == 'z') {
                    StreamWriter filewrite = new StreamWriter (Environment.GetFolderPath (Environment.SpecialFolder.Desktop) + @"\Storage\" + DateTime.Today.Date.ToString ("D") + ".txt", true, Encoding.ASCII);
                    if (type) {
                        filewrite.WriteLine ("Product " + product + " withdrawn at {0:HH:mm:ss tt}", DateTime.Now);
                    } else {
                        filewrite.WriteLine ("Product " + product + " re-stocked at {0:HH:mm:ss tt}", DateTime.Now);
                    }
                    filewrite.Close ();
                    progressBar2.Value = 100;
                    EnableButtons ();
                    textBox3.Text = "Select a Product";
                    break;
                }
                if (serialPort1.ReadByte () == 'y') {
                    progressBar2.Value = 100;
                    EnableButtons ();
                    textBox3.Text = "Select a Product";
                    break;
                }
            }
        }
        private void progressBar1_Click (object sender, EventArgs e) {

        }
        /**
         * The button that opens the serial port.
         * If there is no port chosen and no baud rate than it sends a warning.
         * If there is, then it opens the chosed port and it sets it with the chosed baud rate.
         */
        private void button3_Click_1 (object sender, EventArgs e) {
            try {
                if (comboBox1.Text == "" || comboBox2.Text == "") {
                    textBox2.Text = "Select Port settings";
                    textBox3.Text = "Select Port settings";
                } else {
                    serialPort1.PortName = comboBox1.Text;
                    serialPort1.BaudRate = Convert.ToInt32 (comboBox2.Text);
                    serialPort1.Open ();
                    textBox2.Text = "";
                    progressBar1.Value = 100;
                    Send.Enabled = true;
                    Read.Enabled = true;
                    textBox1.Enabled = true;
                    Open.Enabled = false;
                    Close.Enabled = true;
                    EnableButtons ();
                    textBox3.Text = "Select a product";
                }
            } catch (UnauthorizedAccessException) {
                textBox2.Text = "Unauthorized Acess";
            }
        }
        /**
         * Button that closes the serial port.
         */
        private void button4_Click_1 (object sender, EventArgs e) {
            serialPort1.Close ();
            progressBar1.Value = 0;
            Send.Enabled = false;
            Read.Enabled = false;
            textBox1.Enabled = false;
            Open.Enabled = true;
            Close.Enabled = false;
            DisableButtons ();
            textBox3.Text = "Select Port settings";
            progressBar2.Value = 0;
        }
        /**
         * Button used to send the data written on the text box 1 to the serial port.
         */
        private void button1_Click_1 (object sender, EventArgs e) {
            serialPort1.WriteLine (textBox1.Text);
            textBox1.Text = "";
        }
        /**
         * Button used to read some data from the serial port, displaying it on the text box 2.
         */
        private void button2_Click_1 (object sender, EventArgs e) {
            try {
                textBox2.Text = serialPort1.ReadLine ();
            } catch (TimeoutException) {
                MessageBox.Show ("Check out the machine!");
                textBox2.Text = "Timeout Exception";
            }
        }
        /**
         * Buttons 6,5,10,9,8,13,12,11,14,16 and 17 selects the product.
         * First it checks on the combo box 3 what is the type of order, "Pick a Product" or "Put a Product".
         * Then it writes a character to the serial port so that the ARM can identify what is the request.
         * After that, it initializes the function "WaitProduct()" with the parameters such as the name of the product and the type of order.
         */
        private void button6_Click (object sender, EventArgs e) {
            if (comboBox3.Text == "Pick a Product") {
                serialPort1.Write ("a");
                WaitProduct ("A2", true);
            } else if (comboBox3.Text == "Put a Product") {
                serialPort1.Write ("b");
                WaitProduct ("A2", false);
            } else MessageBox.Show ("Please select a mode.");

        }

        private void button5_Click (object sender, EventArgs e) {
            if (comboBox3.Text == "Pick a Product") {
                serialPort1.Write ("c");
                WaitProduct ("A3", true);
            } else if (comboBox3.Text == "Put a Product") {
                serialPort1.Write ("d");
                WaitProduct ("A3", false);
            } else MessageBox.Show ("Please select a mode.");
        }

        private void button10_Click (object sender, EventArgs e) {
            if (comboBox3.Text == "Pick a Product") {
                serialPort1.Write ("e");
                WaitProduct ("B1", true);
            } else if (comboBox3.Text == "Put a Product") {
                serialPort1.Write ("f");
                WaitProduct ("B1", false);
            } else MessageBox.Show ("Please select a mode.");
        }

        private void button9_Click (object sender, EventArgs e) {
            if (comboBox3.Text == "Pick a Product") {
                serialPort1.Write ("g");
                WaitProduct ("B2", true);
            } else if (comboBox3.Text == "Put a Product") {
                serialPort1.Write ("h");
                WaitProduct ("B2", false);
            } else MessageBox.Show ("Please select a mode.");
        }

        private void button8_Click (object sender, EventArgs e) {
            if (comboBox3.Text == "Pick a Product") {
                serialPort1.Write ("i");
                WaitProduct ("B3", true);
            } else if (comboBox3.Text == "Put a Product") {
                serialPort1.Write ("j");
                WaitProduct ("B3", false);
            } else MessageBox.Show ("Please select a mode.");
        }

        private void button13_Click (object sender, EventArgs e) {
            if (comboBox3.Text == "Pick a Product") {
                serialPort1.Write ("k");
                WaitProduct ("C1", true);
            } else if (comboBox3.Text == "Put a Product") {
                serialPort1.Write ("l");
                WaitProduct ("C1", false);
            } else MessageBox.Show ("Please select a mode.");
        }

        private void button12_Click (object sender, EventArgs e) {
            if (comboBox3.Text == "Pick a Product") {
                serialPort1.Write ("m");
                WaitProduct ("C2", true);
            } else if (comboBox3.Text == "Put a Product") {
                serialPort1.Write ("n");
                WaitProduct ("C2", false);
            } else MessageBox.Show ("Please select a mode.");
        }

        private void button11_Click (object sender, EventArgs e) {
            if (comboBox3.Text == "Pick a Product") {
                serialPort1.Write ("o");
                WaitProduct ("C3", true);
            } else if (comboBox3.Text == "Put a Product") {
                serialPort1.Write ("p");
                WaitProduct ("C3", false);
            } else MessageBox.Show ("Please select a mode.");
        }

        private void button14_Click (object sender, EventArgs e) {
            if (comboBox3.Text == "Pick a Product") {
                serialPort1.Write ("q");
                WaitProduct ("D1", true);
            } else if (comboBox3.Text == "Put a Product") {
                serialPort1.Write ("r");
                WaitProduct ("D1", false);
            } else MessageBox.Show ("Please select a mode.");
        }

        private void button16_Click (object sender, EventArgs e) {
            if (comboBox3.Text == "Pick a Product") {
                serialPort1.Write ("s");
                WaitProduct ("D2", true);
            } else if (comboBox3.Text == "Put a Product") {
                serialPort1.Write ("t");
                WaitProduct ("D2", false);
            } else MessageBox.Show ("Please select a mode.");
        }

        private void button17_Click (object sender, EventArgs e) {
            if (comboBox3.Text == "Pick a Product") {
                serialPort1.Write ("u");
                WaitProduct ("D3", true);
            } else if (comboBox3.Text == "Put a Product") {
                serialPort1.Write ("v");
                WaitProduct ("D3", false);
            } else MessageBox.Show ("Please select a mode.");
        }

        /**
         * Executes this everytime that the program is initialized.
         */
        private void Serial_TI_Load (object sender, EventArgs e) {
            string folder = Environment.GetFolderPath (Environment.SpecialFolder.Desktop) + @"\Storage";
            if (!Directory.Exists (folder)) // Checks if there isn't a folder called "Storage" at the desktop.
            {
                Directory.CreateDirectory (folder); // If so, it creates the folder "Storage" at the desktop.
            }
            if (!(File.Exists (folder + @"\" + DateTime.Today.Date.ToString ("D") + ".txt"))) //Checks if there isn't a text file with the name of the current date on the Storage file.
            {
                File.Create (folder + @"\" + DateTime.Today.Date.ToString ("D") + ".txt"); //If so, it creates the text file with the name of the current date on the Storage file.
            }
        }
        /**
         * Button that displays the products flow of the current day on the text box 4, in the "Registers" tab.
         */
        private void Today_Click (object sender, EventArgs e) {
            StreamReader file = new StreamReader (Environment.GetFolderPath (Environment.SpecialFolder.Desktop) + @"\Storage\" + DateTime.Today.Date.ToString ("D") + ".txt");
            textBox4.Text = file.ReadToEnd ();
            file.Close ();
        }
        /**
         * Button that displays the selected text file on the text box 4, in the "Registers" tab.
         * This botton should be used as a way to access previous documents of the products flow.
         */
        private void Select_Click (object sender, EventArgs e) {
            DialogResult result = openFileDialog1.ShowDialog ();
            if (result == DialogResult.OK) // Test result.
            {
                StreamReader file = new StreamReader (openFileDialog1.FileName);
                textBox4.Text = file.ReadToEnd ();
                file.Close ();
            }
        }
    }

}
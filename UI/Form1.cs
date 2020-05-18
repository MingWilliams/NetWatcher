using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace UI
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }


        private void OpenToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string File = "";
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Multiselect = false;
            ofd.InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.MyComputer);
            ofd.Title = "Select a pcap file";
            ofd.Filter = "Pcap file(*.pcap)|*.pcap";
            ofd.ShowDialog();
            if (ofd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                File = ofd.FileName;

            }
        }

    }
}

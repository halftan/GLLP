using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace gomoku
{
    public partial class MainForm : Form
    {
        private int[,] bdmap;
        private System.Windows.Forms.Label[,] blocks;
        public const int BLACK = 1;
        public const int WHITE = 2;
        public const int BLANK = 0;
        private int whosTurn = BLACK;
        private bool isEnabled = true;

        public MainForm()
        {
            InitializeComponent();
            this.bdmap = new int[15, 15];
            this.blocks = new System.Windows.Forms.Label[15, 15];
            //
            // blocks
            //
            for (int i = 0; i < 15; ++i)
                for (int j = 0; j < 15; ++j)
                {
                    bdmap[i, j] = 0;
                    blocks[i, j] = new System.Windows.Forms.Label();
                    blocks[i, j].BackColor = System.Drawing.Color.Transparent;
                    blocks[i, j].Size = new System.Drawing.Size(35, 35);
                    blocks[i, j].Location =
                        new System.Drawing.Point(23 + i * 35, 18 + j * 35);
                    blocks[i, j].Name = i.ToString() + "," + j.ToString();
                    blocks[i, j].MouseClick += new MouseEventHandler(this.setPiece);
                    blocks[i, j].MouseEnter += new EventHandler(this.setActive);
                    blocks[i, j].MouseLeave += new EventHandler(this.setInactive);
                    blocks[i, j].Image = null;
                    this.gomokuBoard.Controls.Add(blocks[i, j]);
                }
        }

        private void setActive(object sender, EventArgs e)
        {
            if(((Label)sender).Image == null)
                ((Label)sender).Image = Properties.Resources.active;
        }

        private void setInactive(object sender, EventArgs e)
        {
            string[] axis = ((Label)sender).Name.Split(',');
            int i = System.Int32.Parse(axis[0]);
            int j = System.Int32.Parse(axis[1]);
            if(bdmap[i, j] == BLANK)
                ((Label)sender).Image = null;
        }

        private void setPiece(object sender, MouseEventArgs e)
        {
            string[] axis = ((Label)sender).Name.Split(',');
            int i = System.Int32.Parse(axis[0]);
            int j = System.Int32.Parse(axis[1]);
            if (this.isEnabled == false || bdmap[i, j] != BLANK)
                return;
            System.Diagnostics.Trace.Assert(this.whosTurn != BLANK);
            if (whosTurn == BLACK)
                ((Label)sender).Image = Properties.Resources.blackp;
            else
                ((Label)sender).Image = Properties.Resources.whitep;
            bdmap[i, j] = whosTurn;
            if (hasFive(i, j, whosTurn))
            {
                string player =
                    whosTurn == BLACK ? this.p1Label.Text : this.p2Label.Text;
                this.notice.Text = "Winner is " + player + " !";
                this.isEnabled = false;
            }
            this.whosTurn = 3 - whosTurn;
        }

        private bool hasFive(int loc_i, int loc_j, int patt)
        {
            int i, j, count;
            i = loc_i;
            j = loc_j;
            while(i >= 0 && bdmap[i, j] == patt)
                --i;
            ++i; count = 0;
            //up down 5
            while(i < 15 && bdmap[i, j] == patt){
                ++count; ++i;
            }
            if(count >= 5)
                return true;
            // left right 5
            i = loc_i; j = loc_j;
            while(j >= 0 && bdmap[i, j] == patt)
                --j;
            ++j; count = 0;
            while(j < 15 && bdmap[i, j] == patt){
                ++count; ++j;
            }
            if(count >= 5)
                return true;
            //up left - down right 5
            i = loc_i; j = loc_j;
            while(i >= 0 && j >= 0 && bdmap[i, j] == patt){
                --i; --j;
            }
            ++i; ++j; count = 0;
            while(i < 15 && j < 15 && bdmap[i, j] == patt){
                ++count; ++i; ++j;
            }
            if(count >= 5)
                return true;
            //up right - down left 5
            i = loc_i; j = loc_j;
            while(i >= 0 && j < 15 && bdmap[i, j] == patt){
                --i; ++j;
            }
            ++i; --j; count = 0;
            while(i < 15 && j >= 0 && bdmap[i, j] == patt){
                ++count; ++i; --j;
            }
            if(count >= 5)
                return true;
            //no five
            return false;
        }

        private void quitButton_Click(object sender, EventArgs e)
        {
            this.Dispose();
        }

        private void p1TB_TextChanged(object sender, EventArgs e)
        {
            this.p1Label.Text = ((TextBox)sender).Text;
        }

        private void p2TB_TextChanged(object sender, EventArgs e)
        {
            this.p2Label.Text = ((TextBox)sender).Text;
        }            
        
        private void clearButton_Click(object sender, EventArgs e)
        {
            for(int i = 0; i < 15; ++i)
                for (int j = 0; j < 15; ++j)
                {
                    bdmap[i, j] = BLANK;
                    if (blocks[i, j].Image != null)
                        blocks[i, j].Image = null;
                }
            isEnabled = true;
            whosTurn = BLACK;
            notice.Text = "";
        }
    }
}

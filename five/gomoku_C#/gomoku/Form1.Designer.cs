namespace gomoku
{
    partial class MainForm
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.gomokuBoard = new System.Windows.Forms.Panel();
            this.mainLayout = new System.Windows.Forms.FlowLayoutPanel();
            this.leftPanel = new System.Windows.Forms.Panel();
            this.whiteP = new System.Windows.Forms.Label();
            this.blackP = new System.Windows.Forms.Label();
            this.quitButton = new System.Windows.Forms.Button();
            this.clearButton = new System.Windows.Forms.Button();
            this.p2TB = new System.Windows.Forms.TextBox();
            this.p1TB = new System.Windows.Forms.TextBox();
            this.notice = new System.Windows.Forms.Label();
            this.p2Label = new System.Windows.Forms.Label();
            this.p1Label = new System.Windows.Forms.Label();
            this.mainLayout.SuspendLayout();
            this.leftPanel.SuspendLayout();
            this.SuspendLayout();
            // 
            // gomokuBoard
            // 
            this.gomokuBoard.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.gomokuBoard.BackgroundImage = global::gomoku.Properties.Resources.gomokub;
            this.gomokuBoard.Location = new System.Drawing.Point(3, 3);
            this.gomokuBoard.Name = "gomokuBoard";
            this.gomokuBoard.Size = new System.Drawing.Size(565, 565);
            this.gomokuBoard.TabIndex = 0;
            // 
            // mainLayout
            // 
            this.mainLayout.Controls.Add(this.gomokuBoard);
            this.mainLayout.Controls.Add(this.leftPanel);
            this.mainLayout.Dock = System.Windows.Forms.DockStyle.Fill;
            this.mainLayout.FlowDirection = System.Windows.Forms.FlowDirection.TopDown;
            this.mainLayout.Location = new System.Drawing.Point(0, 0);
            this.mainLayout.Name = "mainLayout";
            this.mainLayout.Size = new System.Drawing.Size(764, 572);
            this.mainLayout.TabIndex = 6;
            // 
            // leftPanel
            // 
            this.leftPanel.Controls.Add(this.whiteP);
            this.leftPanel.Controls.Add(this.blackP);
            this.leftPanel.Controls.Add(this.quitButton);
            this.leftPanel.Controls.Add(this.clearButton);
            this.leftPanel.Controls.Add(this.p2TB);
            this.leftPanel.Controls.Add(this.p1TB);
            this.leftPanel.Controls.Add(this.notice);
            this.leftPanel.Controls.Add(this.p2Label);
            this.leftPanel.Controls.Add(this.p1Label);
            this.leftPanel.Location = new System.Drawing.Point(574, 3);
            this.leftPanel.Name = "leftPanel";
            this.leftPanel.Size = new System.Drawing.Size(200, 565);
            this.leftPanel.TabIndex = 1;
            // 
            // whiteP
            // 
            this.whiteP.Image = global::gomoku.Properties.Resources.whitep;
            this.whiteP.Location = new System.Drawing.Point(18, 212);
            this.whiteP.Name = "whiteP";
            this.whiteP.Size = new System.Drawing.Size(35, 35);
            this.whiteP.TabIndex = 8;
            // 
            // blackP
            // 
            this.blackP.Image = global::gomoku.Properties.Resources.blackp;
            this.blackP.Location = new System.Drawing.Point(18, 80);
            this.blackP.Name = "blackP";
            this.blackP.Size = new System.Drawing.Size(35, 35);
            this.blackP.TabIndex = 7;
            // 
            // quitButton
            // 
            this.quitButton.Location = new System.Drawing.Point(57, 411);
            this.quitButton.Name = "quitButton";
            this.quitButton.Size = new System.Drawing.Size(75, 23);
            this.quitButton.TabIndex = 6;
            this.quitButton.Text = "Quit";
            this.quitButton.UseVisualStyleBackColor = true;
            this.quitButton.Click += new System.EventHandler(this.quitButton_Click);
            // 
            // clearButton
            // 
            this.clearButton.Location = new System.Drawing.Point(57, 382);
            this.clearButton.Name = "clearButton";
            this.clearButton.Size = new System.Drawing.Size(75, 23);
            this.clearButton.TabIndex = 5;
            this.clearButton.Text = "Clear";
            this.clearButton.UseVisualStyleBackColor = true;
            this.clearButton.Click += new System.EventHandler(this.clearButton_Click);
            // 
            // p2TB
            // 
            this.p2TB.Location = new System.Drawing.Point(20, 188);
            this.p2TB.MaxLength = 16;
            this.p2TB.Name = "p2TB";
            this.p2TB.Size = new System.Drawing.Size(137, 21);
            this.p2TB.TabIndex = 4;
            this.p2TB.Text = "Player 2";
            this.p2TB.TextChanged += new System.EventHandler(this.p2TB_TextChanged);
            // 
            // p1TB
            // 
            this.p1TB.Location = new System.Drawing.Point(20, 56);
            this.p1TB.MaxLength = 16;
            this.p1TB.Name = "p1TB";
            this.p1TB.Size = new System.Drawing.Size(137, 21);
            this.p1TB.TabIndex = 3;
            this.p1TB.Text = "Player 1";
            this.p1TB.TextChanged += new System.EventHandler(this.p1TB_TextChanged);
            // 
            // notice
            // 
            this.notice.Font = new System.Drawing.Font("宋体", 14F);
            this.notice.Location = new System.Drawing.Point(16, 263);
            this.notice.Name = "notice";
            this.notice.Size = new System.Drawing.Size(141, 116);
            this.notice.TabIndex = 2;
            // 
            // p2Label
            // 
            this.p2Label.AutoSize = true;
            this.p2Label.Font = new System.Drawing.Font("宋体", 14F);
            this.p2Label.Location = new System.Drawing.Point(16, 157);
            this.p2Label.Name = "p2Label";
            this.p2Label.Size = new System.Drawing.Size(89, 19);
            this.p2Label.TabIndex = 1;
            this.p2Label.Text = "Player 2";
            // 
            // p1Label
            // 
            this.p1Label.AutoSize = true;
            this.p1Label.Font = new System.Drawing.Font("宋体", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.p1Label.Location = new System.Drawing.Point(16, 34);
            this.p1Label.Name = "p1Label";
            this.p1Label.Size = new System.Drawing.Size(89, 19);
            this.p1Label.TabIndex = 0;
            this.p1Label.Text = "Player 1";
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(764, 572);
            this.Controls.Add(this.mainLayout);
            this.Name = "MainForm";
            this.Text = "Gomoku";
            this.mainLayout.ResumeLayout(false);
            this.leftPanel.ResumeLayout(false);
            this.leftPanel.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.FlowLayoutPanel mainLayout;
        private System.Windows.Forms.Panel leftPanel;
        private System.Windows.Forms.Label whiteP;
        private System.Windows.Forms.Label blackP;
        private System.Windows.Forms.Button quitButton;
        private System.Windows.Forms.Button clearButton;
        private System.Windows.Forms.TextBox p2TB;
        private System.Windows.Forms.TextBox p1TB;
        private System.Windows.Forms.Label notice;
        private System.Windows.Forms.Label p2Label;
        private System.Windows.Forms.Label p1Label;
        private System.Windows.Forms.Panel gomokuBoard;
    }
}


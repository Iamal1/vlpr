#pragma once
 
namespace vlpr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	int pic_width=0,pic_height=0;
	int boxNum=0,minBoundingBox[100][5]={0};//Xmin Xmax Ymin Ymax Number

	Byte bmp_src_rgb[MAX_HEIGHT][MAX_WIDTH][3];
	Byte bmp_src_gray[MAX_HEIGHT][MAX_WIDTH];

	Byte bmp_rgb_tmp1[MAX_HEIGHT][MAX_WIDTH][3]; 
	Byte bmp_rgb_tmp2[MAX_HEIGHT][MAX_WIDTH][3]; 
	Byte bmp_gray_tmp1[MAX_HEIGHT][MAX_WIDTH]; 
	Byte bmp_gray_tmp2[MAX_HEIGHT][MAX_WIDTH]; 
	Byte bmp_gray_tmp3[MAX_HEIGHT][MAX_WIDTH]; 

	/// <summary>
	/// Form1 摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Drawing::Bitmap^ bmp;  
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog; 

	private: System::Windows::Forms::PictureBox^  pictureBox0;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::PictureBox^  pictureBox6;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2; 
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::PictureBox^  pictureBox8;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::PictureBox^  pictureBox9;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::PictureBox^  pictureBox10;
	private: System::Windows::Forms::PictureBox^  pictureBox11;
	private: System::Windows::Forms::PictureBox^  pictureBox12;
	private: System::Windows::Forms::PictureBox^  pictureBox13;
	private: System::Windows::Forms::PictureBox^  pictureBox14;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::PictureBox^  pictureBox15;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox16;



	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox0 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox13 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox14 = (gcnew System::Windows::Forms::PictureBox());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->pictureBox15 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox16 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox13))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox14))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox15))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox16))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(12, 225);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(382, 21);
			this->textBox1->TabIndex = 1;
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"openFileDialog1";
			// 
			// pictureBox0
			// 
			this->pictureBox0->BackColor = System::Drawing::SystemColors::Control;
			this->pictureBox0->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox0->Enabled = false;
			this->pictureBox0->Location = System::Drawing::Point(288, 12);
			this->pictureBox0->Name = L"pictureBox0";
			this->pictureBox0->Size = System::Drawing::Size(270, 210);
			this->pictureBox0->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox0->TabIndex = 9;
			this->pictureBox0->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::Control;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Enabled = false;
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(270, 210);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox2->Enabled = false;
			this->pictureBox2->Location = System::Drawing::Point(564, 12);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(270, 210);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox3->Enabled = false;
			this->pictureBox3->Location = System::Drawing::Point(840, 12);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(270, 210);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 7;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox4->Enabled = false;
			this->pictureBox4->Location = System::Drawing::Point(12, 252);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(270, 210);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 7;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox5->Enabled = false;
			this->pictureBox5->Location = System::Drawing::Point(288, 252);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(270, 210);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox5->TabIndex = 7;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox6->Enabled = false;
			this->pictureBox6->Location = System::Drawing::Point(564, 252);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(270, 210);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox6->TabIndex = 7;
			this->pictureBox6->TabStop = false;
			// 
			// pictureBox7
			// 
			this->pictureBox7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox7->Enabled = false;
			this->pictureBox7->Location = System::Drawing::Point(840, 252);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(130, 100);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox7->TabIndex = 7;
			this->pictureBox7->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(400, 223);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(61, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Open Pic";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(667, 223);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Top-hat";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(956, 223);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Soble";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Enabled = false;
			this->button4->Location = System::Drawing::Point(75, 468);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(121, 23);
			this->button4->TabIndex = 8;
			this->button4->Text = L"Otsu Binarization";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->Enabled = false;
			this->button5->Location = System::Drawing::Point(316, 468);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(219, 23);
			this->button5->TabIndex = 8;
			this->button5->Text = L"Noise and bounding curves removing";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button6
			// 
			this->button6->Enabled = false;
			this->button6->Location = System::Drawing::Point(667, 468);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 8;
			this->button6->Text = L"close";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button7
			// 
			this->button7->Enabled = false;
			this->button7->Location = System::Drawing::Point(943, 468);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(103, 23);
			this->button7->TabIndex = 8;
			this->button7->Text = L"Bounding Box";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// pictureBox8
			// 
			this->pictureBox8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox8->Enabled = false;
			this->pictureBox8->Location = System::Drawing::Point(975, 252);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(130, 100);
			this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox8->TabIndex = 7;
			this->pictureBox8->TabStop = false;
			// 
			// button8
			// 
			this->button8->Enabled = false;
			this->button8->Location = System::Drawing::Point(75, 566);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(103, 23);
			this->button8->TabIndex = 8;
			this->button8->Text = L"Origin Plate";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// pictureBox9
			// 
			this->pictureBox9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox9->Enabled = false;
			this->pictureBox9->Location = System::Drawing::Point(840, 358);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(130, 100);
			this->pictureBox9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox9->TabIndex = 7;
			this->pictureBox9->TabStop = false;
			// 
			// button9
			// 
			this->button9->Enabled = false;
			this->button9->Location = System::Drawing::Point(302, 566);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(159, 23);
			this->button9->TabIndex = 8;
			this->button9->Text = L"Gray and Otsu";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// pictureBox10
			// 
			this->pictureBox10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox10->Enabled = false;
			this->pictureBox10->Location = System::Drawing::Point(975, 358);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(130, 100);
			this->pictureBox10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox10->TabIndex = 7;
			this->pictureBox10->TabStop = false;
			// 
			// pictureBox11
			// 
			this->pictureBox11->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->pictureBox11->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox11->Enabled = false;
			this->pictureBox11->Location = System::Drawing::Point(40, 510);
			this->pictureBox11->Name = L"pictureBox11";
			this->pictureBox11->Size = System::Drawing::Size(170, 50);
			this->pictureBox11->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox11->TabIndex = 7;
			this->pictureBox11->TabStop = false;
			// 
			// pictureBox12
			// 
			this->pictureBox12->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->pictureBox12->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox12->Enabled = false;
			this->pictureBox12->Location = System::Drawing::Point(392, 510);
			this->pictureBox12->Name = L"pictureBox12";
			this->pictureBox12->Size = System::Drawing::Size(170, 50);
			this->pictureBox12->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox12->TabIndex = 7;
			this->pictureBox12->TabStop = false;
			// 
			// pictureBox13
			// 
			this->pictureBox13->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->pictureBox13->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox13->Enabled = false;
			this->pictureBox13->Location = System::Drawing::Point(568, 510);
			this->pictureBox13->Name = L"pictureBox13";
			this->pictureBox13->Size = System::Drawing::Size(170, 50);
			this->pictureBox13->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox13->TabIndex = 7;
			this->pictureBox13->TabStop = false;
			// 
			// pictureBox14
			// 
			this->pictureBox14->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->pictureBox14->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox14->Enabled = false;
			this->pictureBox14->Location = System::Drawing::Point(744, 510);
			this->pictureBox14->Name = L"pictureBox14";
			this->pictureBox14->Size = System::Drawing::Size(170, 50);
			this->pictureBox14->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox14->TabIndex = 7;
			this->pictureBox14->TabStop = false;
			// 
			// button10
			// 
			this->button10->Enabled = false;
			this->button10->Location = System::Drawing::Point(578, 566);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(147, 23);
			this->button10->TabIndex = 8;
			this->button10->Text = L"Binary Plate";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
			// 
			// button11
			// 
			this->button11->Enabled = false;
			this->button11->Location = System::Drawing::Point(840, 566);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(137, 23);
			this->button11->TabIndex = 8;
			this->button11->Text = L"Number Segmentation";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Form1::button11_Click);
			// 
			// pictureBox15
			// 
			this->pictureBox15->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->pictureBox15->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox15->Enabled = false;
			this->pictureBox15->Location = System::Drawing::Point(920, 510);
			this->pictureBox15->Name = L"pictureBox15";
			this->pictureBox15->Size = System::Drawing::Size(170, 50);
			this->pictureBox15->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox15->TabIndex = 7;
			this->pictureBox15->TabStop = false;
			// 
			// textBox2
			// 
			this->textBox2->Enabled = false;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox2->ForeColor = System::Drawing::Color::DarkRed;
			this->textBox2->Location = System::Drawing::Point(992, 562);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(87, 29);
			this->textBox2->TabIndex = 10;
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pictureBox16
			// 
			this->pictureBox16->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->pictureBox16->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox16->Enabled = false;
			this->pictureBox16->Location = System::Drawing::Point(216, 510);
			this->pictureBox16->Name = L"pictureBox16";
			this->pictureBox16->Size = System::Drawing::Size(170, 50);
			this->pictureBox16->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox16->TabIndex = 7;
			this->pictureBox16->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(1117, 607);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox15);
			this->Controls->Add(this->pictureBox14);
			this->Controls->Add(this->pictureBox13);
			this->Controls->Add(this->pictureBox16);
			this->Controls->Add(this->pictureBox12);
			this->Controls->Add(this->pictureBox11);
			this->Controls->Add(this->pictureBox10);
			this->Controls->Add(this->pictureBox9);
			this->Controls->Add(this->pictureBox8);
			this->Controls->Add(this->pictureBox7);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox0);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Vehicle License Plate Recognition";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox13))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox14))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox15))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox16))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) { 

				 openFileDialog->InitialDirectory= "C:\\Users\\Asin\\Desktop\\car\\vlpr\\car_test\\";
				 openFileDialog->Filter="JPG files|*.jpg|All files|*.*";
				 openFileDialog->RestoreDirectory=true;
				 openFileDialog->FilterIndex=1;
				 if ( openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK )
				 {
					 textBox1->Text=openFileDialog->FileName;//openFileDialog->SafeFileName;
					 bmp=(Bitmap^)Image::FromFile(openFileDialog->FileName);
					 

					 pictureBox1->Image=bmp;//pictureBox1->ImageLocation=openFileDialog->FileName;					   
					 pic_width=bmp->Size.Width;
					 pic_height=bmp->Size.Height;
					 Bitmap2Byte(bmp,bmp_src_rgb); 

					 rgb2gray(bmp_src_rgb,bmp_src_gray,pic_width,pic_height);
					 pictureBox0->Image=grayByte2Bitmap(bmp_src_gray,pic_width,pic_height); 

					 button2->Enabled = true; 
				 }
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 button2->Enabled = false;

				 TopHat(bmp_src_gray,bmp_gray_tmp1,pic_width,pic_height);
				 pictureBox2->Image=grayByte2Bitmap(bmp_gray_tmp1,pic_width,pic_height); 

				 button3->Enabled = true;				     
			 }

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 button3->Enabled = false;

			 Soble(bmp_gray_tmp1,bmp_gray_tmp2,pic_width,pic_height);
			 pictureBox3->Image=grayByte2Bitmap(bmp_gray_tmp2,pic_width,pic_height); 

			 button4->Enabled = true;			  
		 } 

private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 button4->Enabled = false;

			 OtsuBinarization(bmp_gray_tmp2,pic_width,pic_height);
			 pictureBox4->Image=grayByte2Bitmap(bmp_gray_tmp2,pic_width,pic_height); 

			 button5->Enabled = true; 
		 }

private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 button5->Enabled = false;

			 CurveNoiseRemove(bmp_gray_tmp2,bmp_gray_tmp1,bmp_gray_tmp3,pic_width,pic_height);
			 pictureBox5->Image=grayByte2Bitmap(bmp_gray_tmp2,pic_width,pic_height);

			 button6->Enabled = true;
		 }

private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 button6->Enabled = false;

			 CloseOp(bmp_gray_tmp2,bmp_gray_tmp1,pic_width,pic_height);
			 pictureBox6->Image=grayByte2Bitmap(bmp_gray_tmp1,pic_width,pic_height);

			 button7->Enabled = true;
		 }
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {	
			 button7->Enabled = false; 

			 Fill(bmp_gray_tmp1,bmp_gray_tmp2,pic_width,pic_height);
			 pictureBox7->Image=grayByte2Bitmap(bmp_gray_tmp2,pic_width,pic_height);
			 Contours(bmp_gray_tmp2,bmp_gray_tmp1,pic_width,pic_height);
			 pictureBox8->Image=grayByte2Bitmap(bmp_gray_tmp1,pic_width,pic_height);
			 boxNum=BoundingColor(bmp_gray_tmp2,bmp_gray_tmp1,pic_width,pic_height,minBoundingBox); 
			 pictureBox9->Image=grayByte2Bitmap(bmp_gray_tmp1,pic_width,pic_height);
			 int w=0,h=0;
			 BoundingBox(bmp_src_rgb,bmp_rgb_tmp1,bmp_rgb_tmp2,minBoundingBox,boxNum,&w,&h); 
			 pictureBox10->Image=rgbByte2Bitmap(bmp_rgb_tmp1,pic_width,pic_height); 
			 pic_width=w;
			 pic_height=h;

			 button8->Enabled = true;
		 }
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {	
			 button8->Enabled = false; 

			 pictureBox11->Image=rgbByte2Bitmap(bmp_rgb_tmp2,pic_width,pic_height);

			 button9->Enabled = true;
		 }
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {	
			 button9->Enabled = false;	 

// 			 HistogramEqualization(bmp_src_gray,bmp_gray_tmp1,pic_width,pic_height);
// 			 pictureBox13->Image=grayByte2Bitmap(bmp_gray_tmp1,pic_width,pic_height); 
			 rgb2gray(bmp_rgb_tmp2,bmp_src_gray,pic_width,pic_height);
			 pictureBox16->Image=grayByte2Bitmap(bmp_src_gray,pic_width,pic_height); 
			 OtsuBinarization(bmp_src_gray,pic_width,pic_height);  
			 pictureBox12->Image=grayByte2Bitmap(bmp_src_gray,pic_width,pic_height); 


			 button10->Enabled = true;

		 }
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {	
			 button10->Enabled = false;	  
			  

			 Plate(bmp_src_gray,pic_width,pic_height);
			 pictureBox13->Image=grayByte2Bitmap(bmp_src_gray,pic_width,pic_height);  

			  

			 button11->Enabled = true;
		 }
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {	
			 button11->Enabled = false;

			 int number[10][100][100]={0};
			 double feature_X[10][120]={0},feature_Y[10][240]={0};
			 in_f(number);
			 number_feature(number,feature_X,feature_Y);
			 boxNum=seg_Number(bmp_src_gray,bmp_gray_tmp1,pic_width,pic_height,minBoundingBox,feature_X,feature_Y); //Xmin Xmax Ymin Ymax 
			 pictureBox14->Image=grayByte2Bitmap(bmp_gray_tmp1,pic_width,pic_height);   
			   

			 seg_sort(boxNum,minBoundingBox);
			 if (boxNum)
			 {

				 int temp=0;
				 for (int k=0;k<=boxNum-1;k++)
				 {
					 temp*=10;
					 temp+=minBoundingBox[k][4];
				 }
				 char buffer[20];
				 _itoa(temp, buffer, 10 );  
				 String^ str=gcnew System::String(buffer);
				 textBox2->Text=str; 
			 }
			 else
				 textBox2->Text="";
			 seg_RGB(bmp_rgb_tmp2,bmp_rgb_tmp1,boxNum,minBoundingBox);
			 pictureBox15->Image=rgbByte2Bitmap(bmp_rgb_tmp1,pic_width,pic_height); 
		 }
		  
};
}


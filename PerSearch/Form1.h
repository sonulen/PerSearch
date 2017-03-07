#pragma once


// Include lib's
#include "myFunction.h"
#include "myRoi.h"
#include <fstream>
#include "FramePersons.h"
#include <ctime>

// Global Obj
std::string filesDir; // ���������� � ����� � ����� �������_���//Files// ��� ����� ��� �����
std::string loadFileName; // ���� � ���������� �����
int timeInterval; // ��������� ��������
bool resolutionForResize; // ���������� ��� �������� ������� ��������� ������� �����������
bool flagForOnClickPictureBox = false;
myRoi* myCurrentRoi; // ����� ��� �������� ���������� � ROI
bool Drow; // ���������� ��� �������� ���������
int defaultWidth; // ����������� ������ �����
int defaultHeight; // ����������� ������ �����
int resizeWidth; // ��������� ������ �����
int resizeHeight; // ��������� ������ �����
int coefficientWidth; // �� ������� ��� ����� ����������� �� ������
int coefficientHeight; // �� ������� ��� ����� ����������� �� ������
std::vector <int> detectResultsOnFrames; // ���������� ��������� �� ���� ������
std::vector <int> myPersonsResultsOnFrames; // ���������� ������ FramePersons �� ���� ������
std::vector <int> resultForRoiOne;
std::vector <int> resultForRoiTwo;
std::vector <int> resultForRoiThree;
std::vector <int> resultForRoiFour;
std::vector <int> resultForRoiFive;

namespace PerSearch {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected: 
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  radioButton5;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;

	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(13, 13);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1206, 487);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label12);
			this->tabPage1->Controls->Add(this->label11);
			this->tabPage1->Controls->Add(this->label10);
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Controls->Add(this->button6);
			this->tabPage1->Controls->Add(this->button7);
			this->tabPage1->Controls->Add(this->button5);
			this->tabPage1->Controls->Add(this->button4);
			this->tabPage1->Controls->Add(this->textBox5);
			this->tabPage1->Controls->Add(this->textBox6);
			this->tabPage1->Controls->Add(this->textBox4);
			this->tabPage1->Controls->Add(this->label9);
			this->tabPage1->Controls->Add(this->label8);
			this->tabPage1->Controls->Add(this->textBox3);
			this->tabPage1->Controls->Add(this->label7);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->pictureBox1);
			this->tabPage1->Controls->Add(this->button3);
			this->tabPage1->Controls->Add(this->textBox2);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->button2);
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1198, 461);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"HOG + SVM";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(12, 183);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(41, 13);
			this->label12->TabIndex = 29;
			this->label12->Text = L"label12";
			this->label12->Visible = false;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(13, 141);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(41, 13);
			this->label11->TabIndex = 28;
			this->label11->Text = L"label11";
			this->label11->Visible = false;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(12, 101);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(41, 13);
			this->label10->TabIndex = 27;
			this->label10->Text = L"label10";
			this->label10->Visible = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton5);
			this->groupBox1->Controls->Add(this->radioButton4);
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Location = System::Drawing::Point(35, 167);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(136, 166);
			this->groupBox1->TabIndex = 25;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"�������� ����������";
			this->groupBox1->Visible = false;
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(6, 128);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(127, 17);
			this->radioButton5->TabIndex = 4;
			this->radioButton5->Text = L"�������� ��������";
			this->radioButton5->UseVisualStyleBackColor = true;
			this->radioButton5->Visible = false;
			this->radioButton5->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton5_CheckedChanged);
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(6, 105);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(78, 17);
			this->radioButton4->TabIndex = 3;
			this->radioButton4->Text = L"1280 � 960";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->Visible = false;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton4_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(6, 82);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(72, 17);
			this->radioButton3->TabIndex = 2;
			this->radioButton3->Text = L"960 � 720";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->Visible = false;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton3_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(6, 59);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(72, 17);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->Text = L"640 � 480";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->Visible = false;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton2_CheckedChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(6, 36);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(72, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->Text = L"320 x 240";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->Visible = false;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_CheckedChanged);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(15, 339);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(176, 26);
			this->button6->TabIndex = 24;
			this->button6->Text = L"�������";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Visible = false;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(16, 339);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(175, 26);
			this->button7->TabIndex = 26;
			this->button7->Text = L"button7";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Visible = false;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(60, 309);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(85, 23);
			this->button5->TabIndex = 23;
			this->button5->Text = L"���������";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Visible = false;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(15, 309);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(176, 23);
			this->button4->TabIndex = 22;
			this->button4->Text = L"����������";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(15, 283);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(85, 20);
			this->textBox5->TabIndex = 20;
			this->textBox5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox5->Visible = false;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(106, 283);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(85, 20);
			this->textBox6->TabIndex = 21;
			this->textBox6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox6->Visible = false;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(106, 244);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(85, 20);
			this->textBox4->TabIndex = 19;
			this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox4->Visible = false;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(12, 267);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(116, 13);
			this->label9->TabIndex = 18;
			this->label9->Text = L"������ ������ ����:";
			this->label9->Visible = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(12, 228);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(112, 13);
			this->label8->TabIndex = 17;
			this->label8->Text = L"������� ����� ����:";
			this->label8->Visible = false;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(15, 244);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(85, 20);
			this->textBox3->TabIndex = 16;
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox3->Visible = false;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 215);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(35, 13);
			this->label7->TabIndex = 15;
			this->label7->Text = L"label7";
			this->label7->Visible = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 188);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(212, 13);
			this->label6->TabIndex = 14;
			this->label6->Text = L"���������� ��������� ���������� ROI";
			this->label6->Visible = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(230, 141);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(320, 240);
			this->pictureBox1->TabIndex = 13;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseUp);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(122, 141);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(89, 20);
			this->button3->TabIndex = 12;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(15, 141);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 11;
			this->textBox2->Text = L"1";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox2->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 124);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(199, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"���������� ������� ���������� ROI";
			this->label5->Visible = false;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(15, 91);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 9;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(15, 65);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 8;
			this->textBox1->Text = L"2";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 49);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"label4";
			this->label4->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 22);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(78, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"������ ����:";
			this->label3->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(96, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(10, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L" ";
			this->label2->Visible = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(239, 17);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(128, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"������� ����";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(221, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"���������� ������� ����������� ����:";
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1198, 461);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"tabPage2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1231, 512);
			this->Controls->Add(this->tabControl1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"PerSearch";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	// ����� ��������� �����
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 filesDir = converSystemStringToStdString(checkAndCreateDirectory(System::IO::Directory::GetCurrentDirectory()));
			 }
	// ��������� ������� ������ "�������� ����"
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				// �������� ���� ������� � ����������� ������ ����� ������ Avi � Mov
				OpenFileDialog^ open_dialog = gcnew OpenFileDialog();
				open_dialog->Title = "����� ������������ �����";
				open_dialog->Filter = "All files (*.*)|*.*|Video Files(*.AVI)|*.AVI|Mov Files(*.MOV)|*.MOV";
				open_dialog->InitialDirectory = "//";
					try {
						if (open_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
							// ��������������� system string � std string ��� ��������� � openCV � ������� ��� ��������� � label2
							loadFileName = converSystemStringToStdString(open_dialog->FileName);
							System::String^ myString = convertStdStringToSystemString(loadFileName);
							// ����� ���� ��� ������� ���� ���������� ������� �������� ���������� ��������
							// ������ ���� : ����
							label2->Text = myString;
							label2->Visible = true;
							label3->Visible = true;
							button1->Visible = false;
							label1->Visible = false;
							// �������� ����� ��������� ������� - ����������
							label4->Visible = true;
							textBox1->Visible = true;
							button2->Visible = true;
							label4->Text = "������� �������� ������� t";
							button2->Text = "�������";
							// �������� "�������� ����" ���������� ������
							label1->Visible = false;
							button1->Visible = false;

							delete (myString);
						}
					else throw 123;  // ���� ������ ��������
					} catch(int inspect) {
						if ( inspect == 123 )
							MessageBox::Show("������ ��� ������ �����");
					}
			 }
	// ��������� ������� ������ "������� �������� �������"
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			try 
			 {
				timeInterval=Int32::Parse(textBox1->Text);
				if ( timeInterval == 0 ) throw 0;
				if ( timeInterval < 0 ) throw -1;

				// �������� ����� ��������� ������� - ������
				label4->Text = "�������� ������� = " + timeInterval;
				button2->Visible=false;
				textBox1->Visible=false;

				// �������� ����� ���������� ROI - ����������
				label5->Visible=true;
				textBox2->Visible=true;
				button3->Visible=true;
				button3->Text = "�������";

				// �������� 1 ���� �����, ��������� ��� � jpg � ������� � PictureBox1
				cv::VideoCapture video;
				video.open(loadFileName);
				cv::Mat imag;
				video >> imag;

				defaultWidth = imag.size().width;
				defaultHeight = imag.size().height;

				if ( imag.size().width != 320 && imag.size().height != 240 ) {
					coefficientWidth = imag.size().width/320;
					coefficientHeight = imag.size().height/240;
					cv::resize(imag,imag,cv::Size(320,240),0,0,1);
				}
				else {
					coefficientWidth = 1;
					coefficientHeight = 1;
				}
				
				cv::imwrite( filesDir+"SavedParams\\firstframe.jpg", imag);
				pictureBox1->Image=Image::FromFile( convertStdStringToSystemString( filesDir+"SavedParams\\firstframe.jpg" ));
				pictureBox1->Visible = true;
				video.~VideoCapture();
				imag.~Mat();
			 }
			 catch ( int inspect )
			 {
				 if ( inspect == 0 )
					MessageBox::Show("������ �������� ��������� �������. �� ����� ���� ����� = " + inspect);
				 if ( inspect == -1 )
					MessageBox::Show("������ �������� ��������� �������. �� ����� ���� ������������� ");
			 }
			 catch (FormatException^ e) 
			 {
				 MessageBox::Show("������ �������! "+ e->Message);
			 }
			 catch (OverflowException^ e) 
			 {
				 MessageBox::Show("������ �������! "+ e->Message);
			 }
	}
	// ��������� ������� ������ "������� ���������� ROI"
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 try 
				 {
					int nRoi = Int32::Parse(textBox2->Text);
					if ( nRoi == 0 ) throw 0;
					if ( nRoi < 0 ) throw -1;
					if ( nRoi > 5 ) throw 3;
					// ������� ������ ��� � ��� ����� ��� ���� ROI � ��������� ��� �� �����
					myCurrentRoi = new myRoi (nRoi);
					myCurrentRoi->fillRoiCoord(filesDir);
					// ������� ���������� 1 ROI �� ����� �� UI
					int* mas;
					mas = myCurrentRoi->getCurrentRoiCoord();
					System::String^ str;
					str = mas[0].ToString();
					textBox3->Text= str;
					str = mas[1].ToString();
					textBox4->Text= str;
					str = mas[2].ToString();
					textBox5->Text= str;
					str = mas[3].ToString();
					textBox6->Text= str;
					// �������� ����� ���������� ROI - ������
					label10->Visible = true;
					label10->Text = "���������� ROI = " + nRoi;
					label5->Visible=false;
					textBox2->Visible=false;
					button3->Visible=false;
					// �������� ����� ��������� ROI - ����������
					label6->Visible = true;
					label7->Visible = true;
					label8->Visible = true;
					label9->Visible = true;
					label7->Text = "ROI #" + (myCurrentRoi->getCurrentNumberRoi()+1);
					textBox3->Visible = true;
					textBox4->Visible = true;
					textBox5->Visible = true;
					textBox6->Visible = true;
					if ( myCurrentRoi->getAmountRoi() == 1 ) {
						button5->Visible = false;
						button4->Visible = true;
						button4->Text = "������� ���������� ROI";
					} else button5->Visible = true;
					// ��������� ���������� ROI �� �����������
					Bitmap ^ myBitmap = gcnew Bitmap(convertStdStringToSystemString(filesDir+"SavedParams\\firstframe.jpg")); 
					Graphics ^ g = Graphics::FromImage(myBitmap); 
					g->DrawRectangle(getPsevdoRandColor(myCurrentRoi->getCurrentNumberRoi()),mas[0],mas[1],(mas[2]-mas[0]),(mas[3]-mas[1]));
					pictureBox1->Image = myBitmap;
					flagForOnClickPictureBox = true;
				 }
				 catch ( int inspect )
				 {
					 if ( inspect == 0 )
						MessageBox::Show("������ �������� ���������� ROI. �� ����� ���� ����� = " + inspect);
					 if ( inspect == -1 )
						MessageBox::Show("������ �������� ���������� ROI. �� ����� ���� ������������� ");
					 if ( inspect == 5 )
						MessageBox::Show("����� ���� �� �����?");
				 }
	}			 
	// ��������� ������� ����� �� pictureBox
	private: System::Void pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 if ( pictureBox1->Visible == true && flagForOnClickPictureBox ) {
					 System::String^ str;
					 Drow = true;
					 int mas[4];
					 mas[0] = e->X;
					 mas[1] = e->Y;
					 mas[2] = -1;
					 mas[3] = -1;
					 myCurrentRoi->fillCurrentRoi(mas); 
					 str = mas[0].ToString();
					 textBox3->Text= str;
					 str = mas[1].ToString();
					 textBox4->Text= str;
				 }
		 }
	private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 if ( pictureBox1->Visible == true && flagForOnClickPictureBox) {
					 int* mas = myCurrentRoi->getCurrentRoiCoord();
					 Bitmap ^ myBitmap = gcnew Bitmap(convertStdStringToSystemString(filesDir+"SavedParams\\firstframe.jpg")); 
					 Graphics ^ g = Graphics::FromImage(myBitmap); 
					 if ( Drow ) {
						 g->DrawRectangle(getPsevdoRandColor(myCurrentRoi->getCurrentNumberRoi()), mas[0], mas[1], (e->X)-mas[0], (e->Y)-mas[1]);
						 pictureBox1->Image = myBitmap;
					 }
				 }
		 }
	private: System::Void pictureBox1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 if ( pictureBox1->Visible == true && flagForOnClickPictureBox ) {
					 Drow = false;
					 System::String^ str;
					 int mas[4];
					 mas[0] = -1;
					 mas[1] = -1;
					 mas[2] = e->X;
					 mas[3] = e->Y;
					 myCurrentRoi->fillCurrentRoi(mas); 
					 str = mas[2].ToString();
					 textBox5->Text= str;
					 str = mas[3].ToString();
					 textBox6->Text= str;
				 }
		 }
	// ��������� ����� ��������� ��������� ROI
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
				 // �������� �� ���� ����������
				 int mas[4];
				 try 
				 {
						mas[0] = Convert::ToInt32(textBox3->Text);
						mas[1] = Convert::ToInt32(textBox4->Text);
						mas[2] = Convert::ToInt32(textBox5->Text);
						mas[3] = Convert::ToInt32(textBox6->Text);
						if ( mas[0] < 0 || mas[1] < 0 || mas[2] < 0 || mas[3] < 0 ) throw -1;
						if ( mas[0] == mas[2] && mas[1] == mas[3] ) throw 1;
						if ( mas[0] > mas[2] || mas[1] > mas[3] ) throw 2;
						if ( mas[0] > 320 || mas[2] > 320 || mas[1] > 240 || mas[3] > 240 ) throw 3;
						myCurrentRoi->fillCurrentRoi(mas);
						// ��� ROI ���������
						std::ofstream fout(filesDir + "\\SavedParams\\ROI_coordinates.txt"); // ������� ����� � ��������� ��� � �����. �������� ���.
						Bitmap ^ myBitmap = gcnew Bitmap(convertStdStringToSystemString(filesDir+"SavedParams\\firstframe.jpg")); 
						Graphics ^ g = Graphics::FromImage(myBitmap); 
						for (int i = 0; i < myCurrentRoi->getAmountRoi(); i++) {
							myCurrentRoi->setRoi(i);
							int* nextMas = myCurrentRoi->getCurrentRoiCoord();
							g->DrawRectangle(getPsevdoRandColor(myCurrentRoi->getCurrentNumberRoi()),nextMas[0],nextMas[1],(nextMas[2]-nextMas[0]),(nextMas[3]-nextMas[1]));
							fout << nextMas[0] << std::endl;
							fout << nextMas[1] << std::endl;
							fout << nextMas[2] << std::endl;
							fout << nextMas[3] << std::endl;
						}
						pictureBox1->Image = myBitmap;
						fout.close();
						flagForOnClickPictureBox = false;
						// ������ ������ ������� ROI � ��������� �������� ������ ����������
						button4->Visible = false;
						radioButton1->Visible = true;
						radioButton2->Visible = true;
						radioButton3->Visible = true;
						radioButton4->Visible = true;
						radioButton5->Visible = true;
						groupBox1->Visible = true;
						// ������ �������� ������ ��������� ROI
						label11->Visible = true;
						label11->Text = "���������� ROI �������.";
						label6->Visible = false;
						label7->Visible = false;
						label8->Visible = false;
						label9->Visible = false;
						textBox3->Visible = false;
						textBox4->Visible = false;
						textBox5->Visible = false;
						textBox6->Visible = false;

				 }
				 catch ( int inspect )
				 {
					 //button4->Visible=false;
					 if ( inspect == -1 )
						 MessageBox::Show("������ ���������� ����� ROI �� ����� ��������������!");
					 if ( inspect == 1 )
						MessageBox::Show("������ ���������� ����� ROI �� ����� ���� �����!");
					 if ( inspect == 2 )
						MessageBox::Show("������ ���������� ������ �������� ���� �� ����� ���� ������ ��������� ������� �������!");
					 if ( inspect == 3 )
						MessageBox::Show("������ ���������� ������� �� ����� ���������� ����������!");
				 }
				 catch (FormatException^ e) 
				 {
					 MessageBox::Show("������ �������! "+ e->Message);
				 }
				 catch (OverflowException^ e) 
				 {
					 MessageBox::Show("������ �������! "+ e->Message);
				 }
		 }
	// ��������� ����� ��������� ROI ���� ����� ���������
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
				int mas[4];
				bool lastRoi = myCurrentRoi->getCurrentNumberRoi() == (myCurrentRoi->getAmountRoi() -1);
				Bitmap ^ myBitmap = gcnew Bitmap(convertStdStringToSystemString(filesDir+"SavedParams\\firstframe.jpg")); 
				Graphics ^ g = Graphics::FromImage(myBitmap); 
				try 
				{
					
						mas[0] = Convert::ToInt32(textBox3->Text);
						mas[1] = Convert::ToInt32(textBox4->Text);
						mas[2] = Convert::ToInt32(textBox5->Text);
						mas[3] = Convert::ToInt32(textBox6->Text);
						if ( mas[0] < 0 || mas[1] < 0 || mas[2] < 0 || mas[3] < 0 ) throw -1;
						if ( mas[0] == mas[2] && mas[1] == mas[3] ) throw 1;
						if ( mas[0] > mas[2] || mas[1] > mas[3] ) throw 2;
						if ( mas[0] > 320 || mas[2] > 320 || mas[1] > 240 || mas[3] > 240 ) throw 3;
						myCurrentRoi->fillCurrentRoi(mas);
						myCurrentRoi->nextRoi();
						// ���������
						if ( myCurrentRoi->getCurrentNumberRoi() < myCurrentRoi->getAmountRoi() && !lastRoi ) {
							int* nextMas = myCurrentRoi->getCurrentRoiCoord();
							System::String^ str;
							str = nextMas[0].ToString();
							textBox3->Text= str;
							str = nextMas[1].ToString();
							textBox4->Text= str;
							str = nextMas[2].ToString();
							textBox5->Text= str;
							str = nextMas[3].ToString();
							textBox6->Text= str;
							label7->Text = "ROI #" + (myCurrentRoi->getCurrentNumberRoi()+1); 
							g->DrawRectangle(getPsevdoRandColor(myCurrentRoi->getCurrentNumberRoi()),nextMas[0],nextMas[1],(nextMas[2]-nextMas[0]),(nextMas[3]-nextMas[1]));
							if ( myCurrentRoi->getCurrentNumberRoi() == (myCurrentRoi->getAmountRoi() -1)) 
								lastRoi = true;
						} 
						if ( lastRoi ) {
							button5->Visible = false;
							button4->Visible = true;
							button4->Text = "���������� ��������� ������";
						}
						pictureBox1->Image = myBitmap;
				 }
				catch ( int inspect )
				 {
					 //button4->Visible=false;
					 if ( inspect == -1 )
						 MessageBox::Show("������ ���������� ����� ROI �� ����� ��������������!");
					 if ( inspect == 1 )
						MessageBox::Show("������ ���������� ����� ROI �� ����� ���� �����!");
					 if ( inspect == 2 )
						MessageBox::Show("������ ���������� ������ �������� ���� �� ����� ���� ������ ��������� ������� �������!");
					 if ( inspect == 3 )
						MessageBox::Show("������ ���������� ������� �� ����� ���������� ����������!");
				 }
				 catch (FormatException^ e) 
				 {
					 MessageBox::Show("������ �������! "+ e->Message);
				 }
				 catch (OverflowException^ e) 
				 {
					 MessageBox::Show("������ �������! "+ e->Message);
				 }
		 }
	// �������� ������ "������� ��������� ����������"
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
				 groupBox1->Visible = false;
				 radioButton1->Visible = false;
				 radioButton2->Visible = false;
				 radioButton3->Visible = false;
				 radioButton4->Visible = false;
				 radioButton5->Visible = false;
				 button7->Visible = true;
				 button7->Text = "������ ������ �����������";
				 button6->Visible = false;
				 label12->Visible = true;
				 label12->Text = "�������� ����������: " + resizeWidth + " x " + resizeHeight;
	}
	// ��������� radioButton's
	private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if ( radioButton1->Checked ) {
				 resolutionForResize = true;
				 resizeWidth = 320;
				 resizeHeight = 240;
				 button6->Visible = true;
			 }
		 }
	private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if ( radioButton2->Checked ) {
				 resolutionForResize = true;
				 resizeWidth = 640;
				 resizeHeight = 480;
				 button6->Visible = true;
			 }
		 }
	private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if ( radioButton3->Checked ) {
				 resolutionForResize = true;
				 resizeWidth = 960;
				 resizeHeight = 720;
				 button6->Visible = true;
			 }
		 }
	private: System::Void radioButton4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if ( radioButton4->Checked ) {
				 resolutionForResize = true;
				 resizeWidth = 1280;
				 resizeHeight = 960;
				 button6->Visible = true;
			 }
		 }
	private: System::Void radioButton5_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if ( radioButton5->Checked ) {
				 resolutionForResize = false;
				 resizeWidth = defaultWidth;
				 resizeHeight = defaultHeight;
				 button6->Visible = true;
			 }
		 }
		 // ��������� ������� ������ "������ ������"
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
				 cv::VideoCapture video;// ���������� ��� �������� ������ �����
				 video.open(loadFileName); // ����� �����
				 cv::HOGDescriptor HGDES; // ��� ����������
				 cv::Mat imag; // ���������� ��� �������� �����
				 HGDES.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector()); // ��� ��� ���������� � ��� ���������������
				 // ����
				 cv::namedWindow("����������� ���������", CV_WINDOW_AUTOSIZE); // ���� ��� ������ ����� � ���������� ���������
				 cv::namedWindow("Background", CV_WINDOW_AUTOSIZE);
				 cv::namedWindow("Updated scene", CV_WINDOW_AUTOSIZE);
				 cv::namedWindow("MyCheckWindow", CV_WINDOW_AUTOSIZE);
				 // �����
				 int fontFace = CV_FONT_HERSHEY_COMPLEX_SMALL; //����� �����
				 double fontScale = 2; //2
				 int thickness = 2;  //2
				 // ���������� ��� �����
				 cv::Ptr<cv::BackgroundSubtractor> pMOG;
				 pMOG= new cv::BackgroundSubtractorMOG();
				 cv::Mat fgMaskMOG;
				 cv::Mat foregroundImg;
				 cv::Mat kernel = (cv::Mat_<double>(3,3) << 1,1,1,1,1,1,1,1,1);	
				 // �������� ROI � ����������� ���������
				 myCurrentRoi->resizeForVideo( resizeWidth / 320 );
				 // ���-�� ������
				 int counter = -1;
				 //
				 // ���������� � filesDir �������� ������� �����_����_�����
				 filesDir += "DetectResults\\";
				 char buffer[80];
				 time_t seconds = time(NULL);
				 tm* timeinfo = localtime(&seconds);
				 char* format = "%A %B %d %Y %H.%M.%S";
				 std::strftime(buffer, 80, format, timeinfo);
				 filesDir += buffer;
				 System::IO::Directory::CreateDirectory(convertStdStringToSystemString(filesDir));
				 //
				 std::ofstream fout(filesDir+"\\Detectors_Results.txt");
				 fout << "Analyzed file:	" << loadFileName << "\n";
				 fout << "Width frame: " << resizeWidth << "\n";
				 fout << "Height frame: " << resizeHeight << "\n";
				 std::ofstream checkout(filesDir+"\\Persons_Search_Results.txt");
				 checkout << "Analyzed file:	" << loadFileName << "\n";
				 checkout << "Width frame: " << resizeWidth << "\n";
				 checkout << "Height frame: " << resizeHeight << "\n";
				 // �������������� ���� ����� ��� ������������ � ������������
				 FramePersons checkPersons (myCurrentRoi);
				 //
				 // ��� �������� ����� ROI �� ���� �����x
				 if ( myCurrentRoi->getAmountRoi() > 1 ) {
					 std::vector <int> resultForRoiOne;
					 std::vector <int> resultForRoiTwo;
				 }
				 if ( myCurrentRoi->getAmountRoi() > 2 ) {
					 std::vector <int> resultForRoiThree;
				 }
				 if ( myCurrentRoi->getAmountRoi() > 3 ) {
					 std::vector <int> resultForRoiFour;
				 }
				 if ( myCurrentRoi->getAmountRoi() > 4 ) {
					 std::vector <int> resultForRoiFive;
				 }
				 //
				 while (true) { // ���� �� ������ ������� ��� ���� ����� ������� ���� ����������
					 video >> imag; // ��������� ����	
					 if (imag.empty()) // ���� �� ������ ������� - ����� �� �����
						break;
					 counter++;
					 fout << "Frame �	" << counter << " ----------------------\n";
					 checkout << "Frame �	" << counter << " ----------------------\n";
					 // �������� ���������� ����� � ����������� ���������
					 if ( resolutionForResize ) cv::resize(imag,imag,cv::Size(resizeWidth,resizeHeight),0,0,1);
					 //
					 // background
					 foregroundImg = cv::Scalar::all(0);
					 pMOG->operator()(imag, fgMaskMOG, 0.005);
					 cv::GaussianBlur(fgMaskMOG, fgMaskMOG, cv::Size(41,41), 10,10);
					 cv::threshold(fgMaskMOG, fgMaskMOG, 10, 255 ,cv::THRESH_BINARY);
					 foregroundImg = cv::Scalar::all(0);				 
					 cv::filter2D(fgMaskMOG, fgMaskMOG, -1, kernel, cvPoint(-1,-1), 0, cv::BORDER_DEFAULT);
					 imag.copyTo(foregroundImg, fgMaskMOG);
					 // HOG 
					 std::vector<cv::Rect> detect, detect_filter; // ������� ��� �������� ���������
					 HGDES.detectMultiScale(foregroundImg, detect, 0, cv::Size(8,8), cv::Size(16,16), 1.05, 2); // ����������� ����� ���� 8 8 32 32
					 // �������� ��������� � ROI 
					 if ( myCurrentRoi->getAmountRoi() > 0 ) resultForRoiOne.push_back(0);
					 if ( myCurrentRoi->getAmountRoi() > 1 ) resultForRoiTwo.push_back(0);
					 if ( myCurrentRoi->getAmountRoi() > 2 ) resultForRoiThree.push_back(0);
					 if ( myCurrentRoi->getAmountRoi() > 3 ) resultForRoiFour.push_back(0);
					 if ( myCurrentRoi->getAmountRoi() > 4 ) resultForRoiFive.push_back(0);
					 //
					 size_t i, j; //��� �������� �� ���������
					 fout << "Object's on frame in detect:	" << detect.size() << "\n";
					 for (i=0; i<detect.size(); i++) 
					 {
						cv::Rect r = detect[i];
						fout << "+Object's �: " << i << "\n";
						fout << " Coordinate: " << r << "\n";
						for (j=0; j<detect.size(); j++) 
							if (j!=i && (r & detect[j]) == r)
								break;
						if (j== detect.size())
							detect_filter.push_back(r); // ��������� � �����
					 }
					 
					 if ( detect.size() != detect_filter.size() ) fout << "				-----rejected------" << "\n";
					 fout << "Object's on frame in detect_filter:	" << detect_filter.size() << "\n";
					 // ��������� ������� ������������ ����
					 cv::Mat myCheckImage;
					 foregroundImg.copyTo(myCheckImage);
					 //
					 for (i=0; i<detect_filter.size(); i++) 
					 {
							//������� ���������
							cv::Rect rec = detect_filter[i];
							fout << "+Object's �: " << i << "\n";
							fout << " Coordinate: " << rec << "\n";
							
							cv::rectangle(foregroundImg, rec.tl(), rec.br(), cv::Scalar(0,255,0), 3); // ������������� ������ ��������� ��������

							//������ ����� � ����
							char buffer[10];
							_i64toa(detect_filter.size(), buffer, 10); // ����������� int64 � char
							cv::Point textOrg(290,30);
							cv::putText(imag, buffer, textOrg, fontFace, fontScale, CV_RGB(0,255,0), thickness,8); // ������� � ���� ���-�� ����� �� �����
						
							cv::circle(foregroundImg,cv::Point((rec.x+rec.width/2),(rec.y+rec.height/2)),5,CV_RGB(205,0,0),-1,8,00); // ����� ������ � ��������� �������
					 }
					 // ������ ����������� ��������� � ������ �������� �� ������ �����
					 detectResultsOnFrames.push_back(detect_filter.size());
					 // MOE
					 checkPersons.checkObjForTrack(detect, myCheckImage, filesDir);
					 checkout << "Object's on frame in myPersons:	" << checkPersons.getCountofPerson() << "\n";
					 for (i = 0; i < checkPersons.getCountofPerson(); i++)
					 {
						 cv::Rect rec = checkPersons.getVector(i);
						 if ( rec.x == -100 && rec.y == -100 ) 
							 continue;
						 // ������ � ����
						 checkout << "+Object's �: " << i << "\n";
						 checkout << " Coordinate: " << rec << "\n";
						 // ������������� ������ ��������� ��������
						 rec.x += cvRound(rec.width*0.1);
						 rec.width = cvRound(rec.width*0.8);
						 rec.y += cvRound(rec.height*0.07);
						 rec.height = cvRound(rec.height*0.8);
						 cv::rectangle(myCheckImage, rec.tl(), rec.br(), cv::Scalar(255,0,0), 3);
						 // �������� �� ������ � ����� ���� ROI
						 for (int i = 0; i < myCurrentRoi->getAmountRoi(); i++) {
							myCurrentRoi->setRoi(i);
							int* nextMas = myCurrentRoi->getCurrentRoiCoord();
							if ( (rec.x+rec.width/2) >= nextMas[0] && (rec.x+rec.width/2) <= nextMas[2] ) {
								if ( (rec.y+rec.height/2) >= nextMas[1] && (rec.y+rec.height/2) <= nextMas[3] ) {
									if ( i == 0 ) resultForRoiOne.back() += 1;
									if ( i == 1 ) resultForRoiTwo.back() += 1;
									if ( i == 2 ) resultForRoiThree.back() += 1;
									if ( i == 3 ) resultForRoiFour.back() += 1;
									if ( i == 4 ) resultForRoiFive.back() += 1;
								}
							}
						 }
						 // ����������
						 for (int j = 0; j < checkPersons.trackCount(i); j++ ) {
							 cv::circle(myCheckImage,checkPersons.getTrackPointofMan(i,j),5,CV_RGB(0,0,205),-1,8,00);
						 }
					 }
					 //
					 myPersonsResultsOnFrames.push_back(checkPersons.getCountofPerson());
					 // ���������� ��� ROI �� �����
					 for (int i = 0; i < myCurrentRoi->getAmountRoi(); i++) {
							myCurrentRoi->setRoi(i);
							int* nextMas = myCurrentRoi->getCurrentRoiCoord();
							cv::rectangle(imag, cv::Point(nextMas[0],nextMas[1]), cv::Point(nextMas[2],nextMas[3]), CV_RGB(myCurrentRoi->getCurrentNumberRoi()*50,0,0), 1);
						}					 
					 //
					 // �������� ���������� ROI � �����
						 if ( myCurrentRoi->getAmountRoi() > 0 ) {
							 std::ofstream foutForRoi(filesDir+"\\ROI1_Results.txt", std::ios_base::app);
							 foutForRoi << "�� ����� � " + std::to_string(counter) + " ����� ROI1 ������ = ";
							 foutForRoi << resultForRoiOne.back() << "\n";
							 foutForRoi.close();
						 }
						 if ( myCurrentRoi->getAmountRoi() > 1 ) {
							 std::ofstream foutForRoi(filesDir+"\\ROI2_Results.txt", std::ios_base::app);
							 foutForRoi << "�� ����� � " + std::to_string(counter) + " ����� ROI2 ������ = ";
							 foutForRoi << resultForRoiTwo.back() << "\n";
							 foutForRoi.close();
						 }
						 if ( myCurrentRoi->getAmountRoi() > 2 ) {
							 std::ofstream foutForRoi(filesDir+"\\ROI3_Results.txt", std::ios_base::app);
							 foutForRoi << "�� ����� � " + std::to_string(counter) + " ����� ROI3 ������ = ";
							 foutForRoi << resultForRoiThree.back() << "\n";
							 foutForRoi.close();
						 }
						 if ( myCurrentRoi->getAmountRoi() > 3 ) {
							 std::ofstream foutForRoi(filesDir+"\\ROI4_Results.txt", std::ios_base::app);
							 foutForRoi << "�� ����� � " + std::to_string(counter) + " ����� ROI4 ������ = ";
							 foutForRoi << resultForRoiFour.back() << "\n";
							 foutForRoi.close();
						 }
						 if ( myCurrentRoi->getAmountRoi() > 4 ) {
							 std::ofstream foutForRoi(filesDir+"\\ROI5_Results.txt", std::ios_base::app);
							 foutForRoi << "�� ����� � " + std::to_string(counter) + " ����� ROI5 ������ = ";
							 foutForRoi << resultForRoiFive.back() << "\n";
							 foutForRoi.close();
						 }
					 //
					 // ���������� �������������� �����������
					 cv::imshow("����������� ���������", imag);
					 cv::imshow("Background", fgMaskMOG);
					 cv::imshow("Updated scene", foregroundImg);
					 cv::imshow("MyCheckWindow", myCheckImage);
					 
					 
					 if (cv::waitKey(1)>=0){
					 	break;
						checkPersons.~FramePersons();
					 }
				 }
				 cvDestroyAllWindows();
				 fout.close();
				 checkout.close();
		 }
};// ���������
}


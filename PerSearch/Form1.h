#pragma once


// Include lib's
#include "myFunction.h"
#include "myRoi.h"
#include <fstream>
#include "FramePersons.h"
#include <ctime>

// Global Obj
std::string filesDir; // Директория с путем к папке Текущая_дир//Files// где лежат все файлы
std::string loadFileName; // Путь к выбранному файлу
std::string savedParams; // путь к сохраненным параметрам
int timeInterval; // Временной интервал
bool resolutionForResize; // Переменная для хранения решения изменения размера изображения
bool flagForOnClickPictureBox = false;
myRoi* myCurrentRoi; // Класс для хранения информации о ROI
bool Drow; // переменная для проверки отрисовки
int defaultWidth; // Изначальная ширина видео
int defaultHeight; // Изначальная высота видео
int resizeWidth; // Выбранная ширина видео
int resizeHeight; // Выбранная высота видео
int coefficientWidth; // Во сколько раз сжали изображение по ширине
int coefficientHeight; // Во сколько раз сжали изображение по высоте
std::vector <int> detectResultsOnFrames; // результаты детектора на всех кадрах
std::vector <int> myPersonsResultsOnFrames; // результаты класса FramePersons на всех кадрах
std::vector <int> resultForRoiOne; // Массив для хранения кол-ва прошедших людей через ROI1 на каждом кадре
std::vector <int> resultForRoiTwo; // Массив для хранения кол-ва прошедших людей через ROI2 на каждом кадре
std::vector <int> resultForRoiThree; // Массив для хранения кол-ва прошедших людей через ROI3 на каждом кадре
std::vector <int> resultForRoiFour; // Массив для хранения кол-ва прошедших людей через ROI4 на каждом кадре
std::vector <int> resultForRoiFive; // Массив для хранения кол-ва прошедших людей через ROI5 на каждом кадре
std::vector <int> intensityDetectResultsOnFrames; // Массив для хранения интенсивности результатов детектора на всех кадрах
std::vector <int> intensityMyPersonsResultsOnFrames; // результаты интенсивности класса FramePersons на всех кадрах
std::vector <int> intensityResultForRoiOne; // Массив для хранения интенсивности прошедших людей через ROI1 на каждом кадре
std::vector <int> intensityResultForRoiTwo; // Массив для хранения интенсивности прошедших людей через ROI2 на каждом кадре
std::vector <int> intensityResultForRoiThree; // Массив для хранения интенсивности прошедших людей через ROI3 на каждом кадре
std::vector <int> intensityResultForRoiFour; // Массив для хранения интенсивности прошедших людей через ROI4 на каждом кадре
std::vector <int> intensityResultForRoiFive; // Массив для хранения интенсивности прошедших людей через ROI5 на каждом кадре
// Переменна для хранения всего кол-ва прошедших подтвержденных людей
int manConfirmedCounter;
// Переменные для хранения кол-ва подтвержденных людей через ROI
int* masManConfirmedCounterForRoi;
// Переменная для выбора точности детектора
int accuracy;
// Функция обработки трэкбара
void myTrackbarAccuracy(int pos) {
	if ( pos == 0 ) accuracy = 4;
	if ( pos == 1 ) accuracy = 6;
	if ( pos == 2 ) accuracy = 8;
	if ( pos == 3 ) accuracy = 12;
	if ( pos == 4 ) accuracy = 16;
	if ( pos == 5 ) accuracy = 24;
	if ( pos == 6 ) accuracy = 32;
	//System::Windows::Forms::MessageBox::Show("Точность" + accuracy);
}
// Переменная для выбора размера ядра сглаживания
int kernelSize;
// Переменная для выбора отступов от ядра сглаживания
int deviationSize;
// Минимальное значение threshold
int minTrashValue;
// Максимальное значение threshold
int maxTrashValue;
// Функция для обработки выбора размера ядра сглаживания
void myTrackbarkernelSize(int pos) {
	if ( !(pos % 2) ) pos--;
	kernelSize = pos;
}
// Функция для обработки выбора отступов от ядра сглаживания
void myTrackbardeviationSize(int pos) {
	deviationSize = pos;
}
// Функция для обработки Минимального значения threshold
void myTrackbarminTrashValue(int pos) {
	minTrashValue = pos;
}
// Функция для обработки Максимального значения threshold
void myTrackbarmaxTrashValue(int pos) {
	maxTrashValue = pos;
}


namespace PerSearch {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
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
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Button^  button16;
	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::Button^  button17;
	private: System::Windows::Forms::Button^  button24;
	private: System::Windows::Forms::Button^  button23;
	private: System::Windows::Forms::Button^  button22;
	private: System::Windows::Forms::Button^  button21;
	private: System::Windows::Forms::Button^  button20;
	private: System::Windows::Forms::Button^  button19;
	private: System::Windows::Forms::Button^  button18;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->BeginInit();
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
			this->tabPage1->Controls->Add(this->button24);
			this->tabPage1->Controls->Add(this->button23);
			this->tabPage1->Controls->Add(this->button22);
			this->tabPage1->Controls->Add(this->button21);
			this->tabPage1->Controls->Add(this->button20);
			this->tabPage1->Controls->Add(this->button19);
			this->tabPage1->Controls->Add(this->button18);
			this->tabPage1->Controls->Add(this->button17);
			this->tabPage1->Controls->Add(this->textBox8);
			this->tabPage1->Controls->Add(this->label14);
			this->tabPage1->Controls->Add(this->textBox7);
			this->tabPage1->Controls->Add(this->chart1);
			this->tabPage1->Controls->Add(this->label13);
			this->tabPage1->Controls->Add(this->button16);
			this->tabPage1->Controls->Add(this->button15);
			this->tabPage1->Controls->Add(this->button14);
			this->tabPage1->Controls->Add(this->button13);
			this->tabPage1->Controls->Add(this->button12);
			this->tabPage1->Controls->Add(this->button11);
			this->tabPage1->Controls->Add(this->button10);
			this->tabPage1->Controls->Add(this->button9);
			this->tabPage1->Controls->Add(this->button8);
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
			// button24
			// 
			this->button24->Location = System::Drawing::Point(889, 394);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(214, 23);
			this->button24->TabIndex = 51;
			this->button24->Text = L"Интенсивность пешеходов в ROI 5";
			this->button24->UseVisualStyleBackColor = true;
			this->button24->Visible = false;
			this->button24->Click += gcnew System::EventHandler(this, &Form1::button24_Click);
			// 
			// button23
			// 
			this->button23->Location = System::Drawing::Point(889, 336);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(214, 23);
			this->button23->TabIndex = 50;
			this->button23->Text = L"Интенсивность пешеходов в ROI 4";
			this->button23->UseVisualStyleBackColor = true;
			this->button23->Visible = false;
			this->button23->Click += gcnew System::EventHandler(this, &Form1::button23_Click);
			// 
			// button22
			// 
			this->button22->Location = System::Drawing::Point(889, 278);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(214, 23);
			this->button22->TabIndex = 49;
			this->button22->Text = L"Интенсивность пешеходов в ROI 3";
			this->button22->UseVisualStyleBackColor = true;
			this->button22->Visible = false;
			this->button22->Click += gcnew System::EventHandler(this, &Form1::button22_Click);
			// 
			// button21
			// 
			this->button21->Location = System::Drawing::Point(889, 220);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(214, 23);
			this->button21->TabIndex = 48;
			this->button21->Text = L"Интенсивность пешеходов в ROI 2";
			this->button21->UseVisualStyleBackColor = true;
			this->button21->Visible = false;
			this->button21->Click += gcnew System::EventHandler(this, &Form1::button21_Click);
			// 
			// button20
			// 
			this->button20->Location = System::Drawing::Point(889, 160);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(214, 23);
			this->button20->TabIndex = 47;
			this->button20->Text = L"Интенсивность пешеходов в ROI 1";
			this->button20->UseVisualStyleBackColor = true;
			this->button20->Visible = false;
			this->button20->Click += gcnew System::EventHandler(this, &Form1::button20_Click);
			// 
			// button19
			// 
			this->button19->Location = System::Drawing::Point(589, 231);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(278, 35);
			this->button19->TabIndex = 46;
			this->button19->Text = L"Показать интенсивность на результатах работы класса FramePersons";
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Visible = false;
			this->button19->Click += gcnew System::EventHandler(this, &Form1::button19_Click);
			// 
			// button18
			// 
			this->button18->Location = System::Drawing::Point(589, 162);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(278, 34);
			this->button18->TabIndex = 45;
			this->button18->Text = L"Показать интенсивность на результатах работы детектора";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Visible = false;
			this->button18->Click += gcnew System::EventHandler(this, &Form1::button18_Click);
			// 
			// button17
			// 
			this->button17->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button17.Image")));
			this->button17->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button17->Location = System::Drawing::Point(273, 404);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(208, 35);
			this->button17->TabIndex = 44;
			this->button17->Text = L"      Перезапустить приложение";
			this->button17->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Visible = false;
			this->button17->Click += gcnew System::EventHandler(this, &Form1::button17_Click);
			// 
			// textBox8
			// 
			this->textBox8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox8->Location = System::Drawing::Point(592, 33);
			this->textBox8->Multiline = true;
			this->textBox8->Name = L"textBox8";
			this->textBox8->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox8->Size = System::Drawing::Size(590, 399);
			this->textBox8->TabIndex = 43;
			this->textBox8->Visible = false;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(589, 17);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(41, 13);
			this->label14->TabIndex = 42;
			this->label14->Text = L"label14";
			this->label14->Visible = false;
			// 
			// textBox7
			// 
			this->textBox7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox7->Location = System::Drawing::Point(592, 251);
			this->textBox7->Multiline = true;
			this->textBox7->Name = L"textBox7";
			this->textBox7->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox7->Size = System::Drawing::Size(590, 178);
			this->textBox7->TabIndex = 41;
			this->textBox7->Visible = false;
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(592, 33);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(593, 215);
			this->chart1->TabIndex = 40;
			this->chart1->Text = L"chart1";
			this->chart1->Visible = false;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(586, 91);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(134, 13);
			this->label13->TabIndex = 39;
			this->label13->Text = L"Полученные результаты:";
			this->label13->Visible = false;
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(592, 435);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(75, 23);
			this->button16->TabIndex = 38;
			this->button16->Text = L"Назад";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Visible = false;
			this->button16->Click += gcnew System::EventHandler(this, &Form1::button16_Click);
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(589, 272);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(278, 38);
			this->button15->TabIndex = 37;
			this->button15->Text = L"Показать файл с найденными объектами и траекториями";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Visible = false;
			this->button15->Click += gcnew System::EventHandler(this, &Form1::button15_Click);
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(889, 365);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(214, 23);
			this->button14->TabIndex = 36;
			this->button14->Text = L"Показать результаты захода в ROI 5";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Visible = false;
			this->button14->Click += gcnew System::EventHandler(this, &Form1::button14_Click);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(889, 307);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(214, 23);
			this->button13->TabIndex = 35;
			this->button13->Text = L"Показать результаты захода в ROI 4";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Visible = false;
			this->button13->Click += gcnew System::EventHandler(this, &Form1::button13_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(889, 249);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(214, 23);
			this->button12->TabIndex = 34;
			this->button12->Text = L"Показать результаты захода в ROI 3";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Visible = false;
			this->button12->Click += gcnew System::EventHandler(this, &Form1::button12_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(889, 191);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(214, 23);
			this->button11->TabIndex = 33;
			this->button11->Text = L"Показать результаты захода в ROI 2";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Visible = false;
			this->button11->Click += gcnew System::EventHandler(this, &Form1::button11_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(889, 131);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(214, 23);
			this->button10->TabIndex = 32;
			this->button10->Text = L"Показать результаты захода в ROI 1";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Visible = false;
			this->button10->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(589, 202);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(278, 23);
			this->button9->TabIndex = 31;
			this->button9->Text = L"Показать результат работы класса FramePersons";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Visible = false;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(589, 133);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(278, 23);
			this->button8->TabIndex = 30;
			this->button8->Text = L"Показать результат работы детектора";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Visible = false;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
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
			this->groupBox1->Text = L"Изменить разрешение";
			this->groupBox1->Visible = false;
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(6, 128);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(127, 17);
			this->radioButton5->TabIndex = 4;
			this->radioButton5->Text = L"Оставить исходным";
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
			this->radioButton4->Text = L"1280 х 960";
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
			this->radioButton3->Text = L"960 х 720";
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
			this->radioButton2->Text = L"640 х 480";
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
			this->button6->Text = L"Принять";
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
			this->button5->Text = L"Следующая";
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
			this->button4->Text = L"Предыдущая";
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
			this->label9->Text = L"Нижний правый угол:";
			this->label9->Visible = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(12, 228);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(112, 13);
			this->label8->TabIndex = 17;
			this->label8->Text = L"Верхний левый угол:";
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
			this->label6->Text = L"Необходимо заполнить координаты ROI";
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
			this->label5->Text = L"Необходимо выбрать количество ROI";
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
			this->label3->Text = L"Выбран файл:";
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
			this->button1->Text = L"Выбрать файл";
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
			this->label1->Text = L"Необходимо выбрать загружаемый файл:";
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	// Перед загрузкой формы
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 filesDir = converSystemStringToStdString(checkAndCreateDirectory(System::IO::Directory::GetCurrentDirectory()));
			 }
	// Обработка нажатия кнопки "Выберите файл"
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				// Загрузка файл диалога с параметрами Только видео Только Avi и Mov
				OpenFileDialog^ open_dialog = gcnew OpenFileDialog();
				open_dialog->Title = "Выбор загружаемого видео";
				open_dialog->Filter = "All files (*.*)|*.*|Video Files(*.AVI)|*.AVI|Mov Files(*.MOV)|*.MOV";
				open_dialog->InitialDirectory = "//";
					try {
						if (open_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
							// Перекодирование system string в std string для подгрузки в openCV и обратно для подгрузки в label2
							loadFileName = converSystemStringToStdString(open_dialog->FileName);
							System::String^ myString = convertStdStringToSystemString(loadFileName);
							// После того как выбрали файл необходимо сделать видимыми дальнейшие действия
							// Выбран файл : путь
							label2->Text = myString;
							label2->Visible = true;
							label3->Visible = true;
							button1->Visible = false;
							label1->Visible = false;
							// Элементы ввода интервала времени - отобразить
							label4->Visible = true;
							textBox1->Visible = true;
							button2->Visible = true;
							label4->Text = "Введите интервал времени t";
							button2->Text = "Принять";
							// Элементы "Выберите файл" необходимо скрыть
							label1->Visible = false;
							button1->Visible = false;
							// Рестарт кнопка
							button17->Visible = true;

							delete (myString);
						}
					else throw 123;  // Если нажали отменить
					} catch(int inspect) {
						if ( inspect == 123 )
							MessageBox::Show("Ошибка при выборе файла");
					}
			 }
	// Обработка нажатия кнопки "Считать интервал времени"
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			try 
			 {
				timeInterval=Int32::Parse(textBox1->Text);
				if ( timeInterval == 0 ) throw 0;
				if ( timeInterval < 0 ) throw -1;

				// Элементы ввода интервала времени - скрыть
				label4->Text = "Интервал времени = " + timeInterval + " секунд";
				button2->Visible=false;
				textBox1->Visible=false;

				// Элементы ввода количества ROI - отобразить
				label5->Visible=true;
				textBox2->Visible=true;
				button3->Visible=true;
				button3->Text = "Принять";

				// Получаем 1 кадр видео, сохраняем его в jpg и выводим в PictureBox1
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
				savedParams = filesDir+"SavedParams\\";
				pictureBox1->Image=Image::FromFile( convertStdStringToSystemString( filesDir+"SavedParams\\firstframe.jpg" ));
				pictureBox1->Visible = true;
				video.~VideoCapture();
				imag.~Mat();
			 }
			 catch ( int inspect )
			 {
				 if ( inspect == 0 )
					MessageBox::Show("Ошибка значения интервала времени. Не может быть равен = " + inspect);
				 if ( inspect == -1 )
					MessageBox::Show("Ошибка значения интервала времени. Не может быть отрицательным ");
			 }
			 catch (FormatException^ e) 
			 {
				 MessageBox::Show("Ошибка формата! "+ e->Message);
			 }
			 catch (OverflowException^ e) 
			 {
				 MessageBox::Show("Ошибка формата! "+ e->Message);
			 }
	}
	// Обработка нажатия кнопки "Считать количество ROI"
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 try 
				 {
					int nRoi = Int32::Parse(textBox2->Text);
					if ( nRoi == 0 ) throw 0;
					if ( nRoi < 0 ) throw -1;
					if ( nRoi > 5 ) throw 3;
					// Создаем объект где у нас будут все наши ROI и заполняем его из файла
					myCurrentRoi = new myRoi (nRoi);
					myCurrentRoi->fillRoiCoord(filesDir);
					// Выведем координаты 1 ROI из файла на UI
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
					// Элементы ввода количества ROI - скрыть
					label10->Visible = true;
					label10->Text = "Количество ROI = " + nRoi;
					label5->Visible=false;
					textBox2->Visible=false;
					button3->Visible=false;
					// Элементы ввода координат ROI - отобразить
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
						button4->Text = "Принять координаты ROI";
					} else button5->Visible = true;
					// Отобразим полученную ROI на координатах
					Bitmap ^ myBitmap = gcnew Bitmap(convertStdStringToSystemString(filesDir+"SavedParams\\firstframe.jpg")); 
					Graphics ^ g = Graphics::FromImage(myBitmap); 
					g->DrawRectangle(getPsevdoRandColor(myCurrentRoi->getCurrentNumberRoi()),mas[0],mas[1],(mas[2]-mas[0]),(mas[3]-mas[1]));
					pictureBox1->Image = myBitmap;
					flagForOnClickPictureBox = true;
				 }
				 catch ( int inspect )
				 {
					 if ( inspect == 0 )
						MessageBox::Show("Ошибка значения количества ROI. Не может быть равен = " + inspect);
					 if ( inspect == -1 )
						MessageBox::Show("Ошибка значения количества ROI. Не может быть отрицательным ");
					 if ( inspect == 5 )
						MessageBox::Show("Может быть не стоит?");
				 }
	}			 
	// Обработка событий мышки на pictureBox
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
	// Обработка ввода последних координат ROI
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
				 // Умножить на коэф координаты
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
						// Все ROI заполнены
						std::ofstream fout(filesDir + "\\SavedParams\\ROI_coordinates.txt"); // создали поток и привязали его к файлу. проверки нет.
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
						// Уберем кнопку принять ROI и отобразим элементы выбора разрешения
						button4->Visible = false;
						radioButton1->Visible = true;
						radioButton2->Visible = true;
						radioButton3->Visible = true;
						radioButton4->Visible = true;
						radioButton5->Visible = true;
						groupBox1->Visible = true;
						// Уберем элементы выбора координат ROI
						label11->Visible = true;
						label11->Text = "Координаты ROI введены.";
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
						 MessageBox::Show("Ошибка координаты углов ROI не могут отрицательными!");
					 if ( inspect == 1 )
						MessageBox::Show("Ошибка координаты углов ROI не могут быть равны!");
					 if ( inspect == 2 )
						MessageBox::Show("Ошибка координаты левого верхнего угла не могут быть больше координат нижнего правого!");
					 if ( inspect == 3 )
						MessageBox::Show("Ошибка координаты выходят за рамки разрешения видеофайла!");
				 }
				 catch (FormatException^ e) 
				 {
					 MessageBox::Show("Ошибка формата! "+ e->Message);
				 }
				 catch (OverflowException^ e) 
				 {
					 MessageBox::Show("Ошибка формата! "+ e->Message);
				 }
		 }
	// Обработка ввода координат ROI всех кроме последней
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
						// Следующий
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
							button4->Text = "Отобразить выбранные данные";
						}
						pictureBox1->Image = myBitmap;
				 }
				catch ( int inspect )
				 {
					 //button4->Visible=false;
					 if ( inspect == -1 )
						 MessageBox::Show("Ошибка координаты углов ROI не могут отрицательными!");
					 if ( inspect == 1 )
						MessageBox::Show("Ошибка координаты углов ROI не могут быть равны!");
					 if ( inspect == 2 )
						MessageBox::Show("Ошибка координаты левого верхнего угла не могут быть больше координат нижнего правого!");
					 if ( inspect == 3 )
						MessageBox::Show("Ошибка координаты выходят за рамки разрешения видеофайла!");
				 }
				 catch (FormatException^ e) 
				 {
					 MessageBox::Show("Ошибка формата! "+ e->Message);
				 }
				 catch (OverflowException^ e) 
				 {
					 MessageBox::Show("Ошибка формата! "+ e->Message);
				 }
		 }
	// Обаботка кнопки "Принять изменение разрешения"
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
				 groupBox1->Visible = false;
				 radioButton1->Visible = false;
				 radioButton2->Visible = false;
				 radioButton3->Visible = false;
				 radioButton4->Visible = false;
				 radioButton5->Visible = false;
				 button7->Visible = true;
				 button7->Text = "Начать анализ видеопотока";
				 button6->Visible = false;
				 label12->Visible = true;
				 label12->Text = "Выбранно разрешение: " + resizeWidth + " x " + resizeHeight;
	}
	// Обработка radioButton's
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
	// Обработка нажатия кнопки "Начать анализ"
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
				 cv::VideoCapture video;// переменная для хранения потока видео
				 video.open(loadFileName); // поток видео
				 cv::HOGDescriptor HGDES; // хог дескриптор
				 cv::Mat imag; // переменная для хранения кадра
				 HGDES.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector()); // сам хог дескриптор с свм классификатором
				 // Окна
				 cv::namedWindow("Распознание пешеходов", CV_WINDOW_AUTOSIZE); // окно для вывода кадра с найденными объектами
				 cv::namedWindow("Background", CV_WINDOW_AUTOSIZE);
				 cv::namedWindow("Updated scene", CV_WINDOW_AUTOSIZE);
				 cv::namedWindow("MyCheckWindow", CV_WINDOW_AUTOSIZE);
				 cv::namedWindow("Intensity", CV_WINDOW_AUTOSIZE);
				 // TrackBar
				 // Точность детектора
				 cvCreateTrackbar("Accuracy", "Updated scene", &accuracy, 6, myTrackbarAccuracy);
				 cvSetTrackbarPos("Accuracy", "Updated scene", 2);
				 accuracy = 8;
				 // Размер ядра для сглаживания
				 cvCreateTrackbar("Kernel", "Background", &kernelSize, 101, myTrackbarkernelSize);
				 cvSetTrackbarPos("Kernel", "Background", 41);
				 kernelSize = 41;
				 // Отступ от ядра для сглаживания
				 cvCreateTrackbar("Deviation", "Background", &deviationSize, 20, myTrackbardeviationSize);
				 cvSetTrackbarPos("Deviation", "Background", 10);
				 deviationSize = 10;
				 // Мин порог threshold
				 cvCreateTrackbar("Minthresh", "Background", &minTrashValue, 255, myTrackbarminTrashValue);
				 cvSetTrackbarPos("Minthresh", "Background", 10);
				 minTrashValue = 10;
				 // Макс порог threshold
				 cvCreateTrackbar("Maxthresh", "Background", &maxTrashValue, 255, myTrackbarmaxTrashValue);
				 cvSetTrackbarPos("Maxthresh", "Background", 255);
				 maxTrashValue = 255;
				 // Кисти
				 int fontFace = CV_FONT_HERSHEY_COMPLEX_SMALL; //стиль фонта
				 double fontScale = 2; //2
				 int thickness = 2;  //2
				 // Переменные для сцены
				 cv::Ptr<cv::BackgroundSubtractor> pMOG;
				 pMOG= new cv::BackgroundSubtractorMOG();
				 cv::Mat fgMaskMOG;
				 cv::Mat foregroundImg;
				 cv::Mat kernel = (cv::Mat_<double>(3,3) << 1,1,1,1,1,1,1,1,1);	
				 // Привести ROI к соотносимым значениям
				 myCurrentRoi->resizeForVideo( resizeWidth / 320 );
				 // Кол-во кадров
				 int counter = -1;
				 //
				 // Необходимо в filesDir добавить текущую Видео_Дата_папку
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
				 // Инициализируем свой класс для отслеживания и трекирования
				 FramePersons checkPersons (myCurrentRoi);
				 //
				 // Интенсивность 
				 cv::Mat Intensityimag, IntensityMap;
				 Intensityimag = cv::imread(savedParams+"firstframe.jpg");
				 if ( resolutionForResize ) cv::resize(Intensityimag,Intensityimag,cv::Size(resizeWidth,resizeHeight),0,0,1);
				 Intensityimag.copyTo(IntensityMap);
				 int scale = 40;
				 int IntensityMask [40][40];
				 for ( int i = 0; i < scale; i ++ ) {
					 for ( int j = 0; j < scale; j++ ) {
						 IntensityMask[i][j] = 0;
					 }
				 }
				 int scaleX = resizeWidth/scale;
				 int scaleY = resizeHeight/scale;
				 int maxIntensity = 0;
				 //
				 while (true) { // пока не нажата клавиша или пока можно считать кадр записываем
					 video >> imag; // считываем кадр	
					 if (imag.empty()) // если не смогли считать - выход из цикла
						break;
					 counter++;
					 fout << "Frame №	" << counter << " ----------------------\n";
					 checkout << "Frame №	" << counter << " ----------------------\n";
					 // Привести разрешение видео к соотносимым значениям
					 if ( resolutionForResize ) cv::resize(imag,imag,cv::Size(resizeWidth,resizeHeight),0,0,1);
					 //
					 // background
					 //cv::imwrite (filesDir+"\\image.jpg", imag);
					 foregroundImg = cv::Scalar::all(0);
					 pMOG->operator()(imag, fgMaskMOG, 0.005);
					 //cv::imwrite (filesDir+"\\fgMaskMog.jpg", fgMaskMOG);
					 cv::GaussianBlur(fgMaskMOG, fgMaskMOG, cv::Size(kernelSize,kernelSize), deviationSize,deviationSize);
					 //cv::imwrite (filesDir+"\\fgMaskMog and Gaussian.jpg", fgMaskMOG);
					 cv::threshold(fgMaskMOG, fgMaskMOG, minTrashValue, maxTrashValue ,cv::THRESH_BINARY);
					 //cv::imwrite (filesDir+"\\fgMaskMog and Gaussian and threshold.jpg", fgMaskMOG);
					 foregroundImg = cv::Scalar::all(0);				 
					 cv::filter2D(fgMaskMOG, fgMaskMOG, -1, kernel, cvPoint(-1,-1), 0, cv::BORDER_DEFAULT);
					 imag.copyTo(foregroundImg, fgMaskMOG);
					 //cv::imwrite (filesDir+"\\foreground.jpg", foregroundImg);
					 // HOG 
					 std::vector<cv::Rect> detect, detect_filter; // массивы для хранения найденных
					 HGDES.detectMultiScale(foregroundImg, detect, 0, cv::Size(accuracy,accuracy), cv::Size(16,16), 1.05, 2); // мультискейл поиск было 8 8 32 32
					 // Добавить результат в ROI 
					 if ( myCurrentRoi->getAmountRoi() > 0 ) resultForRoiOne.push_back(0);
					 if ( myCurrentRoi->getAmountRoi() > 1 ) resultForRoiTwo.push_back(0);
					 if ( myCurrentRoi->getAmountRoi() > 2 ) resultForRoiThree.push_back(0);
					 if ( myCurrentRoi->getAmountRoi() > 3 ) resultForRoiFour.push_back(0);
					 if ( myCurrentRoi->getAmountRoi() > 4 ) resultForRoiFive.push_back(0);
					 //
					 size_t i, j; //для пробежки по найденным
					 fout << "Object's on frame in detect:	" << detect.size() << "\n";
					 for (i=0; i<detect.size(); i++) 
					 {
						cv::Rect r = detect[i];
						fout << "+Object's №: " << i << "\n";
						fout << " Coordinate: " << r << "\n";
						for (j=0; j<detect.size(); j++) 
							if (j!=i && (r & detect[j]) == r)
								break;
						if (j== detect.size())
							detect_filter.push_back(r); // добавляем в конец
					 }
					 //
					 if ( detect.size() != detect_filter.size() ) fout << "				-----rejected------" << "\n";
					 fout << "Object's on frame in detect_filter:	" << detect_filter.size() << "\n";
					 // Скопируем текущий обработанный кадр
					 cv::Mat myCheckImage;
					 foregroundImg.copyTo(myCheckImage);
					 //
					 for (i=0; i<detect_filter.size(); i++) 
					 {
							//обводим найденных
							cv::Rect rec = detect_filter[i];
							fout << "+Object's №: " << i << "\n";
							fout << " Coordinate: " << rec << "\n";
							
							cv::rectangle(foregroundImg, rec.tl(), rec.br(), cv::Scalar(0,255,0), 3); // прямоугольник вокруг найденных объектов

							//рисуем число в углу
							char buffer[10];
							_i64toa(detect_filter.size(), buffer, 10); // преобразуем int64 в char
							cv::Point textOrg(290,30);
							cv::putText(imag, buffer, textOrg, fontFace, fontScale, CV_RGB(0,255,0), thickness,8); // надпись в углу кол-во людей на кадре
						
							cv::circle(foregroundImg,cv::Point((rec.x+rec.width/2),(rec.y+rec.height/2)),5,CV_RGB(205,0,0),-1,8,00); // точка центра в найденном объекте
					 }
					 // Для презентации сохраним изобр. обработанное
					// cv::imwrite (filesDir+"\\foregroundImg_After_detect.jpg", foregroundImg);
					 // Запись результатов детектора в вектор итоговый на каждом кадре
					 detectResultsOnFrames.push_back(detect_filter.size());
					 // MOE
					 checkPersons.checkObjForTrack(detect, myCheckImage, filesDir);
					 checkout << "Object's on frame in myPersons:	" << checkPersons.getCountofPerson() << "\n";
					 for (i = 0; i < checkPersons.getCountofPerson(); i++)
					 {
						 cv::Rect rec = checkPersons.getVector(i);
						 if ( rec.x == -100 && rec.y == -100 ) 
							 continue;
						 // Запись в файл
						 checkout << "+Object's №: " << i << "\n";
						 checkout << " Coordinate: " << rec << "\n";
						 // прямоугольник вокруг найденных объектов
						 rec.x += cvRound(rec.width*0.1);
						 rec.width = cvRound(rec.width*0.8);
						 rec.y += cvRound(rec.height*0.07);
						 rec.height = cvRound(rec.height*0.8);
						 cv::rectangle(myCheckImage, rec.tl(), rec.br(), cv::Scalar(255,0,0), 3);
						 // Интенсивность на карте движения
						 cv::circle(Intensityimag,cv::Point((rec.x+rec.width/2),(rec.y+rec.height/2)),3,CV_RGB(255,99,71),-1,8,00);
						 IntensityMask[(rec.x+rec.width/2)/scaleX][(rec.y+rec.height/2)/scaleY] ++;
						 if ( maxIntensity <= IntensityMask[(rec.x+rec.width/2)/scaleX][(rec.y+rec.height/2)/scaleY] ) maxIntensity = IntensityMask[(rec.x+rec.width/2)/scaleX][(rec.y+rec.height/2)/scaleY];
						 //
						 // Попадает ли объект в какую либо ROI
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
						 // Траектория
						 for (int j = 0; j < checkPersons.trackCount(i); j++ ) {
							 cv::circle(myCheckImage,checkPersons.getTrackPointofMan(i,j),3,CV_RGB(0,0,205),-1,8,00);
						 }
					 }
					 // Для презентации
					 //cv::imwrite (filesDir+"\\myClassImage.jpg", myCheckImage);
					 //// Для HOG дескриптора показать как работает
					 //cv::Mat imgrad = cv::imread("C:\\Users\\Medivh\\Desktop\\image.jpg");
					 //imgrad.convertTo(imgrad, CV_32F, 1/255.0);
					 //cv::Mat gx, gy; 
					 //cv::Mat mag, angle; 
					 //Sobel(imgrad, gx, CV_32F, 1, 0, 1);				 
					 //Sobel(imgrad, gy, CV_32F, 0, 1, 1);
					 //cv::imshow("Распознание пешеходов", gx);
					 //cv::waitKey();
					 //cv::imshow("Распознание пешеходов", gy);
					 //cv::waitKey();
					 //cv::cartToPolar(gx, gy, mag, angle, 1); 
					 //cv::imshow("Распознание пешеходов", mag);
					 //cv::waitKey();
					 //cv::imshow("Распознание пешеходов", angle);
					 //cv::waitKey();
					 //cv::imwrite (filesDir+"\\gx.png", gx);
					 //cv::imwrite (filesDir+"\\gy.png", gy);
					 //cv::imwrite (filesDir+"\\imgrad.png", imgrad);
					 //
					 //
					 myPersonsResultsOnFrames.push_back(checkPersons.getCountofPerson());
					 // Отрисовать все ROI на кадре
					 for (int i = 0; i < myCurrentRoi->getAmountRoi(); i++) {
							myCurrentRoi->setRoi(i);
							int* nextMas = myCurrentRoi->getCurrentRoiCoord();
							cv::rectangle(imag, cv::Point(nextMas[0],nextMas[1]), cv::Point(nextMas[2],nextMas[3]), CV_RGB(myCurrentRoi->getCurrentNumberRoi()*50,0,0), 1);
						}					 
					 //
					 // Записать результаты ROI в файлы
						 if ( myCurrentRoi->getAmountRoi() > 0 ) {
							 std::ofstream foutForRoi(filesDir+"\\ROI1_Results.txt", std::ios_base::app);
							 foutForRoi << "На кадре № " + std::to_string(counter) + " через ROI1 прошло = ";
							 foutForRoi << resultForRoiOne.back() << "\n";
							 foutForRoi.close();
						 }
						 if ( myCurrentRoi->getAmountRoi() > 1 ) {
							 std::ofstream foutForRoi(filesDir+"\\ROI2_Results.txt", std::ios_base::app);
							 foutForRoi << "На кадре № " + std::to_string(counter) + " через ROI2 прошло = ";
							 foutForRoi << resultForRoiTwo.back() << "\n";
							 foutForRoi.close();
						 }
						 if ( myCurrentRoi->getAmountRoi() > 2 ) {
							 std::ofstream foutForRoi(filesDir+"\\ROI3_Results.txt", std::ios_base::app);
							 foutForRoi << "На кадре № " + std::to_string(counter) + " через ROI3 прошло = ";
							 foutForRoi << resultForRoiThree.back() << "\n";
							 foutForRoi.close();
						 }
						 if ( myCurrentRoi->getAmountRoi() > 3 ) {
							 std::ofstream foutForRoi(filesDir+"\\ROI4_Results.txt", std::ios_base::app);
							 foutForRoi << "На кадре № " + std::to_string(counter) + " через ROI4 прошло = ";
							 foutForRoi << resultForRoiFour.back() << "\n";
							 foutForRoi.close();
						 }
						 if ( myCurrentRoi->getAmountRoi() > 4 ) {
							 std::ofstream foutForRoi(filesDir+"\\ROI5_Results.txt", std::ios_base::app);
							 foutForRoi << "На кадре № " + std::to_string(counter) + " через ROI5 прошло = ";
							 foutForRoi << resultForRoiFive.back() << "\n";
							 foutForRoi.close();
						 }
					 //
					 // Отобразить результирующие изображения
					 cv::imshow("Распознание пешеходов", imag);
					 cv::imshow("Background", fgMaskMOG);
					 cv::imshow("Updated scene", foregroundImg);
					 cv::imshow("MyCheckWindow", myCheckImage);
					 cv::imshow("Intensity", Intensityimag);
					 //if ( counter > 300 ) cv::waitKey();
					 if (cv::waitKey(1)>=0){
					 	break;
						checkPersons.~FramePersons();
					 }
				 }
				 cvDestroyAllWindows();
				 fout.close();
				 checkout.close();
				 // IntensityMap	
				 cv::namedWindow("IntensityTrack's", CV_WINDOW_AUTOSIZE);
			     cv::imshow("IntensityTrack's", Intensityimag);
				 int startX = 0, startY = 0;
				 for ( int i = 0; i < scale; i++ ) {
					 for ( int j = 0; j < scale; j++ ) {
						 cv::Rect r( startX, startY, scaleX, scaleY );
						 // Вот здесьт важно J и I поменяны местами, сделал руководствуясь что идем сначало по ширине а потом по высоте и снова по ширине. ездим по строчкам а не столбам
						 int red = IntensityMask[j][i] * 255 / maxIntensity;
						 IntensityMap(r) += CV_RGB(red,0,0);
						 startX += scaleX;
					 }
					 startX = 0; 
					 startY += scaleY;
				 }
				 cv::namedWindow("IntensityMap", CV_WINDOW_AUTOSIZE);
			     cv::imshow("IntensityMap", IntensityMap);
				 //
				 // Запишем полученные значения counterов
				 manConfirmedCounter = checkPersons.getManConfirmedCounter();
				 masManConfirmedCounterForRoi = checkPersons.getRoiManConfirmedCounter();
				 //
				 // Вычислим интенсивности пешеходов для всех результатов.
				 // Узнаем кол-во кадров в секунду у выбранного видеофайла
				 CvCapture *capture = cvCreateFileCapture(loadFileName.c_str()); // cсоздаем capture для потока видео
				 int framesPerSecond; //кол-во кадров в видео
				 framesPerSecond = cvGetCaptureProperty(capture, CV_CAP_PROP_FPS); //получем кол-во кадров в загруженном видео
				 delete(capture);
				 // Интенсивность детектора
				 std::ofstream foutForIntensity(filesDir+"\\Intensity_Detectors_Results.txt", std::ios_base::app);
				 for (int i = 0; i < detectResultsOnFrames.size(); i ++ ) {
					 foutForIntensity << "Интервал c " << i << " по ";
					 int countForintensity = 0;
					 int j = 0;
					 for ( j = 0; j < (timeInterval*framesPerSecond) && i < detectResultsOnFrames.size(); j++,i++) {
						 countForintensity += detectResultsOnFrames[i]; 
					 }
					 foutForIntensity << i << " кадр\nИнтенсивность пешеходов = ";
					 countForintensity = ceil(Convert::ToDouble(countForintensity)/j);
					 intensityDetectResultsOnFrames.push_back( countForintensity );
					 foutForIntensity << countForintensity << "\n";
					 countForintensity = 0;
				 }
				 foutForIntensity.close();
				 // Интенсивность класса FramePersons;
				 foutForIntensity.open(filesDir+"\\Intensity_Persons_Search_Results.txt", std::ios_base::app);
				 for (int i = 0; i < myPersonsResultsOnFrames.size(); i ++ ) {
					 foutForIntensity << "Интервал c " << i << " по ";
					 int countForintensity = 0;
					 int j = 0;
					 for ( j = 0; j < (timeInterval*framesPerSecond) && i < myPersonsResultsOnFrames.size(); j++,i++) {
						 countForintensity += myPersonsResultsOnFrames[i]; 
					 }
					 foutForIntensity << i << " кадр\nИнтенсивность пешеходов = ";
					 countForintensity = ceil(Convert::ToDouble(countForintensity)/j);
					 intensityMyPersonsResultsOnFrames.push_back( countForintensity );
					 foutForIntensity << countForintensity << "\n";
					 countForintensity = 0;
				 }
				 foutForIntensity.close();
				 // Интенсивность для ROI1;
				 if ( myCurrentRoi->getAmountRoi() > 0 ) {
					 std::ofstream foutForIntensity(filesDir+"\\Intensity_ROI1_Results.txt", std::ios_base::app);
					 for (int i = 0; i < resultForRoiOne.size(); i ++ ) {
						 foutForIntensity << "Интервал c " << i << " по ";
						 int countForintensity = 0;
						 int j = 0;
						 for ( j = 0; j < (timeInterval*framesPerSecond) && i < resultForRoiOne.size(); j++,i++) {
							 countForintensity += resultForRoiOne[i]; 
						 }
						 foutForIntensity << i << " кадр\nИнтенсивность пешеходов = ";
						 countForintensity = ceil(Convert::ToDouble(countForintensity)/j);
						 intensityResultForRoiOne.push_back( countForintensity );
						 foutForIntensity << countForintensity << "\n";
						 countForintensity = 0;
					 }
					 foutForIntensity.close();
				 }
				 // Интенсивность для ROI2;
				 if ( myCurrentRoi->getAmountRoi() > 1 ) {
					 std::ofstream foutForIntensity(filesDir+"\\Intensity_ROI2_Results.txt", std::ios_base::app);
					 for (int i = 0; i < resultForRoiTwo.size(); i ++ ) {
						 foutForIntensity << "Интервал c " << i << " по ";
						 int countForintensity = 0;
						 int j = 0;
						 for ( j = 0; j < (timeInterval*framesPerSecond) && i < resultForRoiTwo.size(); j++,i++) {
							 countForintensity += resultForRoiTwo[i]; 
						 }
						 foutForIntensity << i << " кадр\nИнтенсивность пешеходов = ";
						 countForintensity = ceil(Convert::ToDouble(countForintensity)/j);
						 intensityResultForRoiTwo.push_back( countForintensity );
						 foutForIntensity << countForintensity << "\n";
						 countForintensity = 0;
					 }
					 foutForIntensity.close();
				 }
				 // Интенсивность для ROI3;
				 if ( myCurrentRoi->getAmountRoi() > 2 ) {
					 std::ofstream foutForIntensity(filesDir+"\\Intensity_ROI3_Results.txt", std::ios_base::app);
					 for (int i = 0; i < resultForRoiThree.size(); i ++ ) {
						 foutForIntensity << "Интервал c " << i << " по ";
						 int countForintensity = 0;
						 int j = 0;
						 for ( j = 0; j < (timeInterval*framesPerSecond) && i < resultForRoiThree.size(); j++,i++) {
							 countForintensity += resultForRoiThree[i]; 
						 }
						 foutForIntensity << i << " кадр\nИнтенсивность пешеходов = ";
						 countForintensity = ceil(Convert::ToDouble(countForintensity)/j);
						 intensityResultForRoiThree.push_back( countForintensity );
						 foutForIntensity << countForintensity << "\n";
						 countForintensity = 0;
					 }
					 foutForIntensity.close();
				 }
				 // Интенсивность для ROI4;
				 if ( myCurrentRoi->getAmountRoi() > 3 ) {
					 std::ofstream foutForIntensity(filesDir+"\\Intensity_ROI4_Results.txt", std::ios_base::app);
					 for (int i = 0; i < resultForRoiFour.size(); i ++ ) {
						 foutForIntensity << "Интервал c " << i << " по ";
						 int countForintensity = 0;
						 int j = 0;
						 for ( j = 0; j < (timeInterval*framesPerSecond) && i < resultForRoiFour.size(); j++,i++) {
							 countForintensity += resultForRoiFour[i]; 
						 }
						 foutForIntensity << i << " кадр\nИнтенсивность пешеходов = ";
						 countForintensity = ceil(Convert::ToDouble(countForintensity)/j);
						 intensityResultForRoiFour.push_back( countForintensity );
						 foutForIntensity << countForintensity << "\n";
						 countForintensity = 0;
					 }
					 foutForIntensity.close();
				 }
				 // Интенсивность для ROI5;
				 if ( myCurrentRoi->getAmountRoi() > 4 ) {
					 std::ofstream foutForIntensity(filesDir+"\\Intensity_ROI5_Results.txt", std::ios_base::app);
					 for (int i = 0; i < resultForRoiFive.size(); i ++ ) {
						 foutForIntensity << "Интервал c " << i << " по ";
						 int countForintensity = 0;
						 int j = 0;
						 for ( j = 0; j < (timeInterval*framesPerSecond) && i < resultForRoiFive.size(); j++,i++) {
							 countForintensity += resultForRoiFive[i]; 
						 }
						 foutForIntensity << i << " кадр\nИнтенсивность пешеходов = ";
						 countForintensity = ceil(Convert::ToDouble(countForintensity)/j);
						 intensityResultForRoiFive.push_back( countForintensity );
						 foutForIntensity << countForintensity << "\n";
						 countForintensity = 0;
					 }
					 foutForIntensity.close();
				 }
				 //
				 resultInterfaceVisibleTrue();
		 }
	// Показать интерфейс результатов
	private: System::Void resultInterfaceVisibleTrue () {
				 label13->Visible = true;
				 button8->Visible = true;
				 button9->Visible = true;
				 button15->Visible = true;
				 button18->Visible = true;
				 button19->Visible = true;
				 if ( myCurrentRoi->getAmountRoi() > 0 ) {
					 button10->Visible = true;
					 button20->Visible = true;
				 }
				 if ( myCurrentRoi->getAmountRoi() > 1 ) {
					 button11->Visible = true;
					 button21->Visible = true;
				 }
				 if ( myCurrentRoi->getAmountRoi() > 2 ) {
					 button12->Visible = true;
					 button22->Visible = true;
				 }
				 if ( myCurrentRoi->getAmountRoi() > 3 ) {
					 button13->Visible = true;
					 button23->Visible = true;
				 }
				 if ( myCurrentRoi->getAmountRoi() > 4 ) {
					 button14->Visible = true;
					 button24->Visible = true;
				 }

				 chart1->Visible = false;
				 textBox7->Visible = false;
				 label14->Visible = false;
				 button16->Visible = false;
				 textBox8->Visible = false;
			 }
	// Скрыть интерфейс результатов
	private: System::Void resultInterfaceVisibleFalse () {
				 label13->Visible = false;
				 button8->Visible = false;
				 button9->Visible = false;
				 button10->Visible = false;
				 button11->Visible = false;
				 button12->Visible = false;
				 button13->Visible = false;
				 button14->Visible = false;
				 button15->Visible = false;
				 button18->Visible = false;
				 button19->Visible = false;
				 button20->Visible = false;
				 button21->Visible = false;
				 button22->Visible = false;
				 button23->Visible = false;
				 button24->Visible = false;
				 button16->Visible = true;
			 }			 
	// Отобразить результаты работы детектора на всех кадрах
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
				 //
				 resultInterfaceVisibleFalse();
				 chart1->Visible = true;
				 textBox7->Visible = true;
				 label14->Visible = true;
				 label14->Text = "Результаты работы детектора";
				 //
				 try 
				 {
					auto MyReader = gcnew IO::StreamReader(convertStdStringToSystemString(filesDir + "\\Detectors_Results.txt"), System::Text::Encoding::GetEncoding(1251)); 
					textBox7->Text= MyReader->ReadToEnd();
					MyReader->Close();
				 } 
				 catch (int inspect ) 
				 { 
					MessageBox::Show("Ошибка при считывании файла");
				 }
				 this->chart1->Series->Clear();
				 this->chart1->Series->Add("Количество людей найденных детектором на каждом кадре");
				 chart1->Series["Количество людей найденных детектором на каждом кадре"]->ChartType=System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
				 chart1->ChartAreas["ChartArea1"]->AxisX->MajorGrid->Enabled = false;
				 chart1->ChartAreas["ChartArea1"]->AxisY->MajorGrid->Enabled = false;
				 for (int i=0; i<detectResultsOnFrames.size(); i++)
				 {
					 this->chart1->Series["Количество людей найденных детектором на каждом кадре"]->Points->AddXY(i,detectResultsOnFrames[i]);
				 }	

			 }
	// Кнопка Назад
	private: System::Void button16_Click(System::Object^  sender, System::EventArgs^  e) {
				 resultInterfaceVisibleTrue();
			 }
	// Отобразить результаты работы класса FramePersons
	private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
				 resultInterfaceVisibleFalse();
				 chart1->Visible = true;
				 textBox7->Visible = true;
				 label14->Visible = true;
				 label14->Text = "Результаты работы класса FramePersons. Всего засчитанно подтвержденных объектов: " + manConfirmedCounter;
				 try 
				 {
					auto MyReader = gcnew IO::StreamReader(convertStdStringToSystemString(filesDir + "\\Persons_Search_Results.txt"), System::Text::Encoding::GetEncoding(1251)); 
					textBox7->Text= MyReader->ReadToEnd();
					MyReader->Close();
				 } 
				 catch (int inspect ) 
				 { 
					MessageBox::Show("Ошибка при считывании файла");
				 }
				 this->chart1->Series->Clear();
				 this->chart1->Series->Add("Количество людей найденных классом FramePersons на каждом кадре");
				 chart1->Series["Количество людей найденных классом FramePersons на каждом кадре"]->ChartType=System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
				 chart1->ChartAreas["ChartArea1"]->AxisX->MajorGrid->Enabled = false;
				 chart1->ChartAreas["ChartArea1"]->AxisY->MajorGrid->Enabled = false;
				 for (int i=0; i<myPersonsResultsOnFrames.size(); i++)
				 {
					 this->chart1->Series["Количество людей найденных классом FramePersons на каждом кадре"]->Points->AddXY(i,myPersonsResultsOnFrames[i]);
 				 }
			 }
	// Отобразить файл с треками
	private: System::Void button15_Click(System::Object^  sender, System::EventArgs^  e) {
				label14->Visible = true;
				label14->Text = "Найденные объекты и их траектории движения. Всего засчитанно подтвержденных объектов: " + manConfirmedCounter;
				resultInterfaceVisibleFalse();
				textBox8->Visible = true;
				try 
				{
					auto MyReader = gcnew IO::StreamReader(convertStdStringToSystemString(filesDir + "\\Mans.txt"), System::Text::Encoding::GetEncoding(1251)); 
					textBox8->Text = MyReader->ReadToEnd();
					MyReader->Close();
				} 
				catch (int inspect ) 
				{ 
					textBox8->Text = "Ошибка при считывании файла";
				}
				catch( System::IO::FileNotFoundException^){
					textBox8->Text = "Файл не был создан. Ни одного подтвержденного объекта найденно не было.";
				}
			 }
	// Отобразить результаты захода в ROI 1 
	private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
				 resultInterfaceVisibleFalse();
				 chart1->Visible = true;
				 textBox7->Visible = true;
				 label14->Visible = true;
				 label14->Text = "Результаты захода объектов в ROI#1. Подтвержденных объектов: " + masManConfirmedCounterForRoi[0];
				 try 
				 {
					auto MyReader = gcnew IO::StreamReader(convertStdStringToSystemString(filesDir + "\\ROI1_Results.txt"), System::Text::Encoding::GetEncoding(1251)); 
					textBox7->Text= MyReader->ReadToEnd();
					MyReader->Close();
				 } 
				 catch (int inspect ) 
				 { 
					MessageBox::Show("Ошибка при считывании файла");
				 }
				 this->chart1->Series->Clear();
				 this->chart1->Series->Add("Количество людей прошедших через ROI#1");
				 chart1->Series["Количество людей прошедших через ROI#1"]->ChartType=System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
				 chart1->ChartAreas["ChartArea1"]->AxisX->MajorGrid->Enabled = false;
				 chart1->ChartAreas["ChartArea1"]->AxisY->MajorGrid->Enabled = false;
				 for (int i=0; i<resultForRoiOne.size(); i++)
				 {
					 this->chart1->Series["Количество людей прошедших через ROI#1"]->Points->AddXY(i,resultForRoiOne[i]);
 				 }
			 }
	// Отобразить результаты захода в ROI 2
	private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
				 resultInterfaceVisibleFalse();
				 chart1->Visible = true;
				 textBox7->Visible = true;
				 label14->Visible = true;
				 label14->Text = "Результаты захода объектов в ROI#2. Подтвержденных объектов: " + masManConfirmedCounterForRoi[1];
				 try 
				 {
					auto MyReader = gcnew IO::StreamReader(convertStdStringToSystemString(filesDir + "\\ROI2_Results.txt"), System::Text::Encoding::GetEncoding(1251)); 
					textBox7->Text= MyReader->ReadToEnd();
					MyReader->Close();
				 } 
				 catch (int inspect ) 
				 { 
					MessageBox::Show("Ошибка при считывании файла");
				 }
				 this->chart1->Series->Clear();
				 this->chart1->Series->Add("Количество людей прошедших через ROI#2");
				 chart1->Series["Количество людей прошедших через ROI#2"]->ChartType=System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
				 chart1->ChartAreas["ChartArea1"]->AxisX->MajorGrid->Enabled = false;
				 chart1->ChartAreas["ChartArea1"]->AxisY->MajorGrid->Enabled = false;
				 for (int i=0; i<resultForRoiTwo.size(); i++)
				 {
					 this->chart1->Series["Количество людей прошедших через ROI#2"]->Points->AddXY(i,resultForRoiTwo[i]);
 				 }
			 }
	// Отобразить результаты захода в ROI 3
	private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
				 resultInterfaceVisibleFalse();
				 chart1->Visible = true;
				 textBox7->Visible = true;
				 label14->Visible = true;
				 label14->Text = "Результаты захода объектов в ROI#3. Подтвержденных объектов: " + masManConfirmedCounterForRoi[2];
				 try 
				 {
					auto MyReader = gcnew IO::StreamReader(convertStdStringToSystemString(filesDir + "\\ROI3_Results.txt"), System::Text::Encoding::GetEncoding(1251)); 
					textBox7->Text= MyReader->ReadToEnd();
					MyReader->Close();
				 } 
				 catch (int inspect ) 
				 { 
					MessageBox::Show("Ошибка при считывании файла");
				 }
				 this->chart1->Series->Clear();
				 this->chart1->Series->Add("Количество людей прошедших через ROI#3");
				 chart1->Series["Количество людей прошедших через ROI#3"]->ChartType=System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
				 chart1->ChartAreas["ChartArea1"]->AxisX->MajorGrid->Enabled = false;
				 chart1->ChartAreas["ChartArea1"]->AxisY->MajorGrid->Enabled = false;
				 for (int i=0; i<resultForRoiThree.size(); i++)
				 {
					 this->chart1->Series["Количество людей прошедших через ROI#3"]->Points->AddXY(i,resultForRoiThree[i]);
 				 }
			 }
	// Отобразить результаты захода в ROI 4
	private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
				 resultInterfaceVisibleFalse();
				 chart1->Visible = true;
				 textBox7->Visible = true;
				 label14->Visible = true;
				 label14->Text = "Результаты захода объектов в ROI#4. Подтвержденных объектов: " + masManConfirmedCounterForRoi[3];
				 try 
				 {
					auto MyReader = gcnew IO::StreamReader(convertStdStringToSystemString(filesDir + "\\ROI4_Results.txt"), System::Text::Encoding::GetEncoding(1251)); 
					textBox7->Text= MyReader->ReadToEnd();
					MyReader->Close();
				 } 
				 catch (int inspect ) 
				 { 
					MessageBox::Show("Ошибка при считывании файла");
				 }
				 this->chart1->Series->Clear();
				 this->chart1->Series->Add("Количество людей прошедших через ROI#4");
				 chart1->Series["Количество людей прошедших через ROI#4"]->ChartType=System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
				 chart1->ChartAreas["ChartArea1"]->AxisX->MajorGrid->Enabled = false;
				 chart1->ChartAreas["ChartArea1"]->AxisY->MajorGrid->Enabled = false;
				 for (int i=0; i<resultForRoiFour.size(); i++)
				 {
					 this->chart1->Series["Количество людей прошедших через ROI#4"]->Points->AddXY(i,resultForRoiFour[i]);
 				 }
			 }
	// Отобразить результаты захода в ROI 5
	private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) {
				 resultInterfaceVisibleFalse();
				 chart1->Visible = true;
				 textBox7->Visible = true;
				 label14->Visible = true;
				 label14->Text = "Результаты захода объектов в ROI#5. Подтвержденных объектов: " + masManConfirmedCounterForRoi[4];
				 try 
				 {
					auto MyReader = gcnew IO::StreamReader(convertStdStringToSystemString(filesDir + "\\ROI5_Results.txt"), System::Text::Encoding::GetEncoding(1251)); 
					textBox7->Text= MyReader->ReadToEnd();
					MyReader->Close();
				 } 
				 catch (int inspect ) 
				 { 
					MessageBox::Show("Ошибка при считывании файла");
				 }
				 this->chart1->Series->Clear();
				 this->chart1->Series->Add("Количество людей прошедших через ROI#5");
				 chart1->Series["Количество людей прошедших через ROI#5"]->ChartType=System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
				 chart1->ChartAreas["ChartArea1"]->AxisX->MajorGrid->Enabled = false;
				 chart1->ChartAreas["ChartArea1"]->AxisY->MajorGrid->Enabled = false;
				 for (int i=0; i<resultForRoiFive.size(); i++)
				 {
					 this->chart1->Series["Количество людей прошедших через ROI#5"]->Points->AddXY(i,resultForRoiFive[i]);
 				 }
			 }
	// Перезагрузить приложение
	private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {
			 Application::Restart();
		 }
	// Отобразить интенсивность пешеходов на результатах работы Detector
	private: System::Void button18_Click(System::Object^  sender, System::EventArgs^  e) {
				 resultInterfaceVisibleFalse();
				 chart1->Visible = true;
				 textBox7->Visible = true;
				 label14->Visible = true;
				 label14->Text = "Интенсивность пешеходов на результатах работы детектора";
				 try 
				 {
					auto MyReader = gcnew IO::StreamReader(convertStdStringToSystemString(filesDir + "\\Intensity_Detectors_Results.txt"), System::Text::Encoding::GetEncoding(1251)); 
					textBox7->Text= MyReader->ReadToEnd();
					MyReader->Close();
				 } 
				 catch (int inspect ) 
				 { 
					MessageBox::Show("Ошибка при считывании файла");
				 }
				 this->chart1->Series->Clear();
				 this->chart1->Series->Add("Интенсивность потока пешеходов");
				 chart1->Series["Интенсивность потока пешеходов"]->ChartType=System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
				 chart1->ChartAreas["ChartArea1"]->AxisX->MajorGrid->Enabled = false;
				 chart1->ChartAreas["ChartArea1"]->AxisY->MajorGrid->Enabled = false;
				 for (int i=0; i<intensityDetectResultsOnFrames.size(); i++)
				 {
					 this->chart1->Series["Интенсивность потока пешеходов"]->Points->AddXY(i,intensityDetectResultsOnFrames[i]);
 				 }
		 }
	// Отобразить интенсивность пешеходов на результатах работы FramePersons
	private: System::Void button19_Click(System::Object^  sender, System::EventArgs^  e) {
				 resultInterfaceVisibleFalse();
				 chart1->Visible = true;
				 textBox7->Visible = true;
				 label14->Visible = true;
				 label14->Text = "Интенсивность пешеходов на результатах работы класса FramePersons";
				 try 
				 {
					auto MyReader = gcnew IO::StreamReader(convertStdStringToSystemString(filesDir + "\\Intensity_Persons_Search_Results.txt"), System::Text::Encoding::GetEncoding(1251)); 
					textBox7->Text= MyReader->ReadToEnd();
					MyReader->Close();
				 } 
				 catch (int inspect ) 
				 { 
					MessageBox::Show("Ошибка при считывании файла");
				 }
				 this->chart1->Series->Clear();
				 this->chart1->Series->Add("Интенсивность потока пешеходов");
				 chart1->Series["Интенсивность потока пешеходов"]->ChartType=System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
				 chart1->ChartAreas["ChartArea1"]->AxisX->MajorGrid->Enabled = false;
				 chart1->ChartAreas["ChartArea1"]->AxisY->MajorGrid->Enabled = false;
				 for (int i=0; i<intensityMyPersonsResultsOnFrames.size(); i++)
				 {
					 this->chart1->Series["Интенсивность потока пешеходов"]->Points->AddXY(i,intensityMyPersonsResultsOnFrames[i]);
 				 }
		 }
	// Интенсивность пешеходов для ROI 1
	private: System::Void button20_Click(System::Object^  sender, System::EventArgs^  e) {
				 resultInterfaceVisibleFalse();
				 chart1->Visible = true;
				 textBox7->Visible = true;
				 label14->Visible = true;
				 label14->Text = "Интенсивность пешеходов прошедших через ROI 1";
				 try 
				 {
					auto MyReader = gcnew IO::StreamReader(convertStdStringToSystemString(filesDir + "\\Intensity_ROI1_Results.txt"), System::Text::Encoding::GetEncoding(1251)); 
					textBox7->Text= MyReader->ReadToEnd();
					MyReader->Close();
				 } 
				 catch (int inspect ) 
				 { 
					MessageBox::Show("Ошибка при считывании файла");
				 }
				 this->chart1->Series->Clear();
				 this->chart1->Series->Add("Интенсивность потока пешеходов");
				 chart1->Series["Интенсивность потока пешеходов"]->ChartType=System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
				 chart1->ChartAreas["ChartArea1"]->AxisX->MajorGrid->Enabled = false;
				 chart1->ChartAreas["ChartArea1"]->AxisY->MajorGrid->Enabled = false;
				 for (int i=0; i<intensityResultForRoiOne.size(); i++)
				 {
					 this->chart1->Series["Интенсивность потока пешеходов"]->Points->AddXY(i,intensityResultForRoiOne[i]);
 				 }
		 }
	// Интенсивность пешеходов для ROI 2
	private: System::Void button21_Click(System::Object^  sender, System::EventArgs^  e) {
				 resultInterfaceVisibleFalse();
				 chart1->Visible = true;
				 textBox7->Visible = true;
				 label14->Visible = true;
				 label14->Text = "Интенсивность пешеходов прошедших через ROI 2";
				 try 
				 {
					auto MyReader = gcnew IO::StreamReader(convertStdStringToSystemString(filesDir + "\\Intensity_ROI2_Results.txt"), System::Text::Encoding::GetEncoding(1251)); 
					textBox7->Text= MyReader->ReadToEnd();
					MyReader->Close();
				 } 
				 catch (int inspect ) 
				 { 
					MessageBox::Show("Ошибка при считывании файла");
				 }
				 this->chart1->Series->Clear();
				 this->chart1->Series->Add("Интенсивность потока пешеходов");
				 chart1->Series["Интенсивность потока пешеходов"]->ChartType=System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
				 chart1->ChartAreas["ChartArea1"]->AxisX->MajorGrid->Enabled = false;
				 chart1->ChartAreas["ChartArea1"]->AxisY->MajorGrid->Enabled = false;
				 for (int i=0; i<intensityResultForRoiTwo.size(); i++)
				 {
					 this->chart1->Series["Интенсивность потока пешеходов"]->Points->AddXY(i,intensityResultForRoiTwo[i]);
 				 }
			 }
	// Интенсивность пешеходов для ROI 3
	private: System::Void button22_Click(System::Object^  sender, System::EventArgs^  e) {
				 resultInterfaceVisibleFalse();
				 chart1->Visible = true;
				 textBox7->Visible = true;
				 label14->Visible = true;
				 label14->Text = "Интенсивность пешеходов прошедших через ROI 3";
				 try 
				 {
					auto MyReader = gcnew IO::StreamReader(convertStdStringToSystemString(filesDir + "\\Intensity_ROI3_Results.txt"), System::Text::Encoding::GetEncoding(1251)); 
					textBox7->Text= MyReader->ReadToEnd();
					MyReader->Close();
				 } 
				 catch (int inspect ) 
				 { 
					MessageBox::Show("Ошибка при считывании файла");
				 }
				 this->chart1->Series->Clear();
				 this->chart1->Series->Add("Интенсивность потока пешеходов");
				 chart1->Series["Интенсивность потока пешеходов"]->ChartType=System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
				 chart1->ChartAreas["ChartArea1"]->AxisX->MajorGrid->Enabled = false;
				 chart1->ChartAreas["ChartArea1"]->AxisY->MajorGrid->Enabled = false;
				 for (int i=0; i<intensityResultForRoiThree.size(); i++)
				 {
					 this->chart1->Series["Интенсивность потока пешеходов"]->Points->AddXY(i,intensityResultForRoiThree[i]);
 				 }
			 }
	// Интенсивность пешеходов для ROI 4
	private: System::Void button23_Click(System::Object^  sender, System::EventArgs^  e) {
				 resultInterfaceVisibleFalse();
				 chart1->Visible = true;
				 textBox7->Visible = true;
				 label14->Visible = true;
				 label14->Text = "Интенсивность пешеходов прошедших через ROI 4";
				 try 
				 {
					auto MyReader = gcnew IO::StreamReader(convertStdStringToSystemString(filesDir + "\\Intensity_ROI4_Results.txt"), System::Text::Encoding::GetEncoding(1251)); 
					textBox7->Text= MyReader->ReadToEnd();
					MyReader->Close();
				 } 
				 catch (int inspect ) 
				 { 
					MessageBox::Show("Ошибка при считывании файла");
				 }
				 this->chart1->Series->Clear();
				 this->chart1->Series->Add("Интенсивность потока пешеходов");
				 chart1->Series["Интенсивность потока пешеходов"]->ChartType=System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
				 chart1->ChartAreas["ChartArea1"]->AxisX->MajorGrid->Enabled = false;
				 chart1->ChartAreas["ChartArea1"]->AxisY->MajorGrid->Enabled = false;
				 for (int i=0; i<intensityResultForRoiFour.size(); i++)
				 {
					 this->chart1->Series["Интенсивность потока пешеходов"]->Points->AddXY(i,intensityResultForRoiFour[i]);
 				 }
			 }
	// Интенсивность пешеходов для ROI 5
	private: System::Void button24_Click(System::Object^  sender, System::EventArgs^  e) {
				 resultInterfaceVisibleFalse();
				 chart1->Visible = true;
				 textBox7->Visible = true;
				 label14->Visible = true;
				 label14->Text = "Интенсивность пешеходов прошедших через ROI 5";
				 try 
				 {
					auto MyReader = gcnew IO::StreamReader(convertStdStringToSystemString(filesDir + "\\Intensity_ROI5_Results.txt"), System::Text::Encoding::GetEncoding(1251)); 
					textBox7->Text= MyReader->ReadToEnd();
					MyReader->Close();
				 } 
				 catch (int inspect ) 
				 { 
					MessageBox::Show("Ошибка при считывании файла");
				 }
				 this->chart1->Series->Clear();
				 this->chart1->Series->Add("Интенсивность потока пешеходов");
				 chart1->Series["Интенсивность потока пешеходов"]->ChartType=System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
				 chart1->ChartAreas["ChartArea1"]->AxisX->MajorGrid->Enabled = false;
				 chart1->ChartAreas["ChartArea1"]->AxisY->MajorGrid->Enabled = false;
				 for (int i=0; i<intensityResultForRoiFive.size(); i++)
				 {
					 this->chart1->Series["Интенсивность потока пешеходов"]->Points->AddXY(i,intensityResultForRoiFive[i]);
 				 }
			 }
};// Окончание
}


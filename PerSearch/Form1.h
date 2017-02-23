#pragma once


// Include lib's
#include "myFunction.h"
#include "myRoi.h"
#include <fstream>

// Global Obj
std::string filesDir; // Директория с путем к папке Текущая_дир//Files// где лежат все файлы
std::string loadFileName; // Путь к выбранному файлу
int timeInterval; // Временной интервал
bool resolutionForResize; // Переменная для хранения решения изменения размера изображения
myRoi* myCurrentRoi; // Класс для хранения информации о ROI
bool Drow; // переменная для проверки отрисовки
int coefficientWidth; // Во сколько раз сжали изображение по ширине
int coefficientHeight; // Во сколько раз сжали изображение по высоте

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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->button6 = (gcnew System::Windows::Forms::Button());
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
			this->tabPage1->Controls->Add(this->button6);
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
			// button6
			// 
			this->button6->Location = System::Drawing::Point(15, 339);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(176, 26);
			this->button6->TabIndex = 24;
			this->button6->Text = L"Начать анализ";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Visible = false;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
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
			this->Text = L"PerSearch";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
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
				open_dialog->Filter = "Video Files(*.AVI)|*.AVI|Mov Files(*.MOV)|*.MOV|All files (*.*)|*.*";
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
				label4->Visible=false;
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

				if ( imag.size().width != 320 && imag.size().height != 240 ) {
					resolutionForResize = true;
					coefficientWidth = imag.size().width/320;
					coefficientHeight = imag.size().height/240;
				}
				else resolutionForResize = false;
				if ( resolutionForResize ) cv::resize(imag,imag,cv::Size(320,240),0,0,1);
				
				cv::imwrite( filesDir+"SavedParams\\firstframe.jpg", imag);
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
						button4->Text = "Отобразить выбранные данные";
					} else button5->Visible = true;
					// Отобразим полученную ROI на координатах
					Bitmap ^ myBitmap = gcnew Bitmap(convertStdStringToSystemString(filesDir+"SavedParams\\firstframe.jpg")); 
					Graphics ^ g = Graphics::FromImage(myBitmap); 
					g->DrawRectangle(getPsevdoRandColor(myCurrentRoi->getCurrentNumberRoi()),mas[0],mas[1],(mas[2]-mas[0]),(mas[3]-mas[1]));
					pictureBox1->Image = myBitmap;
					
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
	private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 int* mas = myCurrentRoi->getCurrentRoiCoord();
				 Bitmap ^ myBitmap = gcnew Bitmap(convertStdStringToSystemString(filesDir+"SavedParams\\firstframe.jpg")); 
				 Graphics ^ g = Graphics::FromImage(myBitmap); 
				 if ( Drow ) {
					 g->DrawRectangle(getPsevdoRandColor(myCurrentRoi->getCurrentNumberRoi()), mas[0], mas[1], (e->X)-mas[0], (e->Y)-mas[1]);
					 pictureBox1->Image = myBitmap;
				 }
		 }
	private: System::Void pictureBox1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
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
						button4->Visible = false;
						button6->Visible = true;
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
	// Обаботка кнопки "Начать Анализ"
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	 
	}



};// Окончание
}


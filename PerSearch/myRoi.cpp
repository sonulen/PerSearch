#include "stdafx.h"
#include "myRoi.h"
#include <fstream>
// ������ �����������
myRoi::myRoi () {

}
// ����������� ��. �������� �������� ���������� ������� ����� ����� ROI
myRoi::myRoi (int amount) {
	this->amountRoi = amount;
	this->p_arrayRoiCoordinate = new int [amount * 4];
	for (int i = 0; i < amount*4; i++ ) this->p_arrayRoiCoordinate[i] = 0;
	this->currentNumberRoi = 0;
}
// ����������
myRoi::~myRoi () {
	delete [] this->p_arrayRoiCoordinate;
}
// ���������� ����� ROI � ������� �������� 
int myRoi::getCurrentNumberRoi () {
	return this->currentNumberRoi;
}
// ����������� ����� ROI � ������� ��������
void myRoi::nextRoi () {
	this->currentNumberRoi++;
}
// ��������� ����� ROI � ������� ��������
void myRoi::previousRoi () {
	this->currentNumberRoi--;
}
// ������ �� ����� ���� ��������� � ROI
void myRoi::fillRoiCoord (std::string filesDir) {
	filesDir += "\\SavedParams\\ROI_coordinates.txt";
	try {
		std::ifstream fin(filesDir);
		if ( fin.is_open() ) {
			for (int i = 0; i < this->amountRoi; i++) {
				fin >> this->p_arrayRoiCoordinate[i*4];
				fin >> this->p_arrayRoiCoordinate[i*4+1];
				fin >> this->p_arrayRoiCoordinate[i*4+2];
				fin >> this->p_arrayRoiCoordinate[i*4+3];
			}
		}
		fin.close();
	}
	catch (System::FormatException^ e) 
			 {
				 System::Windows::Forms::MessageBox::Show("������ �������! "+ e->Message);
			 }	
	catch (System::OverflowException^ e) 
			 {
				 System::Windows::Forms::MessageBox::Show("������ ������! "+ e->Message);
			 }
}
// ������� int mas[4] � ������������ ROI � ������� ������ ��������
int* myRoi::getCurrentRoiCoord () {
	int* mas = new int [4];
	for (int i = 0; i < 4; i++) {
		mas[i] = this->p_arrayRoiCoordinate[this->currentNumberRoi*4 + i];
	}
	return mas;
}
// ��������� ���������� ������� ROI. ���� ������� �������� <0 �� ���������� �� ���������� 
void myRoi::fillCurrentRoi (int* mas) {
	if ( mas[0] >= 0) this->p_arrayRoiCoordinate[this->currentNumberRoi*4] = mas[0];
	if ( mas[1] >= 0) this->p_arrayRoiCoordinate[this->currentNumberRoi*4+1] = mas[1];
	if ( mas[2] >= 0) this->p_arrayRoiCoordinate[this->currentNumberRoi*4+2] = mas[2];
	if ( mas[3] >= 0) this->p_arrayRoiCoordinate[this->currentNumberRoi*4+3] = mas[3];
}
// ������� ���������� ROI �� �� ������
int* myRoi::getSomeRoiCoord (int someNum) {
	int* mas = new int[4];
	for (int i = 0; i < 4; i++) {
		mas[i] = this->p_arrayRoiCoordinate[someNum*4 + i];
	}
	return mas;
}
// ������� ���� ���-�� ROI
int myRoi::getAmountRoi () {
	return this->amountRoi;
}

// ������������� ����� ROI � ������� ��������
void myRoi::setRoi (int i) {
	this->currentNumberRoi = i;
}

void myRoi::resizeForVideo (int factor) {
	for ( int i = 0; i < this->amountRoi*4; i++ ) 
		this->p_arrayRoiCoordinate[i] = this->p_arrayRoiCoordinate[i] * factor;
}

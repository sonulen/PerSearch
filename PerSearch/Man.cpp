#include "stdafx.h"
#include "Person.h"
#include <fstream>
#include <math.h>
#include "Man.h"

Man::Man (cv::Rect rack, int count) {
	this->loseFocusOnMan = 0;
	this->onFindFrameCount = 1;
	this->idMan = count;
	this->manWay.push_back(rack);
}

Man::~Man() {
	
	if ( this->onFindFrameCount >= 3 && this->loseFocusOnMan > 6 ) {
		//����� ��� ��� �� �������
		//System::Windows::Forms::MessageBox::Show("������� �������");
		std::ofstream fout("Files\\DetectResults\\Mans.txt", std::ios_base::app);
		fout << "������ � " << this->idMan << "\n";
		fout << "��� ����:" << "\n";
		for (int i = 0; i < this->manWay.size(); i++) {
			fout << i << ": " << this->manWay[i] << "\n";
		}
		fout << "���-�� ���������� ������: " << this->loseFocusOnMan << "\n";
		fout << "���-�� ��������� � ������ ��� ������: " << this->onFindFrameCount << "\n";
		fout << "------------------------------------------------------------" << "\n";
		fout.close();
	} 
	manWay.~vector();
}

cv::Rect Man::getCurrentCoord () {
	return this->manWay.back();
}

void Man::AddCoord (cv::Rect rack) {
	if ( this->onFindFrameCount != -1 ) {
		this->onFindFrameCount++;
		this->loseFocusOnMan = 0;
		this->manWay.push_back(rack);
	}
}

void Man::loseHim () {
	this->loseFocusOnMan++;
	if ( this->onFindFrameCount < 3 ) {
		this->onFindFrameCount = -1;
	}
}

bool Man::isReal() {
	if ( this->onFindFrameCount == -1 ) {
		return false;
	}
	return true;
}

int Man::howManyReal () {
	return this->onFindFrameCount;
}

int Man::howManyLose () {
	return this->loseFocusOnMan;
}

void Man::restoreCoord (cv::Rect rack) {
	if ( this->onFindFrameCount != -1 ) {
		this->onFindFrameCount++;
		this->manWay.push_back(rack);
	}
}
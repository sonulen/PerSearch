#include "stdafx.h"
#include <fstream>
#include <math.h>
#include "Man.h"

Man::Man (cv::Rect rack, int count, int FramesTheObjectOfConservation, int ConfirmedFramesHuman, cv::Mat Frame) {
	this->loseFocusOnMan = 0;
	this->onFindFrameCount = 1;
	this->idMan = count;
	this->manWay.push_back(rack);
	this->speed.x = 0;
	this->speed.y = 0;
	this->numberOfFramesTheObjectOfConservation = FramesTheObjectOfConservation;
	this->numberOfConfirmedFramesHuman = ConfirmedFramesHuman;
	Frame.copyTo(this->currentFrame);
}

Man::~Man() {
	manWay.~vector();
}

cv::Rect Man::getCurrentCoord () {
	return this->manWay.back();
}

void Man::AddCoord (cv::Rect rack, cv::Mat updateFrame) {
	if ( this->onFindFrameCount != -1 ) {
		calculateSpeed();
		this->onFindFrameCount++;
		this->loseFocusOnMan = 0;
		this->manWay.push_back(rack);
		updateFrame.copyTo(this->currentFrame);
	}
}

void Man::loseHim () {
	this->loseFocusOnMan++;
	if ( this->onFindFrameCount < this->numberOfConfirmedFramesHuman ) {
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
		rack.x = rack.x + this->speed.x;
		rack.y = rack.y + this->speed.y;
		this->manWay.push_back(rack);
	}
}

void Man::calculateSpeed () {
	double x = 0;
	double y = 0;
	int i = 1;
	for (i = 1; i < this->manWay.size(); i++) {
		x += (this->manWay[i].x + this->manWay[i].width/2)  - (this->manWay[i-1].x + this->manWay[i-1].width/2);
		y += (this->manWay[i].y + this->manWay[i].height/2)  - (this->manWay[i-1].y + this->manWay[i-1].height/2);
	}
	this->speed.x = floor(x / i);
	this->speed.y = floor(y / i);
}

cv::Point Man::getSpeedMan () {
	return this->speed;
}

int Man::getCountofWay () {
	return this->manWay.size();
}

cv::Point Man::getTrackPoint ( int i) {
	return cv::Point (this->manWay[i].x + this->manWay[i].width/2, this->manWay[i].y + this->manWay[i].height/2);
}

void Man::deleteMan (std::string filesDir) {
	if ( this->onFindFrameCount >= this->numberOfConfirmedFramesHuman) {
		// Запись в файл
		std::ofstream fout(filesDir + "\\Mans.txt", std::ios_base::app);
		fout << "Объект № " << this->idMan << "\n";
		fout << "Его путь:" << "\n";
		for (int i = 0; i < this->manWay.size(); i++) {
			fout << i << ": " << this->manWay[i] << "\n";
			// Нарисуем траекторию
			cv::circle(this->currentFrame, cv::Point (this->manWay[i].x + this->manWay[i].width/2, this->manWay[i].y + this->manWay[i].height/2) ,5,CV_RGB(0,0,205),-1,8,00);
		}
		// Нарисуем прямоугольник вокруг объекта
		cv::rectangle(this->currentFrame, this->manWay.back().tl(), this->manWay.back().br(), cv::Scalar(0,0,205), 3); 
		fout << "Кол-во потерянных кадров: " << this->loseFocusOnMan << "\n";
		fout << "Кол-во найденных в начале бля кадров: " << this->onFindFrameCount << "\n";
		fout << "------------------------------------------------------------" << "\n";
		fout.close();
		// Сохранение изображения
		std::string rackString = filesDir + "\\" + std::to_string(this->idMan) + ".jpg";
		cv::imwrite (rackString, this->currentFrame);
		//
	} 
}
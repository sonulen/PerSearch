#include "stdafx.h"
#include "Person.h"
#include <math.h>

Person::Person () {
	countPersonOnFrame = 0;
}

void Person::checkObjForTracking ( std::vector<cv::Rect> detect) {
	bool updateFlag = false;
	for (int i = 0; i < this->person.size(); i++ ) 
		this->checkPerson[i] = false;
	for (int i = 0; i < detect.size(); i++) {
		cv::Rect rack = detect[i];
		for (int j = 0; j < this->person.size() && !updateFlag; j++) {
			if ( abs((rack.x+rack.width/2) - (this->person[j].x+this->person[j].width/2)) < 10 ) {
				if ( abs((rack.y+rack.height/2) - (this->person[j].y + this->person[j].height/2)) < 10) {
					this->person[j] = rack;
					this->loosePerson[j] = 0;
					this->checkPerson[j] = true;
					updateFlag = true;
				}
			}
		}
		if (!updateFlag) {
			this->person.push_back(rack);
			this->loosePerson.push_back(0);
			this->checkPerson.push_back(true);
			this->countPersonOnFrame++;
		}
		updateFlag = false;
	}
	for (int i = 0; i < this->person.size(); i++) {
		if ( !this->checkPerson[i] ) this->loosePerson[i] += 1;
	}
	// Проверку надо на включающие друг друга прямоугольники
	updateVector();
}

int Person::getCountofPerson() {
	return countPersonOnFrame;
}

void Person::updateVector () {
	for (int i = 0; i < person.size(); i++) {
		if ( loosePerson[i] > 6 ) {
			loosePerson.erase (loosePerson.begin() + i);
			person.erase (person.begin() + i);
			checkPerson.erase ( checkPerson.begin() + i);
			countPersonOnFrame--;
		}
	}	
}

cv::Rect Person::getVector (int i) {
	return person[i];
}

bool Person::getOtherNess (int i) {
	return checkPerson[i];
}

Person::~Person () {

}
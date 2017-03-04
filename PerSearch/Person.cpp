#include "stdafx.h"
#include "Person.h"
#include <math.h>

#include <fstream>

Person::Person () {
	this->distanceDriftX = 20;
	this->distanceDriftY = 20;
	this->numberOfFramesTheObjectOfConservation = 6;
	this->numberOfConfirmedFramesHuman = 3;
	countPersonOnFrame = 0;
}

void Person::checkObjForTracking ( std::vector<cv::Rect> detect) {
	bool updateFlag = false;
	for (int i = 0; i < this->person.size(); i++ ) 
		this->checkPerson[i] = false;
	for (int i = 0; i < detect.size(); i++) {
		cv::Rect rack = detect[i];
		for (int j = 0; j < this->person.size() && !updateFlag; j++) {
			if ( abs((rack.x + rack.width/2) - (this->person[j].x + this->person[j].width/2)) < this->distanceDriftX ) {
				if ( abs((rack.y + rack.height/2) - (this->person[j].y + this->person[j].height/2)) < this->distanceDriftY) {
					this->speedPerson[j].x = (this->speedPerson[j].x + (rack.x + rack.width/2) - (this->person[j].x + this->person[j].width/2))/2;
					this->speedPerson[j].y = (this->speedPerson[j].y + (rack.y + rack.height/2) - (this->person[j].y + this->person[j].height/2))/2;
					this->person[j] = rack;
					this->loosePerson[j] = 0;
					this->checkPerson[j] = true;
					updateFlag = true;
					this->checkRealPerson[j] ++;
				}
			}
		}
		if (!updateFlag) {
			this->person.push_back(rack);
			this->loosePerson.push_back(0);
			this->checkPerson.push_back(true);
			this->countPersonOnFrame++;
			this->checkRealPerson.push_back(1);
			this->speedPerson.push_back(cv::Point(0,0));
		}
		updateFlag = false;
	}
	for (int i = 0; i < this->person.size(); i++) {
		if ( !this->checkPerson[i] ) {
			this->loosePerson[i] += 1;
			this->person[i].x += this->speedPerson[i].x;
			this->person[i].y += this->speedPerson[i].y;
			if ( this->checkRealPerson[i] < this->numberOfConfirmedFramesHuman )
				this->checkRealPerson[i] = -100;
		}
	}

	// Скорость почему то уводить назад?!
	removeNestedRect();
	removeUnrealPerson();
	updateVector();
	
}

int Person::getCountofPerson () {
	return countPersonOnFrame;
}

void Person::removeUnrealPerson () {
	for (int i = 0; i < this->person.size(); i++) {
		if ( this->checkRealPerson[i] == -100 ) {
			loosePerson.erase (loosePerson.begin() + i);
			person.erase (person.begin() + i);
			checkPerson.erase (checkPerson.begin() + i);
			countPersonOnFrame--;
			this->checkRealPerson.erase (this->checkRealPerson.begin() + i);
			this->speedPerson.erase(this->speedPerson.begin() + i);
		}
	}
}

void Person::removeNestedRect () {	
	for (int i = 0; i < this->person.size(); i++) {
		cv::Rect rack = this->person[i];
		for ( int j = 0; j < this->person.size(); j++) {
			if ( j != i && (rack & this->person[j]) == this->person[j] ) {
				this->loosePerson.erase (this->loosePerson.begin() + i);
				this->person.erase (this->person.begin() + i);
				this->checkPerson.erase ( this->checkPerson.begin() + i);
				this->checkRealPerson.erase ( this->checkRealPerson.begin() + i);
				this->countPersonOnFrame--;
				this->speedPerson.erase(this->speedPerson.begin() + i);
				i--;
			}
		}
	}
}

void Person::updateVector () {
	for (int i = 0; i < person.size(); i++) {
		if ( loosePerson[i] > this->numberOfFramesTheObjectOfConservation ) {
			loosePerson.erase (loosePerson.begin() + i);
			person.erase (person.begin() + i);
			checkPerson.erase ( checkPerson.begin() + i);
			countPersonOnFrame--;
			this->checkRealPerson.erase ( this->checkRealPerson.begin() + i);
			this->speedPerson.erase(this->speedPerson.begin() + i);
		}
	}	
}

cv::Rect Person::getVector (int i) {
	if ( this->checkRealPerson[i] >= this->numberOfConfirmedFramesHuman )
		return person[i];
	cv::Rect retRack(-100,-100,-100,-100);
	return retRack;
}

bool Person::getOtherNess (int i) {
	return checkPerson[i];
}

Person::~Person () {

}
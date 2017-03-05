#include "stdafx.h"
#include "Person.h"
#include <math.h>
#include "FramePersons.h"

FramePersons::FramePersons() {
	this->allCount = 0;
	this->currentCount = 0;
	this->distanceDriftX = 20;
	this->distanceDriftY = 20;
	this->numberOfFramesTheObjectOfConservation = 6;
	this->numberOfConfirmedFramesHuman = 3;
}

FramePersons::~FramePersons() {
	for (int i = 0; i < this->manOnFrame.size(); i++) {
			this->checkPerson.erase ( this->checkPerson.begin() + i);
			this->manOnFrame.erase ( this->manOnFrame.begin() + i);
			this->currentCount--;
	}
}

void FramePersons::checkObjForTrack (std::vector<cv::Rect> detect, cv::Mat Frame, std::string filesDir) {
	for (int i = 0; i < this->manOnFrame.size(); i++ ) 
		this->checkPerson[i] = false;
	cv::Rect rack;
	bool flagUpdate = false;
	for (int i = 0; i < detect.size(); i++) {
		rack = detect[i];
		for (int j = 0; j < this->manOnFrame.size(); j++) {
			if ( abs((rack.x + rack.width/2) - (this->manOnFrame[j].getCurrentCoord().x + this->manOnFrame[j].getCurrentCoord().width/2)) < this->distanceDriftX ) {
				if ( abs((rack.y + rack.height/2) - (this->manOnFrame[j].getCurrentCoord().y + this->manOnFrame[j].getCurrentCoord().height/2)) < this->distanceDriftY) {
					this->manOnFrame[j].AddCoord(rack, Frame);
					this->checkPerson[j] = true;
					flagUpdate = true;
				}
			}
		}
		if ( !flagUpdate ) {
			this->allCount++;
			this->manOnFrame.push_back(Man(rack,allCount, this->numberOfFramesTheObjectOfConservation, this->numberOfConfirmedFramesHuman, Frame));
			this->checkPerson.push_back(true);
			this->currentCount++;
		}
		flagUpdate = false;
	}
	for (int i = 0; i < this->manOnFrame.size(); i++) {
		if ( !this->checkPerson[i] ) {
			this->manOnFrame[i].loseHim();
			this->manOnFrame[i].restoreCoord(this->manOnFrame[i].getCurrentCoord());
		}
	}
	for (int i = 0; i < this->manOnFrame.size(); i++) {
		if ( this->manOnFrame[i].howManyLose() >= this->numberOfFramesTheObjectOfConservation && this->manOnFrame[i].isReal()) {
			this->manOnFrame[i].deleteMan(filesDir);
		}
	}
	removeUnrealPerson();
	removeNestedRect();
	updateFramePersons();
}

void FramePersons::removeNestedRect () {
	for (int i = 0; i < this->manOnFrame.size(); i++) {
		cv::Rect rack = this->manOnFrame[i].getCurrentCoord();
		for ( int j = 0; j < this->manOnFrame.size(); j++) {
			if ( j != i && (rack & this->manOnFrame[j].getCurrentCoord()) == this->manOnFrame[j].getCurrentCoord() ) {
				this->checkPerson.erase ( this->checkPerson.begin() + i);
				this->manOnFrame.erase ( this->manOnFrame.begin() + i);
				this->currentCount--;
				i--;
				break;
			}
		}
	}
}

void FramePersons::removeUnrealPerson () {
	for (int i = 0; i < this->manOnFrame.size(); i++) {
		if ( !this->manOnFrame[i].isReal() ) {
			this->checkPerson.erase ( this->checkPerson.begin() + i);
			this->manOnFrame.erase ( this->manOnFrame.begin() + i);
			this->currentCount--;
		}
	}
}

void FramePersons::updateFramePersons () {
	for (int i = 0; i < this->manOnFrame.size(); i++) {
		if ( this->manOnFrame[i].howManyLose() > this->numberOfFramesTheObjectOfConservation ) {
			this->checkPerson.erase ( this->checkPerson.begin() + i);
			this->manOnFrame.erase ( this->manOnFrame.begin() + i);
			this->currentCount--;
		}
	}
}

cv::Rect FramePersons::getVector (int i) {
	if ( this->manOnFrame[i].howManyReal() >= this->numberOfConfirmedFramesHuman) {
		return this->manOnFrame[i].getCurrentCoord();
	}
	cv::Rect retRack(-100,-100,-100,-100);
	return retRack;
}

int FramePersons::getCountofPerson() {
	return this->currentCount;
}

int FramePersons::trackCount (int i) {
	return this->manOnFrame[i].getCountofWay();
}

cv::Point FramePersons::getTrackPointofMan (int i,int j) {
	return this->manOnFrame[i].getTrackPoint(j);
}
#include "stdafx.h"
#include <vector>
#include <opencv2/opencv.hpp>
#include "Man.h"
#include "myRoi.h"

class FramePersons {
private:
	// ������ ������������ ��������
	std::vector <Man> manOnFrame;
	// ����� ���� �������� ��������
	int allCount;
	// ����� �������� � ������
	int currentCount;
	// ������ �������� �� ������� ����� ��������
	std::vector <bool> checkPerson; 
	// �������� �� ��������� � ���� ����� ��������������. ������� ����� �������
	void removeNestedRect ();
	// �������� �� ������ � �������� ���� ���� �������
	void removeUnrealPerson (); 
	// �������� ������ �������  ������ ���� �� ��� �������� ����� 5 ������
	void updateFramePersons();
	// ���������� ���������� ������� �� �
	int distanceDriftX;
	// ���������� ���������� ������� �� Y
	int distanceDriftY;
	// ���-�� ������ ������ 
	int numberOfFramesTheObjectOfConservation;
	// ���-�� ������ ����� ������� ������������ ��� ��� �������
	int numberOfConfirmedFramesHuman;
	// ������ �� ROI �����
	myRoi* myRoiObj;
	// ��������� ��� �������� ����� ���-�� ��������� �������������� �����
	int manConfirmedCounter;
	// ���������� ��� �������� ���-�� �������������� ����� ����� ROI
	int* masCounterForRoi;
	// ������� ��� ������������ ���������
	void fillCounters(int);

public:
	FramePersons(myRoi*);
	~FramePersons();
	// �������� ���� ������ ���������� � ��������� � ��������� �������, ��������� ���
	// ��� ������ � ����
	void checkObjForTrack (std::vector<cv::Rect>,cv::Mat, std::string);
	// ������ ������
	cv::Rect FramePersons::getVector (int);
	// ������ ���-�� �������� �� �����
	int getCountofPerson();
	// ������ ���-�� ��������� � Man
	int trackCount (int);
	// ����� ����� �� Man ������� � ���������� � ����� �����
	cv::Point getTrackPointofMan (int,int);
	// ������ ���-�� �������������� ����� �� ��� �����
	int getManConfirmedCounter ();
	// ������ ������ �� ������ � ���-���� �������������� ����� ��������� ����� ROI �� ���� ������
	int* getRoiManConfirmedCounter ();
};
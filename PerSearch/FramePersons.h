#include "stdafx.h"
#include <vector>
#include <opencv2/opencv.hpp>
#include "Man.h"

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
	// �������� �� ��������� � ���� ����� �������������. ������� ����� �������
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
public:
	FramePersons();
	~FramePersons();
	// �������� ���� ������ ���������� � ��������� � ��������� �������, ��������� ���
	// ��� ������ � ����
	void checkObjForTrack (std::vector<cv::Rect>);
	// ������ ������
	cv::Rect FramePersons::getVector (int );
	// ������ ���-�� �������� �� �����
	int getCountofPerson();
};
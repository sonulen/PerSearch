#include "stdafx.h"
#include <vector>
#include <opencv2/opencv.hpp>

class Man {
private:
	// ������ ��������� ��� ����������� ��������
	std::vector <cv::Rect> manWay;
	// �������������
	int idMan;
	// �������� ������ ���-�� ������ ������� 
	int loseFocusOnMan;
	// �������� ����� ���-�� ������ ������ ��� ��������
	int onFindFrameCount;
	// �������� ������������
	cv::Point speed;
	// ��������� ��������
	void calculateSpeed();
	// ���-�� ������ ������ 
	int numberOfFramesTheObjectOfConservation;
	// ���-�� ������ ����� ������� ������������ ��� ��� �������
	int numberOfConfirmedFramesHuman;
	// ������� ����
	cv::Mat currentFrame;
public:
	Man(cv::Rect, int, int, int, cv::Mat);
	~Man();
	// ������� ��������� ����������
	cv::Rect getCurrentCoord ();
	// �������� � ������ ����������
	void Man::AddCoord (cv::Rect, cv::Mat);
	// �������� ������� �������� �� �����
	void loseHim();
	// ���� �������� ������ � ������ ����������� � �� ��� ����� 3 ������ �� �� �������
	bool isReal();
	// ������� ������ ������ ��� ���������� ������
	int howManyLose ();
	// ������� ������ ������ ����� �� 1�� ��������
	int howManyReal ();
	// ���������� ��������������� ���������
	void restoreCoord (cv::Rect);
	// ���������� �������� �������
	cv::Point getSpeedMan ();
	// ���������� ���-�� ��������� ����
	int getCountofWay();
	// ���������� ���������� ����� ����
	cv::Point getTrackPoint (int);
	// ������� � ����� ��������� ��� �������
	void Man::deleteMan (std::string);
};
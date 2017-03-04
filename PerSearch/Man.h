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
public:
	Man(cv::Rect, int);
	~Man();
	// ������� ��������� ����������
	cv::Rect getCurrentCoord ();
	// �������� � ������ ����������
	void Man::AddCoord (cv::Rect);
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
};
#include <vector>
#include <opencv2/opencv.hpp>

class Person {
	private:
		std::vector <cv::Rect> person; // ���������� ���������
		std::vector <int> loosePerson; // ������ �������� ��������� �� �������
		std::vector <bool> checkPerson; // ������ �������� �� ������� ����� ��������
		int countPersonOnFrame; // ����� ������ �� ������ ������ � �������
		void Person::updateVector (); // �������� ������ ������� �� ������ ���� �� ��� �������� ����� 3 ������
	public:
		// ����������� ������ � ��� ������ countPersonOnFrame ������������� � 0
		Person(); 
		// �������� ������ � ��������� � ������������ ���
		void checkObjForTracking ( std::vector<cv::Rect> ); 
		// ���������� ������� � ��� ����� �������� � ������� ������
		int getCountofPerson (); 
		// ���������� ������� �� ������� �� ������ 
		cv::Rect getVector ( int ); 
		// ���������� ��������� �� �� ���� ������ �� ���� �����
		bool getOtherNess(int); 
		~Person(); // ������ ����������
};
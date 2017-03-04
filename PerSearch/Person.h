#include <vector>
#include <opencv2/opencv.hpp>

class Person {
	private:
		// ���������� ���������
		std::vector <cv::Rect> person; 
		// ������ �������� ��������� �� �������
		std::vector <int> loosePerson; 
		// ������ �������� �� ������� ����� ��������
		std::vector <bool> checkPerson; 
		// ������ �������� �� ������ ������������. ���� � ������� ���-�� ������ ������ <3 - ������.
		std::vector <int> checkRealPerson;
		// ������ �������� �������
		std::vector <cv::Point> speedPerson;
		// ����� ������ �� ������ ������ � �������
		int countPersonOnFrame; 
		// �������� ������ ������� �� ������ ���� �� ��� �������� ����� 3 ������
		void Person::updateVector (); 
		// �������� �� ��������� � ���� ����� �������������. ������� ����� �������
		void Person::removeNestedRect ();
		// �������� �� ������ � �������� ���� ���� �������
		void Person::removeUnrealPerson ();
		
		// ��������� �������������
		// ���-�� ������ ������ 
		int numberOfFramesTheObjectOfConservation;
		// ���������� ���������� ������� �� �
		int distanceDriftX;
		// ���������� ���������� ������� �� Y
		int distanceDriftY;
		// ���-�� ������ ����� ������� ������������ ��� ��� �������
		int numberOfConfirmedFramesHuman;

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
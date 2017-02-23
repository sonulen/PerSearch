#include <string>

class myRoi {
	private:
		int amountRoi; // ����� ���-�� ROI
		int currentNumberRoi; // ������� �������������� ����� ROI
		int* p_arrayRoiCoordinate; // ������ ��������� ���� ROI
	public:
		// ������ �����������
		myRoi();
		// ����������� ��. �������� �������� ���������� ������� ����� ����� ROI
		myRoi(int amount);
		// ���������� ����� ROI � ������� �������� 
		int getCurrentNumberRoi();
		// ����������� ����� ROI � ������� ��������
		void nextRoi();
		// ��������� ����� ROI � ������� ��������
		void previousRoi();
		// ������ �� ����� ���� ��������� � ROI
		void fillRoiCoord (std::string);
		// ������� int mas[4] � ������������ ROI � ������� ������ ��������
		int* getCurrentRoiCoord ();
		// ��������� ���������� ������� ROI. ���� ������� �������� <0 �� ���������� �� ���������� 
		void fillCurrentRoi (int*);
		// ������� ���������� ROI �� �� ������
		int* getSomeRoiCoord (int);
		// ������� ��������� ����� = ���-�� ROI
		int myRoi::getAmountRoi ();
		// ������������� ����� ROI � ������� ��������
		void myRoi::setRoi (int);
		// ����������
		~myRoi();
};
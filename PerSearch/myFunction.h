//
#include <opencv2/opencv.hpp>

void showImage (std::string fileName);
// ������ ������� ����������, ������� ����������� �����
System::String^ checkAndCreateDirectory ( System::String^ path );
// ����������� �� System::String^ � std::string
std::string converSystemStringToStdString ( System::String^ systemStr );
//
#include <opencv2/opencv.hpp>

// ������ ������� ����������, ������� ����������� �����
System::String^ checkAndCreateDirectory ( System::String^ path );
// ����������� �� System::String^ � std::string
std::string converSystemStringToStdString ( System::String^ systemStr );
// ����������� �� std::string � System::String^
System::String^ convertStdStringToSystemString ( std::string stdStr );
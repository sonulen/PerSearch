//
#include <opencv2/opencv.hpp>

// Узнаем текущую директорию, создаем недостающие папки
System::String^ checkAndCreateDirectory ( System::String^ path );
// Конвертация из System::String^ в std::string
std::string converSystemStringToStdString ( System::String^ systemStr );
// Конвертация из std::string в System::String^
System::String^ convertStdStringToSystemString ( std::string stdStr );
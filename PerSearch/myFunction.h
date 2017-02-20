//
#include <opencv2/opencv.hpp>

void showImage (std::string fileName);
// Узнаем текущую директорию, создаем недостающие папки
System::String^ checkAndCreateDirectory ( System::String^ path );
// Конвертация из System::String^ в std::string
std::string converSystemStringToStdString ( System::String^ systemStr );
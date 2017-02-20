#include "stdafx.h"
#include "myFunction.h"
#include <msclr/marshal_cppstd.h>

//void showImage (std::string fileName ) {
//	IplImage* image = 0;
//
//	char * filepic = new char[fileName.size() + 1];
//	std::copy(fileName.begin(), fileName.end(), filepic);
//	filepic[fileName.size()] = '\0'; // don't forget the terminating 0
//
//	// получаем картинку
//	image = cvLoadImage(filepic,1);
//	cvNamedWindow("original",CV_WINDOW_AUTOSIZE);
//	cvShowImage("original",image);
//}

System::String^ checkAndCreateDirectory ( System::String^ path ) {
	System::String^ filesDir = path + "\\Files\\";
	if (!System::IO::Directory::Exists(filesDir)) System::IO::Directory::CreateDirectory((filesDir));
	if (!System::IO::Directory::Exists(filesDir+"SavedParams\\")) System::IO::Directory::CreateDirectory((filesDir+"SavedParams\\"));
	if (!System::IO::Directory::Exists(filesDir+"DetectResults\\")) System::IO::Directory::CreateDirectory((filesDir+"DetectResults\\"));
	return filesDir;
}

std::string converSystemStringToStdString ( System::String^ systemStr ) {
	std::string stdStr;
	// Перекодирование system string в std string для подгрузки в openCV
	stdStr = msclr::interop::marshal_as<std::string>(systemStr);
	stdStr[systemStr->Length]='\0';
	return stdStr;
}
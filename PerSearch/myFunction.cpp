#include "stdafx.h"
#include "myFunction.h"
#include <msclr/marshal_cppstd.h>

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

System::String^ convertStdStringToSystemString ( std::string stdStr ) {
	System::String^ systemStr;
	systemStr = msclr::interop::marshal_as<System::String^>(stdStr);
	return systemStr;
}
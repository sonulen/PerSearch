#include "stdafx.h"
#include "myFunction.h"

void showImage (std::string fileName ) {
	IplImage* image = 0;

	char * filepic = new char[fileName.size() + 1];
	std::copy(fileName.begin(), fileName.end(), filepic);
	filepic[fileName.size()] = '\0'; // don't forget the terminating 0

	// получаем картинку
	image = cvLoadImage(filepic,1);
	cvNamedWindow("original",CV_WINDOW_AUTOSIZE);
	cvShowImage("original",image);
}
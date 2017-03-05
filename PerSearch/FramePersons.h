#include "stdafx.h"
#include <vector>
#include <opencv2/opencv.hpp>
#include "Man.h"

class FramePersons {
private:
	// Вектор существующих объектов
	std::vector <Man> manOnFrame;
	// Всего было объектов созданно
	int allCount;
	// Всего объектов в памяти
	int currentCount;
	// Вектор проверки на текущем кадре пешехода
	std::vector <bool> checkPerson; 
	// Проверка на вложенные в друг друга прямоугольник. удалять будем больший
	void removeNestedRect ();
	// Проверка на ложные и удаление если есть таковые
	void removeUnrealPerson (); 
	// Проверка внутри удаляем  объект если он был пропущен более 5 кадров
	void updateFramePersons();
	// Расстояние отклонения объекта по Х
	int distanceDriftX;
	// Расстояние отклонения объекта по Y
	int distanceDriftY;
	// Кол-во кадров потери 
	int numberOfFramesTheObjectOfConservation;
	// Кол-во кадров после которых подтверждаем что это человек
	int numberOfConfirmedFramesHuman;

public:
	FramePersons();
	~FramePersons();
	// Посылаем сюда вектор полученный с детектора и принимаем решения, добавлять или
	// нет объект в трек
	void checkObjForTrack (std::vector<cv::Rect>,cv::Mat, std::string);
	// Вернем объект
	cv::Rect FramePersons::getVector (int);
	// Вернем кол-во объектов на кадре
	int getCountofPerson();
	// Вернем кол-во координат у Man
	int trackCount (int);
	// Берет точку из Man объекта и возвращает в общий поток
	cv::Point getTrackPointofMan (int,int);
};
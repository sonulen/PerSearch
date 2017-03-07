#include "stdafx.h"
#include <vector>
#include <opencv2/opencv.hpp>
#include "Man.h"
#include "myRoi.h"

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
	// Проверка на вложенные в друг друга прямоугольники. удалять будем больший
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
	// Ссылка на ROI класс
	myRoi* myRoiObj;
	// Переменна для хранения всего кол-ва прошедших подтвержденных людей
	int manConfirmedCounter;
	// Переменные для хранения кол-ва подтвержденных людей через ROI
	int* masCounterForRoi;
	// Функция для увеличивания счетчиков
	void fillCounters(int);

public:
	FramePersons(myRoi*);
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
	// Вернем кол-во подтвержденных людей за все видео
	int getManConfirmedCounter ();
	// Вернем ссылку на массив с кол-вами подтвержденных людей прошедших через ROI за весь период
	int* getRoiManConfirmedCounter ();
};
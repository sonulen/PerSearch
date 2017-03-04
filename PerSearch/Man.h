#include "stdafx.h"
#include <vector>
#include <opencv2/opencv.hpp>

class Man {
private:
	// Вектор координат для конкретного человека
	std::vector <cv::Rect> manWay;
	// Идентификатор
	int idMan;
	// Значение равное кол-ву потери объекта 
	int loseFocusOnMan;
	// Значение равно кол-ву кадров подряд при создании
	int onFindFrameCount;
public:
	Man(cv::Rect, int);
	~Man();
	// Вернуть последние координаты
	cv::Rect getCurrentCoord ();
	// Добавить в вектор координаты
	void Man::AddCoord (cv::Rect);
	// Добавить пропуск человека на видео
	void loseHim();
	// Если потеряли объект в начале обноружения и он был менее 3 кадров то не человек
	bool isReal();
	// Сколько кадров подряд уже пропустили объект
	int howManyLose ();
	// Сколько кадров объект виден до 1го пропуска
	int howManyReal ();
	// Добавление восстановленных координат
	void restoreCoord (cv::Rect);
};
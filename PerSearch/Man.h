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
	// Скорость передвижения
	cv::Point speed;
	// Высчитать скорость
	void calculateSpeed();
	// Кол-во кадров потери 
	int numberOfFramesTheObjectOfConservation;
	// Кол-во кадров после которых подтверждаем что это человек
	int numberOfConfirmedFramesHuman;
	// Текущий кадр
	cv::Mat currentFrame;
public:
	Man(cv::Rect, int, int, int, cv::Mat);
	~Man();
	// Вернуть последние координаты
	cv::Rect getCurrentCoord ();
	// Добавить в вектор координаты
	void Man::AddCoord (cv::Rect, cv::Mat);
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
	// Возвращает скорость объекта
	cv::Point getSpeedMan ();
	// Возвращает кол-во координат пути
	int getCountofWay();
	// Возвращает конкретную точку пути
	cv::Point getTrackPoint (int);
	// удаляем и соотв сохраняем все объекты
	void Man::deleteMan (std::string);
};
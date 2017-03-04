#include <vector>
#include <opencv2/opencv.hpp>

class Person {
	private:
		// Координаты пешеходов
		std::vector <cv::Rect> person; 
		// Вектор пропуска пешеходов на объекте
		std::vector <int> loosePerson; 
		// Вектор проверки на текущем кадре пешехода
		std::vector <bool> checkPerson; 
		// Вектор проверки на ложное срабатывания. если у объекта кол-во подряд кадров <3 - ложное.
		std::vector <int> checkRealPerson;
		// Вектор скорости объекта
		std::vector <cv::Point> speedPerson;
		// Всего объект на данный момент в векторе
		int countPersonOnFrame; 
		// Проверка внутри удаляем ли объект если он был пропущен более 3 кадров
		void Person::updateVector (); 
		// Проверка на вложенные в друг друга прямоугольник. удалять будем больший
		void Person::removeNestedRect ();
		// Проверка на ложные и удаление если есть таковые
		void Person::removeUnrealPerson ();
		
		// Параметры настраиваемые
		// Кол-во кадров потери 
		int numberOfFramesTheObjectOfConservation;
		// Расстояние отклонения объекта по Х
		int distanceDriftX;
		// Расстояние отклонения объекта по Y
		int distanceDriftY;
		// Кол-во кадров после которых подтверждаем что это человек
		int numberOfConfirmedFramesHuman;

	public:
		// конструктор пустой в нем только countPersonOnFrame устанавливаем в 0
		Person(); 
		// получаем вектор с детектора и обрабатываем его
		void checkObjForTracking ( std::vector<cv::Rect> ); 
		// возвращаем сколько у нас всего объектов в векторе сейчас
		int getCountofPerson (); 
		// возвращаем объекты из вектора по номеру 
		cv::Rect getVector ( int ); 
		// возвращаем обновляли ли мы этот объект на этом кадре
		bool getOtherNess(int); 
		
		~Person(); // пустой деструктор
};
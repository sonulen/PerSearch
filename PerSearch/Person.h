#include <vector>
#include <opencv2/opencv.hpp>

class Person {
	private:
		std::vector <cv::Rect> person; // Координаты пешеходов
		std::vector <int> loosePerson; // Вектор пропуска пешеходов на объекте
		std::vector <bool> checkPerson; // Вектор проверки на текущем кадре пешехода
		int countPersonOnFrame; // Всего объект на данный момент в векторе
		void Person::updateVector (); // Проверка внутри удаляем ли объект если он был пропущен более 3 кадров
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
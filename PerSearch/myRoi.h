#include <string>

class myRoi {
	private:
		int amountRoi; // Общее кол-во ROI
		int currentNumberRoi; // Текущий обрабатываемый номер ROI
		int* p_arrayRoiCoordinate; // Массив координат всех ROI
	public:
		// Пустой конструктор
		myRoi();
		// Конструктор вх. параметр которого определяет сколько всего будет ROI
		myRoi(int amount);
		// Возвращает номер ROI с которой работаем 
		int getCurrentNumberRoi();
		// Увеличивает номер ROI с которой работаем
		void nextRoi();
		// Уменьшает номер ROI с которой работаем
		void previousRoi();
		// Запись из файла всех координат в ROI
		void fillRoiCoord (std::string);
		// Вернуть int mas[4] с координатами ROI с которой сейчас работаем
		int* getCurrentRoiCoord ();
		// Заполнить координаты текущей ROI. Если входной параметр <0 то координата не изменяется 
		void fillCurrentRoi (int*);
		// Вернуть координаты ROI по ее номеру
		int* getSomeRoiCoord (int);
		// Вернуть введенное число = кол-во ROI
		int myRoi::getAmountRoi ();
		// Устанавливает номер ROI с которой работаем
		void myRoi::setRoi (int);
		// Деструктор
		~myRoi();
};
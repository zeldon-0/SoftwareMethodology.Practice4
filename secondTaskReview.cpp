﻿enum TransportType
{
	eCar,
	ePlane,
	eSubmarine
};
class Transport
{
public:
	Transport(TransportType type) : m_type(type) {}
	// Не запах коду, але через особливість цілочисельних обчислень, будь-який результат з дробовою частиною заокруглиться до цілого значення.
	int GetSpeed(int distance, int time)
	{
		// Запах коду - надлишкова вкладеність, а також наразі немає коду, що визначає значення, повернене у разі, якщо умова не виконана.
		// Слід замінити на блок вигляду "if (time == 0) { return 0; }"
		if (time != 0)
		{
			// Запах коду - зловживання оператором "switch". Клас "Transport" суто інстиниктивно не повинен визначати, якого типу транспорт у бізнес-логіці.
			// Слід виділити окрему ієрархію дочірніх класів "Transport" на заміну переліченню.
			switch (m_type)
			{
			case eCar:
				return distance / time;
			case ePlane:
				// Вирази доволі довгі. Задля легшого читання є сенс винести проміжний результат в окрему змінну.
				// Не запах коду, але можлива логічна помилка: ймовірно, різниця між заданими нижче показниками часу буде від'ємним числом, 
				// а отже в результаті швидкість буде від'ємною. 
				// Але в даній роботі обмежимось рефакторингом коду і припускатимемо, що логіка дійсно правильна для поставленої задачі - 
				// і для кожного виду транспорту потрібно зберігати час початку і кінця подорожі в об'єкті, в той час, як наданий параметр "time"
				// також є потрібним і окремим від них.
				return distance / (time - getTakeOffTime() - getLandingTime());
			case eSubmarine:
				return distance / (time - getDiveTime() - getAscentTime());
			}
		}
	}
	...
private:
	// Запах коду - тимчасові поля, заповнені і використані лише за певних умов - коли об'єкт має конкретний внутрішній тип.
	// Наразі немає коду, що виставляє значення полів. Припускаємо, що він наявний у повній версії, але пропущений у фрагменті - як геттер.
	// Тим не менш, навіть за наявності сеттера поля лишаються тимчасовими - і набувають значення лише коли клієнтський код його додатково виставить.
	// Таким чином створений об'єкт є не до кінця сформованим, а отже, є сенс винести код для виставлення у конструктор 
	// (додатковий сеттер при цьому може лишитись, залежно від доменної логіки додатку).
	int m_takeOffTime;
	int m_landingTime;
	int m_diveTime;
	int m_ascentTime;
	enum m_type;
};
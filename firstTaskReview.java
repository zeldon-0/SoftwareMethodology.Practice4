﻿// Припускаємо, що код написаний мовою "Java", від чого залежать деталі рефакторингу
void checkSecurity(String[] people)
{
	// Запах коду - тимчасова змінна, що використовується лише для перевірки закінчення виконання циклу.
	boolean found = false; 
	// Запах коду - ожержимість елементарними типами. Замість використання індексу в масиві, можемо ітеруватись його членами
	for (int i = 0; i < people.length; i++)
	{
		// Вищезгадана тимчасова зміннане закінчує виконання циклу - 
		// він виконуватиметься для кожного елемента масиву навіть за попереднього виконання умови
		if (!found) 
		{
			// Запах коду - використання літералів. Можливі значення є сенс винести у, скажімо, приватне поле
			if (people[i].equals(“Don”))
			{
				// Запах коду - дублювання. 2 блоки "if" виконують однаковий код
				sendAlert(); 
				// Замість виставлення значення тимчасової змінної слід використати "return",
				// що закінчить виконання циклу
				found = true;
			}
			if (people[i].equals(“John”))
			{
				sendAlert();
				found = true;
			}
		}
	}
}
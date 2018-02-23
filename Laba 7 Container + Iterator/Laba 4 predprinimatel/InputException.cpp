#include "InputException.h"
#include <iostream>

using namespace std;

void InputException::NumError()
{
		switch (error)
		{
		case 1:
				cout << "Ошибка 1.1" << endl;
				cout << "Вы ввели недопустимый символ!" << endl;
				cout << "Разрешён ввод только букв латинского алфавита." << endl << endl;
				break;
		case 2:
				cout << "Ошибка 1.2" << endl;
				cout << "Введён недопустимый символ либо длина номера не равна семи" << endl << endl;
				break;
		case 3:
				cout << "Ошибка 1.3" << endl;
				cout << "Превышен лимит по вводу символов!" << endl;
				cout << "Максимально допустимое значение - 15 символов." << endl << endl;
				break;
		case 4:
				cout << "Ошибка 1.4" << endl;
				cout << "Вы ввели символы вместо числа либо превышен предел по вводу чисел!" << endl << endl;
				break;
		case 5:
				cout << "Ошибка 1.5" << endl;
				cout << "Строка не может содержать более двух знаков дефиса." << endl << endl;
				break;
		case 6:
				cout << "Ошибка 1.6" << endl;
				cout << "Строка не может начинаться со знака дефиса." << endl << endl;
				break;
		case 7:
				cout << "Ошибка 1.7" << endl;
				cout << "Некорретно введена дата. Формат - ДД.ММ.ГГГГ" << endl << endl;
				break;
		case 8:
				cout << "Ошибка 1.8" << endl;
				cout << "Используйте точку для разделения дня, месяца и года" << endl << endl;
				break;
		case 9:
				cout << "Ошибка 1.9" << endl;
				cout << "Использован недопустимый символ. Разрешён ввод только цифр и символа точки." << endl << endl;
				break;
		case 10:
				cout << "Ошибка 1.10" << endl;
				cout << "Неверно введён день." << endl << endl;
				break;
		case 11:
				cout << "Ошибка 1.11" << endl;
				cout << "Неверно введён месяц." << endl << endl;
				break;
		case 12:
				cout << "Ошибка 1.12" << endl;
				cout << "Неверно введён год." << endl << endl;
				break;
		default:
				puts("Ошибка ввода");
				puts("Повторите ввод");
				break;
		}
}
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
				cout << "Разрешён ввод ТОЛЬКО букв латинского алфавита и цифр." << endl << endl;
				break;
		case 2:
				cout << "Ошибка 1.2" << endl;
				cout << "Имя пользователя не может начинаться с цифры!" << endl << endl;
				break;
		case 3:
				cout << "Ошибка 1.3" << endl;
				cout << "Превышен лимит по вводу символов!" << endl;
				cout << "Максимально допустимое значение - 20 символов." << endl << endl;
				break;
		case 4:
				cout << "Ошибка 3.1" << endl;
				cout << "Вы ввели символы вместо числа либо превышен предел по вводу чисел!" << endl << endl;
				break;
		case 5:
				cout << "Ошибка 1.4" << endl;
				cout << "Невозможно совершить операцию!" << endl;
				cout << "Баланс пользователя не может быть отрицательным" << endl;
				break;
		default:
				puts("Ошибка ввода");
				puts("Повторите ввод");
				break;
		}
}
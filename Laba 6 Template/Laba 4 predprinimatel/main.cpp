#include <iostream>
#include <iomanip>
#include "String.h"
#include "List.h"
#include <vector>

using namespace std;

#define SIZE 10

#include "Human.h"
#include "tourist.h"

int main()
{
		vector <cTourist> ct;

		List<cTourist> t;
		setlocale(LC_CTYPE, "Russian");
		system("cls");

		while (1)
		{
				system("cls");
				cout << "Выберите действие:" << endl;
				cout << "1. Просмотреть cTourist" << endl;
				cout << "2. Изменить cTourist" << endl;
				cout << "3. Добавить cTourist" << endl;
				cout << "4. Удалить cTourist" << endl << endl;
				cout << "0. Выход" << endl;
				cin.sync();
				rewind(stdin);
				int choice = cin.get();
				switch (choice)
				{
				case '1':
				{
						system("cls");
						t.sort();
						if (t.size() > 0)
						{
								cout << setw(20) << "Имя" << setw(20) << "Фамилия" << setw(9) << "Возраст" << setw(9) << "Паспорт" << setw(20) << "Страна"
									   << setw(12) << "Дата" << endl;
								t.output();
								//cout << endl;
						}
						else cout << "Список пуст!" << endl;
						system("pause");
						break;
				}
				case '2':
				{
						system("cls");
						cout << "Введите номер изменяемого объекта: " << endl;
						int tempNumber = InputCheck(1,t.size());
						cTourist tmp;
						cin >> tmp;
						t[tempNumber - 1] = tmp;
						system("pause");
						break;
				}
				case '3':
				{
						system("cls");
						cTourist tmp;
						cin >> tmp;
						t.push_tail(tmp);
						break;
				}
				case '4':
				{
						system("cls");
						if (t.size() == 1)
						{
								t.pop_head();
						}
						if (t.size() > 1)
						{
								t.pop_tail();
						}
						system("pause");
						break;
				}
				case '0':
				{
						return 0;
				}
				}
		}
		system("pause");
		return 0;
}
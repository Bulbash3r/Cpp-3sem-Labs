#include <iostream>
#include <iomanip>
#include "List.h"
#include "File.h"

using namespace std;

#define SIZE 10

#include "Human.h"
#include "tourist.h"

int main()
{
		List<cTourist> t;
		File<cTourist> f;
	  //f.TxtFileOpen(t);
		f.BinFileOpen(t);
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
				cout << "0. Сохранить и выйти" << endl;
				cin.sync();
				rewind(stdin);
				int choice = cin.get();
				switch (choice)
				{
				case '1':
				{
						system("cls");
						if (t.size() > 0)
						{
								t.sort();
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
						f.BinFileSave(t);
						//f.TxtFileSave(t);
						return 0;
				}
				}
		}
		system("pause");
		return 0;
}
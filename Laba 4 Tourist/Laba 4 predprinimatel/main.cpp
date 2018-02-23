#include <iostream>
#include <iomanip>
#include "String.h"
using namespace std;

#define SIZE 10

#include "Human.h"
#include "tourist.h"
#include "businessman.h"
#include "businesstourist.h"

int main()
{
		setlocale(LC_CTYPE, "Russian");
		cHuman h[SIZE]; int i = 0;
		cTourist t[SIZE]; int j = 0;
		cBusinessman bs[SIZE]; int k = 0;
		cBusinessTourist bst[SIZE]; int l = 0;

		system("cls");
		while (1)
		{
				cBusinessTourist temp1;
				cout << endl;
				system("pause");
				system("cls");
				break;
		}
		cout << endl;
		system("pause");
		while (1)
		{
				system("cls");
				cout << "Выберите действие:" << endl;
				cout << "1. Просмотреть cHuman" << endl;
				cout << "2. Изменить cHuman" << endl;
				cout << "3. Добавить cHuman" << endl << endl;
				cout << "4. Просмотреть cTourist" << endl;
				cout << "5. Изменить cTourist" << endl;
				cout << "6. Добавить cTourist" << endl << endl;
				cout << "7. Просмотреть cBusinessman" << endl;
				cout << "8. Изменить cBusinessman" << endl;
				cout << "9. Добавить cBusinessman" << endl << endl;
				cout << "q. Просмотреть cBusinessTourist" << endl;
				cout << "w. Изменить cBusinessTourist" << endl;
				cout << "e. Добавить cBusinessTourist" << endl << endl;
				cout << "0. Выход" << endl;
				cin.sync();
				rewind(stdin);
				int choice = cin.get();
				switch (choice)
				{
				case '1':
				{
						system("cls");
						cout << setw(15) << "Имя" << setw(15) << "Фамилия" << setw(8) << "Возраст" << endl;
						for (int x=0; x<i; x++)
								cout << h[x];
						system("pause");
						break;
				}
				case '2':
				{
						system("cls");
						cout << "Введите номер изменяемого объекта: " << endl;
						int a;
						cin >> a;
						if (a >= i) break;
						cHuman tmp;
						cin >> tmp;
						h[a-1] = tmp;
						break;
				}
				case '3':
				{
						system("cls");
						cHuman tmp;
						cin >> tmp;
						h[i] = tmp;
						i++;
						break;
				}
				case '4':
				{
						system("cls");
						cout << setw(15) << "Имя" << setw(15) << "Фамилия" << setw(8) << "Возраст" << setw(8) << "Паспорт" << setw(10) << "Страна"
								<< setw(6) << "Дата" << endl;
						for (int x = 0; x<j; x++)
								cout << t[x];
						system("pause");
						break;
				}
				case '5':
				{
						system("cls");
						cout << "Введите номер изменяемого объекта: " << endl;
						int a;
						cin >> a;
						if (a >= j) break;
						cTourist tmp;
						cin >> tmp;
						t[a - 1] = tmp;
						break;
				}
				case '6':
				{
						system("cls");
						cTourist tmp;
						cin >> tmp;
						t[j] = tmp;
						j++;
						break;
				}
				case '7':
				{
						system("cls");
						cout << setw(15) << "Имя" << setw(15) << "Фамилия" << setw(8) << "Возраст" << setw(9) << "Лицензия" << setw(10) << "Сумма"
								<< setw(6) << "Дата" << endl;
						for (int x = 0; x<k; x++)
								cout << bs[x];
						system("pause");
						break;
				}
				case '8':
				{
						system("cls");
						cout << "Введите номер изменяемого объекта: " << endl;
						int a;
						cin >> a;
						if (a >= k) break;
						cBusinessman tmp;
						cin >> tmp;
						bs[a - 1] = tmp;
						break;
				}
				case '9':
				{
						system("cls");
						cBusinessman tmp;
						cin >> tmp;
						bs[k] = tmp;
						k++;
						break;
				}
				case 'q':
				{
						system("cls");
						cout << setw(15) << "Имя" << setw(15) << "Фамилия" << setw(8) << "Возраст" << setw(8) << "Паспорт" << setw(10) << "Страна"
								<< setw(10) << "Дата" << setw(9) << "Лицензия" << setw(10) << "Сумма"
								<< setw(6) << "Дата" << setw (20) << "Адрес" << endl;
						for (int x = 0; x<l; x++)
								cout << bst[x];
						system("pause");
						break;
				}
				case 'w':
				{
						system("cls");
						cout << "Введите номер изменяемого объекта: " << endl;
						int a;
						cin >> a;
						if (a >= l) break;
						cBusinessTourist tmp;
						cin >> tmp;
						bst[a - 1] = tmp;
						break;
				}
				case 'e':
				{
						system("cls");
						cBusinessTourist tmp;
						cin >> tmp;
						bst[l] = tmp;
						l++;
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
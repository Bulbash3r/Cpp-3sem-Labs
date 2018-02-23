#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <conio.h>
#include <fstream>
#include "BalanceChange.h"
#include "User.h"
#include "List.h"
#include "Consum.h"
#include "Income.h"
#include <windows.h>
#include <vector>
#include "File.h"

using namespace std;

int main()
{
		system("color F0");
		setlocale(LC_ALL, "Russian");

		List<Consum> consum;
		List<Income> income;

		File<Income> fi;
		File<Consum> fc;

		fi.FileOpenIncome(income, "income.txt");
		fc.FileOpenConsum(consum, "consum.txt");

		ifstream if_user("user.txt");
		User MainUser;
		cout << "Введите имя пользователя: ";
		cin >> MainUser;
		ofstream of_user("user.txt");
		MainUser.setBalance(income.getBalance(income, consum));
		of_user << MainUser.getUsername() << " " << MainUser.getBalance();
		of_user.close();

		HWND hWnd = GetForegroundWindow();	//запрет аварийного закрытия окна (через крестик)
		EnableWindow(hWnd, false);

		vector<Consum> CCancel;
		vector<int> c;
		vector<Income> ICancel;
		vector<int> i;

		while (true)
		{
				MainUser.setBalance(income.getBalance(income, consum));
				system("cls");
				cout << "Вас приветствует система Домашняя бухгалтерия!" << endl;
				cout << "Добро пожаловать, " << MainUser.getUsername() << "!" << endl;
				cout << "Ваш текущий баланс составляет " << MainUser.getBalance() <<  "р." << endl << endl;
				cout << "Выберите действие, которое хотите совершить:" << endl;
				cout << "1. Добавить доход в базу" << endl;
				cout << "2. Добавить расход в базу" << endl;
				cout << "3. Посмотреть список доходов" << endl;
				cout << "4. Посмотреть список расходов" << endl;
				cout << "5. Удалить последний доход из базы" << endl;
				cout << "6. Удалить последний расход из базы" << endl;
				cout << "7. Изменить доход" << endl;
				cout << "8. Изменить расход" << endl;
				cout << "9. Вывод доходов по типу" << endl;
				cout << "q. Вывод расходов по типу" << endl;
				cout << "c. Отмена предыдущего действия с доходом" << endl;
				cout << "v. Отмена предыдущего действия с расходом" << endl;
				cout << "r. Обновить состояние" << endl;
				cout << "0. Выход из программы" << endl;
				switch (_getch())
				{
				case '1':		//Добавить доход
				{
						system("cls");
						Income tmp;
						cin >> tmp;
						income.push_tail(tmp);
						ICancel.insert(ICancel.end(), tmp);
						i.insert(i.end(), 1);
						system("pause");
						break;
				}
				case '2':		//Добавить расход
				{
						system("cls");
						Consum tmp;
						cin >> tmp;
						if (CheckConsum(MainUser.getBalance() - tmp.getSum()))
						{
								system("pause");
								break;
						}
						consum.push_tail(tmp);
						CCancel.insert(CCancel.end(), tmp);
						c.insert(c.end(), 1);
						system("pause");
						break;
				}
				case '3':		//Посмотреть доходы
				{
						system("cls");
						if (income.size() > 0)
						{
								cout << setw(3) << "#" << setw(12) << "Сумма" << setw(15) << "Тип" << endl << endl;
								income.output();
								cout << endl;
						}
						else cout << "Список пуст!" << endl;
						system("pause");
						break;
				}
				case '4':		//Посмотреть расходы
				{
						system("cls");
						if (consum.size() > 0)
						{
								cout << setw(3) << "#" << setw(12) << "Сумма" << setw(25) << "Тип" << setw(8) << "Долг" << endl << endl;
								consum.output();
								cout << endl;
						}
						else cout << "Список пуст!" << endl;
						system("pause");
						break;
				}
				case '5':		//Удалить доход
				{
						system("cls");
						if (CheckConsum(MainUser.getBalance()- income[income.size()-1].getSum()))
						{
								system("pause");
								break;
						}
						if (income.size() == 1)
						{
								Income tmp = income[income.size()];
								ICancel.insert(ICancel.end(), tmp);
								i.insert(i.end(), 2);
								income.pop_head();
						}
						if (income.size() > 1)
						{
								Income tmp = income[income.size()];
								ICancel.insert(ICancel.end(), tmp);
								i.insert(i.end(), 2);
								income.pop_tail();
						}
						system("pause");
						break;
				}
				case '6':		//Удалить расход
				{
						system("cls");
						
						if (consum.size() == 1)
						{
								Consum tmp = consum[consum.size()];
								CCancel.insert(CCancel.end(), tmp);
								c.insert(c.end(), 2);
								consum.pop_head();
						}
						if (consum.size() > 1)
						{
								Consum tmp = consum[consum.size()];
								CCancel.insert(CCancel.end(), tmp);
								c.insert(c.end(), 2);
								consum.pop_tail();
						}
						system("pause");
						break;
				}
				case '7':		//Изменить доход
				{
						system("cls");
						cout << "Введите номер изменяемого дохода: ";
						int tempNumber=InputCheck(1, consum.size());
						Income tmp;
						cin >> tmp;
						income[tempNumber-1] = tmp;
						system("pause");
						break;
				}
				case '8':		//Изменить расход
				{
						system("cls");
						cout << "Введите номер изменяемого расхода: ";
						int tempNumber=InputCheck(1,consum.size());
						Consum tmp;
						cin >> tmp;
						if (CheckConsum(MainUser.getBalance() - tmp.getSum()))
						{
								system("pause");
								break;
						}
						consum[tempNumber-1] = tmp;
						system("pause");
						break;
				}
				case '9':		//Просмотр по типу дохода
				{
						system("cls");
						cout << "Выберите тип дохода: " << endl;
						cout << "1. Зарплата" << endl;
						cout << "2. Подарок" << endl;
						cout << "3. Дивиденды" << endl;
						cout << "4. Другое" << endl;
						int tempType=InputCheck(1,4);
						system("cls");
						income.output_for_type(tempType);
						system("pause");
						break;
				}
				case 'q':		//Просмотр по типу расхода
				{
						system("cls");
						cout << "Выберите тип расхода: " << endl;
						cout << "1. Еда" << endl;
						cout << "2. Одежда" << endl;
						cout << "3. Медицина и здоровье" << endl;
						cout << "4. Автомобиль" << endl;
						cout << "5. Дом" << endl;
						cout << "6. Интернет и мобильная связь" << endl;
						cout << "7. Транспорт" << endl;
						cout << "8. Другое" << endl;
						int tempType = InputCheck(1, 8);
						system("cls");
						consum.output_for_type(tempType);
						system("pause");
						break;
				}
				case 'c':		//Отмена действия с доходом
				{
						if (i.back() == 1)
						{
								income.pop_tail();
								i.erase(i.end() - 1);
								ICancel.erase(ICancel.end() - 1);
						}
						if (i.back() == 2)
						{
								income.push_tail(ICancel.back());
								i.erase(i.end() - 1);
								ICancel.erase(ICancel.end() - 1);
						}
						break;
				}
				case 'v':		//Отмена действия с расходом
				{
						if (c.back() == 1)
						{
								consum.pop_tail();
								c.erase(c.end() - 1);
								CCancel.erase(CCancel.end() - 1);
						}
						if (c.back() == 2)
						{
								consum.push_tail(CCancel.back());
								c.erase(c.end() - 1);
								CCancel.erase(CCancel.end() - 1);
						}
						break;
				}
				case 'r':		//Обновление баланса (мой маленький рудементик курсача)
				{
						MainUser.setBalance(income.getBalance(income,consum));
						break;
				}
				case '0':		//Безопасный выход из программы
				{
						fi.FileSaveIncome(income, "income.txt");
						fc.FileSaveConsum(consum, "consum.txt");
						exit (0);
				}
				}
		}
}
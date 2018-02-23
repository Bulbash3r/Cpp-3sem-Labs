#include "Consum.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include "InputException.h"

using namespace std;

Consum::Consum(const Consum &tmp)
{
		sum = tmp.sum;
		debt = tmp.debt;
		type = tmp.type;
}
Consum::Consum(int _type, double _sum, bool _debt)
{
		type = _type;
		sum = _sum;
		debt = _debt;
}

void operator >> (std::istream & is, Consum & tmp)
{
		cout << "Введите сумму расхода: ";
		tmp.sum=InputCheck(0, 999999);
		cout << "Выберите тип расхода:" << endl;
		cout << "1. Еда" << endl;
		cout << "2. Одежда" << endl;
		cout << "3. Медицина и здоровье" << endl;
		cout << "4. Автомобиль" << endl;
		cout << "5. Дом" << endl;
		cout << "6. Интернет и мобильная связь" << endl;
		cout << "7. Транспорт" << endl;
		cout << "8. Другое" << endl;
		tmp.type = InputCheck(1, 8);
		if (tmp.type == 8)
		{
						cout << "Это долг?" << endl;
						cout << "1 - Да" << endl;
						cout << "Любой другой символ - нет" << endl;
						switch (_getch())
						{
						case '1':
						{
								tmp.debt = true; break;
						}
						default:
						{
								tmp.debt = false; break;
						}
						}
		}
}
void operator << (std::ostream & os, Consum & tmp)
{
		os << setw(12) << tmp.sum;
		switch (tmp.type)
		{
		case 1:
		{
				os << setw(25) << "Еда";
				break;
		}
		case 2:
		{
				os << setw(25) << "Одежда";
				break;
		}
		case 3:
		{
				os << setw(25) << "Медицина и здоровье";
				break;
		}
		case 4:
		{
				os << setw(25) << "Автомобиль";
				break;
		}
		case 5:
		{
				os << setw(25) << "Домашние расходы";
				break;
		}
		case 6:
		{
				os << setw(25) << "Интернет и моб. связь";
				break;
		}
		case 7:
		{
				os << setw(25) << "Транспорт";
				break;
		}
		case 8:
		{
				os << setw(25) << "Другое";
				if (tmp.debt)
						os << setw(8) << "Да";
				break;
		}
		}
}
void Consum::operator = (const Consum & tmp)
{
		sum = tmp.sum;
		debt = tmp.debt;
		type = tmp.type;
}

bool  operator== (Consum tmp1, Consum tmp2)
{
		if (tmp1.debt == tmp2.debt && tmp1.sum == tmp2.sum && tmp1.type == tmp2.type)
				return true;
		return false;
}
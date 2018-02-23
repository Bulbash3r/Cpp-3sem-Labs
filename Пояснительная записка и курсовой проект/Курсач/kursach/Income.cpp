#include "Income.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include "InputException.h"

using namespace std;

Income::Income(const Income &tmp)
{
		sum = tmp.sum;
		type = tmp.type;
}
Income::Income(int _type, double _sum)
{
		type = _type;
		sum = _sum;
}

void operator >> (std::istream & is, Income & tmp)
{
		cout << "Введите сумму дохода: ";
		tmp.sum=InputCheck(0,999999);
		cout << "Выберите тип дохода:" << endl;
		cout << "1. Зарплата" << endl;
		cout << "2. Подарок" << endl;
		cout << "3. Дивиденды" << endl;
		cout << "4. Другое" << endl;
		tmp.type = InputCheck(1, 4);
}
void operator << (std::ostream & os, Income & tmp)
{
		os << setw(12) << tmp.sum;
		switch (tmp.type)
		{
		case 1:
		{
				os << setw(15) << "Зарплата";
				break;
		}
		case 2:
		{
				os << setw(15) << "Подарок";
				break;
		}
		case 3:
		{
				os << setw(15) << "Дивиденды";
				break;
		}
		case 4:
		{
				os << setw(15) << "Другое";
				break;
		}
		}
}
void Income::operator = (const Income & tmp)
{
		sum = tmp.sum;
		type = tmp.type;
}

bool  operator== (Income tmp1, Income tmp2)
{
		if (tmp1.sum == tmp2.sum && tmp1.type == tmp2.type)
				return true;
		return false;
}
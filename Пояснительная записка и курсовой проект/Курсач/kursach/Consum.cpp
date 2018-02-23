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
		cout << "������� ����� �������: ";
		tmp.sum=InputCheck(0, 999999);
		cout << "�������� ��� �������:" << endl;
		cout << "1. ���" << endl;
		cout << "2. ������" << endl;
		cout << "3. �������� � ��������" << endl;
		cout << "4. ����������" << endl;
		cout << "5. ���" << endl;
		cout << "6. �������� � ��������� �����" << endl;
		cout << "7. ���������" << endl;
		cout << "8. ������" << endl;
		tmp.type = InputCheck(1, 8);
		if (tmp.type == 8)
		{
						cout << "��� ����?" << endl;
						cout << "1 - ��" << endl;
						cout << "����� ������ ������ - ���" << endl;
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
				os << setw(25) << "���";
				break;
		}
		case 2:
		{
				os << setw(25) << "������";
				break;
		}
		case 3:
		{
				os << setw(25) << "�������� � ��������";
				break;
		}
		case 4:
		{
				os << setw(25) << "����������";
				break;
		}
		case 5:
		{
				os << setw(25) << "�������� �������";
				break;
		}
		case 6:
		{
				os << setw(25) << "�������� � ���. �����";
				break;
		}
		case 7:
		{
				os << setw(25) << "���������";
				break;
		}
		case 8:
		{
				os << setw(25) << "������";
				if (tmp.debt)
						os << setw(8) << "��";
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
#include "InputException.h"
#include <iostream>

using namespace std;

void InputException::NumError()
{
		switch (error)
		{
		case 1:
				cout << "������ 1.1" << endl;
				cout << "�� ����� ������������ ������!" << endl;
				cout << "�������� ���� ������ ���� ���������� ��������." << endl << endl;
				break;
		case 2:
				cout << "������ 1.2" << endl;
				cout << "����� ������������ ������ ���� ����� ������ �� ����� ����" << endl << endl;
				break;
		case 3:
				cout << "������ 1.3" << endl;
				cout << "�������� ����� �� ����� ��������!" << endl;
				cout << "����������� ���������� �������� - 15 ��������." << endl << endl;
				break;
		case 4:
				cout << "������ 1.4" << endl;
				cout << "�� ����� ������� ������ ����� ���� �������� ������ �� ����� �����!" << endl << endl;
				break;
		case 5:
				cout << "������ 1.5" << endl;
				cout << "������ �� ����� ��������� ����� ���� ������ ������." << endl << endl;
				break;
		case 6:
				cout << "������ 1.6" << endl;
				cout << "������ �� ����� ���������� �� ����� ������." << endl << endl;
				break;
		case 7:
				cout << "������ 1.7" << endl;
				cout << "���������� ������� ����. ������ - ��.��.����" << endl << endl;
				break;
		case 8:
				cout << "������ 1.8" << endl;
				cout << "����������� ����� ��� ���������� ���, ������ � ����" << endl << endl;
				break;
		case 9:
				cout << "������ 1.9" << endl;
				cout << "����������� ������������ ������. �������� ���� ������ ���� � ������� �����." << endl << endl;
				break;
		case 10:
				cout << "������ 1.10" << endl;
				cout << "������� ����� ����." << endl << endl;
				break;
		case 11:
				cout << "������ 1.11" << endl;
				cout << "������� ����� �����." << endl << endl;
				break;
		case 12:
				cout << "������ 1.12" << endl;
				cout << "������� ����� ���." << endl << endl;
				break;
		default:
				puts("������ �����");
				puts("��������� ����");
				break;
		}
}
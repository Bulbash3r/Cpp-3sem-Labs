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
				cout << "�������� ���� ������ ���� ���������� �������� � ����." << endl << endl;
				break;
		case 2:
				cout << "������ 1.2" << endl;
				cout << "��� ������������ �� ����� ���������� � �����!" << endl << endl;
				break;
		case 3:
				cout << "������ 1.3" << endl;
				cout << "�������� ����� �� ����� ��������!" << endl;
				cout << "����������� ���������� �������� - 20 ��������." << endl << endl;
				break;
		case 4:
				cout << "������ 3.1" << endl;
				cout << "�� ����� ������� ������ ����� ���� �������� ������ �� ����� �����!" << endl << endl;
				break;
		case 5:
				cout << "������ 1.4" << endl;
				cout << "���������� ��������� ��������!" << endl;
				cout << "������ ������������ �� ����� ���� �������������" << endl;
				break;
		default:
				puts("������ �����");
				puts("��������� ����");
				break;
		}
}
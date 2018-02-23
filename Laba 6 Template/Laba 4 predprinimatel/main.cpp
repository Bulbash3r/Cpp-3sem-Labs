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
				cout << "�������� ��������:" << endl;
				cout << "1. ����������� cTourist" << endl;
				cout << "2. �������� cTourist" << endl;
				cout << "3. �������� cTourist" << endl;
				cout << "4. ������� cTourist" << endl << endl;
				cout << "0. �����" << endl;
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
								cout << setw(20) << "���" << setw(20) << "�������" << setw(9) << "�������" << setw(9) << "�������" << setw(20) << "������"
									   << setw(12) << "����" << endl;
								t.output();
								//cout << endl;
						}
						else cout << "������ ����!" << endl;
						system("pause");
						break;
				}
				case '2':
				{
						system("cls");
						cout << "������� ����� ����������� �������: " << endl;
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
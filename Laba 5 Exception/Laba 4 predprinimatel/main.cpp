#include <iostream>
#include <iomanip>
#include "String.h"
using namespace std;

#define SIZE 10

#include "Human.h"
#include "tourist.h"

int main()
{
		setlocale(LC_CTYPE, "Russian");
		cHuman h[SIZE]; int i = 0;
		cTourist t[SIZE]; int j = 0;
		system("cls");

		while (1)
		{
				system("cls");
				cout << "�������� ��������:" << endl;
				cout << "1. ����������� cTourist" << endl;
				cout << "2. �������� cTourist" << endl;
				cout << "3. �������� cTourist" << endl << endl;
				cout << "0. �����" << endl;
				cin.sync();
				rewind(stdin);
				int choice = cin.get();
				switch (choice)
				{
				case '1':
				{
						system("cls");
						cout << setw(20) << "���" << setw(20) << "�������" << setw(9) << "�������" << setw(9) << "�������" << setw(20) << "������"
								<< setw(12) << "����" << endl;
						for (int x = 0; x<j; x++)
								cout << t[x];
						system("pause");
						break;
				}
				case '2':
				{
						system("cls");
						cout << "������� ����� ����������� �������: " << endl;
						int a;
						cin >> a;
						if (a >= j) break;
						cTourist tmp;
						cin >> tmp;
						t[a - 1] = tmp;
						break;
				}
				case '3':
				{
						system("cls");
						cTourist tmp;
						cin >> tmp;
						t[j] = tmp;
						j++;
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
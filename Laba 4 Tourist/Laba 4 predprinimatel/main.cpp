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
				cout << "�������� ��������:" << endl;
				cout << "1. ����������� cHuman" << endl;
				cout << "2. �������� cHuman" << endl;
				cout << "3. �������� cHuman" << endl << endl;
				cout << "4. ����������� cTourist" << endl;
				cout << "5. �������� cTourist" << endl;
				cout << "6. �������� cTourist" << endl << endl;
				cout << "7. ����������� cBusinessman" << endl;
				cout << "8. �������� cBusinessman" << endl;
				cout << "9. �������� cBusinessman" << endl << endl;
				cout << "q. ����������� cBusinessTourist" << endl;
				cout << "w. �������� cBusinessTourist" << endl;
				cout << "e. �������� cBusinessTourist" << endl << endl;
				cout << "0. �����" << endl;
				cin.sync();
				rewind(stdin);
				int choice = cin.get();
				switch (choice)
				{
				case '1':
				{
						system("cls");
						cout << setw(15) << "���" << setw(15) << "�������" << setw(8) << "�������" << endl;
						for (int x=0; x<i; x++)
								cout << h[x];
						system("pause");
						break;
				}
				case '2':
				{
						system("cls");
						cout << "������� ����� ����������� �������: " << endl;
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
						cout << setw(15) << "���" << setw(15) << "�������" << setw(8) << "�������" << setw(8) << "�������" << setw(10) << "������"
								<< setw(6) << "����" << endl;
						for (int x = 0; x<j; x++)
								cout << t[x];
						system("pause");
						break;
				}
				case '5':
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
						cout << setw(15) << "���" << setw(15) << "�������" << setw(8) << "�������" << setw(9) << "��������" << setw(10) << "�����"
								<< setw(6) << "����" << endl;
						for (int x = 0; x<k; x++)
								cout << bs[x];
						system("pause");
						break;
				}
				case '8':
				{
						system("cls");
						cout << "������� ����� ����������� �������: " << endl;
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
						cout << setw(15) << "���" << setw(15) << "�������" << setw(8) << "�������" << setw(8) << "�������" << setw(10) << "������"
								<< setw(10) << "����" << setw(9) << "��������" << setw(10) << "�����"
								<< setw(6) << "����" << setw (20) << "�����" << endl;
						for (int x = 0; x<l; x++)
								cout << bst[x];
						system("pause");
						break;
				}
				case 'w':
				{
						system("cls");
						cout << "������� ����� ����������� �������: " << endl;
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
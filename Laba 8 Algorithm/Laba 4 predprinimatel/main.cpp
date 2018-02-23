#include <iostream>
#include <iomanip>
#include "List.h"																												//��������� output
#include "Algorithm.h"
using namespace std;

#define SIZE 10

#include "Human.h"
#include "tourist.h"

int main()
{
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
				cout << "4. ������� cTourist" << endl;
				cout << "5. ����� cTourist" << endl;
				cout << "6. ����������� �� ��������" << endl;
				cout << "7. ����������� �� �������" << endl;
				cout << "8. ���������� �� ���������� �����" << endl;
				cout << "9. ����� �� �����" << endl << endl;
				cout << "0. �����" << endl;
				cin.sync();
				rewind(stdin);
				int choice = cin.get();
				switch (choice)
				{
				case '1':
				{
						system("cls");
						if (t.size() > 0)
						{
								cout << setw(20) << "���" << setw(20) << "�������" << setw(9) << "�������" << setw(9) << "�������" << setw(20) << "������"
										<< setw(12) << "����" << endl;
								t.output();
								cout << endl;
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
				case '5':
				{
						system("cls");
						cTourist tmp;
						cin >> tmp;
						Algorithm<cTourist> tempalg;
						tempalg.Find(tmp, t);
						break;
				}
				case '6':
				{
						Algorithm<cTourist> tempalg;
						tempalg.sortAge(t);
						break;
				}
				case '7':
				{
						Algorithm<cTourist> tempalg;
						tempalg.sortName(t);
				}
				case '8':
				{
						int *ms = new int[6];
						for (int i = 0; i < 6; i++)
						{
								ms[i] = 0;
						}
						cout << "1. ���" << endl;
						cout << "2. �������" << endl;
						cout << "3. �������" << endl;
						cout << "4. ����� ��������" << endl;
						cout << "5. ������" << endl;
						cout << "6. ����" << endl;
						cout << "0. �����" << endl;

						while (1)
						{
								int tmp;
								cin >> tmp;
								if (tmp == 0) break;
								ms[tmp - 1] = 1;
						}

						Algorithm<cTourist> tempalg;
						tempalg.sortAll(t, ms);

						break;
				}
				case '9':
				{
						system("cls");
						string tmp;
						cin >> tmp;
						Algorithm<cTourist> tempalg;
						tempalg.FindName(tmp, t);
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
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
		cout << "������� ��� ������������: ";
		cin >> MainUser;
		ofstream of_user("user.txt");
		MainUser.setBalance(income.getBalance(income, consum));
		of_user << MainUser.getUsername() << " " << MainUser.getBalance();
		of_user.close();

		HWND hWnd = GetForegroundWindow();	//������ ���������� �������� ���� (����� �������)
		EnableWindow(hWnd, false);

		vector<Consum> CCancel;
		vector<int> c;
		vector<Income> ICancel;
		vector<int> i;

		while (true)
		{
				MainUser.setBalance(income.getBalance(income, consum));
				system("cls");
				cout << "��� ������������ ������� �������� �����������!" << endl;
				cout << "����� ����������, " << MainUser.getUsername() << "!" << endl;
				cout << "��� ������� ������ ���������� " << MainUser.getBalance() <<  "�." << endl << endl;
				cout << "�������� ��������, ������� ������ ���������:" << endl;
				cout << "1. �������� ����� � ����" << endl;
				cout << "2. �������� ������ � ����" << endl;
				cout << "3. ���������� ������ �������" << endl;
				cout << "4. ���������� ������ ��������" << endl;
				cout << "5. ������� ��������� ����� �� ����" << endl;
				cout << "6. ������� ��������� ������ �� ����" << endl;
				cout << "7. �������� �����" << endl;
				cout << "8. �������� ������" << endl;
				cout << "9. ����� ������� �� ����" << endl;
				cout << "q. ����� �������� �� ����" << endl;
				cout << "c. ������ ����������� �������� � �������" << endl;
				cout << "v. ������ ����������� �������� � ��������" << endl;
				cout << "r. �������� ���������" << endl;
				cout << "0. ����� �� ���������" << endl;
				switch (_getch())
				{
				case '1':		//�������� �����
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
				case '2':		//�������� ������
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
				case '3':		//���������� ������
				{
						system("cls");
						if (income.size() > 0)
						{
								cout << setw(3) << "#" << setw(12) << "�����" << setw(15) << "���" << endl << endl;
								income.output();
								cout << endl;
						}
						else cout << "������ ����!" << endl;
						system("pause");
						break;
				}
				case '4':		//���������� �������
				{
						system("cls");
						if (consum.size() > 0)
						{
								cout << setw(3) << "#" << setw(12) << "�����" << setw(25) << "���" << setw(8) << "����" << endl << endl;
								consum.output();
								cout << endl;
						}
						else cout << "������ ����!" << endl;
						system("pause");
						break;
				}
				case '5':		//������� �����
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
				case '6':		//������� ������
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
				case '7':		//�������� �����
				{
						system("cls");
						cout << "������� ����� ����������� ������: ";
						int tempNumber=InputCheck(1, consum.size());
						Income tmp;
						cin >> tmp;
						income[tempNumber-1] = tmp;
						system("pause");
						break;
				}
				case '8':		//�������� ������
				{
						system("cls");
						cout << "������� ����� ����������� �������: ";
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
				case '9':		//�������� �� ���� ������
				{
						system("cls");
						cout << "�������� ��� ������: " << endl;
						cout << "1. ��������" << endl;
						cout << "2. �������" << endl;
						cout << "3. ���������" << endl;
						cout << "4. ������" << endl;
						int tempType=InputCheck(1,4);
						system("cls");
						income.output_for_type(tempType);
						system("pause");
						break;
				}
				case 'q':		//�������� �� ���� �������
				{
						system("cls");
						cout << "�������� ��� �������: " << endl;
						cout << "1. ���" << endl;
						cout << "2. ������" << endl;
						cout << "3. �������� � ��������" << endl;
						cout << "4. ����������" << endl;
						cout << "5. ���" << endl;
						cout << "6. �������� � ��������� �����" << endl;
						cout << "7. ���������" << endl;
						cout << "8. ������" << endl;
						int tempType = InputCheck(1, 8);
						system("cls");
						consum.output_for_type(tempType);
						system("pause");
						break;
				}
				case 'c':		//������ �������� � �������
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
				case 'v':		//������ �������� � ��������
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
				case 'r':		//���������� ������� (��� ��������� ���������� �������)
				{
						MainUser.setBalance(income.getBalance(income,consum));
						break;
				}
				case '0':		//���������� ����� �� ���������
				{
						fi.FileSaveIncome(income, "income.txt");
						fc.FileSaveConsum(consum, "consum.txt");
						exit (0);
				}
				}
		}
}
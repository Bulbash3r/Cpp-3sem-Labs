#include <iostream>
#include <iomanip>
#include "List.h"
#include <queue>
#include "File.h"
#include <algorithm>
using namespace std;

#include "Human.h"
#include "tourist.h"

bool myfunction(cTourist i, cTourist j) { return (i<j); }
struct myclass {
bool operator() (cTourist i, cTourist j) { return (i<j); }
} myobject;

int main()
{
		queue<cTourist> q;
		setlocale(LC_CTYPE, "Russian");
		system("cls");

		while (1)
		{
				system("cls");
				cout << "Выберите действие:" << endl;
				cout << "1. Просмотреть всю очередь" << endl;
				cout << "2. Размер очереди" << endl;
				cout << "3. Добавить в очередь" << endl;
				cout << "4. Удалить" << endl << endl;
				cout << "0. Выход" << endl;
				cin.sync();
				rewind(stdin);
				int choice = cin.get();
				switch (choice)
				{
				case '1':
				{
						queue<cTourist> temp = q;
						if (q.size() == 0) break;
						system("cls");
						while (!temp.empty())
						{
								cout << temp.front();
								temp.pop();
						}
						system("pause");
						break;
				}
				case '2':
				{
						system("cls");
						cout << "Размер очереди " << q.size() << " элемента(-ов)" << endl;
						system("pause");
						break;
				}
				case '3':
				{
						system("cls");
						cTourist tmp;
						cin >> tmp;
						q.push(tmp);
						break;
				}
				case '4':
				{
						if (q.size() == 0) break;
						system("cls");
						q.pop();
						system("pause");
						break;
				}
				case '5':
				{
						(q.front(), q.back(), q, myobject);
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
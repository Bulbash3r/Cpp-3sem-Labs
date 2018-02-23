#include "ListException.h"
#include <iostream>

using namespace std;

void ListException::NumError()
{
		switch (error)
		{
		case 1:
				cout << "Ошибка 2.1" << endl;
				cout << "Список пуст" << endl;
				break;
		}
}
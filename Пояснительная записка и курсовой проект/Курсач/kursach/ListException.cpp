#include "ListException.h"
#include <iostream>

using namespace std;

void ListException::NumError()
{
		switch (error)
		{
		case 1:
				cout << "������ 2.1" << endl;
				cout << "������ ����" << endl;
				break;
		}
}
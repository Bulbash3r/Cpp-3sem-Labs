#include <iostream>
#include "myString.h"

using namespace std;

int main()
{
		setlocale(LC_CTYPE, "Russian");
		myString obj1 = myString("Hello");
		myString obj2 ("world");
		myString obj3;
		myString obj4;

		obj3 += obj2;
		obj3.printString();
		obj4 = obj1 + obj2;
		obj4.printString();
		cout << obj4[0] << endl;

		system("pause");
		return 0;
}
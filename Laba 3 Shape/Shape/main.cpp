#include <iostream>
#include"Shape.h"
#include"Circle.h"
#include"Rectangle.h"
#include"Triangle.h"
#include"Sphere.h"
#include"Cylinder.h"
#include"Parallelepiped.h"

using namespace std;

int main()
{
		setlocale(LC_CTYPE, "Russian");
		int pr;
		do {
				int i=1;
				cout << "�������� ������:" << endl;
				cout << "1.����" << endl;
				cout << "2.�������������" << endl;
				cout << "3.�����������" << endl;
				cout << "4.�����" << endl;
				cout << "5.��������������" << endl;
				cout << "6.�������" << endl;
				cin >> i;
				switch (i)
				{
				case 1: {
						Shape *p = new Krug(5,5,1,1);
						p->name();
						cout << p->Area() << endl; 
						delete p; 
						break;
				};
				case 2: {
						Rectangle tmp(1, 1, 5, 5);
						Shape *p = &tmp;
						tmp.name();
						cout << p->Volume() << endl; break;
				};
				case 3: {
						Treugolnik tmp(1, 1, 5, 5);
						Shape *p = &tmp;
						tmp.name();
						cout << p->Area() << endl; 
						cout << p->Volume() << endl; break;
				};
				case 4: {
						Sfera tmp(5);
						Shape *p = &tmp;
						tmp.name();
						cout << p->Volume() << endl; break;
				};
				case 5: {
						Parallelepiped tmp(2, 5, 3);
						Shape *p = &tmp;
						tmp.name();
						cout << p->Area() << endl; break;
				};
				case 6: {
						Cylinder tmp(3, 5);
						Shape *p = &tmp;
						tmp.name();
						cout << p->Volume() << endl;
						cout << p->Area() << endl; break;
				};
				}
				cout << "1 to continue. . ." << endl;
				cin >> pr;
		} while (pr == 1);

		
		system("pause");
		return 0;
}
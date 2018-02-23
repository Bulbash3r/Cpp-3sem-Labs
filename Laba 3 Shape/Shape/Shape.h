#ifndef _SHAPE_H_
#define _SHAPE_H_
#include <iostream>
using namespace std;

class Shape
{
public:
		Shape()
		{	cout << "constr Shape" << endl;	}
		/*virtual*/ ~Shape() { cout << "destruktor Shape" << endl; }
		virtual double Area() = 0;
		virtual double Volume() = 0;
		virtual void name() {};
};

#endif
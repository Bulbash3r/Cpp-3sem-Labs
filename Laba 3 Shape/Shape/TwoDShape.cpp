#include"TwoDShape.h"

Shape2d::Shape2d(int _x,int _y)
{
	this->x = _x;
	this->y = _y;
	cout << "constr TwoD" << endl;
}

Shape2d::~Shape2d() { cout << "destruktor TwoD" << endl; }

void Shape2d::Set(int _x,int _y)
{
	this->x = _x;
	this->y = _y;
}
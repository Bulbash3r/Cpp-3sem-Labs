#include"Cylinder.h"
#include<iostream>
using namespace std;

Cylinder::~Cylinder()
{
}

void Cylinder::Input()
{
	int tmp;
	cout << "¬ведите радиус:";
	cin >> tmp;
	Shape3d::set(tmp);
	cout << "¬ведите высоту:";
	cin >> height;
}

void Cylinder::name()
{
	cout << "÷илиндр" << endl;
}

double Cylinder::Volume()
{
	return 3.14 * this->getRadius() * this->getRadius() * height;
}

double Cylinder::Area()
{
	return 2 * 3.14 * this->getRadius() * (this->getRadius() + height);
}


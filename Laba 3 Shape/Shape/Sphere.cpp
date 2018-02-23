#include"Sphere.h"
#include<iostream>
using namespace std;
#include<cmath>

Sfera::Sfera(int _radius) : Shape3d(_radius)
{

}

Sfera::~Sfera()
{
}

double Sfera::Volume()
{
	double volume;
	return volume = (4 * 3.14 * this->getRadius() * this->getRadius() * this->getRadius())/3;
}

double Sfera::Area()
{
	double area;
	return area = 4 * 3.14 * this->getRadius() * this->getRadius();
}

void Sfera::Input()
{
	int tmp;
	cout << "Введите радиус:";
	cin >> tmp;
	Shape3d::set(tmp);
}

void Sfera::name()
{
	cout << "Сфера" << endl;
}
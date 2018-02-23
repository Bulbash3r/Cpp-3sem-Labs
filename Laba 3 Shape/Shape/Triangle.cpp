#include"Triangle.h"
#include<iostream>
using namespace std;

Treugolnik::Treugolnik(int _x,int _y,int _x2,int _y2) : Shape2d(_x,_y)
{
	this->x2 = _x2;
	this->y2 = _y2;
}

Treugolnik::~Treugolnik()
{
}

void Treugolnik::Set(int _x,int _y,int _x2,int _y2)
{
	Shape2d::Set(_x,_y);
	this->x2 = _x2;
	this->y2 = _y2;
}

double Treugolnik::Area()
{
	int d_x = 0,d_y = 0;

	if(this->x2 > this->GetX())
		d_x = this->x2 - this->GetX();
	else if(this->x2 < this->GetX())
		d_x = this->GetX() - this->x2;
	else if(this->x2 == this->GetX())
		d_x = 0;

	if(this->y2 > this->GetY())
		d_y = this->y2 - this->GetY();
	else if(this->y2 < this->GetY())
		d_y = this->GetY() - this->y2;
	else if(this->y2 == this->GetY())
		d_y = 0;
	double area = 0.5 * (d_x * d_y);

	return area;	
}

void Treugolnik::Input()
{
	int tmp1 = 0,tmp2 = 0;
	cout << "¬ведите коорд x:";
	cin >> tmp1;
	cout << "¬ведите коорд y:";
	cin >> tmp2;
	Shape2d::Set(tmp1,tmp2);
	cout << "¬ведите коорд x2:";
	cin >> x2;
	cout << "¬ведите коорд y2:";
	cin >> y2;
}

void Treugolnik::name()
{
	cout << "“реугольник" << endl;
}
#ifndef _TWODSHAPE_H_
#define _TWODSHAPE_H_
#include"Shape.h"

class Shape2d : public Shape
{
private:
	int x;
	int y;
public:
	Shape2d(int _x = 0, int _y = 0);
	~Shape2d();
	inline int GetX() { return this->x; }
	inline int GetY() { return this->y; }
	void Set(int _x,int _y);
	double Area() { return 0; }
	double Volume() { cout <<"Невозможно вычислить объем данных фигур!" << endl;return 0; }
	void name() {};
};

#endif
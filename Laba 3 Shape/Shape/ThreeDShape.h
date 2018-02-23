#ifndef _THREEDSHAPE_H_
#define _THREEDSHAPE_H_

#include"Shape.h"

class Shape3d: public Shape
{
private:
	int radius;
public:
	Shape3d( int _radius = 0);
	~Shape3d() {};
	int getRadius() { return this->radius; }
	void set(int _radius) { radius = _radius; }
	double Volume() { return 0; };
	double Area() { return 0; };
	void name() {};
};

#endif
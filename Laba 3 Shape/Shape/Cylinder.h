#ifndef _CYLINDER_H_
#define _CYLINDER_H_
#include"ThreeDShape.h"

class Cylinder : public Shape3d
{
private:
	int radius;
	int height;
public:
	Cylinder(int _radius = 0, int _height = 0):Shape3d(_radius)
	{
		height = _height;
	};
	~Cylinder();
	inline int GetHeight() { return this->height; };
	double Volume();
	double Area();
	void Input();
	void name();
};

#endif
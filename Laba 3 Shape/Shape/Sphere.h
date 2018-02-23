#ifndef _SPHERE_H_
#define _SPHERE_H_
#include"ThreeDShape.h"

class Sfera : public Shape3d
{
private:
	
public:
	Sfera(int _radius = 0);
	~Sfera();
	double Volume();
	double Area();
	void Input();
	void name();
};

#endif
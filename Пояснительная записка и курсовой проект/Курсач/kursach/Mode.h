#pragma once
#include<iostream>
#include <iomanip>
#include "User.h"

using namespace std;

template <class X> 
class Mode
{
public:
		void Act(X obj, int i, const char *filename, int choice);
};

template <class X>
void Mode<X>::Act(X obj, int i, const char *filename, int choice)
{
		static Queue<X> init;
		Files<X> f;
		int size = 0;

		size = f.FileOpen(init, filename);
		switch (choice)
		{
		case 1:
		{

		}
		case 2:
		{

		}
		case 3:
		{

		}
		case 4:
		{

		}
		case 5:
		{

		}
		case 6:
		{

		}
		case 7:
		{

		}
		case 8:
		{

		}
		case 9:
		{

		}
		case 10:
		{

		}
		}
}
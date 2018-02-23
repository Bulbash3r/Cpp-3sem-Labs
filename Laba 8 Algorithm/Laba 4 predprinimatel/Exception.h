#pragma once

#include <iostream>

class Exception
{
protected:
		int error;
public:
		Exception()
		{
				error = 0;
		}
		Exception(int n)
		{
				error = n;
		}
};
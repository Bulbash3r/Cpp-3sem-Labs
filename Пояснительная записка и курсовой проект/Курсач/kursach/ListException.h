#pragma once

#include "exception.h"

class ListException :public Exception
{
public:
		ListException() : Exception() {};
		ListException(int n) : Exception(n) {};
		void NumError();
};

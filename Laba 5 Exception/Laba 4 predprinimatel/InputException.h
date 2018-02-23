#pragma once

#include "Exception.h"
#include <string>

class InputException :public Exception
{
public:
		InputException() :Exception() {};
		InputException(int n) :Exception(n) {};
		void NumError();
};


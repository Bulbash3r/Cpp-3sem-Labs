#pragma once

#include "exception.h"

class InputException :public Exception
{
public:
		InputException() :Exception() {};
		InputException(int n) :Exception(n) {};
		void NumError();
};
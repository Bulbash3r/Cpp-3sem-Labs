#pragma once

#include "Exception.h"

class InputException :public Exception
{
public:
		InputException() :Exception() {};
		InputException(int n) :Exception(n) {};
		void NumError();
};
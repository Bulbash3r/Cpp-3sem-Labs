#pragma once
#include "BalanceChange.h"

class Income : public BalanceChange
{
		int type;
public:
		Income() { type = 0; }
		Income(const Income &tmp);
		Income(int _type, double _sum);
		~Income() {}

		double getSum() { return this->sum; }
		int getType() { return this->type; }

		void setSum(double _sum) { sum = _sum; }
		void setType(int _type) { type = _type; }

		friend void operator >> (std::istream & is, Income & tmp);
		friend void operator << (std::ostream & os, Income & tmp);
		friend bool  operator== (Income tmp1, Income tmp2);
		void operator = (const Income & tmp);
};
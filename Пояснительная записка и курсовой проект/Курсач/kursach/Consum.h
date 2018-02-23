#pragma once
#include "BalanceChange.h"

class Consum : public BalanceChange
{
		int type;
		bool debt;
public: 
		Consum() { type = 0, debt = false; }
		Consum(const Consum &tmp);
		Consum(int _type, double _sum, bool _debt);
		~Consum() {}

		double getSum() { return this->sum; }
		int getType() { return this->type; }
		bool getDebt() { return this->debt; }

		void setSum(double _sum) { sum = _sum; }
		void setType(int _type) { type = _type; }
		void setDebt(int _debt) { debt = _debt; }

		friend void operator >> (istream & is, Consum & tmp);
		friend void operator << (ostream & os, Consum & tmp);
		friend bool operator== (Consum tmp1, Consum tmp2);
		void operator = (const Consum & tmp);
};
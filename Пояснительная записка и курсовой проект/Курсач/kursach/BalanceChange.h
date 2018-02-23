#pragma once
#include <iostream>
using namespace std;
class BalanceChange
{
protected:
		double sum;
public:
		BalanceChange() { sum = 0; }
		~BalanceChange() { }

		double getSum() { return sum; }
		void setSum(double _sum) { this->sum = _sum; }
};
bool CheckConsum(double a);
int InputCheck(double inter1, double inter2);
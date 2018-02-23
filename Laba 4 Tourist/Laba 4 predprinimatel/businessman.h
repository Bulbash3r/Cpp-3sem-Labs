#pragma once
#include "Human.h"

struct tax
{
		String TaxDate;
		int sum;
};

class cBusinessman :  virtual public cHuman
{
protected:
		int NumberOfLicense;
		tax TaxInfo;
public:
		cBusinessman();
		cBusinessman(int _num, int _sum, char* _taxdate);
		cBusinessman(const cBusinessman &tmp);
		~cBusinessman();
		
		friend void operator >> (std::istream & is, cBusinessman & tmp);
		friend void operator << (std::ostream & os, cBusinessman & tmp);
		void cBusinessman::operator = (const cBusinessman & tmp);
};
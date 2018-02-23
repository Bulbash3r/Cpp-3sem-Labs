#pragma once
#include "Human.h"

struct border
{
		String country;
		String date;
};

class cTourist :  virtual public cHuman
{
protected:
		int NumberOfPassport;
		border BorderInfo;
public:
		cTourist();
		cTourist(char *_fname, char *_lname, int _age, int _num, char* _country, char* _date);
		cTourist(const cTourist & tmp);
		~cTourist();

		void operator = (const cTourist & tmp);
		friend void operator << (std::ostream & os, cTourist & tmp);
		friend void operator >> (std::istream & is, cTourist & tmp);
};
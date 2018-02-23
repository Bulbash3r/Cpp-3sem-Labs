#pragma once
#include "tourist.h"
#include "Businessman.h"
#include "Human.h"

class cBusinessTourist : public cTourist, public cBusinessman
{
protected:
		String adress;
public:
		cBusinessTourist() : cTourist(), cBusinessman()
		{
				std::cout << "constr businesstourist ";
		}
		cBusinessTourist(char *_fname, char* _lname, int _age, int _num2, int _sum, char *_taxdate, int _num, char *_country, char *_date, char *_adress) :	cHuman(_fname, _lname, _age), cTourist(_num2, _sum, _taxdate), cBusinessman(_num, _country, _date);
		cBusinessTourist(const cBusinessTourist &tmp);
		~cBusinessTourist();

		friend void operator >> (std::istream & is, cBusinessTourist & tmp);
		friend void operator << (std::ostream & os, cBusinessTourist & tmp);
		void cBusinessTourist::operator = (const cBusinessTourist & tmp);
};
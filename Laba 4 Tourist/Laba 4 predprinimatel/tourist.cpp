#include "tourist.h"
#include <iostream>
#include <iomanip>
using namespace std;

cTourist::cTourist() : cHuman()
{
		cout << "constr tourist ";
		NumberOfPassport = 0;
}

cTourist::cTourist(char *_fname, char *_lname, int _age, int _num, char* _country, char* _date) : cHuman(*_fname, *_lname, _age)
{
		this->FirstName = _fname;
		this->LastName = _lname;
		this->Age = _age;
		this->NumberOfPassport = _num;
		this->BorderInfo.country = _country;
		this->BorderInfo.date = _date;
}

cTourist::cTourist(const cTourist &tmp)
{
		this->FirstName = tmp.FirstName;
		this->LastName = tmp.LastName;
		this->Age = tmp.Age;
		this->NumberOfPassport = tmp.NumberOfPassport;
		this->BorderInfo.country = tmp.BorderInfo.country;
		this->BorderInfo.date = tmp.BorderInfo.date;
}

cTourist::~cTourist()
{
		std::cout << "destr Tourist ";
}

void operator >> (std::istream & is, cTourist & tmp)
{
		cout << "¬ведите им€: ";
		rewind(stdin);
		is >> tmp.FirstName;
		cout << "¬ведите фамилию: ";
		rewind(stdin);
		is >> tmp.LastName;
		cout << "¬ведите возраст: ";
		rewind(stdin);
		is >> tmp.Age;
		cout << "¬ведите номер паспорта: ";
		rewind(stdin);
		is >> tmp.NumberOfPassport;
		cout << "¬ведите страну: ";
		rewind(stdin);
		is >> tmp.BorderInfo.country;
		cout << "¬ведите дату: ";
		rewind(stdin);
		is >> tmp.BorderInfo.date;
}

void operator << (std::ostream & os, cTourist & tmp)
{
		os << setw(15) << tmp.FirstName << setw(15) << tmp.LastName << setw(8) << tmp.Age << setw(8) << tmp.NumberOfPassport << setw (10) << tmp.BorderInfo.country
				<< setw (6) << tmp.BorderInfo.date << endl;
}

void cTourist::operator = (const cTourist & tmp)
{
		this->FirstName = tmp.FirstName;
		this->LastName = tmp.LastName;
		this->Age = tmp.Age;
		this->NumberOfPassport = tmp.NumberOfPassport;
		this->BorderInfo.country = tmp.BorderInfo.country;
		this->BorderInfo.date = tmp.BorderInfo.date;
}
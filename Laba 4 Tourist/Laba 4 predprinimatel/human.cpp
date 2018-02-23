#include "Human.h"
#include <iostream>
#include <iomanip>
using namespace std;

cHuman::cHuman()
{
		cout << "contsr Human ";
}

cHuman::cHuman(char *_fname, char *_lname, int _age)
{
		this->FirstName = _fname;
		this->LastName = _lname;
		this->Age = _age;
}

cHuman::cHuman(const cHuman &tmp)
{
		this->FirstName = tmp.FirstName;
		this->LastName = tmp.LastName;
		this->Age = tmp.Age;
}

void operator >> (std::istream & is, cHuman & tmp)
{
		cout << "¬ведите им€:";
		rewind(stdin);
		is >> tmp.FirstName;
		cout << "¬ведите фамилию:";
		rewind(stdin);
		is >> tmp.LastName;
		cout << "¬ведите возраст:";
		rewind(stdin);
		is >> tmp.Age;
}

void operator << (std::ostream & os, cHuman & tmp)
{
		os << setw(15) << tmp.FirstName << setw(15) << tmp.LastName << setw(8) << tmp.Age << endl;
}

void cHuman::operator = (const cHuman & tmp)
{
		this->FirstName = tmp.FirstName;
		this->LastName = tmp.LastName;
		this->Age = tmp.Age;
}
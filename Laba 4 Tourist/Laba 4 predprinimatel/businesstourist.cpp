#include "businesstourist.h"
#include <iostream>
#include <iomanip>

using namespace std;

cBusinessTourist::cBusinessTourist(char *_fname, char* _lname, int _age, int _num2, int _sum, char *_taxdate, int _num, char *_country, char *_date, char *_adress) : 
		cHuman(_fname, _lname, _age), cTourist(_num2, _sum, _taxdate), cBusinessman (_num, _country, _date)
{
		this->FirstName = _fname;
		this->LastName = _lname;
		this->Age = _age;
		this->NumberOfLicense = _num2;
		this->TaxInfo.sum = _sum;
		this->TaxInfo.TaxDate = _taxdate;
		this->NumberOfPassport = _num;
		this->BorderInfo.country = _country;
		this->BorderInfo.date = _date;
		this->adress = _adress;
}

cBusinessTourist::cBusinessTourist(const cBusinessTourist &tmp)
{
		this->FirstName = tmp.FirstName;
		this->LastName = tmp.LastName;
		this->Age = tmp.Age;
		this->NumberOfLicense = tmp.NumberOfLicense;
		this->TaxInfo.sum = tmp.TaxInfo.sum;
		this->TaxInfo.TaxDate = tmp.TaxInfo.TaxDate;
		this->NumberOfPassport = tmp.NumberOfPassport;
		this->BorderInfo.country = tmp.BorderInfo.country;
		this->BorderInfo.date = tmp.BorderInfo.date;
		this->adress = tmp.adress;
}

cBusinessTourist::~cBusinessTourist()
{
		std::cout << "destr Businesstorusist ";
}

void operator >> (std::istream & is, cBusinessTourist & tmp)
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
		cout << "¬ведите номер лицензии: ";
		rewind(stdin);
		is >> tmp.NumberOfLicense;
		cout << "¬ведите сумму: ";
		rewind(stdin);
		is >> tmp.TaxInfo.sum;
		cout << "¬ведите дату: ";
		rewind(stdin);
		is >> tmp.TaxInfo.TaxDate;
		cout << "¬ведите адрес: ";
		rewind(stdin);
		is >> tmp.adress;
}

void operator << (std::ostream & os, cBusinessTourist & tmp)
{
		os << setw(15) << tmp.FirstName << setw(15) << tmp.LastName << setw(8) << tmp.Age << setw(8) << tmp.NumberOfPassport << setw(10) << tmp.BorderInfo.country
				<< setw(10) << tmp.BorderInfo.date << setw(9) << tmp.NumberOfLicense << setw(10) << tmp.TaxInfo.sum
				<< setw(6) << tmp.TaxInfo.TaxDate << setw(20) << tmp.adress << endl;
}

void cBusinessTourist::operator = (const cBusinessTourist & tmp)
{
		this->FirstName = tmp.FirstName;
		this->LastName = tmp.LastName;
		this->Age = tmp.Age;
		this->NumberOfLicense = tmp.NumberOfLicense;
		this->TaxInfo.sum = tmp.TaxInfo.sum;
		this->TaxInfo.TaxDate = tmp.TaxInfo.TaxDate;
		this->NumberOfPassport = tmp.NumberOfPassport;
		this->BorderInfo.country = tmp.BorderInfo.country;
		this->BorderInfo.date = tmp.BorderInfo.date;
		this->adress = tmp.adress;
}
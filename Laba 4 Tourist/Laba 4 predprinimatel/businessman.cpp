#include "businessman.h"
#include <iostream>
#include <iomanip>
using namespace std;

cBusinessman::cBusinessman() : cHuman()
{
		cout << "constr businessman ";
}

cBusinessman::cBusinessman(int _num, int _sum, char* _taxdate) : cHuman()
{
		this->NumberOfLicense = _num;
		this->TaxInfo.sum = _sum;
		this->TaxInfo.TaxDate = _taxdate;
}

cBusinessman::cBusinessman(const cBusinessman &tmp)
{
		this->FirstName = tmp.FirstName;
		this->LastName = tmp.LastName;
		this->Age = tmp.Age;
		this->NumberOfLicense = tmp.NumberOfLicense;
		this->TaxInfo.sum = tmp.TaxInfo.sum;
		this->TaxInfo.TaxDate = tmp.TaxInfo.TaxDate;
}

cBusinessman::~cBusinessman()
{
		std::cout << "destr Businessman ";
}

void operator >> (std::istream & is, cBusinessman & tmp)
{
		cout << "������� ���: ";
		rewind(stdin);
		is >> tmp.FirstName;
		cout << "������� �������: ";
		rewind(stdin);
		is >> tmp.LastName;
		cout << "������� �������: ";
		rewind(stdin);
		is >> tmp.Age;
		cout << "������� ����� ��������: ";
		rewind(stdin);
		is >> tmp.NumberOfLicense;
		cout << "������� ������: ";
		rewind(stdin);
		is >> tmp.TaxInfo.sum;
		cout << "������� ����: ";
		rewind(stdin);
		is >> tmp.TaxInfo.TaxDate;
}

void operator << (std::ostream & os, cBusinessman & tmp)
{
		os << setw(15) << tmp.FirstName << setw(15) << tmp.LastName << setw(8) << tmp.Age << setw(9) << tmp.NumberOfLicense << setw(10) << tmp.TaxInfo.sum
				<< setw(6) << tmp.TaxInfo.TaxDate << endl;
}

void cBusinessman::operator = (const cBusinessman & tmp)
{
		this->FirstName = tmp.FirstName;
		this->LastName = tmp.LastName;
		this->Age = tmp.Age;
		this->NumberOfLicense = tmp.NumberOfLicense;
		this->TaxInfo.sum = tmp.TaxInfo.sum;
		this->TaxInfo.TaxDate = tmp.TaxInfo.TaxDate;
}
#include "tourist.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "String.h"
#include <cctype>
#include "InputException.h"
using namespace std;

//bool CheckCorrect(string input, bool fl);

cTourist::cTourist() : cHuman()
{
		NumberOfPassport = 0;
}

cTourist::cTourist(char *_fname, char *_lname, int _age, int _num, char* _country, char* _date)
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
}

void operator >> (std::istream & is, cTourist & tmp)
{
		string temp;

		cout << "Введите имя: ";
		tmp.FirstName = InputCharCheck(temp);

		cout << "Введите фамилию: ";
		tmp.LastName = InputCharCheck(temp);

		cout << "Введите возраст: ";
		tmp.Age = InputCheck(0,100);

		cout << "Введите номер паспорта (7 цифр): ";
		tmp.NumberOfPassport=InputPassport();

		cout << "Введите страну: ";
		tmp.BorderInfo.country = InputCharCheck(temp);

		cout << "Введите дату (в формате ДД.ММ.ГГГГ): ";
		tmp.BorderInfo.date = InputDateCheck(temp);
}

void operator << (std::ostream & os, cTourist & tmp)
{
		os << setw(20) << tmp.FirstName << setw(20) << tmp.LastName << setw(9) << tmp.Age << setw(9) << tmp.NumberOfPassport << setw (20) << tmp.BorderInfo.country
				<< setw (12) << tmp.BorderInfo.date << endl;
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

bool operator < (const cTourist &v1, const cTourist &v2)
{
		if (v1.FirstName < v2.FirstName)
				if (v1.LastName < v2.LastName)
						if (v1.Age < v2.Age)
								return true;
		return false;
}
string InputCharCheck(string input)
{
		bool fl = true;
		do {
				try {
						fflush(stdin);
						cin.sync();
						cin.clear();
						cin >> input;
						CheckCorrect(input, fl);
						fl = false;
				}
				catch (InputException e)
				{
						e.NumError();
						fflush(stdin);
						cin.sync();
						cin.clear();
						//InputCharCheck(input);
				}
				fflush(stdin);
		} while (fl);
		input[0]=toupper(input[0]);
		return input;
}

bool CheckCorrect(string input, bool fl) throw (InputException)
{
		int len = input.length();
		for (int i = 0; i < len; i++)
		{
				if (input[i] < 'A' || input[i] > 'Z')
				{
						if (input[i]<'a' || input[i]>'z')
						{
								if (input[i] != '-')
								{
										fl = false;
										throw InputException(1);
								}
						}
				}
		}
		int count=0;
		for (int i = 0; i < len; i++)
		{
				if (input[i] == '-')
				{
						count++;
						if (count > 1)
						{
								fl = false;
								throw InputException(5);
						}
				}
		}
		if (input[0] == '-')
		{
				fl = false;
				throw InputException(6);
		}
		if (len>15)
		{
				fl = false;
				throw InputException(3);
		}
		return fl;
}

int InputCheck(int inter1, int inter2)
{
		bool flag = true;
		int tmp = 0;
		do
		{
				try
				{
						cin.sync();
						cin.clear();
						rewind(stdin);
						cin >> tmp;
						flag = true;
						if (!cin || cin.peek() != '\n')
						{
								flag = false;
								throw InputException(4);
						}
						if (tmp<inter1 || tmp>inter2)
						{
								flag = false;
								throw 5;
						}
				}
				catch (InputException e)
				{
						e.NumError();
						cin.sync();
						cin.clear();
						rewind(stdin);
				}
				catch (...)
				{
						cin.sync();
						cin.clear();
						rewind(stdin);
						cout << "Введите число в интервале от " << inter1 << " до " << inter2 << endl;
				}
		} while (!flag);
		return tmp;
}

int InputPassport()
{
		bool flag = true;
		int tmp = 0;
		do
		{
				try
				{
						cin.sync();
						cin.clear();
						rewind(stdin);
						cin >> tmp;
						flag = true;
						if (!cin || cin.peek() != '\n' || tmp>9999999 || tmp<1000000)
						{
								flag = false;
								throw InputException(2);
						}
						if (tmp < 0)
						{
								flag = false;
								throw 5;
						}
				}
				catch (InputException e)
				{
						e.NumError();
						cin.sync();
						cin.clear();
						rewind(stdin);
				}
				catch (...)
				{
						cin.sync();
						cin.clear();
						rewind(stdin);
						cout << "Введите положительное 7-значное число" << endl;
				}
		} while (!flag);
		return tmp;
}

string InputDateCheck(string input)
{
		bool fl = true;
		do {
				try {
						fflush(stdin);
						cin.sync();
						cin.clear();
						cin >> input;
						CheckDateCorrect(input, fl);
						fl = false;
				}
				catch (InputException e)
				{
						e.NumError();
						fflush(stdin);
						cin.sync();
						cin.clear();
				}
				fflush(stdin);
		} while (fl);
		return input;
}

bool CheckDateCorrect(string input, bool fl) throw (InputException)
{
		int len = input.length();
		if (len!=10)
		{
				fl = false;
				throw InputException(7);
		}
		if (input[2] != '.' || input[5] != '.')
		{
				fl = false;
				throw InputException(8);
		}
		for (int i = 0; i < len; i++)
		{
				if (i == 2 || i == 5) continue;
				else if (input[i]<'0' || input[i]>'9')
				{
						fl = false;
						throw InputException(9);
				}
		}
		if ((input[0] >'2') && (input[1] > '1'))
		{
				fl = false;
				throw InputException(10);
		}
		if ((input[3] >'1') && (input[4] > '2'))
		{
				fl = false;
				throw InputException(11);
		}
		if (input[6] >= '2' && input[7] >= '0' && input[8] > '1')
		{
				fl = false;
				throw InputException(12);
		}
		return fl;
}
#pragma once
#include "Human.h"
#include <string>
#include "File.h"

struct border
{
		string country;
		string date;
};

class cTourist : public cHuman
{
protected:
		int NumberOfPassport;
		border BorderInfo;
public:
		cTourist();
		cTourist(char *_fname, char *_lname, int _age, int _num, char* _country, char* _date);
		cTourist(const cTourist & tmp);
		~cTourist();

		int getAge() { return Age; }
		int getNumber() { return NumberOfPassport; }
		string getDate() { return BorderInfo.date; }
		string getCountry() { return BorderInfo.country; }
		string getFirstName() { return FirstName; }
		string getLastName() { return LastName; }

		void setAge(int _Age) { Age = _Age; }
		void setNumber(int _number) { NumberOfPassport = _number; }
		void setDate(string &_date) { BorderInfo.date = _date; }
		void setCountry(string &_country) { BorderInfo.country = _country; }
		void setFirstName(string &_FirstName) { FirstName = _FirstName; }
		void setLastName(string &_LastName) { LastName = _LastName; }
		void setDate(char* _date) { BorderInfo.date = _date; }
		void setCountry(char* _country) { BorderInfo.country = _country; }
		void setFirstName(char* _FirstName) { FirstName = _FirstName; }
		void setLastName(char* _LastName) { LastName = _LastName; }

		friend ofstream& operator<<(std::ofstream& ofs, const cTourist& obj);
		friend ifstream& operator>>(ifstream& ifs, const cTourist& obj);
		void operator = (const cTourist & tmp);
		friend void operator << (std::ostream & os, cTourist & tmp);
		friend void operator >> (std::istream & is, cTourist & tmp);
		void writeobj(ostream &os);
};

bool CheckCorrect(string input, bool fl);
string InputCharCheck(string input);
int InputCheck(int inter1, int inter2);
int InputPassport();
bool CheckDateCorrect(string input, bool fl);
string InputDateCheck(string input);
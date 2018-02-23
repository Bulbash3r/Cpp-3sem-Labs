#pragma once
#include "Human.h"
#include <string>
#include "List.h"

struct border
{
		string country;
		string date;
};

class cTourist : public cHuman
{
private:
		template <typename T> friend class Iterator;
protected:
		int NumberOfPassport;
		border BorderInfo;
public:
		cTourist();
		cTourist(char *_fname, char *_lname, int _age, int _num, char* _country, char* _date);
		cTourist(const cTourist & tmp);
		~cTourist();

		friend bool  operator== (cTourist tmp1, cTourist tmp2);
		void operator = (const cTourist & tmp);
		friend void operator << (std::ostream & os, cTourist & tmp);
		friend void operator >> (std::istream & is, cTourist & tmp);
};

bool CheckCorrect(string input, bool fl);
string InputCharCheck(string input);
int InputCheck(int inter1, int inter2);
int InputPassport();
bool CheckDateCorrect(string input, bool fl);
string InputDateCheck(string input);
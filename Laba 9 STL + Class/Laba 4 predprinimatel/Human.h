#pragma once
#include <iostream>
#include <string>

using namespace std;
class cHuman
{
protected:
		string FirstName;
		string LastName;
		int Age;
public:
		cHuman();
		cHuman(char *_fname, char *_lname, int _age);
		cHuman(const cHuman & tmp);
		~cHuman() {}

		inline string GetFname() const { return this->FirstName; };
		inline string GetLname() const { return this->LastName; };
		inline int GetAge() const { return this->Age; };

		void SetFname(const string & _fname) { this->FirstName = _fname; };
		void SetLname(const string & _lname) { this->LastName = _lname; };
		void SetFname(const char * _fname) { this->FirstName = _fname; };
		void SetLname(const char * _lname) { this->LastName = _lname; };
		void SetAge(const int _age) { this->Age = _age; };

		void operator = (const cHuman & tmp);
		friend void operator << (std::ostream & os, cHuman & tmp);
		friend void operator >> (std::istream & is, cHuman & tmp);
};
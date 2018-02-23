#pragma once
#include<iostream>
#include"String.h"
class cHuman
{
protected:
		String FirstName;
		String LastName;
		int Age;
public:
		cHuman();
		cHuman(char *_fname, char *_lname, int _age);
		cHuman(const cHuman & tmp);
		~cHuman() { std::cout << "destr human "; }

		inline String GetFname() const { return this->FirstName; };
		inline String GetLname() const { return this->LastName; };
		inline int GetAge() const { return this->Age; };

		void SetFname(const String & _fname) { this->FirstName = _fname; };
		void SetLname(const String & _lname) { this->LastName = _lname; };
		void SetFname(const char * _fname) { this->FirstName = _fname; };
		void SetLname(const char * _lname) { this->LastName = _lname; };
		void SetAge(const int _age) { this->Age = _age; };

		void operator = (const cHuman & tmp);
		friend void operator << (std::ostream & os, cHuman & tmp);
		friend void operator >> (std::istream & is, cHuman & tmp);
};
#define _CRT_SECURE_NO_WARNINGS

#include "myString.h"
#include <iostream>
#include <new>

using namespace std;

myString::myString(char* str)
{
		length = strlen(str);
		this->string = new char[length + 1];
		strcpy(string, str);
}

myString::myString(const myString& str)
{
		cout << "Constr copy" << endl;
		length = strlen(str.string);
		string = new char[length + 1];
		strcpy(string, str.string);
}

void myString::printString()
{
		cout << string;
}

int myString::getLength()
{
		return length;
}

myString &myString::operator = (const myString &str)
{
		if (strcmp(this->string, str.string))
		{
				length = strlen(str.string);
				delete[] this->string;
				this->string = new char[length + 1];
				strcpy(this->string, str.string);
		}
		return *this;
}

myString myString::operator+=(const myString& str)
{
		int sz = strlen(this->string) + strlen(str.string)+1;

		myString temp;
		strcpy(temp.string, this->string);
		delete[] this->string;
		this->string = new char[sz];
		strcpy(this->string, temp.string);
		strcat(this->string, " ");
		strcat(this->string, str.string);
		return *this;
}

myString myString::operator+(const myString& right)
{
		myString temp;
		temp.length = strlen(this->string) + strlen(right.string)+1;
		temp.string = new char[temp.length + 1];
		strcpy(temp.string, this->string);
		//int sz = strlen(this->string) + strlen(right.string) + 1;
		//delete[] this->string;
		//this->string = new char[sz];
		strcpy(temp.string, this->string);
		strcat(temp.string, " ");
		strcat(temp.string, right.string);
		return temp;
}

char& myString::operator[](int i)
{
		char cnull = 0;
		return (i >= 0 && i < strlen(this->string)) ? this->string[i] : cnull;
}

bool myString::operator == (const myString &str)
{
		return (strcmp(this->string, str.string) == 0) ? 1 : 0;
}

bool myString::operator > (const myString &str)
{
		return (strcmp(this->string, str.string) == 1) ? 1 : 0;
}

bool myString::operator < (const myString &str)
{
		return (strcmp(this->string, str.string) == -1) ? 1 : 0;
}

bool myString::operator >= (const myString &str)
{
		return (strcmp(this->string, str.string) >= 0) ? 1 : 0;
}

bool myString::operator <= (const myString &str)
{
		return (strcmp(this->string, str.string) <= 0) ? 1 : 0;
}

myString::~myString()
{
		if (string)
				delete[] string;
}
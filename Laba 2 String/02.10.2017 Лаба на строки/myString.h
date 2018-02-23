#pragma once

class myString
{
		char* string;
		int length;
public:
		myString(const myString& str);
		explicit myString(char* str = "");
		int getLength();
		void printString();

		myString &operator =(const myString &str);
		myString operator+=(const myString &str);
		myString operator+(const myString &str);
		char& operator[](int);

		bool operator == (const myString &str);
		bool operator > (const myString &str);
		bool operator < (const myString &str);
		bool operator >= (const myString &str);
		bool operator <= (const myString &str);

		~myString();
};

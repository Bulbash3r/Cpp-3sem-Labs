#pragma once
#include <string>
using namespace std;

class User
{
		string username;
		double balance;
public:
		User() { balance = 0; };
		User(char* currentName, double currentMoney);
		User(const User &tmp);
		~User() {};

		string getUsername() const { return this->username; }
		double getBalance() { return this->balance; }

		void setUsername(string tmp) { this->username = tmp; }
		void setBalance(double _balance) {this->balance = _balance; }

		string InputCharCheck(string input);
		bool CheckCorrect(string input, bool fl);

		friend void operator >> (std::istream & is, User & tmp);
};
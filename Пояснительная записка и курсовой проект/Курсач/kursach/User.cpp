#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "User.h"
#include <string>
#include <iostream>
#include "InputException.h"

using namespace std;

User :: User(char* currentName, double currentMoney)
{

		username = currentName;
		balance = currentMoney;
}

User::User(const User &tmp)
{
		this->balance = tmp.balance;
		username = tmp.username;
}



bool User::CheckCorrect(string input, bool fl) throw (InputException)
{
		int len = input.length();
		for (int i = 0; i < len; i++)
		{
				if (input[i] < 'A' || input[i] > 'Z')
				{
						if (input[i]<'a' || input[i]>'z')
						{
								if (input[i]< '0' || input[i]>'9')
								{
										fl = false;
										throw InputException(1);
								}
						}
				}
		}
		if (len>20)
		{
				fl = false;
				throw InputException(3);
		}
		if (input[0] >= '0' && input[0] <= '9')
		{
				fl = false;
				throw InputException(2);
		}
		return fl;
}

string User::InputCharCheck(string input)
{
		bool fl = true;
		do {
				try {
						User tmp;
						fflush(stdin);
						cin.sync();
						cin.clear();
						cin >> input;
						tmp.CheckCorrect(input, fl);
				}
				catch (InputException e)
				{

						e.NumError();
						cin.clear();
						cin.sync();
						InputCharCheck(input);
				}
				fflush(stdin);
		} while (!fl);
		return input;
}

void operator >> (std::istream & is, User &tmp)
{
		tmp.username = tmp.InputCharCheck(tmp.username);
}

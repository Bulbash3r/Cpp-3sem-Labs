#pragma once
#include <fstream>
#include "tourist.h"
#include "List.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

template <class T>
char* as_bytes(T&i)
{
		void* addr = &i;
		return static_cast<char*>(addr);
}

template <class X>
class File
{
private:
		ifstream input_txt;
		ofstream output_txt;
		ifstream input_bin;
		ofstream output_bin;
public:
		File() {}
		~File() {}
		void TxtFileSave(List<X> &tmp);
		void TxtFileOpen(List<X> &tmp);
		void BinFileSave(List<X> &tmp);
		void BinFileOpen(List<X> &tmp);
};

template <class X>
void File<X>::TxtFileOpen(List<X> &tmp)
{
		input_txt.open("cTourist_txt.txt", ios::in);
		if (!input_txt.is_open())
		{
				cout << "Невозможно открыть файл!" << endl;
				return;
		}
		while (true)
		{
				//X temp;
				//input_txt >> tmp;
				X temp;
				string buff;
				input_txt >> buff;
				if (input_txt.eof()) break;

				int buffi;

				temp.setFirstName(buff);

				input_txt >> buff;
				temp.setLastName(buff);

				input_txt >> buffi;
				temp.setAge(buffi);

				input_txt >> buffi;
				temp.setNumber(buffi);

				input_txt >> buff;
				temp.setCountry(buff);

				input_txt >> buff;
				temp.setDate(buff);

				tmp.push_tail(temp);
		}
		input_txt.close();
}

template <class X>
void File<X>::TxtFileSave(List<X> &tmp)
{
		output_txt.open("cTourist_txt.txt", ios::in | ios_base::trunc);
		if (!output_txt.is_open())
		{
				cout << "Невозможно открыть файл!" << endl;
				return;
		}
		for (int i = 0; i < tmp.size(); i++)
		{
				//output_txt << tmp[i];
				output_txt << tmp[i].getFirstName() << " " << tmp[i].getLastName() << " " << tmp[i].getAge() << " " << tmp[i].getNumber() << " " << tmp[i].getCountry() << " " << tmp[i].getDate() << endl;
		}
		output_txt.close();
}
template <class X>
void File<X>::BinFileSave(List<X> &tmp)
{
		output_bin.open("cTourist_bin.bin", ios::in | ios_base::trunc | ios::binary);
		if (!output_bin.is_open())
		{
				cout << "Невозможно открыть файл!" << endl;
				return;
		}
		for (int i = 0; i < tmp.size(); i++)
		{
				tmp[i].writeobj(output_bin);
		}
		output_bin.close();
}

template <class X>
void File<X>::BinFileOpen(List<X> &tmp)
{
		input_bin.open("cTourist_bin.bin", ios::in | ios::binary);
		if (!input_bin.is_open())
		{
				cout << "Невозможно открыть файл!" << endl;
				return;
		}
		while (true)
		{
				X temp;
				char buff[50] = "";
				char str[50] = "";
				input_bin.read(buff, 2);
				int size = atoi(buff);
				if (input_bin.eof()) break;

				input_bin.read(str, size);
				temp.setFirstName(str);

				memset(buff, '\0', 50);
				memset(str, '\0', 50);
				input_bin.read(buff, 2);
				size = atoi(buff);
				input_bin.read(str, size);
				temp.setLastName(str);

				memset(str, '\0', 50);
				input_bin.read(str, 2);
				temp.setAge(atoi(str));

				memset(str, '\0', 50);
				input_bin.read(str, 7);
				temp.setNumber(atoi(str));

				memset(buff, '\0', 50);
				memset(str, '\0', 50);
				input_bin.read(buff, 2);
				size = atoi(buff);
				input_bin.read(str, size);
				temp.setCountry(str);

				memset(buff, '\0', 50);
				memset(str, '\0', 50);
				input_bin.read(buff, 2);
				size = atoi(buff);
				input_bin.read(str, size);
				temp.setDate(str);

				tmp.push_tail(temp);
		}
		input_bin.close();
}
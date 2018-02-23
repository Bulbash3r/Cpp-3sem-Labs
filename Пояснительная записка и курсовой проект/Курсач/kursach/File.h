#pragma once
#include "List.h"

template <class X>
class File
{
public:
		File() {};
		~File() {};
		void FileSaveIncome (List<X> &tmp, const char *file);
		void FileSaveConsum(List<X> &tmp, const char *file);
		void FileOpenIncome(List<X> &tmp, const char *file);
		void FileOpenConsum(List<X> &tmp, const char *file);
};

template <class X>
void File<X>::FileOpenIncome(List <X> &tmp, const char *file)
{
		ifstream in;
		in.open(file, ios::in);
		if (!in.is_open())
		{
				cout << "Невозможно открыть файл!" << endl;
				return;
		}
		while (true)
		{
						float tmp1;
						int tmp2;
						in >> tmp1 >> tmp2;
						if (tmp1 == -1) break;
						Income obj(tmp2, tmp1);
						tmp.push_tail(obj);
		}
		in.close();
}

template <class X>
void File<X>::FileOpenConsum(List <X> &tmp, const char *file)
{
		ifstream in;
		in.open(file, ios::in);
		if (!in.is_open())
		{
				cout << "Невозможно открыть файл!" << endl;
				return;
		}
		while (true)
		{
				float tmp1;
				int tmp2;
				bool tmp3;
				in >> tmp1 >> tmp2 >> tmp3;
				if (tmp1 == -1) break;
				Consum obj(tmp2, tmp1, tmp3);
				tmp.push_tail(obj);
		}
		in.close();
}

template <class X>
void File<X>::FileSaveIncome(List <X> &tmp, const char *file)
{
		ofstream on;
		on.open(file, ios::in | ios_base::trunc);
		if (!on.is_open())
		{
				cout << "Невозможно открыть файл!" << endl;
				return;
		}
		for (int i = 0; i<tmp.size(); i++)
		{
				on << tmp[i].getSum() << " " << tmp[i].getType() << endl;
		}
		on << "-1";
		on.close();
}

template <class X>
void File<X>::FileSaveConsum(List <X> &tmp, const char *file)
{
		ofstream on;
		on.open(file, ios::in | ios_base::trunc);
		if (!on.is_open())
		{
				cout << "Невозможно открыть файл!" << endl;
				return;
		}
		for (int i = 0; i<tmp.size(); i++)
		{
				on << tmp[i].getSum() << " " << tmp[i].getType() << " " << tmp[i].getDebt() << endl;
		}
		on << "-1";
		on.close();
}
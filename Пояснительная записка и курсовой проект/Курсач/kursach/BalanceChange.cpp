#include "BalanceChange.h"
#include "InputException.h"

bool CheckConsum(double a)
{
		try
		{
				if (a < 0) throw InputException(5);
		}
		catch (InputException e)
		{
				e.NumError();
				return true;
		}
		return false;
}
int InputCheck(double inter1, double inter2)
{
		bool flag = true;
		int tmp = 0;
		do
		{
				try
				{
						cin.sync();
						cin.clear();
						rewind(stdin);
						cin >> tmp;
						flag = true;
						if (!cin || cin.peek() != '\n')
						{
								flag = false;
								throw InputException(4);
						}
						if (tmp<inter1 || tmp>inter2)
						{
								flag = false;
								throw 5;
						}
				}
				catch (InputException e)
				{
						e.NumError();
						cin.sync();
						cin.clear();
						rewind(stdin);
				}
				catch (...)
				{
						cin.sync();
						cin.clear();
						rewind(stdin);
						cout << "¬ведите число в интервале от " << inter1 << " до " << inter2 << endl;
				}
		} while (!flag);
		return tmp;
}
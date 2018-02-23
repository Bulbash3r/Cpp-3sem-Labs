#include <iostream>
#include <cstdlib>
#include <new>
#include <iomanip>
#include "myClass.h"

using namespace std;

/*Конструктор*/
myMatrix::myMatrix(int sz)
{
		size = sz;
		matrix = new int*[size];
		for (int i = 0; i < size; i++)
		{
				matrix[i] = new int[size];
		}
		for (int i = 0; i < size; i++)
				for (int j = 0; j < size; j++)
				{
						matrix[i][j] = 0;
				}
}

/*Ввод матрицы*/
void myMatrix::enterMatrix()
{
		for (int i = 0; i < size; i++)
		{
				for (int j = 0; j < size; j++)
				{
						cin >> matrix[i][j];
				}
		}
}

/*myMatrix::myMatrix(int sz = 4)
{
		size = sz;
		matrix = new int*[size];
		for (int i = 0; i < size; i++)
		{
				matrix[i] = new int[size];
		}
		for (int i = 0; i < size; i++)
				for (int j = 0; j < size; j++)
				{
						cin >> matrix[i][j];
				}
		}
*/

/*Деструктор*/
myMatrix::~myMatrix()
{
		for (int i = 0; i < size; i++)
				delete[] matrix[i];
		delete[] matrix;
}

/*Вывод матрицы на экран*/
void myMatrix::getMatrix()
{
		for (int i = 0; i < size; i++)
		{
				for (int j = 0; j < size; j++)
				{
						cout << setw(5) << matrix[i][j];
				}
				cout << endl;
		}
}

/*Консруктор копирования*/
myMatrix::myMatrix(const myMatrix &obj)
{
		size = obj.size;
		matrix = new int*[size];
		for (int i = 0; i < size; i++)
				matrix[i] = new int[size];

		for (int i = 0; i < size; i++)
				for (int j = 0; j < size; j++)
						matrix[i][j] = obj.matrix[i][j];
}

/*Создание матрицы, в которой будут удалены строка и столбец
* с самым большим числом. Если самых больших чисел несколько,
* то будет удалены строка и столбец с первым встретившимся числом
*/
myMatrix myMatrix::FindAndDelete(myMatrix obj)
{
		int max = obj.matrix[0][0];
		int min_i = 0;
		int min_j = 0;

		for (int i = 0; i < obj.size; i++)
				for (int j = 0; j < obj.size; j++)
				{
						if (obj.matrix[i][j] > max)
						{
								max = obj.matrix[i][j];
								min_i = i;
								min_j = j;
						}
				}
		int i1 = 0;
		int j1 = 0;
		myMatrix temp(obj.size - 1);
		for (int i = 0, i1 = 0; i < obj.size; i++)
		{
				if (i != min_i)
				{
						for (int j = 0, j1 = 0; j < obj.size; j++)
						{
								if (j != min_j)
								{
										temp.matrix[i1][j1] = obj.matrix[i][j];
										j1++;
								}
						}
						i1++;
				}
		}
		return temp;
}

myMatrix myMatrix::operator+ (const myMatrix &mx)
{
		if (size != mx.size)
		{
				cout << "Массивы разного размера!\n";
				return (0);
		}

		for (int i = 0; i < size; i++)
				for (int j = 0; j < size; j++)
						this->matrix[i][j] += mx.matrix[i][j];
		return *this;
}

myMatrix &myMatrix::operator= (const myMatrix& mx)
{
		if (this != &mx)
		{
				for (int i = 0; i < size; i++)
						delete[]matrix[i];
				delete[]matrix;

				this->matrix = new int*[size = mx.size];
				for (int i = 0; i < size; i++)
						this->matrix[i] = new int[size = mx.size];

				for (int i = 0; i < size; i++)
						for (int j = 0; j < size; j++)
								this->matrix[i][j] = mx.matrix[i][j];
		}
				return *this;
}

myMatrix myMatrix::operator+= (const myMatrix &mx)
{
		return *this = (*this+mx);
}
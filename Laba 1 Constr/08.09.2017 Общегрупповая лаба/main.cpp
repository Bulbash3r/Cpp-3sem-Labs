/* Общегрупповая лаба
 * 8 сентября 2017 года
 * Студент группы 650503 Юревич Антон
 * 5 вариант
 *
 * Условие: Создать класс для работы с массивами. Память под массивы выделять динамически
 * Использовать конструктор без параметров, с параметрами; с параметрами, заданными по умолчанию; конструктор копирования и explicit
 * Деструктор
 * Реализовать функции: ввод данных в массив, вывода массива на экран, конструкторы/деструкторы
 * 5 вариант: реализовать (дана квадратная матрица) функцию, в которой будет создана квадратная матрица n-1 с отсутствующим столбцом и строкой с наибольшим элементом
 */

#include <iostream>
#include <cstdlib>
#include "myClass.h"

using namespace std;

int main()
{
		setlocale(LC_ALL, "Russian");
		int size;
		while (1)
		{
				system("cls");
				cout << "Введите размер матрицы: ";
				cin >> size;

				if (size < 0)
				{
						cout << "Некорректный ввод размера матрицы" << endl;
						system("pause");
						return 0;
				}

				system("cls");

				myMatrix matrix(size);
				matrix.enterMatrix();
				system("cls");
				matrix.getMatrix();

				system("pause");
				system("cls");

				myMatrix newMatrix = matrix.FindAndDelete(matrix);
				newMatrix.getMatrix();

				cout << "Для выхода введите '0', для продолжения любой другой символ. . . ";
				char exit;
				cin >> exit;
				if (exit == '0')
						break;
						return 0;
		}
		system("cls");
		myMatrix matrix1(size);
		myMatrix matrix2(size);

		matrix1.enterMatrix();
		matrix2.enterMatrix();
		
		myMatrix matrix3 = matrix1 + matrix2;
		matrix3.getMatrix();

		cout << endl;

		myMatrix matrix4(size);
		matrix4 += matrix3;
		matrix4 += matrix3;
		matrix4.getMatrix();

		system("pause"); 

		return 0;
}
/* ������������� ����
 * 8 �������� 2017 ����
 * ������� ������ 650503 ������ �����
 * 5 �������
 *
 * �������: ������� ����� ��� ������ � ���������. ������ ��� ������� �������� �����������
 * ������������ ����������� ��� ����������, � �����������; � �����������, ��������� �� ���������; ����������� ����������� � explicit
 * ����������
 * ����������� �������: ���� ������ � ������, ������ ������� �� �����, ������������/�����������
 * 5 �������: ����������� (���� ���������� �������) �������, � ������� ����� ������� ���������� ������� n-1 � ������������� �������� � ������� � ���������� ���������
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
				cout << "������� ������ �������: ";
				cin >> size;

				if (size < 0)
				{
						cout << "������������ ���� ������� �������" << endl;
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

				cout << "��� ������ ������� '0', ��� ����������� ����� ������ ������. . . ";
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
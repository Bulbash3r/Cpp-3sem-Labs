#pragma once

class myMatrix
{
		int **matrix;
		int size;
public:
		myMatrix(int sz);
		//myMatrix(int sz = 3);
		myMatrix(const myMatrix &obj);
		~myMatrix();
		void enterMatrix();
		void getMatrix();
		myMatrix FindAndDelete(myMatrix obj);
		myMatrix operator+ (const myMatrix &mx);
		myMatrix &operator= (const myMatrix &mx);
		myMatrix operator+= (const myMatrix &mx);
};

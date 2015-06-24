#include "stdafx.h"
#include <iostream>
#include <array>

using namespace std;
#define N 100
#define M 100

typedef array<array<int, 100>,100> AR;

class MATRIK
{
public:
	//MATRIK();
	void make(AR a, int row, int col);
	MATRIK transpose();
	void print();
	friend MATRIK operator+(MATRIK a,MATRIK b);
	friend MATRIK operator-(MATRIK a, MATRIK b);
	friend MATRIK operator*(MATRIK a, MATRIK b);
private:
	MATRIK dt;
	int nRow, nCol;
};

void MATRIK :: make(AR a, int row, int col)
{
	
}

void MATRIK::print()
{
	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nCol; i++)
		{
			cout << dt[i][j];
			if (j == nCol - 1)
				cout << "\n";
			else
				cout << " ";
		}
	}
}

MATRIK MATRIK::transpose()
{
	dt temp;
	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nCol; i++)
		{
			temp[i][j] = dt[j][i];
		}
	}
	return temp;
}

int main() {
	AR arr = { { { 5, 8, 2 }, { 8, 3, 1 } } };
	int brr[M][N] = { { 1, 2, 1 }, { 0, 1, 1 } };
	MATRIK A, B, C, D, BT;
	A.make(arr, 2, 3);    // buat matrik A ukuran 2x3
	B.make(brr, 2, 3);    // buat matrik B ukuran 2x3
	BT = B.transpose();
	C = A + B; C.print(); // menjumlah 2 matrik
	cout << endl;
	D = A*BT; D.print(); // mengalikan matrik
	return 0;
}
/*
Buat ADT MATRIK yang memiliki kemampuan sama seperti matrik dua dimensi. Memiliki fungsi transpose, penjumlahan, pengurangan, dan perkalian matrik. Ukuran maksimum matrik adalah 100 x100. Karena dalam grader ini masih menggunakan versi lama, maka tidak bisa menggunakan STL Array sehingga pernyataan #include <array> mengakibatkan compile error. Oleh karena itu, dalam tugas ini, gunakan struktur data array biasa. ADT MATRIK yang dibuat harus dapat dijalankan dengan driver seperti contoh berikut:

int main() {
   int arr[M][N]={{5,8,2},{8,3,1}};
   int brr[M][N]={{1,2,1},{0,1,1}};
   MATRIK A,B,C,D,BT;
   A.make(arr,2,3);    // buat matrik A ukuran 2x3
   B.make(brr,2,3);    // buat matrik B ukuran 2x3
   BT=B.transpose();
   C=A+B; C.print(); // menjumlah 2 matrik
   cout << endl;
   D=A*BT; D.print(); // mengalikan matrik
   return 0;
}
Format Masukan

Tidak ada data masukan, karena seluruh data untuk menguji ADT telah disimpan dalam driver.

Format Keluaran

Dua buah matrik hasil penjumlahan A+B dan hasil perkalian AxB' (B transpose).

Contoh Masukan

Tidak ada data masukan

Contoh Keluaran

6 10 3
8 4 2

23 10
15 4

Reference : http://www.cplusplus.com/forum/general/97018/
*/

//#include "stdafx.h"
#include <iostream>
//#include <array>
//#include <conio.h>

using namespace std;
#define N 100
#define M 100

//typedef array<array<int, N>, M> AR;

class MATRIK
{
public:
	//MATRIK();
	void make(int a[M][N], int row, int col);
	MATRIK transpose();
	void print();
	int getRow(){ return nRow; }
	int getCol(){ return nCol; }

	int getArray(){ return AR[M][N]; }
	void setArray(int a[M][N], int row, int col)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				AR[i][j] = a[i][j];
			}
		}
	}

	friend MATRIK operator+(MATRIK a, MATRIK b);
	friend MATRIK operator-(MATRIK a, MATRIK b);
	friend MATRIK operator*(MATRIK a, MATRIK b);
private:
	int AR[M][N];
	int nRow, nCol;
};

void MATRIK::make(int a[M][N], int row, int col)
{
	int temp[M][N];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			temp[i][j] = a[i][j];
		}
	}
	setArray(temp, row, col);
	nRow = row;
	nCol = col;
}

void MATRIK::print()
{
	//cout << "hello world" << endl;
	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nCol; j++)
		{
			cout << AR[i][j];
			if (j == nCol - 1)
				cout << endl;
			else
				cout << " ";
		}
	}
}

MATRIK MATRIK::transpose()
{
	int temp[M][N];
	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nCol; j++)
		{
			temp[j][i] = AR[i][j];
		}
	}
	MATRIK result;
	result.make(temp, nCol, nRow);
	return result;
}

MATRIK operator+(MATRIK a, MATRIK b)
{
	int temp[M][N];
	for (int i = 0; i < a.getRow(); i++)
	{
		for (int j = 0; j < a.getCol(); j++)
		{
			temp[i][j] = a.AR[i][j] + b.AR[i][j];
		}
	}
	MATRIK result;
	result.make(temp, a.getRow(), a.getCol());
	return result;
}

MATRIK operator *(MATRIK a, MATRIK b)
{
	int temp[M][N];
	if (a.getCol() == b.getRow())
	{
		//matrix T(a.m, b.n);
		for (int i = 0; i < a.getRow(); i++)
		{
			for (int k = 0; k < b.getCol(); k++)
			{
				temp[i][k] = 0;
				for (int j = 0; j < a.getCol(); j++)
				{
					temp[i][k] += a.AR[i][j] * b.AR[j][k];
				}
			}
		}
	}
	MATRIK result;
	result.make(temp, a.getRow(), b.getCol());
	return result;
}
int main() {
	//array<array<int, N>, M> arr = { { { 5, 8, 2 }, { 8, 3, 1 } } };
	//array<array<int, N>, M> brr = { { { 1, 2, 1 }, { 0, 1, 1 } } };
	int arr[M][N] = { { 5, 8, 2 }, { 8, 3, 1 } };
	int brr[M][N] = { { 1, 2, 1 }, { 0, 1, 1 } };

	MATRIK A, B, C, D, BT;
	A.make(arr, 2, 3);    // buat matrik A ukuran 2x3
	//A.print();
	B.make(brr, 2, 3);    // buat matrik B ukuran 2x3
	BT = B.transpose();
	//B.print();
	//BT.print();
	C = A + B; C.print(); // menjumlah 2 matrik
	cout << endl;
	D = A*BT; D.print(); // mengalikan matrik
	//_getch();
	return 0;
}

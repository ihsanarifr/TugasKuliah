/*
Bahasa pemrograman Lisp dapat melakukan operasi aritmetika pada bilangan pecahan. Rancanglah suatu program untuk melakukan operasi aritmetika penambahan saja pada bilangan pecahan. Gunakan tipe data struct untuk menyimpan bilangan pecahan seperti berikut ini.

struct pecahan {
int pembilang;
unsigned int penyebut;
};
Format Masukan

Masukan terdiri atas satu baris yang terdiri atas kurung-buka, operasi +, dua bilangan pecahan, dan kurung-tutup. Penyebut pecahan selalu bilangan cacah (bilangan bulat positif lebih dari nol).

Format Keluaran

Keluaran berupa satu baris bilangan pecahan (yang telah disederhanakan) atau bilangan bulat yang diakhiri newline.

Contoh Masukan

(+ 7/3 1/6)

Contoh Keluaran

5/2

Contoh Masukan

(+ -1/3 -2/3)

Contoh Keluaran

-1
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct pecahan {
	int pembilang;
	unsigned int penyebut;
} pecahan_t;

int fpb(int a, int b)
{
	if (b == 0) return a;
	else return fpb(b, a%b);
}

int main()
{
	pecahan_t x, y, z;

	scanf("(+ %d/%u %d/%u)", &x.pembilang, &x.penyebut, &y.pembilang, &y.penyebut);

	// rumusnya kalikan silang
	// 7/3 + 1/6
	// pembilang = 7*6 + 1*3
	// penyebut = 7*6

	// penambahan
	z.pembilang = x.pembilang*y.penyebut + x.penyebut*y.pembilang;
	z.penyebut = x.penyebut*y.penyebut;

	// sederhanakan
	int fpbz = fpb(abs(z.pembilang), z.penyebut);
	z.pembilang /= fpbz;
	z.penyebut /= fpbz;

	printf("%d", z.pembilang);
	if (z.penyebut != 1) printf("/%u\n", z.penyebut);

	return 0;
}
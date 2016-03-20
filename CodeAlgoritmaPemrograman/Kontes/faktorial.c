/*
0! = 1
1! = 1
2! = 2  (1×2)
3! = 6  (1×2×3)
4! = 24 (1×2×3×4)
...
Lengkapilah kode program di bawah ini pada bagian fungsi untuk menghitung nilai faktorial.

#include <stdio.h>

unsigned long long int faktorial(unsigned int n)
{
// TODO: lengkapi kode program
}

int main(void)
{
unsigned int n;
scanf("%u!", &n);
printf("%llu\n", faktorial(n));
return 0;
}
Format Masukan

Masukan berupa satu baris yang terdiri atas satu bilangan asli [0, 20] diikuti dengan karakter '!'.

Format Keluaran

Keluaran berupa satu baris yang terdiri dari satu bilangan asli. Akhiri keluaran dengan newline.

Contoh Masukan

18!
Contoh Keluaran

6402373705728000

*/

#include<stdio.h>

unsigned long long int faktorial(unsigned int n)
{
	unsigned long long int hasil = 1;
	int i;
	for (i = 1; i <= n; i++)
	{
		hasil *= i;
	}
	return hasil;
	// TODO: lengkapi kode program
}

int main(void)
{
	unsigned int n;
	scanf("%u!", &n);
	printf("%llu\n", faktorial(n));
	return 0;
}
/*
Agam ingin membuat sebuah program yang dapat digunakan untuk melakukan operasi transpose matriks. Berikut adalah cuplikan program yang dibuat oleh Agam:

int main(void)
{
int matriks[][] = 0;

//membaca matriks
scanf("%d\n", &n);
for (i = 1; i <= n; i++)
for (j = 1; j <= n; j++)
scanf("%d", &matriks[i][j]);

//cetak transpose matriks
for (i = 1; i <= n; i++)
for (j = 1; j <= n; j++)
printf("%d", matriks[j][i]);

return 0;
}
Dengan mudah, Anda dapat melihat bahwa program tersebut salah. Tugas Anda ialah memperbaiki program tersebut sehingga program dapat menghasilkan keluaran yang benar. Untuk menyelesaikannya, ingatlah kembali sifat-sifat array.

Format Masukan

Masukan terdiri atas n baris dan n kolom yang merupakan matriks yang akan ditranspose (1 <= n <= 20). Nilai setiap sel pada matriks merupakan bilangan bulat positif yang kurang dari satu juta. Setiap nilai sel pada baris yang sama dipisahkan oleh sebuah karakter spasi.

Format Keluaran

Keluaran terdiri atas n baris dan n kolom yang merupakan hasil transpose matriks masukan. Setiap nilai sel pada baris yang sama dipisahkan oleh sebuah karakter spasi. Setelah isi sel terakhir dicetak, setiap baris langsung diakhiri dengan karakter newline.

Contoh Masukan

3
0 1 2
5 6 7
0 1 2
Contoh Keluaran

0 5 0
1 6 1
2 7 2
*/
#include <stdio.h>
#define SIZE 20
void cetakMatrik(int a[SIZE][SIZE], int n) {
	int i, j;
	for (i = 0; i<n; i++)
	for (j = 0; j<n; j++) {
		printf("%d", a[i][j]);
		printf(((j == n - 1) ? "\n" : " "));
	}
}
void transpose(int a[SIZE][SIZE], int b[SIZE][SIZE], int n) {
	int i, j;
	for (i = 0; i<n; i++)
	for (j = 0; j<n; j++)
		b[j][i] = a[i][j];

}

int main() {
	int x[SIZE][SIZE], y[SIZE][SIZE];
	int m, n, i, j;

	scanf("%d\n", &n);
	for (i = 0; i<n; i++)
	for (j = 0; j<n; j++)
		scanf("%d", &x[i][j]);

	//printf("Matrik Transpose:\n");
	transpose(x, y, n);
	cetakMatrik(y, n);
	return 0;
}
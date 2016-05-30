/*
Perusahaan Agri Elektronik sedang membuat perencanaan pengembangan sumber daya manusia perusahaan selama dua puluh tahun ke depan. Salah satu informasi yang mereka butuhkan untuk melakukan perencanaan tersebut ialah persebaran usia pegawai yang saat ini aktif bekerja di perusahaan.

Anda adalah seorang pemrogram yang bekerja di perushaana itu. Anda diminta untuk membuat program yang dapat menghitung jumlah pegawai yang berumur tertentu sesuai dengan format masukan dan format keluaran yang diberikan.

Format Masukan

Masukan terdiri atas tiga baris. Baris pertama ialah jumlah pegawai aktif (N). Baris kedua terdiri atas N bilangan bulat yang merupakan usia dari pegawai-pegawai yang ada. Bilangan bulat ini dipisahkan oleh karakter spasi.

Baris ketiga merupakan dua buah bilangan bulat A dan B yang merupakan batas bawah dan batas atas dari rentang usia yang harus dicetak oleh program. Nilai A dijamin tidak lebih besar daripada nilai B.

Format Keluaran

Keluaran terdiri atas beberapa baris yang terdiri atas dua bilangan yang dipisahkan karakter spasi yang memberikan informasi mengenai jumlah pegawai untuk setiap umur yang ada pada rentang masukan. Bilangan pertama adalah usia, sedangkan bilangan kedua adalah jumlah pegawai dengan usia tersebut. Setiap baris diakhiri oleh karakter newline.

Contoh Masukan

10
20 20 21 22 24 25 26 27 28 21
21 25

Contoh Keluaran

21 2
22 1
23 0
24 1
25 1

Batasan

1 < N < 1000000
20 < usia karyawan < 65
20 < A,B < 65
*/
#include<stdio.h>

int main()
{
	int data[100] = { 0 };
	int i;
	int n, m, o;
	int umur;

	scanf("%d", &n);

	for (i = 0; i<n; i++){
		scanf("%d", &umur);
		data[umur]++;
	}
	//scanf("%d %d",&m,&o);
	int bawah, atas;
	scanf("%d%d", &bawah, &atas);

	for (i = bawah; i <= atas; i++)
	{
		printf("%d %d\n", i, data[i]);
	}
	return 0;
}
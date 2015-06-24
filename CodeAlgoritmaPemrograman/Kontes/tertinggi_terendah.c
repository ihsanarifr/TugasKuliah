/*
Algoria menjadi salah satu panitia ujian internasional. Algoria diminta oleh ketua panitia untuk melaporkan nilai tertinggi dan nilai terendah (nilai berada pada rentang 0-100). Algoria mengalami kesulitan karena jumlah pesertanya sangat banyak (dapat mencapai 2 juta orang). Masalah lainnya adalah, berkas ujian tidak disimpan secara rapih sehingga jumlah berkas ujian yang ada tidak diketahui.

Bantulah Algoria menyelesaikan pekerjaannya dengan membuat program yang dapat digunakannya untuk memasukkan nilai yang ia baca dan mencetak nilai tertinggi dan terendah.

Format Masukan

Masukan sejumlah baris (paling banyak 2.000.000 baris) yang berisi bilangan bulat 0-100. Baris terakhir merupakan nilai -1 yang menandakan bahwa seluruh berkas ujian telah selesai direkap.

Format Keluaran

Keluaran terdiri atas dua buah baris. Baris pertama merupakan sebuah bilangan bulat yang meruipakan nilai ujian tertinggi. Baris kedua merupakan sebuah bilangan bulat yang merupakan nilai ujian terendah. Setiap baris diakhiri oleh karakter newline.

Contoh Masukan

100
20
30
80
10
2
7
14
-1

Contoh Keluaran

100
2
*/
#include<stdio.h>

int main()
{
	int cek;
	int hasil, terkecil = 100, terbesar = 0;

	while (cek != -1)
	{
		scanf("%d", &cek);

		if (cek != -1 && cek > terbesar)
		{
			terbesar = cek;
		}
		else if (cek != -1 && cek < terkecil)
		{
			terkecil = cek;
		}
	}

	printf("%d\n", terbesar);
	printf("%d\n", terkecil);

	return 0;
}
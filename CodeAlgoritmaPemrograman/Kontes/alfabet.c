/*
Kak Rakter ingin mengajarkan adiknya mengenal alfabet. Untuk itu, Kak Rakter ingin membuat sebuah program sederhana yang dapat mencetak karakter alfabet ke layar. Gunakan struktur kontrol perulangan untuk membantu Kak Rakter membuat program tersebut

Format Masukan

Masukan ialah sebuah bilangan bulat n (1 <= n <= 100).

Format Keluaran

Keluaran berupa satu baris yang terdiri atas n buah karakter alfabet berurutan. Apabila karakter alfabet habis (sampai di karakter Z), pencetakan karakter diulang kembali ke karakter A. Karakter yang dicetak semuanya merupakan huruf kapital.

Keluaran diakhiri dengan newline.

Contoh Masukan

27
Contoh Keluaran

ABCDEFGHIJKLMNOPQRSTUVWXYZA
*/

#include<stdio.h>

int main()
{
	int i, n;
	char x = 65;

	scanf("%d", &n);

	for (i = 0; i<n; i++)
	{
		printf("%c", x);
		x++;
		if (x == 91)
		{
			x = 65;
		}
	}
	printf("\n");
	return 0;
}

/*
Rancang sebuah program untuk mengubah kalimat dengan gaya penulisan berantakan huruf besar-kecil (alay) menjadi kalimat dengan gaya penulisan normal (awal kalimat huruf besar, selanjutnya huruf kecil).

Format Masukan

Masukan terdiri atas satu baris string kalimat alay yang diakhiri dengan newline, panjang teks maksimal 1000 karakter.

Format Keluaran

Keluaran berupa kalimat yang sudah diubah sesuai dengan gaya penulisan normal (awal kalimat huruf besar, selanjutnya huruf kecil). Akhiri keluaran dengan newline.

Contoh Masukan

HuRuF bEsAr keCil.

Contoh Keluaran

Huruf besar kecil.
*/
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
	char alay[1001];

	fgets(alay, sizeof(alay), stdin);

	alay[0] = toupper(alay[0]);
	int i;
	int n = strlen(alay);
	for (i = 1; i<n; i++)
	{
		if (isupper(alay[i]))
		{
			alay[i] = tolower(alay[i]);
		}
	}
	fputs(alay, stdout);

	return 0;
}
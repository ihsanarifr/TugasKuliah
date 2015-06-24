/*
Rancang sebuah program untuk membalik suatu teks dengan memakai fungsi dengan prototipe sebagai berikut.

char *text_reverse(char *text);
Berikut adalah contoh pemakaian fungsi tersebut.

int main()
{
char text[81] = {0};

gets(text);

printf("%s\n", text_reverse(text));

return 0;
}

Format Masukan

Masukan berupa satu baris teks yang terdiri atas maksimal 80 karakter yang diakhiri dengan newline.

Format Keluaran

Keluaran berupa satu baris balikan teks yang diakhiri dengan newline.

Contoh Masukan

Google Maps

Contoh Keluaran

spaM elgooG
*/
#include<stdio.h>
#include<string.h>
char coba[81] = { 0 };
char *text_reverse(char *text)
{
	int i, n, j = 0;
	n = strlen(text);
	//printf("%c",*text);
	for (i = n - 1; i >= 0; i--)
	{
		coba[j] = text[i];
		j++;
	}
	return coba;
}

int main()
{
	char text[81] = { 0 };
	char a[81] = { 0 };
	int n, i;
	gets(text);

	n = strlen(text);
	//printf("%d",n);
	/*for(i=n-1;i>=0;i--)
	{
	printf("%c",text[i]);
	}
	*/
	printf("%s\n", text_reverse(text));

	return 0;
}
/*
Buatlah program untuk membaca dua bilangan bulat a dan b, serta sebuah bilangan pecahan c; kemudian cetak nilai dari a/b+c.

Format Masukan
Baris pertama adalah dua bilangan bulat a dan b yang masing-masing dipisahkan oleh satu spasi, dan baris kedua adalah sebuah bilangan pecahan c, dimana a,b bernilai +2Milyard, dan -3.4E+30≤c≤3.4E+30. Dijamin b tidak pernah bernilai 0.

Format Keluaran
Sebuah bilangan pecahan hasil perhitungan a/b+c dengan dua digit di belakang decimal dan diakhiri dengan newline.

Contoh Masukan
8 4
2.153

Contoh Keluaran
4.15
*/
#include<stdio.h>

int main()
{
    //long int a,b;
    double a,b,c,hasil;

    scanf("%lf %lf\n %lf",&a,&b,&c);
    hasil = (a/b)+c;
    printf("%.2lf\n",hasil);

    return 0;
}

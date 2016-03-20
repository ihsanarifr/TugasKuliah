/*
Buat program yang membaca empat bilangan bulat (a, b, c, dan d). Ada empat istilah terkait dengan susunan dari keempat bilangan tersebut, yaitu KONSTAN (keempat bilangan adalah sama), MONOTON MENAIK (bilangan sebelah kanan lebih besar atau sama dengan dari bilangan sebelah kirinya tetapi keempatnya tidak sama), MONOTON MENURUN (bilangan sebelah kanan lebih kecil atau sama dengan dari bilangan sebelah kirinya tetapi keempatnya tidak sama), dan TIDAK MONOTON jika tidak memenuhi semua syarat sebelumnya.

Format Masukan

Data masukan terdiri atas empat nilai bilangan bulat yang dituliskan dalam satu baris, masing-masing dipisahkan oleh satu spasi, dengan kisaran nilai +2 Milyard.

Format Keluaran

Teks "KONSTAN", "MONOTON MENAIK", "MONOTON MENURUN", atau "TIDAK MONOTON" sesuai dengan ketentuan di atas. Teks dituliskan dengan huruf kapital semua dan diakhiri dengan newline.

Contoh Masukan 1

50 25 15 15
Contoh Keluaran 1

MONOTON MENURUN
Contoh Masukan 2

2 15 15 10
Contoh Keluaran 2

TIDAK MONOTON
*/
#include<stdio.h>

int main()
{
    long int a,b,c,d;

    /*a = 5;
    b = 4;
    c = 3;
    d = 2;
    */
    scanf("%ld %ld %ld %ld",&a,&b,&c,&d);

    if(a >= b && b>=c && c>=d)
    {
        if(a == b && b == c && c == d)
        {
            printf("KONSTAN\n");
        }
        else
        {
            printf("MONOTON MENURUN\n");
        }
    }
    else
    {
        if(a <= b && b <= c && c <= d)
        {
            printf("MONOTON MENAIK\n");
        }
        else
        {
            printf("TIDAK MONOTON\n");
        }
    }
    return 0;
}

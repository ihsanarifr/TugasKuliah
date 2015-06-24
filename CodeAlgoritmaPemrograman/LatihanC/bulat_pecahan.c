/*
Format Masukan
Baris pertama berisi bilangan a dan b yang dipisahkan oleh satu spasi, dan baris kedua berisi bilangan c dengan ketentuan seperti tertulis dalam deskripsi soal di atas.

Format Keluaran
Satu baris yang berisi tiga bilangan dengan susunan a berada paling kiri, kemudian c di tengah, dan paling kanan adalah bilangan b. masing-masing bilangan dipisahkan oleh satu spasi, dan baris ini diakhiri dengan newline. Nilai c dituliskan dengan dua digit di belakang tanda titik (desimal).

Contoh Masukan
5 190829
98.38281

Contoh Keluaran
5 98.38 190829
*/
#include<stdio.h>

int main()
{
    int a;
    long int b;
    double c;
    
    scanf("%d %ld",&a,&b);
    scanf("%lf",&c);
    printf("%d %.2lf %ld\n",a,c,b);
    return 0;
}

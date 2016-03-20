/*
Format Masukan
Satu baris yang berisi dua bilangan bulat, dipisahkan oleh satu spasi. Bilangan a di sebelah kiri, dan bilangan b di sebelah kanan. Nilai bilangan a cukup kecil (+32ribu), sedangkan nilai bilangan b sangat besar (+2Milyard).

Format Keluaran
Dua baris bilangan, dimana baris pertama adalah bilangan b, dan baris kedua adalah bilangan a. Setiap baris diakhiri dengan newline.

Contoh Masukan
10 234

Contoh Keluaran
234
10
*/
#include<stdio.h>

int main()
{
    int a;
    long int b;
    scanf("%d %ld",&a,&b);
    printf("%ld\n",b);
    printf("%d\n",a);
    return 0;
}

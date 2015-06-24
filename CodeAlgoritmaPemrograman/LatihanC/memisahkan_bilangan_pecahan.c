/*
Format Masukan
Data masukan berupa sebuah bilangan positif floating point x.

Format Keluaran
Output program adalah dua bilangan yang dituliskan dalam satu baris yang dipisahkan oleh satu spasi, dimana bilangan sebelah kiri adalah sebuah bilangan bulat yang merupakan bagian bilangan bulat dari x, dan sebelah kanan adalah bagian bilangan pecahan sesuai ketentuan di atas yang ditulis dalam 5 digit di belakang tanda desimal. Output ini diakhiri dengan newline.

Contoh Masukan
54000.345124

Contoh Keluaran
54000 0.34512
*/
#include<stdio.h>
int main()
{
    double asal,desimal;
    int bulat;

    scanf("%lf",&asal);
    //asal = 1242314.1523;
    bulat = asal;
    desimal = asal - bulat;

    //printf("%f %d %lf",asal,bulat,desimal);
    printf("%d %.5lf\n",bulat,desimal);
    return 0;
}

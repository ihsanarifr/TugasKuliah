/*
Format Masukan
Input data berupa tiga bilangan real yang ditulis dalam tiga baris. Nilai masing-masing bilangan adalah antara -100000 sampai dengan +100000.

Format Keluaran
Output program terdiri atas tiga baris yang tiap barisnya berupa komponen sebelum titik desimal dari input dengan urutan yang terbalik. Setiap baris diakhiri dengan newline

Contoh Masukan
10.4
15.67
9.0
Contoh Keluaran
9
15
10
*/
#include<stdio.h>

int main()
{
    double desimal1,desimal2,desimal3;
    int bulat1,bulat2,bulat3;

    scanf("%lf\n",&desimal1);
    scanf("%lf\n",&desimal2);
    scanf("%lf",&desimal3);

    bulat1 = desimal1;
    bulat2 = desimal2;
    bulat3 = desimal3;

    printf("%d\n%d\n%d\n",bulat3,bulat2,bulat1);
}

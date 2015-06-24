/*
Rancang sebuah program untuk mengkonversi dari nomor bulan menjadi nama bulan. Berikut adalah urutan nama bulan yang diinginkan.

Januari, Februari, Maret, April, Mei, Juni, Juli, Agustus, September, Oktober, November, Desember

Format Masukan

Masukan berupa satu baris yang terdiri atas bilangan asli nomor bulan.

Format Keluaran

Keluaran berupa nama bulan. Jika input selain [1, 12], keluaran berupa kalimat "Input tidak valid". Akhiri keluaran dengan karakter newline.

Contoh Masukan 1

2
Contoh Keluaran 1

Februari

Contoh Masukan 2

13
Contoh Keluaran 2

Input tidak valid

*/
#include<stdio.h>

int main()
{
    short bulan;
    
    scanf("%d",&bulan);
    
    switch(bulan)
    {
       case 1:
            printf("Januari\n");
            break;
       case 2:
            printf("Februari\n");
            break;
       case 3:
            printf("Maret\n");
            break;
       case 4:
            printf("April\n");
            break;
       case 5:
            printf("Mei\n");
            break;
       case 6:
            printf("Juni\n");
            break;
       case 7:
            printf("Juli\n");
            break;
       case 8:
            printf("Agustus\n");
            break;
       case 9:
            printf("September\n");
            break;
       case 10:
            printf("Oktober\n");
            break;
       case 11:
            printf("November\n");
            break;
       case 12:
            printf("Desember\n");
            break;
       default:
            printf("Input tidak valid\n");
    }
    //getch();
    return 0;
}

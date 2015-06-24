/*
Algoria diminta maju oleh asisten praktikum. Ia diminta untuk membuat program yang menerima masukan berupa sebuah bilangan bulat n. Program kemudian akan mencetak sebanyak bilangan bulat ganjil yang berada pada selang 1 sampai n. Akan tetapi, program Algoria mengandung beberapa kesalahan. Berikut adalah cuplikan program Algoria:

#include <studio.h>

int main()
{
int i,x;
scanf("%d", &x);
for(i=1; i<x; i+2);
printf("%d\n", x);
return 0;
}

Tugas Anda ialah membantu Algoria memperbaiki program tersebut.

Format Masukan

Masukan berupa sebuah bilangan asli n yang berada pada selang [1,1000].

Format Keluaran

Keluaran berupa bilangan asli ganjil yang berada pada selang [1,n]. Setiap bilangan diakhiri dengan karakter newline.

Contoh Masukan

5
Contoh Keluaran

1
3
5
*/
#include<stdio.h>

int main()
{
    int i,x;
    scanf("%d", &x);
    for(i=1; i<=x; i++)
    {
        printf("%d\n", i);
        i++;
    }
    return 0;
}

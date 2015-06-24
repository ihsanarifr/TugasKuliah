/*
Rancang sebuah program untuk menentukan status kelulusan dari nilai uts, uas, ujian praktikum dan nilai tugas seorang mahasiswa. Bobot nilai uts 35%, uas 35%, ujian praktikum 25% dan tugas 5%. Jika nilai akhir kurang dari 40, maka mahasiswa tidak lulus.

Format Masukan

Masukan berupa satu baris yang terdiri atas bilangan real uts, uas, ujian praktikum, dan tugas yang dipisahkan oleh satu spasi. Rentang nilai ialah [0, 100].

Format Keluaran

Keluaran berupa kata "LULUS" atau "TIDAK LULUS" yang dicetak pada layar sesuai dengan nilai akhir mahasiswa. Akhiri baris dengan karakter newline.

Contoh Masukan

65 78.5 80 90
Contoh Keluaran

LULUS
*/
#include<stdio.h>

int main()
{
    float a,b,c,d,hasil;
    
    scanf("%f %f %f %f",&a,&b,&c,&d);
    
    hasil = (35.0/100.0*a)+(35.0/100.0*b)+(25.0/100.0*c)+(5.0/100.0*d);
    
    //printf("%f",hasil);
    if(hasil < 40.0)
    {
       printf("TIDAK LULUS\n");
    }
    else
    {
        printf("LULUS\n");
    }
    
    //getch();
    return 0;
}

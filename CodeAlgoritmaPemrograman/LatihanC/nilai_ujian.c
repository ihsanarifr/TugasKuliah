/*
Buat program membaca tiga nilai ujian. Dari ketiga nilai tersebut dihitung rata-ratanya, dan selanjutnya dibuat kondisi bahwa jika rata-rata kurang dari 30, maka dituliskan teks KURANG ke layar komputer. Jika rata-rata lebih atau sama dengan 30 tetapi kurang dari 60 maka dituliskan teks CUKUP. Dan jika selainnya (lebih atau sama dengan 60) maka dituliskan teks BAIK.

Format Masukan

Data masukan terdiri atas tiga nilai floating point yang dituliskan dalam satu baris, masing-masing dipisahkan oleh satu spasi, yang menunjukkan tiga nilai ujian dengan skala 0-100.

Format Keluaran

Nilai rata-rata dari ketiga nilai ujian yang dituliskan dengan dua digit di belakang titik desimal, dan diikuti dengan sebuah teks KURANG, CUKUP, atau BAIK sesuai dengan kategori nilai rata-rata yang telah ditetapkan. Teks dituliskan dengan huruf kapital semua. Tidak ada spasi antara nilai rata-rata dan teks.

Contoh Masukan

30.5 98.12 87.956
Contoh Keluaran

72.19BAIK
*/
#include<stdio.h>

int main()
{
    float nilai1,nilai2,nilai3,rata;

    scanf("%f %f %f",&nilai1,&nilai2,&nilai3);

    rata = (nilai1+nilai2+nilai3)/3;

    if(rata >= 60)
    {
        printf("%.2fBAIK",rata);
    }
    else if(rata >= 30)
    {
        printf("%.2fCUKUP",rata);
    }
    else
    {
        printf("%.2fKURANG",rata);
    }
    return 0;
}

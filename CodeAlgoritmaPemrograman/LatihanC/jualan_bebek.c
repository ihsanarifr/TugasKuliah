/*
Pak Algor memiliki peternakan bebek yang sangat besar. Pada saat tertentu, Pak Algor menjual beberapa bebeknya ke pasar terdekat. Setiap bebek yang dijual dikelompokkan ke dalam empat kelas sesuai dengan beratnya, yaitu kelas 1 jika berat bebek 1-2 kg, kelas 2 jika berat bebek 2-3 kg, kelas 3 jika berat bebek 3-4 kg, dan kelas 4 jika berat bebek lebih besar atau sama dengan 4 kg. Harga jual untuk bebek kelas 1 ditentukan sebesar x rupiah per ekor, sedangkan harga bebek kelas berikutnya adalah y rupiah lebih mahal dibanding satu kelas di bawahnya. Jadi, misalnya x=1000, dan y=500, maka harga bebek kelas 1, 2, 3, dan 4 berturut-turut adalah 1000, 1500, 2000, dan 2500 rupiah per ekor.
Pada saat menjual bebek-bebeknya, Pak Algor membawa ke pasar bebek-bebek tersebut dalam jumlah tertentu untuk setiap kelas bebek. Bantulah Pak Algor untuk menghitung berapa uang yang bisa dibawa pulang setelah semua bebek habis terjual.

Format Masukan
Data masukan terdiri atas lima baris. Baris pertama adalah banyaknya bebek kelas 1 yang akan dijual oleh Pak Algor, baris kedua adalah banyaknya bebek kelas 2, baris ketiga adalah banyaknya bebek kelas 3, dan baris keempat adalah banyaknya bebek kelas 4 yang akan dijual. Baris kelima adalah dua bilangan yang dipisahkan oleh satu spasi, dimana bilangan pertama adalah harga jual bebek kelas 1 (nilai x) sedangkan bilangan kedua adalah selisih harga kelas berikutnya (nilai y), keduangan merupakan bilangan floating point.

Format Keluaran
Output program adalah sebuah bilangan floating point yang menunjukkan besar uang yang diperoleh Pak Algor dari hasil penjualan semua bebek-bebeknya. Hasil dituliskan dengan dua digit di belakang tanda titik, dan tanpa diakhiri dengan newline.

Contoh Masukan
3
5
2
1
1000.0 500.0

Contoh Keluaran
17000.00
*/
#include<stdio.h>

int main()
{
    float kelas1,kelas2,kelas3,kelas4;
    float hasil1,hasil2,hasil3,hasil4;
    float x,y;
    float hasil;

    scanf("%f",&kelas1);
    scanf("%f",&kelas2);
    scanf("%f",&kelas3);
    scanf("%f",&kelas4);
    scanf("%f %f",&x,&y);

    hasil1= kelas1 * x;
    hasil2 = kelas2 * (x+y);
    hasil3 = kelas3 * (x+y+y);
    hasil4 = kelas4 * (x+y+y+y);

    hasil = hasil1+hasil2+hasil3+hasil4;

    //printf("%f %f %f %f\n",kelas1,kelas2,kelas3,kelas4);
    printf("%.2f",hasil);

    return 0;
}

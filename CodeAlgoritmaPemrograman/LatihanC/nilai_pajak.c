/*
Seorang petani sukses bernama Pak Algor (saudara kembar Pak Dengklek versi TOKI Biro ITB) merupakan warga negara yang taat pajak, dimana setiap tahun dia mengisi lembar isian pajak penghasilan tahunan dan selanjutnya membayar nilai pajak ke Kantor Pajak setempat. Penghasilan Pak Algor berasal dari penjualan tiga komoditi pertanian. Pak Algor selalu menghitung total penghasilan dari penjualan tersebut. Untuk itu, dia mencatat jumlah satuan penjualan dan harga untuk ketiga komoditi yang dijual. Misalnya komoditi A yang dijual sebanyak 5 dengan harga 1000, komoditi B sebanyak 10 dengan harga 200, dan komoditi C sebanyak 10 dengan harga 1500. Selanjutnya Pak Algor menghitung total penjualan, yaitu 5x1000 + 10x200 + 10x1500 = 22000. Nilai pajak diberikan oleh Kantor Pajak dengan satuan persen. Jadi, misalnya ditentukan besaran pajak adalah 10%, maka Pak Algor akan membayar pajak sebesar 2200, sehingga penghasilan bersih Pak Algor adalah 22000-2200 = 19800.

Format Masukan
Data masukan terdiri atas tiga baris yang menunjukkan penjualan tiga komoditi, masing-masing terdiri dari dua bilangan yang dipisahkan oleh satu spasi. Bilangan pertama adalah banyaknya penjualan dalam bilangan bulat dan bilangan kedua adalah harga jual per satuan dalam bilangan pecahan (floating point). Baris keempat berisi sebuah bilangan floating point yang menunjukkan besar pajak (dalam persen).

Format Keluaran
Output program adalah dua bilangan floating point yang ditulis dalam satu baris dan dipisahkan oleh tepat satu spasi. Bilangan pertama menunjukkan nilai pajak yang dibayarkan oleh Pak Algor, dan bilangan kedua adalah besar penghasilan setelah dipotong pajak. Kedua bilangan tersebut dituliskan dengan dua digit di belakang tanda desimal, dan diakhiri dengan newline.

Contoh Masukan
5 1000
10 200
10 1500
10.0

Contoh Keluaran
2200.00 19800.00
*/
#include<stdio.h>

int main()
{
    int a,b,c;
    float harga1,harga2,harga3,persen,potongan,hasil,total;

    scanf("%d %f",&a,&harga1);
    scanf("%d %f",&b,&harga2);
    scanf("%d %f",&c,&harga3);
    scanf("%f",&persen);

    hasil = (a*harga1)+(b*harga2)+(c*harga3);
    persen = hasil * persen /100;

    total = hasil - persen;

    printf("%.2f %.2f\n",persen,total);
    return 0;
}

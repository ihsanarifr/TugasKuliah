/*
Buatlah program untuk menentukan keliling dan luas lingkaran jika diketahui diameter lingkaran. Perlu diketahui bahwa keliling lingkaran adalah 2 x pi x r, sedangkan luas lingkaran adalah pi x r2, dimana pi bernilai 3.14, dimana r adalah jari-jari lingkaran = 0.5*diameter.

Format Masukan
Sebuah bilangan bulat yang menyatakan diameter lingkaran d, dimana nilai d bisa mencapai 2 milyard.

Format Keluaran
Satu baris berisi dua nilai, sebelah kiri adalah keliling lingkaran, dan sebelah kanannya adalah luas lingkaran. Kedua nilai ini dipisahkan oleh satu spasi, ditulis dengan dua digit di belakang tanda desimal, dan diakhiri dengan newline.

Contoh Masukan
20

Contoh Keluaran
62.80 314.00
*/
#include<stdio.h>

int main()
{
    long int d; 
    double r,l,k,pi = 3.14; 
    
    scanf("%ld",&d);
    r = 0.5*d;
    
    l = pi*r*r;
    k = 2.00*pi*r;
    //printf("%f\n",r);
    printf("%.2lf %.2lf\n",k,l);
    //getch();
    return 0;
}

/*
Di dalam operasi aritmatika dikenal sisa pembagian, atau modulo. Misalnya 8 modulo 4 adalah 0, 10 modulo 4 adalah 2, dan seterusnya. Nah, sekarang buatlah program untuk membaca dua bilangan bulat, dan tuliskan hasil sisa pembagiannya.

Format Masukan
Satu baris yang berisi dua bilangan bulat a dan b, yang dipisahkan oleh satu spasi. Bilangan a di sebelah kiri b. Kedua bilangan ini bisa sangat besar, yaitu bisa mencapai nilai 2 Milyar. Dijamin keduanya tidak negatif, dan b tidak pernah bernilai 0.

Format Keluaran
Sebuah bilangan bulat hasil sisa pembagian a dari b, atau a modulo b. Nilai ini ditulis ke layar dan diakhiri dengan newline.

Contoh Masukan
10 4

Contoh Keluaran
2
*/
#include<stdio.h>

int main()
{
    long int a,b,c;    
    
    scanf("%ld %ld",&a,&b);
    
    if(b > 0)
    {
         c = a % b;
         printf("%ld\n",c);     
    }
    //getch();
    return 0;
}

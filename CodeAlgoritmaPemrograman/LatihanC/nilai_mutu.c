/*
Buat program yang membaca sebuah karakter berupa huruf mutu. Huruf mutu (A, B, C, D, E) dapat dituliskan dalam huruf besar atau kecil. Program akan menuliskan angka mutu, yaitu 4 untuk A, 3 untuk B, 2 untuk C, 1 untuk D, 0 untuk E, dan -1 untuk lainnya. Catatan: ingat format untuk membaca karakter, yaitu misalnya menggunakan fungsi scanf("%c", &ch), dimana ch dideklarasikan sebagai char. Disamping itu, literal constant character dalam program C dituliskan dengan menggunakan tanda kutip, misalnya 'A', 'a', dan sebagainya. Berlatihlah menggunakan pernyataan switch di dalam program Anda.

Format Masukan
Data masukan berupa sebuah huruf mutu (bisa huruf kecil atau besar).

Format Keluaran
Angka mutu dari huruf mutu masukan sesuai ketentuan, dan diakhiri dengan newline.

Contoh Masukan 1
A
Contoh Keluaran 1
4
Contoh Masukan 2
b
Contoh Keluaran 2
3
*/
#include<stdio.h>

int main()
{
    char mutu;

    scanf("%c", &mutu);

    switch(mutu)
    {
    case 'A':
        printf("4\n");
        break;
    case 'a':
        printf("4\n");
        break;
    case 'B':
        printf("3\n");
        break;
    case 'b':
        printf("3\n");
        break;
    case 'C':
        printf("2\n");
        break;
    case 'c':
        printf("2\n");
        break;
    case 'D':
        printf("1\n");
        break;
    case 'd':
        printf("1\n");
        break;
    case 'E':
        printf("0\n");
        break;
    case 'e':
        printf("0\n");
        break;
    default:
        printf("-1\n");
    }
    return 0;
}

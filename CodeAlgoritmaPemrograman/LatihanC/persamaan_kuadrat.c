/*
Nah sekarang buatlah program untuk menentukan jawaban dari persamaan kuadrat ax2+bx+c=0 dengan menggunakan rumus ABC, yaitu x1=(-b+d)/2a dan x2=(-b-d)/2a, dimana d adalah akar kuadrat dari b2-4ac.

Format Masukan
Satu baris terdiri atas tiga bilangan bulat a, b, dan c yang merupakan koefisien dari persamaan kuadrat ax2+bx+c, yang masing-masing dapat bernilai +2 milyar. Ketiga bilangan ini dipisahkan oleh satu spasi.

Format Keluaran
Dua bilangan x1 dan x2 yang merupakan jawaban dari persamaan kuadrat, dimana nilai x1 di sebelah kiri x2, dipisahkan oleh satu spasi, dan diakhiri dengan newline. Dijamin ada jawaban dari persamaan yang diberikan. Kedua nilai x1 dan x2 dituliskan dengan dua digit di belakang tanda desimal.

Contoh Masukan
1 2 -8

Contoh Keluaran
2.00 -4.00
*/
#include <stdio.h>
#include <math.h>

main () {

long int a, b, c;
double d, x1, x2;

scanf("%ld %ld %ld", &a, &b, &c);

d=sqrt(b*b-4*a*c);
x1=(-b+d)/2*a;
x2=(-b-d)/2*a;

printf("%.2lf %.2lf\n", x1, x2);

return 0;

}

#include<stdio.h>
 
int main()
{
    double a,hasil;
    unsigned int c;
    char b;
    scanf("%lf %c %u",&a,&b,&c);
 
    hasil = a * c;
    c = c-1;
    printf("%.2lf %c %u\n",hasil,b,c);
     
}

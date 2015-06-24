#include<stdio.h>

int main()
{
    double a,b,c,hasil,total;
    unsigned int d,e,f,bagi;
    
    scanf("%lf %lf %lf\n",&a,&b,&c);
    scanf("%u %u %u",&d,&e,&f);
    
    total = (a*d) + (b*e) + (c*f);
    bagi = d+e+f;
    
    hasil = total/bagi;
    
    printf("%.2lf\n",hasil);
    getch();
}

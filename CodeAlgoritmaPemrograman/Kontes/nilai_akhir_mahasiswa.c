#include<stdio.h>
int main()
{
    float a,b,c,d,e,f,hasil,hasil2,hasil3,total;
    scanf("%f %f %f\n %f %f %f",&a,&b,&c,&d,&e,&f);
    hasil = a*d;
    hasil2 = b*e;
    hasil3 = f*c;
    total = hasil+hasil2+hasil3;
    printf("%.2f\n",total);
 
    return 0;
}

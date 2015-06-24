#include<stdio.h>
int main()
{
    float alas,tinggi,luas;
 
    scanf("%f %f", &alas,&tinggi);
 
    luas = 0.5 * alas * tinggi;
 
    printf("%.2f\n",luas);
}


#include<stdio.h>
int main()
{
    float a,b,c,d;
    /*
    a = 2.0;
    b = 4.0;
    c = 1.0;
    */
    scanf("%f %f %f",&a,&b,&c);

    d = (b*b) - (4*a*c);

    if(d > 0)
        //d = cbrt(d);
        printf("2 %.2f\n",d);
    else if(d == 0)
        //d = cbrt(d);
        printf("1 %.2f\n",d);
    else
        printf("tidak ada\n");
    return 0;
}

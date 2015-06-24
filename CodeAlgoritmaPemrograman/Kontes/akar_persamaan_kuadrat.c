#include<stdio.h>
#include<math.h>

int main()
{
    short a,b,c;
    float x1,x2,d;

    scanf("%hd %hd %hd",&a,&b,&c);

    d = ((b*b) - (4*a*c));

    x1 = (-b + sqrt(d)) / (2*a);
    x2 = (-b - sqrt(d)) / (2*a);

    if(d < 0)
    {
         printf("Tidak memiliki akar real.\n");
    }
    else
    {
        printf("%g %g\n",x1,x2);
    }

    return 0;
}

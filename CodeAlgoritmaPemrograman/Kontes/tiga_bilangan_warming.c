#include<stdio.h>

int main()
{
    int a,b,c,hasil;

    scanf("%d %d %d",&a,&b,&c);

    hasil = a*b;

    if(c > hasil)
    {
        printf("YA\n");
    }
    else
    {
        printf("TIDAK\n");
    }

    return 0;
}

#include<stdio.h>

int main()
{
    int n,i,x;
    int ganjil=0,genap=0,hasil;

    for(i=0;i<10;i++)
    {
        scanf("%d",&x);
        if( x%2 == 1)
        {
            ganjil++;
        }
        else
        {
            genap++;
        }
    }
    printf("%d %d\n",genap,ganjil);
    return 0;
}

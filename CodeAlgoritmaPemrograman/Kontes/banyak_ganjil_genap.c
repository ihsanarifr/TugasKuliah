#include<stdio.h>

int main()
{
    int ganjil=0,genap=0,i,n,coba=0;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&coba);

        if(coba%2 == 0)
        {
            genap++;
        }
        else
        {
            ganjil++;
        }
    }
    printf("%d %d\n",ganjil,genap);

    return 0;
}

#include<stdio.h>

int main()
{
    int n,i;
    scanf("%ld",&n);

    for(i=1;i<=n;i++)
    {
        //hasil=hasil+i;

        if(i == 93)
        {
            printf("ERROR\n");
            break;
        }
        else
        {
            printf("%d\n",i);
        }
    }
    return 0;
}

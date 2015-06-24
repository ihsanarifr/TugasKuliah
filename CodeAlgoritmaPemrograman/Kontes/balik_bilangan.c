#include<stdio.h>

int main()
{
    int m[1001];
    int n,i,b,t;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&m[i]);

    for(i=n-1;i>0;i--)
    {
        scanf("%d",&b);

        if(b != m[i])
        {
            if(t != 1)
            {
                printf("%d\n",i+1);
                t = 1;
            }
        }
    }

    if(t != 1)
        printf("0\n");
    return 0;
}

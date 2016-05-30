#include<stdio.h>

int main()
{
    int m[1000];
    int i,n,input,low,high;

    scanf("%d",&input);
    for(i=0;i<input;i++)
    {
        scanf("%d",&m[i]);
    }
    scanf("%d %d",&low,&high);

    if(low >= high)
    {
        for(i=low-1;i>=high-1;i--)
        {
        if(i < input)
            printf("%d\n",m[i]);
        else if(i==0)
            break;
        else
            printf("-\n");
        }
    }
    else
    {
        for(i=low-1;i<=high-1;i++)
        {
        if(i < input)
            printf("%d\n",m[i]);
        else
            printf("-\n");
        }
    }

    return 0;
}

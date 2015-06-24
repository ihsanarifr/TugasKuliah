#include <stdio.h>
#define SIZE 100

int main()
{
	int n,i,j;
    int a[SIZE][SIZE]={0};
    int b[SIZE]={0};
	int hasil =0;

    scanf("%d",&n);

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d",&a[i][j]);

    for(i = 0; i < n; i++)
        scanf("%d",&b[i]);


     for(i=0;i<n;i++)
    {
        hasil=0;
        for(j=0;j<n;j++)
        hasil+=a[i][j]*b[j];
            printf("%d\n",hasil);

    }


    return 0;
}

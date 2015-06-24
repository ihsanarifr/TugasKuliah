#include <stdio.h>
#define SIZE 100

void perkalian(int x[SIZE][SIZE],int y[SIZE],int n)
{
    int i,j;
    int hasil = 0;
    for(i=0;i<n;i++)
    {
        hasil=0;
        for(j=0;j<n;j++)
            hasil+=x[i][j]*y[j];
        printf("%d\n",hasil);
    }
}

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

    perkalian(a,b,n);
    return 0;
}

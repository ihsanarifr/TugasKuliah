#include<stdio.h>
int n;
int matriks[20][20];
void tukar_kolom(int a,int b)
{
    int i,simpan[20][20];
    for(i=0;i<n;i++)
    {
        simpan[i][a] = matriks[i][a];
        matriks[i][a] = matriks[i][b];
        matriks[i][b] = simpan[i][a];
    }
}
 
void tukar_baris(int a,int b)
{
    int i,simpan[20][20];
    for(i=0;i<n;i++)
    {
        simpan[a][i] = matriks[a][i];
        matriks[a][i] = matriks[b][i];
        matriks[b][i] = simpan[a][i];
    }
}
 
int main()
{
    int i,j,k,m,a,b;
    int kode[2]={0};
 
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&matriks[i][j]);
        }
    }
 
    scanf("%d", &m);
    for(k=0;k<m;k++)
    {
        scanf("%s %d %d",&kode,&a,&b);
 
        if(kode[0] == 'K')
        {
            tukar_kolom(a,b);
        }
        else
        {
            tukar_baris(a,b);
        }
        /*switch(kode)
        {
        case 'K' :
            tukar_kolom(a,b);
        case 'B' :
            tukar_baris(a,b);
        }*/
    }
 
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d",matriks[i][j]);
            printf(((j==n-1)?"\n":" "));
        }
    }
    return 0;
}
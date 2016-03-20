#include<stdio.h>
int n;
void fliprow(int B[20][20],int c,int d)
{
    int i,temp[20][20];
    for(i=0;i<n;i++)
    {
        temp[c][i] = B[c][i];
        B[c][i]=B[d][i];
        B[d][i]=temp[c][i];
    }
}
void flipcol(int B[20][20],int c,int d)
{
    int i,temp[20][20];
    for(i=0;i<n;i++)
    {
        temp[i][c] = B[i][c];
        B[i][c]=B[i][d];
        B[i][d]=temp[i][c];
    }
}
int main()
{
    int A[20][20];
    int nop;
    char op;
    int x,y;
    int i,j,k;

    // baca matrix
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&A[i][j]);

    // operasi flip(B/K)
    scanf("%d\n",&nop);
    for(k=0;k<nop;k++)
    {
        scanf("%c %d %d\n",&op,&x,&y);
        if(op == 'B')
            fliprow(A,x,y);
        else if(op == 'K')
            flipcol(A,x,y);
    }

    // cetak
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%d ",A[i][j]);
        printf("\n");
    }
}

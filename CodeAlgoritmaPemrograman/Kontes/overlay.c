/*
Format Masukan

Baris pertama masukan ialah bilangan bulat N (1<=N<=20). N baris berikutnya adalah matriks pertama. N baris berikutnya lagi adalah matriks kedua. Setiap matriks yang dioperasikan berukuran N×N. Nilai setiap sel pada matriks berada pada rentang [0, 9]. Nilai setiap sel dipisahkan oleh sebuah karakter spasi.

Format Keluaran

Keluaran terdiri atas N baris dan N kolom yang merupakan hasil operasi overlay maksimum. Setiap nilai sel pada baris yang sama dipisahkan oleh sebuah karakter spasi. Setelah isi sel terakhir dicetak, setiap baris langsung diakhiri dengan karakter newline.

Contoh Masukan

5

1 1 1 1 1
1 6 6 6 1
1 6 3 6 1
1 6 6 6 1
1 1 1 1 1

3 3 3 3 3
3 2 2 2 3
3 2 1 2 3
3 2 2 2 3
3 3 3 3 3
Contoh Keluaran

3 3 3 3 3
3 6 6 6 3
3 6 3 6 3
3 6 6 6 3
3 3 3 3 3

*/
#include<stdio.h>

int main()
{
    int x,y[20][20]={0};
    int i,j,k,m,n;

    scanf("%d %d",&m,&n);
    for(k=0;k<m;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&x);

                if(y[i][j] < x)
                {
                    y[i][j]=x;
                }
                else
                {
                    y[i][j];
                }
            }
        }
        printf("\n");
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",y[i][j]);
        }
        printf("\n");
    }
    return 0;
}

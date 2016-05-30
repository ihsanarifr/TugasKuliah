#include<stdio.h>
#include<stdlib.h>
typedef struct pecahan {
    int pembilang;
    unsigned int penyebut;
} pecahan_t ;

int fpb(int a,int b)
{
    if(b==0) return a;
    else return fpb(b,a%b);
}

int main()
{
    pecahan_t x,y,z;
    char op;
    scanf("(%c %d/%u %d/%u)",&op,&x.pembilang,&x.penyebut,&y.pembilang,&y.penyebut);
    // rumusnya kalikan silang
    // 7/3 + 1/6
    // pembilang = 7*6 + 1*3
    // penyebut = 7*6

    if(op == '+')
    {
        // penambahan
        z.pembilang = (x.pembilang*y.penyebut) + (x.penyebut*y.pembilang);
        z.penyebut = x.penyebut*y.penyebut;
    }
    else if(op == '-')
    {
        // pengurangan
        z.pembilang = (x.pembilang*y.penyebut) - (x.penyebut*y.pembilang);
        z.penyebut = x.penyebut*y.penyebut;
    }
    else if(op == '*')
    {
        z.pembilang = x.pembilang * y.pembilang;
        z.penyebut = x.penyebut*y.penyebut;
    }
    else if(op == '/')
    {
        if(y.pembilang < 0 || y.penyebut < 0)
        {
            y.pembilang*=-1;
            y.penyebut*=-1;
        }
        z.pembilang = x.pembilang * y.penyebut;
        z.penyebut = x.penyebut * y.pembilang;
    }

    // sederhanakan
    int fpbz = fpb(abs(z.pembilang),abs(z.penyebut));
    z.pembilang /= fpbz;
    z.penyebut /= fpbz;

    printf("%d",z.pembilang);
    if(z.penyebut != 1){
        printf("/%u\n",z.penyebut);
    }
    else
    {
        printf("\n");
    }
    return 0;
}

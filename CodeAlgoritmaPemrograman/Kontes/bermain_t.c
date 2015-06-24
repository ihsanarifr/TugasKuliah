#include<stdio.h>

int main()
{
    long int ha, hb, hc, hd, he, va, vb, vc, vd, ve,total,jumlah;

    scanf("%ld %ld %ld %ld %ld",&ha,&hb,&hc,&hd,&he);
    scanf("%ld %ld %ld %ld %ld",&va,&vb,&vc,&vd,&ve);

    total =ha+hb+hc+hd+he+va+vb+vc+vd+ve;

    jumlah = 45 + va;

    //printf("%d %d",jumlah,total);
    if(hc == va)
    {
        if(total == jumlah)
        {
            printf("SESUAI\n");
            printf("%ld\n",hc);
        }
        else
        {
            printf("TIDAK SESUAI\n");
            printf("ANGKA TIDAK LENGKAP\n");
            //printf("%ld %ld",total,jumlah);
        }
    }
    else
    {
        printf("TIDAK SESUAI\n");
        printf("X TIDAK SAMA\n");
    }
    return 0;
}

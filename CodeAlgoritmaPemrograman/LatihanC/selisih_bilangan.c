#include<stdio.h>

int main()
{
    long int a,b,c,d,hasil_ab,hasil_bc,hasil_cd;
    /*
    a = 15;
    b = 10;
    c = 11;
    d = 7;
    */
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if(a > b)
    {
        hasil_ab = a-b;
    }
    else
    {
        hasil_ab = b-a;
    }

    if(b > c)
    {
        hasil_bc = b-c;
    }
    else
    {
        hasil_bc = c-b;
    }

    if(c > d)
    {
        hasil_cd = c-d;
    }
    else
    {
        hasil_cd = d-c;
    }

    if(hasil_ab > hasil_bc && hasil_ab > hasil_cd)
    {
        printf("%d\n",hasil_ab);
    }
    else if(hasil_bc > hasil_cd && hasil_bc > hasil_ab)
    {
        printf("%d\n",hasil_bc);
    }
    else if(hasil_cd > hasil_ab && hasil_cd > hasil_bc)
    {
        printf("%d\n",hasil_cd);
    }

    return 0;
}

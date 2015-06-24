#include<stdio.h>
#include<math.h>
int main()
{
    long int a1,b1,c1,d1,a2,b2,c2,d2,tampung,tampung1,tampung2;
    long int biner1,biner2,biner3,biner4,biner5,jumlah;

    scanf("%ld %ld %ld %ld",&a1,&b1,&c1,&d1);
    scanf("%ld %ld %ld %ld",&a2,&b2,&c2,&d2);

    tampung1 = (a1*pow(2,3))+(b1*pow(2,2))+(c1*pow(2,1))+(d1*pow(2,0));
    tampung2 = (a2*pow(2,3))+(b2*pow(2,2))+(c2*pow(2,1))+(d2*pow(2,0));

    tampung = tampung1 + tampung2;
    //printf("%d",tampung1+tampung2);

    biner1 = tampung%2;
    jumlah = tampung/2;

    biner2 = jumlah%2;
    jumlah = jumlah/2;

    biner3 = jumlah%2;
    jumlah = jumlah/2;

    biner4 = jumlah%2;
    jumlah = jumlah/2;

    biner5 = jumlah%2;

    printf("%d%d%d%d%d",biner5,biner4,biner3,biner2,biner1);
    /*for(b=tampung;b>0;b=hasil)
    {
         hasil = b/2;
         sisa = b%2;
         urut[nomer]=sisa;

         if(hasil == 0)
         {
              break;
         }
         else
         {
              nomer++;
         }
     }

    for(i = 0; i < 4-nomer; i++)
    {
        printf("%d", 0);
    }

    while(nomer > 4)
	{
		nomer--;
	}

     for(nomer=nomer;nomer>=0;nomer--)
    {
        printf("%ld",urut[nomer]);
    }*/
    printf("\n");

    return 0;
}

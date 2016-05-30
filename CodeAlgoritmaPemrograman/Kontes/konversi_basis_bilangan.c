#include<stdio.h>
#include<math.h>

int main()
{
    int urut[8],angka[4];
    int dari,tampung=0,nomer=0;
    int basis,a,b,sisa,hasil;

    scanf("%d %d",&dari,&basis);

    int i;
    for(i = 3; i >=0; i--)
	{
		scanf("%d", &angka[i]); //angka[3]=1 angka[2]=0 angka[1]=1 angka[0]=0
	}

	for(i = 0; i < 4; i++)
	{
		tampung += angka[i]*pow(dari, i);
	}
	/*
    tampung = (angka[3]*pow(dari,3))+(angka[2]*pow(dari,2))+(angka[1]*pow(dari,1))+(angka[0]*pow(dari,0));
    printf("%d\n",tampung);
    */

    for(b=tampung;b>0;b=hasil)
    {
         hasil = b/basis;
         sisa = b%basis;
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

    for(i = 0; i < 3-nomer; i++)
    {
        printf("%d", 0);
    }

    while(nomer > 3)
	{
		nomer--;
	}

    for(nomer=nomer;nomer>=0;nomer--)
    {
        printf("%d",urut[nomer]);
    }

    printf("\n");

     return 0;
}

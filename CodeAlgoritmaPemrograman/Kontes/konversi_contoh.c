#include<stdio.h>

int main()
{
    int urut[4];
    int basis,a,b,hasil,sisa,nomer=0;
    
    scanf("%d %d",&a,&basis);
    
    for(b=a;b>0;b=hasil)
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
           nomer+=1;
       }
    }
    
    for(nomer=nomer;nomer>=0;nomer--)
    {
       printf("%d ",urut[nomer]);
       //printf("%d",sisa);
    }
    printf("\n");
    getch();
}

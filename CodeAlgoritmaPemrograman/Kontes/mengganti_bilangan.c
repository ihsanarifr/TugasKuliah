#include<stdio.h>

int main()
{
    int bil,cek,ganti;

    scanf("%d %d",&cek,&ganti);
    scanf("%d",&bil);

    if(bil != -1)
    {
        printf("%d",bil);
    }

    do
    {
        scanf("%d",&bil);

        if(bil != -1)
        {
            if(cek != bil)
            {
                printf(" %d",bil);
            }
            else if(cek == bil)
            {
                printf(" %d",ganti);
            }
        }
    }
    while(bil!=-1);

    //printf("\n");

    return 0;
}

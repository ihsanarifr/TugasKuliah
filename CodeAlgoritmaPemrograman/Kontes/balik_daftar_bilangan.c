#include<stdio.h>
int main()
{
    int m[1001]={0};
    int i,n,input;

    scanf("%d",&input);
    for(i=0;i<input*2;i++)
        scanf("%d",&m[i]);

    int nilai,nilai2;
    nilai = input*2;
    nilai2= input*2;
    for(i=input-1;i>=0;i--)
    {
        //printf("m[%d]=%d m[%d]=%d\n",i,m[i],nilai-1,m[nilai-1]);
        if( m[i] != m[input])
        {
            //printf("m[%d]=%d m[%d]=%d\n",i,m[i],nilai-1,m[nilai-1]);
            //break;
            //printf("m[%d]=%d == m[%d]=%d Salah\n",i,m[i],input,m[input]);
            printf("%d\n",m[i]);
            break;
        }
        else
        {
            //printf("%d %d\n",input,i);
            if(i==0)
            {
                printf("0");
                //printf("m[%d]=%d == m[%d]=%d Bener\n",i,m[i],input,m[input]);
                break;
            }
        }
        input++;
    }
    return 0;
}

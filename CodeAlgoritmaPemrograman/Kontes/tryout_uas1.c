#include<stdio.h>
/*
2 5
institutpertanian

stit
*/

int main()
{
    char ch;
    int n=0;
    int awal,akhir;

    scanf("%d %d\n",&awal,&akhir);

    do{
        scanf("%c",&ch);
        if(n>= awal && n <= akhir)
            printf("%c",ch);
        n++;
    }while(ch != '\n');

    printf("\n");
    return 0;
}

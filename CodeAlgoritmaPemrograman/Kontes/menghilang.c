#include<stdio.h>

int main()
{
long int x,y;

scanf("%ld",&x);

while(y!=-1)
{
scanf("%ld",&y);
if(y!=-1)
{
if(y!=x)
{
printf("%ld_",y);
}
}
}

printf("\n");
return 0;
}

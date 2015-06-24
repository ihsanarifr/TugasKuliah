#include <stdio.h>

int main(){
int x,y,z;
scanf("%d",&x);
for (; x > 0; y =x%10, z+=y,x/=10);
printf("%d\n",z);
}

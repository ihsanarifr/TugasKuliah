#include <stdio.h>
int main() {
    char ch, c[10],b[10];
    int i;
    scanf("%c",&ch);
    for (i=0; i<10; i++)
       scanf("%c", &c[i]);

    printf("Data yang dibaca:\n");
    printf("%c", ch);
    for (i=0; i<10; i++){
        if(i!=0)
        {
            if(b[i]==c[i])
            {
                b[i]=c[i];
            }
            printf("%c", b[i]);
        }
        else
        {
            b[i]=c[i];
        }
    }
    printf("\n");

    return(0);
}

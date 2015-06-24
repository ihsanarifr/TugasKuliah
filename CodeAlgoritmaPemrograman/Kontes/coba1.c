#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
    char alay[1001],hasil[1001];

    fgets(alay,sizeof(alay),stdin);

    int i;
    int n = strlen(alay);
    for(i=0;i<n;i++)
    {
        if(isupper(alay[i]))
        {
            alay[i]=tolower(alay[i]);
            if(i!=0)
            {
                if(alay[i]==alay[i-1])
                {
                    hasil[i-1]=alay[i];
                }
                else
                {
                    hasil[i-1]=alay[i];
                }
            }
            else
            {
                hasil[i]=alay[i];
            }
        }
        printf("%c",alay[i]);
    }
    fputs(alay,stdout);

    return 0;
}

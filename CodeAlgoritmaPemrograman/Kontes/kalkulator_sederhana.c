#include<stdio.h>

int main()
{
    float a,b;
    double hasil;
    char operat;

    scanf("%f %c %f",&a,&operat,&b);

    if(operat == '+')
    {
        hasil = a + b;
        printf("%.1lf\n",hasil);
    }
    else if(operat == '-')
    {
        hasil = a - b;
        printf("%.1lf\n",hasil);
    }
    else if(operat == '*')
    {
        hasil = a * b;
        printf("%.1lf\n",hasil);
    }
    else if(operat == '/')
    {
        hasil = a / b;
        printf("%.1lf\n",hasil);
    }
    else
    {
        printf("Error\n");
    }

    return 0;
}

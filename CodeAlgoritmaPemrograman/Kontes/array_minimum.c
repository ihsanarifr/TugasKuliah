#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void array_minloc(const int *data, const int n, int *min, int *loc)
{
    int i,j,m;
    for(i=0;i<n;i++)
    {
        if(m>*data-1){
            printf("%d\n",m);
        }
        else{
            m = *data-1;
            printf("%d\n",m);
        }
        /*if(*min < *data+i)
        {
            //*min;
            //*loc = *data-1;
            //*loc = &data[i];
            //printf("%d\n",*min);
            printf("%d\n",*data+i);
        }
        else
        {
            *min = *data+i;
            //*loc = *data-1;
            //*loc = &data[i];
            //printf("%d\n",*min);
            printf("%d\n",*data+i);
        }
        printf("%d\n",*data+i);
        */
    }
}

int main()
{
    int i, n;
    int *data;
    int min, loc;

    scanf("%d", &n);

    data = malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &data[i]);

    array_minloc(data, n, &min, &loc);
    printf("minimum: %d pada indeks ke-%d\n", min, loc);
    return 0;
}

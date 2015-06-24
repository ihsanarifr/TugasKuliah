#include<stdio.h>

int main()
{
    int x1,y1,x2,y2,posisi1,posisi2;
    //int jumlah1,jumlah2,jumlah_posisi;
    int selisih1,selisih2;
    /*
    x1=4;
    y1=5;
    x2=1;
    y2=2;
    posisi1=3;
    posisi2=4;
    */

    scanf("%d %d\n%d %d\n%d %d",&x1,&y1,&x2,&y2,&posisi1,&posisi2);

    /*jumlah1 = x1+y1;
    jumlah2 = x2+y2;
    jumlah_posisi = posisi1+posisi2;
    */
    selisih1 = (x1+posisi1)-(y1+posisi2);
    selisih2 = (x2+posisi1)-(y2+posisi2);

    if(selisih1 < selisih2)
    {
        printf("1\n");
        //printf("%d %d",selisih1,selisih2);
    }
    else if(selisih1 == selisih2)
    {
        printf("12\n");
        //printf("%d %d",selisih1,selisih2);
    }
    else
    {
        printf("2\n");
        //printf("%d %d",selisih1,selisih2);
    }

    return 0;
}

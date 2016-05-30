/*
Pak Dengklek meminta Anda untuk memperhatikan contoh masukan dan keluaran yang diberikan, menemukan polanya, lalu membuat program yang menghasilkan pola tersebut. Bisakah Anda?

Format Masukan

Baris pertama berisi sebuah bilangan bulat N (0 ≤ N ≤ 10).

Format Keluaran

Pola berukuran N.

Contoh Masukan

5
Contoh Keluaran

*
**
***
****
*****
*/
#include<stdio.h>

int main()
{
	int i, j, n, k;

	scanf("%d", &n);
	for (i = 0; i<n; i++)
	{
		for (j = 1; j<n - i; j++)
		{
			printf(" ");
		}
		for (k = 0; k <= i; k++)
		{
			printf("*");
		}

		printf("\n");
	}
	return 0;
}
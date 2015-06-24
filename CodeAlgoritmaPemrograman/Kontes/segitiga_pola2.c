/*
Pak Dengklek meminta Anda untuk memperhatikan contoh masukan dan keluaran yang diberikan, menemukan polanya, lalu membuat program yang menghasilkan pola tersebut. Bisakah Anda?

Format Masukan

Baris pertama berisi sebuah bilangan bulat N (0 ≤ N ≤ 10).

Format Keluaran

Pola berukuran N.

Contoh Masukan 1

5
Contoh Keluaran 1

0
12
345
6789
01234
Contoh Masukan 2

7
Contoh Keluaran 2

0
12
345
6789
01234
567890
1234567
*/
#include<stdio.h>

int main()
{
	int i, j, n, k, z = 0, x;

	scanf("%d", &n);

	for (i = 0; i<n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d", z);
			z++;

			if (z>9)
			{
				z = 0;
			}
		}
		//i=z;
		printf("\n");
	}
	return 0;
}
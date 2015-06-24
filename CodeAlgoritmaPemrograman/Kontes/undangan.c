/*
Bapak Grader memesan surat undangan untuk pernikahan anaknya ke sebuah percetakan. Ketika surat undangan pesanannya tiba, Pak Grader baru tersadar bahwa surat undangan tersebut tidak diberi label oleh pihak percetakan. Untungnya, Pak Grader telah memiliki daftar nama dan jenis kelamin orang yang akan ia undang. Namun, Pak Grader merasa kesulitan untuk mengetikkan label untuk para undangan tersebut satu demi satu.

Tugas Anda ialah membantu Pak Grader membuat label untuk surat undangan tersebut dengan membuat sebuah program bahasa C. Program tersebut akan membaca nama dan jenis kelamin undangan dan mencetak kalimat yang akan dicetak pada label yang sesuai dengan jenis kelamin undangan.

Format Masukan

Masukan berupa N+1 baris. Baris pertama adalah sebuah bilangan bulat N (1<=N<=1000) yang merupakan jumlah nama yang akan dibaca. N baris berikutnya merupakan nama dan jenis kelamin orang yang akan dibuat surat undangannya. Nama hanya terdiri atas satu kata dengan panjang tidak melebihi 50 karakter. Jenis kelamin diwakili oleh sebuah karakter yang dapat bernilai L untuk laki-laki dan P untuk perempuan.

Format Keluaran

Keluaran berupa N baris surat undangan untuk masing-masing orang yang diundang. Akhiri baris dengan karakter newline.

Contoh Masukan

3
Algorani P
Gora L
Algo L

Contoh Keluaran

Kepada Ibu Algorani
Kepada Bapak Gora
Kepada Bapak Algo
*/
struct person{
	char nama[51];
	char jk;
};

typedef struct person person_t;
int main()
{
	person_t P[1000];
	int n, i;

	scanf("%d", &n);
	for (i = 0; i<n; i++)
		scanf("%s %c", P[i].nama, &P[i].jk);

	for (i = 0; i<n; i++){
		if (P[i].jk == 'L' || P[i].jk == 'l')
		{
			printf("Kepada Bapak %s\n", P[i].nama);
		}
		else
		{
			printf("Kepada Ibu %s\n", P[i].nama);
		}
	}
	return 0;
}

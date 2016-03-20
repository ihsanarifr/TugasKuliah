/*
Pak Algor memiliki kebiasaan tepat waktu dalam menghadiri suatu acara. Sebagai contoh, jika ada acara di hari ini pukul 19:00:00 (jam 7 malam), maka sejak pagi hari Pak Algor sudah memasang stopwatch untuk menghitung mundur berapa detik jarak antara pukul 19:00:00 dengan saat sekarang. Misalnya sekarang adalah pukul 12:00:00, maka Pak Algor akan memasang stopwatch hitung mundur dimulai dari angka 25200 karena dari pukul 12:00:00 sampai dengan pukul 19:00:00 adalah selama 25200 detik.
Untuk memudahkan, bantulah Pak Algor dengan membuat program untuk menentukan berapa nilai awal dari stopwatch untuk melakukan hitung mundur dari saat sekarang sampai waktu acara yang akan dihadiri Pak Algor.

Format Masukan
Data masukan terdiri atas dua baris dimana baris pertama menunjukkan jam sekarang, dan baris kedua adalah jam dimana acara yang akan dihadiri oleh Pak Algor. Setiap baris berisi tiga bilangan bulat, masing-masing menunjukkan nilai jam, menit, dan detik yang dipisahkan oleh satu spasi.

Format Keluaran
Output program adalah sebuah bilangan bulat yang menunjukkan lamanya (dalam detik) dari jam sekarang hingga jam acara yang akan dihadiri oleh Pak Algor.

Contoh Masukan
12 0 0
19 0 0

Contoh Keluaran
25200
*/
#include<stdio.h>

int main()
{
    int jam_sekarang,menit_sekarang,detik_sekarang,jam_acara,menit_acara,detik_acara;
    long int total,hasil_sekarang,hasil_acara;

    scanf("%d %d %d",&jam_sekarang,&menit_sekarang,&detik_sekarang);
    scanf("%d %d %d",&jam_acara,&menit_acara,&detik_acara);

    //hasil_sekarang = (jam_sekarang * 3600)+(menit_sekarang * 60) + detik_sekarang;
    //hasil_acara = (jam_acara * 3600) + (menit_acara * 60) + detik_acara;

    total = (jam_acara-jam_sekarang)*3600+(menit_acara-menit_sekarang)*60+(detik_acara-detik_sekarang);

    //total = hasil_acara - hasil_sekarang;

    printf("%ld",total);

    return 0;
}

/*
Pak Agri memiliki lahan sawah yang sangat luas, yang seluruhnya ditanami dengan padi. Pak Agri sangat tertib dan rapih sehingga setiap tanaman padinya memiliki jarak tanam yang sama sehingga membentuk grid seperti sebuah matriks. Ujung kiri atas diberi nomor koordinat (1,1), dan ujung paling kanan bawah tanaman padi diberi nomor koordinat (m,n). Karena luasnya lahan yang dimiliki Pak Agri sehingga nilai m bisa mencapai 1000 dan nilai n mencapai 10000. Dengan demikian, matriks tanaman padi Pak Agri berukuran 1000x10000.

Sebagai seorang petani modern yang sering melakukan penelitian, Pak Agri ingin tahu berapa tinggi tanamannya. Untuk itu, Pak Agri hanya mengukur tinggi beberapa tanaman dimulai dari koordinat (a,b) sampai dengan koordinat (c,d), kemudian merata-ratakannya.

Buat program untuk menghitung rata-rata tinggi tanaman yang diperoleh.

Format Masukan

Baris pertama berisi dua bilangan m (1<m<1000) dan n (1<n<10000) yang menunjukkan ukuran maksimum koordinat tanaman padi (ukuran matrik). Baris-baris berikutnya adalah n bilangan yang menunjukkan tinggi tanaman (bilangan bulat), yang masing-masing dipisahkan oleh satu spasi. Dua baris terakhir adalah koordinat awal dan akhir dari pengukuran tinggi tanaman yang dilakukan.

Format Keluaran

Banyaknya tanaman yang diukur (bilangan bulat), dan sebuah bilangan riil (4 digit di belakang tanda desimal) yang menunjukkan rata-rata tinggi tanaman yang diukur. Output ditulis dalam satu baris, dipisahkan oleh satu spasi, dan diakhiri dengan newline.

Contoh Masukan

5 6
1 2 3 4 5 6
7 8 9 1 2 3
4 5 6 7 8 9
1 2 3 4 5 6
5 6 7 8 9 1
1 1
3 6
Contoh Keluaran

18 5.0000
*/
#include<iostream>

using namespace std;

#define N 10000
#define M 1000

//class myPlant
//{
//private:
//    int a[M][N];
//
//public:
//    void ambil()
//    {
//        int n,m;
//        cin >> m >> n;
//        for(int i=0;i<m;i++)
//        {
//            for(int j=0;j<n;j++)
//            {
//                cin >> a[i][j];
//            }
//        }
//    }
//
//    void print()
//    {
//        int n,m;
//        for(int i=0;i<m;i++)
//        {
//            for(int j=0;j<n;j++)
//            {
//                cout << a[i][j];
//                if (j == n - 1)
//                    cout << endl;
//                else
//                    cout << " ";
//            }
//        }
//    }
//};

int main()
{
//    myPlant p;
//    p.ambil();
//    //p.print();
    int n,m;
    int a[1000][10001]={0};

        cin >> m >> n;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >> a[i][j];
            }
        }
    return 0;
}

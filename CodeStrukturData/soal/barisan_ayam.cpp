/*
Buat ADT DLL untuk dapat menjawab persoalan berikut:

Diketahui n ayam berdiri dalam satu baris dari Utara ke Selatan. Setiap ayam dicatat tinggi badannya. Selanjutnya datang m ayam baru yang berjalan beriringan dari Utara ke Selatan yang ingin ikut dalam barisan. Ternyata ada aturan, bahwa setiap ayam yang baru datang akan menempati sebelum ayam dalam barisan yang pertama kali lebih tinggi darinya. Jika tidak ada yang lebih tinggi darinya, maka ayam tersebut menempati posisi paling belakang dalam barisan. Tuliskan susunan akhir dari barisan ayam tersebut.

Format Masukan

Baris pertama adalah sebuah bilangan bulat n (tidak lebih dari 10000), dan diikuti dengan n bilangan float yang menyatakan tinggi setiap ayam yang sedang berbaris. Baris kedua adalah sebuah bilangan bulat m (tidak lebih dari 10000), dan diikuti dengan m bilangan float yang menyatakan tinggi setiap ayam yang baru datang.

Format Keluaran

Output berupa deretan bilangan yang merupakan tinggi setiap ayam yang berbaris sesuai ketentuan dalam deskripsi soal, yang ditulis dalam satu digit di belakang desimal. Output diakhiri dengan teks "NULL" dan newline.

Contoh Masukan

5 10 40 15 20 35    (n=5)
3 30 50 7           (m=3)
Contoh Keluaran

7.0->10.0->30.0->40.0->15.0->20.0->35.0->50.0->NULL

*/
#include<iostream>
#include<iomanip>
#include<list>

using namespace std;

typedef list<double> data;
class DLL{
    data dt;
public:
    void push_back(double val);
    void insert(double val);
    void print();
};

void DLL::push_back(double val){
    dt.push_back(val);
}
void DLL::insert(double val){
    data::iterator it=dt.begin();

    while(*it<val && it!=dt.end())
        ++it;
    if(it!=dt.end())
        dt.insert(it,val);
    else
        dt.push_back(val);
}

void DLL::print(){
    data::iterator it=dt.begin();
    for(;it!=dt.end();++it)
        cout << fixed << setprecision(1) << (*it) << "->";
    cout << "NULL\n";
}
int main(){
    DLL list;
    int n;
    double tinggi;

    cin >> n;
    while(n--){
        cin >> tinggi;
        list.push_back(tinggi);
    }

    cin >> n;
    while(n--){
        cin >> tinggi;
        list.insert(tinggi);
    }
    list.print();
    return 0;
}

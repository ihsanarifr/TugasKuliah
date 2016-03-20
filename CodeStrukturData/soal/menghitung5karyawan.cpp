#include<iostream>

using namespace std;
class Karyawan
{
private:
    string nama[100];
    int jamKerja[100];
    int pendapatan[100];
    int n;
    int hasil[100];

public:
    void SetKaryawan()
    {
        int jam,pend;
        string x;

        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >> x >> jam >> pend;
            nama[i]=x;
            jamKerja[i]=jam;
            pendapatan[i]=pend;
        }
    }
    void TampilKaryawan()
    {
        for(int i=0;i<n;i++)
        {
            hasil[i]=jamKerja[i]*pendapatan[i];
            cout << nama[i] << " " << hasil[i] << endl;
        }
    }
};

int main()
{
    Karyawan k;

    k.SetKaryawan();
    k.TampilKaryawan();
    return 0;

}

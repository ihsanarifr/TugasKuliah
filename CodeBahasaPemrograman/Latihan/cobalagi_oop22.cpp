#include<iostream>
#include<iomanip>

using namespace std;

class Hitung
{
private:
    int n;
    double a,b;
    double jumlah1,jumlah2;
    double hasil1,hasil2;

public:
    Hitung()
    {
        n=0;
        a=0.0;
        b=0.0;
        hasil1=0.0;
        hasil2=0.0;
    }
    void SetMasukan()
    {
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >> a >> b;
            jumlah(a,b);
            //rataan(a,b);
        }
    }
    void jumlah(double a,double b)
    {
        jumlah1 = jumlah1+a;
        jumlah2 = jumlah2+b;
    }

    double getJumlah1()
    {
        return jumlah1;
    }
    double getJumlah2()
    {
        return jumlah2;
    }
    void rataan()
    {
        hasil1 = jumlah1/double(n);
        hasil2 = jumlah2/double(n);
    }

    double getRataan1()
    {
        return hasil1;
    }
    double getRataan2()
    {
        return hasil2;
    }

    void print()
    {
        cout << fixed << setprecision(2) << getRataan1() << " " << setprecision(2) << getRataan2() << endl;
    }
};
int main()
{
    Hitung coba;
    coba.SetMasukan();
    coba.rataan();
    cout << fixed << setprecision(2) << coba.getRataan1() << " " << setprecision(2) << coba.getRataan2();
    //coba.print();

    return 0;
}

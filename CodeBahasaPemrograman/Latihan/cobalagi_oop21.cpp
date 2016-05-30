#include<iostream>
#include<iomanip>

using namespace std;

class hitung
{
private:
    double a;
    double b;
    double hasil;
public:
    hitung()
    {
        a = 0.0;
        b = 0.0;
        hasil = 0.0;
    }
    void setHitung(double ax,double bx)
    {
        a = ax;
        b = bx;
    }

    double perhitungan()
    {
        hasil = a + b;
        return hasil;
    }

    void print()
    {
        cout << fixed << setprecision(2) << hasil << endl;
    }
};

int main()
{
    hitung coba;
    double isia,isib;

    cin >> isia >> isib;
    coba.setHitung(isia,isib);
    coba.perhitungan();
    coba.print();

    return 0;
}

#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

class vektor
{
public:
    vector<int> v;
    int a,jumlah,rata,
    hapus;
    int CountOrigin,CountModified;
    double AvgOrigin, AvgModified;


    vektor()
    {
        jumlah = 0;
        rata = 0;
        CountOrigin = 0.0;
        CountModified = 0.0;
        AvgOrigin = 0.0;
        AvgModified = 0,0;
    }

    void masukkan()
    {
        cin >> a;
        while(a != -9)
        {
            v.push_back(a);
            cin >> a;
        }
    }
    double Rataan()
    {
        jumlah=0;
        for(int i=0;i<v.size();i++)
        {
            jumlah += v[i];
        }
        return double(jumlah) / double(v.size());
    }
    int jumlahan()
    {
        jumlah=0;
        for(int i=0;i<v.size();i++)
        {
            jumlah += v[i];
        }
        return jumlah;
    }

    void hilang()
    {
        cin >> hapus;
        int i=0;
        do{
            if(hapus == 1){
                v.erase(v.begin());
                cin >> hapus;
                i++;
            }else{
                v.erase(v.begin()+hapus-i-1);
                cin >> hapus;
                i++;
            }
        }
        while(hapus != -9);
    }

    void print()
    {
        CountOrigin = v.size();
        int jumlahorigin = jumlahan();
        AvgOrigin = Rataan();

        hilang();

        CountModified = v.size();
        int jumlahmodified = jumlahan();
        AvgModified = Rataan();

        cout << CountOrigin << " " << CountModified << endl;
        cout << jumlahorigin << " " << jumlahmodified << endl;
        cout << fixed << setprecision(2) << AvgOrigin << " " << setprecision(2) << AvgModified << endl;
    }
};
int main()
{
    vektor p;
    p.masukkan();
    p.print();

    //for(int i=0;i<p.v.size();i++)
    //{
    //    cout << p.v[i];
    //}
}

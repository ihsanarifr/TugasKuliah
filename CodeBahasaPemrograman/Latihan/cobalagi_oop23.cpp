#include<iostream>
#include<iomanip>
#include<list>

using namespace std;

class Person
{
private:
    list<Person> p;
    string nama;
    int usia,tinggi,n;
    double berat;

public:
    Person(){ nama=""; usia=0; tinggi=0; berat=0.0;}
    void setPerson(string n, int u, int t,int b)
    {
        nama=n;
        usia=u;
        tinggi=t;
        berat=b;
    }
    string getNama()
    {
        return nama;
    }
    int getUsia()
    {
        return usia;
    }
    int getTinggi()
    {
        return tinggi;
    }
};

class Orang
{
private:
    list<Person> p;
    Person jelema;
    int n,usia,tinggi;
    string nama;
    double berat;
    double rata,jumlah=0.0;
    int countTinggi;
public:
    Orang()
    {
        n=0;
        usia=0;
        tinggi=0;
        nama="";
        berat=0.0;
        rata=0.0;
        jumlah=0.0;
        countTinggi=0;
    }
    void masukkanOrang()
    {
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >> nama >> usia >> tinggi >> berat;
            jelema.setPerson(nama,usia,tinggi,berat);
            p.push_back(jelema);
        }
    }

    double rataan()
    {
        list<Person>::iterator it;
        for(it=p.begin();it!=p.end();++it)
        {
            jumlah= jumlah+jelema.getTinggi();
        }
        return jumlah/double(p.size());
    }
    int countT()
    {
        list<Person>::iterator it;
        for(it=p.begin();it!=p.end();++it)
        {
            if((*it).getTinggi() > rataan())
            {
                countTinggi++;
            }
        }
        return countTinggi;
    }
    void cetak()
    {
        list<Person>::iterator it;
        for(it=p.begin();it!=p.end();++it){
            cout << (*it).getNama() << " " <<(*it).getUsia() << endl;
            //jti = jti + (*it).getTinggi();
        }
        cout << fixed << setprecision(2) << rataan() << " " << p.size() << endl;
        cout << countT() << endl;
    }
};
int main()
{
    Orang teman;

    teman.masukkanOrang();
    teman.cetak();
}

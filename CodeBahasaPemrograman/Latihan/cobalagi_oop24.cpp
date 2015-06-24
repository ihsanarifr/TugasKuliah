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
    double imt;
    string status;

public:
    Person(){ nama=""; usia=0; tinggi=0; berat=0.0;}
    void setPerson(string n, int u, int t,int b)
    {
        nama=n;
        usia=u;
        tinggi=t;
        berat=b;
        imt=IMT();
        status=StatusGizi();
    }
    double IMT()
    {
        double t=(double)tinggi/100.0;
        return (berat/(t*t));
    }

    string StatusGizi()
    {
        if(imt<17.0)
        {
            status = "sangat kurus";
        }
        else if(imt <18.5)
        {
            status = "kurus";
        }
        else if(imt < 25.0)
        {
            status = "normal";
        }
        else if(imt < 28.0)
        {
            status = "gemuk";
        }
        else
        {
            status = "sangat gemuk";
        }
        return status;
    }
    double getBerat()
    {
        return berat;
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
    double getIMT()
    {
        return imt;
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
    int hitung[5];
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
//        hitung[]={0};
        hitungT();
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

    void hitungT()
    {
        hitung[0]=0;
        hitung[1]=0;
        hitung[2]=0;
        hitung[3]=0;
        hitung[4]=0;
        list<Person>::iterator it;
        for(it=p.begin();it!=p.end();++it)
        {
            if((*it).StatusGizi() == "sangat kurus")
            {
                hitung[0]++;
            }
            else if((*it).StatusGizi() == "kurus")
            {
                hitung[1]++;
            }
            else if((*it).StatusGizi() == "normal")
            {
                hitung[2]++;
            }
            else if((*it).StatusGizi() == "gemuk")
            {
                hitung[3]++;
            }
            else
            {
                hitung[4]++;
            }
        }
    }

    void cetak()
    {
        list<Person>::iterator it;
        for(it=p.begin();it!=p.end();++it){
            cout << (*it).getNama() << " " << (*it).getUsia() << " "
                << (*it).getTinggi() << " " << (*it).getBerat() << " "
                << (*it).getIMT() << " " << (*it).StatusGizi() << endl;
            //jti = jti + (*it).getTinggi();
        }
        cout << fixed << setprecision(2) << rataan() << " " << p.size() << endl;
        cout << countT() << endl;
        cout << hitung[0] << " " << hitung[1] << " " << hitung[2] << " " << hitung[3] << " " << hitung[4] << endl;
    }
};
int main()
{
    Orang teman;

    teman.masukkanOrang();
    teman.cetak();
}

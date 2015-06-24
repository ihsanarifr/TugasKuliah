#include<ios>
#include<iostream>
#include<iomanip>
#include<list>

using namespace std;
class Person {
   private:
      string nama;
      int usia;
      int tinggi;
      double berat;
      double imt;
      string status;
      double IMT() { double t=(double)tinggi/100.0; return (berat/(t*t)); }
      string StatusGizi() {
         double t=IMT();
         if (t<17.0) return "sangat kurus";
         else if (t<18.5) return "kurus";
         else if (t<25.0) return "normal";
         else if (t<28.0) return "gemuk";
         else return "sangat gemuk"; }
   public:
      Person() { nama=""; usia=tinggi=0; berat=0.0; }
      void setPerson(string nm, int u, int t, double b) {
         nama=nm; usia=u; tinggi=t; berat=b;
         imt=IMT(); status=StatusGizi();
      }
      string getNama() { return nama; }
      int getUsia() { return usia; }
      int getTinggi() { return tinggi; }
      double getBerat() { return berat; }
      double getIMT() { return imt; }
      string getStatusGizi() { return status; }
      void cetak() {
         cout << nama << " " << usia << " " << tinggi << " ";
         cout << fixed << setprecision(2) << berat << " " << imt << " " << status << endl;
      }
};

class Orang
{
private:
    list<Person> p;
    Person ord;
    int n,m,usia,tinggi;
    string nama;
    double berat;
public:
    void masukkan()
    {
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >> nama >> usia >> tinggi >> berat;
            ord.setPerson(nama,usia,tinggi,berat);
            p.push_back(ord);
        }
    }
    void pilihan()
    {
        int pilih;
        cin >> pilih;
        do{
            switch(pilih)
            {
                case 1:
                    //simpan diawal
                    cin >> nama >> usia >> tinggi >> berat;
                    ord.setPerson(nama,usia,tinggi,berat);
                    p.push_front(ord);
                    cin >> pilih;
                    break;
                case 2:
                    //tambah objek di p
                    cin >> nama >> usia >> tinggi >> berat;
                    ord.setPerson(nama,usia,tinggi,berat);
                    p.push_back(ord);
                    cin >> pilih;
                    break;
                case 3:
                    //hapus paling depan
                    p.pop_front();
                    cin >> pilih;
                    break;
                case 4:
                    //hapus paling belakang
                    p.pop_back();
                    cin >> pilih;
                    break;
                case 5:
                    //sisip objek setelah ke n
                    cin >> m >> nama >> usia >> tinggi >> berat;
                    ord.setPerson(nama,usia,tinggi,berat);

                    list<Person>::iterator it;
                    it = p.begin();
                    if(m == 1)
                    {
                        p.push_front(ord);
                    }
                    else
                    {
                        int k=0;
                        while(k!=m){
                            it++;
                            k++;
                        }
                        p.insert(it,ord);
                    }
                    cin >> pilih;
                    break;
            }
        }
        while(pilih != -9);
    }

    void cetak()
    {
        list<Person>::iterator it;
        for(it=p.begin();it!=p.end();++it)
        {
            (*it).cetak();
        }
    }
};

int main(){
    Orang jelema;

    jelema.masukkan();
    jelema.pilihan();
    jelema.cetak();
}

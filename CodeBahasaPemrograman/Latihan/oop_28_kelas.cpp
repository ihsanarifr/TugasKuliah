#include<ios>
#include<iostream>
#include<iomanip>
#include<map>

using namespace std;

class Person {
   private:

   public:
      string nama;
      int usia;
      int tinggi;
      double berat;
      double imt;
      double IMT() { double t=(double)tinggi/100.0; return (berat/(t*t)); }

      Person() { nama=""; usia=tinggi=0; berat=0.0;}
      void setPerson(string nm, int u, int t, double b) {
         nama=nm; usia=u; tinggi=t; berat=b;
         imt=IMT();
      }
      string getNama() { return nama; }
      int getUsia() { return usia; }
      int getTinggi() { return tinggi; }
      double getBerat() { return berat; }
      double getIMT() { return imt; }
      void cetak() {
         cout << nama << " " << usia << " " << tinggi << " ";
         cout << berat << " ";
         cout << fixed << setprecision(2) << imt << endl;
      }
      void cetak2() {
         cout << nama << " " << usia << " " << tinggi << " "
              << fixed << setprecision(6) << berat << " "
              << fixed << setprecision(2) << imt << endl;
      }
};
int main(){
    int n,m,i,usia,tinggi;
    string nim, nama;
    double berat;
    Person orang;
    map<string, Person> Mhs;
    //list<Person> s;

    cin >> n;
    for(i=0;i<n;i++){
        cin >> nim >> nama >> usia >> tinggi >> berat;
        orang.setPerson(nama,usia,tinggi,berat);
        Mhs[nim] = orang;
    }

    cin >> m;
    for(i=0;i<m;i++){
        string nim_yang_dicari;
        cin >> nim_yang_dicari;

        if(Mhs.count(nim_yang_dicari)==0){
            cout << "Data " << nim_yang_dicari << " tidak ada" << endl;
        }else{
            /*if(i == 0){
                Mhs[nim_yang_dicari].cetak2();
            }else{
                Mhs[nim_yang_dicari].cetak();
            }*/
            cout << fixed
                 << Mhs[nim_yang_dicari].nama << " "
                 << Mhs[nim_yang_dicari].usia << " "
                 << Mhs[nim_yang_dicari].tinggi << " "
                 << Mhs[nim_yang_dicari].berat << " "
                 << setprecision(2)
                 << Mhs[nim_yang_dicari].imt << endl;
        }
    }
    return 0;
}

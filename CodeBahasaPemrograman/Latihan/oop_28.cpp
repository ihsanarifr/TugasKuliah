#include<ios>
#include<iostream>
#include<iomanip>
#include<map>
#include<list>

using namespace std;

class Person {
   private:
      string nama,nim;
      int usia;
      int tinggi;
      double berat;
      double imt;
      double IMT() { double t=(double)tinggi/100.0; return (berat/(t*t)); }
   public:
      Person() { nama=""; usia=tinggi=0; berat=0.0;nim=""; }
      void setPerson(string nm, int u, int t, double b) {
         nama=nm; usia=u; tinggi=t; berat=b;
         imt=IMT();
      }
      void setNIM(string n) { nim=n; }
      string getNIM() {return nim;}
      string getNama() { return nama; }
      int getUsia() { return usia; }
      int getTinggi() { return tinggi; }
      double getBerat() { return berat; }
      double getIMT() { return imt; }
      void cetak() {
         cout << nama << " " << usia << " " << tinggi << " ";
         cout << fixed << setprecision(2) << berat << " " << imt << endl;
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
    //string cadang[m];
    for(i=0;i<m;i++){
        string nim_yang_dicari;
        cin >> nim_yang_dicari;

        if(Mhs.count(nim_yang_dicari)==0){
            cout << "Data " << nim_yang_dicari << " tidak ada" << endl;
        }else{
            Mhs[nim_yang_dicari].cetak();
        }
        //orang.setNIM(nim);
        //s.push_back(orang);
        //cadang[i]=nim;
    }

    //list<Person>::iterator it;
    /*map<string,Person>::iterator itm,itmm;
    for(i=0;i<m;i++){
        if(Mhs.find(cadang[i])== Mhs.end()){
            cout << "Data " << cadang[i] << " tidak ada" << endl;
        }else{
            Mhs[cadang[i]].cetak();
        }
    }
    */
    /*for(it=s.begin();it!=s.end();++it){

        if(Mhs.find((*it).getNIM()) == Mhs.end()){
            cout << "Data " << (*it).getNIM() << " tidak ada" << endl;
        }else{
            Mhs[(*it).getNIM()].cetak();
        }
        //cout << Mhs.find((*it).getNIM())->second << endl;
        //cout << (*it).getNIM() << endl;
    }
    */
    //cout << Mhs.find("G64144025")->second << endl;

    //map<string, Person>::iterator it;
    //for(it=Mhs.begin();it!=Mhs.end();++it){
    //    (*it).second.cetak();
    //}
    return 0;
}

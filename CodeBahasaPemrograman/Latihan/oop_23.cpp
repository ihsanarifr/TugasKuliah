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
      double rataan;
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
      int setBerat(){ return berat; }
      int getUsia() { return usia; }
      int getTinggi() { return tinggi; }
      double getBerat() { return berat; }
      double getIMT() { return imt; }
      string getStatusGizi() { return status; }

      void cetak() {
         cout << nama << " " << usia << " " << tinggi << " ";
         cout << fixed << setprecision(2) << berat << " " << imt << " " << status << endl;
      }
      void cetak2(){
          cout << nama << " " << usia << endl;
      }
};

int main(){
    list<Person> p;
    Person orang;
    /*orang.setPerson("sule",35,168,59.4);
    p.push_back(orang);
    orang.setPerson("ihsan",50,165,54.4);
    p.push_back(orang);
    orang.setPerson("wakwaw",50,166,53.2);

    p.insert(++p.begin(),orang);
    list<Person>::iterator it;
    for(it=p.begin();it!=p.end();++it){
            (*it).cetak();
    }
    */
    int iterasi,i;
    string na;
    int us,ti,banyak=0;
    double jti=0.0, be,rataan=0;
    cin >> iterasi;
    for(i=0;i<iterasi;i++){
        cin >> na >> us >> ti >> be;
        orang.setPerson(na,us,ti,be);
        p.push_back(orang);
    }
    list<Person>::iterator it;
    for(it=p.begin();it!=p.end();++it){
            (*it).cetak2();
            jti = jti + (*it).getTinggi();
    }
    rataan = jti/double(iterasi);
    cout << fixed << setprecision(2) << rataan << endl;

    for(it=p.begin();it!=p.end();++it){
            //(*it).cetak2();
            if((*it).getTinggi() > rataan){
                //cout << (*it).getTinggi();
                banyak++;
            }
    }
    cout << banyak << endl;
    return 0;
}

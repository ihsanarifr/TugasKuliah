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

      string StatusGizi() {
         double t=IMT();
         if (t<17.0) return "sangat kurus";
         else if (t<18.5) return "kurus";
         else if (t<25.0) return "normal";
         else if (t<28.0) return "gemuk";
         else return "sangat gemuk"; }

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
    int iterasi,i;
    int status[5] = {0};
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
            (*it).cetak();
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
            if((*it).StatusGizi() == "sangat kurus"){
                status[0]++;
            }else if((*it).StatusGizi() == "kurus"){
                status[1]++;
            }else if((*it).StatusGizi() == "normal"){
                status[2]++;
            }else if((*it).StatusGizi() == "gemuk"){
                status[3]++;
            }else if((*it).StatusGizi() == "sangat gemuk"){
                status[4]++;
            }
    }
    cout << banyak << endl;
    cout << status[0] << " " << status[1] << " " << status[2] << " " << status[3] << " " << status[4] << endl;
    return 0;
}

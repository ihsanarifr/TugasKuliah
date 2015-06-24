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

int main(){
    list<Person> p;
    Person orang;
    int t,iterasi,i,n,m;
    string na;
    int us,ti;
    double be;

    cin >> iterasi;
    for(i=0;i<iterasi;i++){
        cin >> na >> us >> ti >> be;
        orang.setPerson(na,us,ti,be);
        p.push_back(orang);
    }
    /*
    list<Person>::iterator it;
    for(it=p.begin();it!=p.end();++it){
        (*it).cetak();
    }
    */
    list<Person>::iterator it;

    cin >> t;
    do{
        /*if(t == 1){
            cout << "satu";
        }else if(t == 2){
            cout << "dua";
        }else if(t == 3){
            cout << "tiga";
        }else if(t == 4){
            cout << "empat";
        }else if(t == 5){
            cout << "lima";
        }
        */
        switch(t){
        case 1:
            cin >> na >> us >> ti >> be;
            orang.setPerson(na,us,ti,be);
            p.push_front(orang);

            cin >> t;
            break;
        case 2:
            cin >> na >> us >> ti >> be;
            orang.setPerson(na,us,ti,be);
            p.push_back(orang);

            cin >> t;
            break;
        case 3:
            p.pop_front();

            cin >> t;
            break;
        case 4:
            p.pop_back();

            cin >> t;
            break;
        case 5:
            cin >> m >> na >> us >> ti >> be;
            orang.setPerson(na,us,ti,be);

            it = p.begin();
            if(m == 1){
                p.push_front(orang);
            }else{
                int k=0;
                while(k!=m){
                    it++;
                    k++;
                }
                //for(int k=0;k < na;k++){
                //    it++;
                //}
                p.insert(it,orang);
            }

            cin >> t;
            break;
        }
    }while(t!=-9);


    for(it=p.begin();it!=p.end();++it){
        (*it).cetak();
    }
}

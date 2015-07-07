#include <iostream>
#include <list>

using namespace std;

struct tanaman{
    string nama;
    list<double> tinggi;
};
typedef struct tanaman plant;

class Oryza{
    list<plant> pt;
public:
    int isEmpty(){ pt.empty();}
    void push_back(plant val) { pt.push_back(val);}
//    LI::iterator find(int val);
    void print();
};

void Oryza::print(){
    plant p;
    list<plant>::iterator it=pt.begin();
    list<double>::iterator itt=p.tinggi.begin();
    for(;it!=pt.end();++it){
        cout << it->nama << " ";
        for(;itt!=p.tinggi.end();++itt){
            cout << *itt << " ";
        }
        cout << endl;
    }
}

int main(){
    Oryza jagung;
    int n,m;
    float t;
    string nama;
    plant data;

    cin >> n;
    while(n--){
        cin >> nama >> m;
        data.nama=nama;
        while(m--){
            cin >> t;
            data.tinggi.push_back(t);
        }
        jagung.push_back(data);
    }

    jagung.print();
    return 0;
}

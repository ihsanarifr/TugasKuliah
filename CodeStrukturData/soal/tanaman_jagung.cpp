#include <iostream>
#include <list>
#include <iomanip>
#include <string>

using namespace std;

struct tanaman{
    string nama;
    list<double> tinggi;
    double rata;
};
typedef struct tanaman plant;

class Zeamays{
    list<plant> pt;
public:
    int isEmpty(){ pt.empty();}
    void push(plant val);
    void print();
    friend bool operator<(const plant& a,const plant& b){ return a.nama<b.nama;};
    void sort(string so);
    bool cmpTinggi(plant& a,plant& b);
};

void Zeamays::sort(string so){
    if(so == "URUTRATA"){
        //cout << "urut rata" << endl;
        pt.sort();
    }else{
        //cout << "urut kode";
        pt.sort();
    }
}

bool Zeamays::cmpTinggi(plant& a,plant& b){
    return(a.nama>b.nama);
}

void Zeamays::push(plant val/*,string so*/){
    pt.push_back(val);
    //sort(string so);
}

void Zeamays::print(){
	plant p;
	list<plant>::iterator it = pt.begin();

	for (; it != pt.end(); ++it){
		cout << it->nama << " ";
		//???? // maybe it->
		list<double>::iterator itt =it->tinggi.begin();
		for (; itt != it->tinggi.end(); ++itt)
			cout << (*itt) << "->";
		cout << "NULL" << endl;
		//cout << fixed << setprecision(2) << it->rata << endl;
	}
}
int main(){
    Zeamays jagung;
    int n,m;
    double t;
    string nama,urut;
    plant data;

    cin >> n;
    while(n--){
        double r=0;
        cin >> nama >> m;
        data.nama=nama;
        while(m--){
            cin >> t;
            data.tinggi.push_back(t);
            //data.tinggi.sort();
            r+=t;
        }
        data.rata = double(r/data.tinggi.size());
        jagung.push(data);
        data.tinggi.clear();
    }

    cin >> urut;
    jagung.sort(urut);

    jagung.print();
    return 0;
}

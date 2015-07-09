//#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <list>
using namespace std;

class Oryza{
public:
    Oryza() { nama="";rata=0.0;}

    void push_tinggi(double tg){ tinggi.push_back(tg);}
    void setrata(double rt){ rata=rt; }
    void setnama(double nm){ nama=nm; }
    void clear(){ tinggi.clear();}
    int getSizeTinggi() { return tinggi.size();}

    string nama;
    list<double> tinggi;
    double rata;
};

bool sortNama(const Oryza& a, const Oryza& b){
    return a.nama<b.nama;
}
bool sortRata(const Oryza& a, const Oryza& b){
    return a.rata<b.rata;
}
/*
inline bool operator<(const Oryza& a, const Oryza& b)
{
	return a.rata < b.rata;
}
*/


int main()
{
    Oryza jg;
	list<Oryza> jagung;
	int n,m;
    double t;
    string nama,urut;

    cin >> n;
    while(n--){
        double r=0;
        cin >> nama >> m;
        while(m--){
            cin >> t;
            jg.push_tinggi(t);
            r+=t;
        }
        jg.rata = double(r/jg.getSizeTinggi());
        jg.nama = nama;
        jagung.push_back(jg);
        jg.clear();
    }

    cin >> urut;
	if(urut == "URUTRATA")
        jagung.sort(sortRata);
    else
        jagung.sort(sortNama);

	list<Oryza>::iterator it=jagung.begin();
	for(;it!=jagung.end();++it){
		cout << (*it).nama <<" : ";
		list<double>::iterator itt=(*it).tinggi.begin();
        for(;itt!=(*it).tinggi.end();++itt)
            cout << *itt << "->";
        cout << "NULL" << endl;
        //cout << fixed << setprecision(2) << (*it).rata << endl;
	}

	return 0;
}

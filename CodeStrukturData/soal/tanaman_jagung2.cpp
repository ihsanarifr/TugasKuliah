#include <iostream>
#include <iomanip>
#include <string>
#include <list>
using namespace std;

class Zeamays{
public:
    Zeamays() { nama="";rata=0.0;}

    void push_tinggi(float tg){ tinggi.push_back(tg);}
    void clear(){ tinggi.clear();}
    int getSizeTinggi() { return tinggi.size();}

    string nama;
    list<float> tinggi;
    float rata;
};

bool sortNama(const Zeamays& a, const Zeamays& b){
    return a.nama<b.nama;
}
bool sortRata(const Zeamays& a, const Zeamays& b){
    return a.rata<b.rata;
}

int main()
{
    Zeamays jg;
	list<Zeamays> jagung;
	int n,m;
    float t;
    string nama,urut;

    cin >> n;
    while(n--){
        float r=0;
        cin >> nama >> m;
        while(m--){
            cin >> t;
            jg.push_tinggi(t);
            r+=t;
        }
        jg.rata = float(r/jg.getSizeTinggi());
        jg.nama = nama;
        jagung.push_back(jg);
        jg.clear();
    }

    cin >> urut;
	if(urut == "URUTRATA")
        jagung.sort(sortRata);
    else
        jagung.sort(sortNama);

	list<Zeamays>::iterator it=jagung.begin();
	for(;it!=jagung.end();++it){
		cout << (*it).nama <<" : ";
		list<float>::iterator itt=(*it).tinggi.begin();
        for(;itt!=(*it).tinggi.end();++itt)
            cout << *itt << "->";
        cout << "NULL" << endl;
        //cout << fixed << setprecision(2) << (*it).rata << endl;
	}

	return 0;
}

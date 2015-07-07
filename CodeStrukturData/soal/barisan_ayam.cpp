#include<iostream>
#include<iomanip>
#include<list>

using namespace std;

typedef list<double> data;
class DLL{
    data dt;
public:
    void push_back(double val);
    void insert(double val);
    void print();
};

void DLL::push_back(double val){
    dt.push_back(val);
}
void DLL::insert(double val){
    data::iterator it=dt.begin();

    while(*it<val && it!=dt.end())
        ++it;
    if(it!=dt.end())
        dt.insert(it,val);
    else
        dt.push_back(val);
}

void DLL::print(){
    data::iterator it=dt.begin();
    for(;it!=dt.end();++it)
        cout << (*it) << "->";
    cout << "NULL\n";
}
int main(){
    DLL list;
    int n;
    double tinggi;

    cin >> n;
    while(n--){
        cin >> tinggi;
        list.push_back(tinggi);
    }

    cin >> n;
    while(n--){
        cin >> tinggi;
        list.insert(tinggi);
    }
    list.print();
    return 0;
}

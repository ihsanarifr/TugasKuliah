#include <iostream>
#include <iomanip>
#include <list>
using namespace std;

struct my{
    string warna;
    int tinggi;
};
typedef struct my myData;

class DLL{
    list<myData> dt;
public:
    void push(string w, int t);
    void print();
};

void DLL::push(string w,int t){
    myData temp;
    temp.warna=w;temp.tinggi=t;

    if(dt.empty())
        dt.push_back(temp);
    else{
        list<myData>::iterator it=dt.begin();
        for(;it!=dt.end();++it)
            if(it->warna==w) break;
        for(;it!=dt.end() && it->warna==w;++it);
            if(it==dt.end()){
                dt.push_back(temp);
            }else{
                dt.insert(it,temp);
            }
    }
}

void DLL::print(){
    list<myData>::iterator it=dt.begin();
    for(;it!=dt.end();++it)
        cout << it->warna<<":"<<it->tinggi<<"->";
    cout << "NULL" << endl;
}
int main(){
    int n;
    string warna;
    int tinggi;
    DLL list;

    cin >> n;
    while(n--){
        cin >> warna >> tinggi;
        list.push(warna,tinggi);
    }
    list.print();
    return 0;
}

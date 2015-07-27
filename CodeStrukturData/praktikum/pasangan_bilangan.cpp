#include <iostream>
#include <list>
#include <string>

using namespace std;
typedef list<int> LI;

class DLL{
    LI dt1,dt2;
public:
    int isEmpty(){ return (dt1.empty() && dt2.empty());}
    void push_back(int val1,int val2){dt1.push_back(val1); dt2.push_back(val2); }
    void push_front(int val1,int val2){dt1.push_front(val1);dt2.push_front(val2);}

    void hapusdepan(){ dt1.pop_front(); dt2.pop_front();}
    void hapusbelakang() { dt1.pop_back(); dt2.pop_back();}
    void sisip(int data1,int data2,int posisi);
    void del(int posisi);
    void print();
};

void DLL::sisip(int val1,int val2,int posisi){
    LI::iterator it1 = dt1.begin();
    LI::iterator it2 = dt2.begin();
    for(int i=0;i<posisi-1;i++){
        ++it1;
        ++it2;
    }
    dt1.insert(it1,val1);
    dt2.insert(it2,val2);
}
void DLL::del(int posisi){
    LI::iterator it1 = dt1.begin();
    LI::iterator it2 = dt2.begin();
    for(int i=0;i<posisi-1;i++){
        ++it1;
        ++it2;
    }
    if(posisi <= dt1.size() && posisi <= dt2.size()){
        dt1.erase(it1);
        dt2.erase(it2);
    }
}

void DLL::print(){
    LI::iterator it1 = dt1.begin();
    LI::iterator it2 = dt2.begin();
    //cout << endl;
    for(;it1!=dt1.end();++it1){
        cout << (*it1) << " " << (*it2) << endl;
        ++it2;
    }
    cout << endl;
}

/*
LI::iterator DLL::find(int val){
    LI::iterator it;
    for(it=dt.begin();it!=dt.end();++it)
        if((*it) == val) return it;
    return it;
}


void DLL::push_after(int val,int after){
    LI::iterator it=find(after);
    if(it!=dt.end()){
        ++it;
        dt.insert(it,val);
    }
}
void DLL::del(int val){
    LI::iterator it=find(val);
    if(it!=dt.end()) dt.erase(it);
}
*/

int main(){
    DLL list;
    int n,data1,data2,aksi,ambil1,ambil2,posisi;
    string coba;


    cin >> n;
    while(n--){
        cin >> data1 >> data2;
        list.push_back(data1,data2);
    }
    cin >> aksi;
    while(aksi--){
        cin >> coba;
        if(coba == "hapusdepan"){
            list.hapusdepan();
        }else if(coba == "hapusbelakang"){
            list.hapusbelakang();
        }else if(coba == "sisipawal"){
            cin >> ambil1 >> ambil2;
            list.push_front(ambil1,ambil2);
        }else if(coba ==  "sisipakhir"){
            cin >> ambil1 >> ambil2;
            list.push_back(ambil1,ambil2);
        }else if(coba == "sisip"){
            cin >> ambil1 >> ambil2 >> posisi;
            list.sisip(ambil1,ambil2,posisi);
        }else if(coba ==  "hapus"){
            cin >> posisi;
            list.del(posisi);
        }else{
            break;
        }
    }
    list.print();
    return 0;
}

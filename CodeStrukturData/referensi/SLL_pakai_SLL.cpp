#include <utility>
#include <iostream>
#include <forward_list>
#include <string>

using namespace std;

//typedef par<string, float> P;
//typedef forward_list<P> SLLP;

class SLL{
    SLLP dt;
    void push_front(string nim,float ipk);
    void push_back(string nim, float ipk);
    void push_after(string nim,float ipk, string after);
    void del(string nim);
    SLLP::iterator find(string nim);
    void print();
};

void SLL::print(){
    SLLP::iterator it;
    for(it=dt.begin();it!=dt.end();++it){
        cout << "(" << it->first << "," << it->second << ")->";
    }
    cout << "NULL"<< endl;
}

void SLL::push_front(string nim, float ipk){
    P t=make_pair(nim,ipk);
    dt.push_front(t);
}
void SLL::push_back(string nim,float ipk){
    P t=make_pair(nim,ipk);

    if(dt.empty())
        dt.push_front(t);
    else{
        SLLP::iterator before=dt.begin();
        SLLP::iterator it=dt.begin();
        for(;it!=dt.end();before=it,++it);
        dt.insert_after(before,t);
    }
}
int main(){
    return 0;
}

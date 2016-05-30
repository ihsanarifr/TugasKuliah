#include <iostream>
#include <list>

using namespace std;
typedef list<int> LI;

class DLL{
    LI dt;
public:
    int isEmpty(){ return dt.empty();}
    void push_back(int val){dt.push_back(val);}
    void push_front(int val){dt.push_front(val);}
    void push_after(int val,int after);
    LI::iterator find(int val);
    void del(int val);
    void print();
};

void DLL::print(){
    LI::iterator it;
    for(it=dt.begin();it!=dt.end();++it)
        cout << (*it) << "->";
    cout << "NULL" << endl;
}

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
int main(){
    DLL list;
    list.push_back(10);
    list.push_front(20);
    list.push_front(30);
    list.push_after(10,50);
    list.del(20);
    list.print();
    return 0;
}

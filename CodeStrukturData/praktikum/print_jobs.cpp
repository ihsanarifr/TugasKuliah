#include <iostream>
#include <iomanip>
#include <string>

#define SIZE 32
using namespace std;

class Stack{
    int stack[SIZE];
    int atas;
    string nama;
public:
    Stack(){atas=SIZE;nama="";}
    bool empty(){return atas==SIZE;}
    bool full(){return atas==0;}
    void push(string nama,int value);
    void pop();
    int top();
    int size(){return SIZE-atas;}
    int getAtas() {return atas;}
    int *getStack() {return stack;}
    string getNama(){ return nama;}
    void setNama(string nama){ nama=nama; }
};

void Stack::push(string nama, int val){
    if(full())
        cout << "Stack is full\n";
    else{
        setNama(nama);
        stack[--atas]=val;
    }
}

void Stack::pop(){
    if(empty())
        cout << "Stack is empty\n";
    else
        ++atas;
}

int Stack::top(){
    if(empty()){
        cout << "Stack is empty\n";
        return 0;
    }else{
        return stack[atas];
    }
}

ostream& operator<< (ostream &out,Stack &s){
    if(s.empty())
        out << "Stack is empty\n";
    else{
        for(int i=s.getAtas();i<s.getAtas()+s.size();++i)
            out << s.getNama() <<s.getStack()[i] << endl;
    }
    return out;
}

int main(){
    Stack st;
    st.push("ihsan",50);
    st.push("arif",15);
    st.push("rahman",20);
    cout << "Stack Awal\n";
    cout << st;
    int nilai=st.top();
    st.pop();
    cout << "\nHasil pop(): " << nilai << endl;
    cout << "\nStack Akhir\n";
    cout << st;
    return 0;
}

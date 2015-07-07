#include <iostream>
#include <iomanip>
#define SIZE 100
using namespace std;

class Stack{
    int stack[SIZE];
    int atas;
public:
    Stack(){atas=SIZE;}
    bool empty(){return atas==SIZE;}
    bool full(){return atas==0;}
    void push(int value);
    void pop();
    int top();
    int size(){return SIZE-atas;}
    int getAtas() {return atas;}
    int *getStack() {return stack;}
};

void Stack::push(int val){
    if(full())
        cout << "Stack is full\n";
    else{
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
            out << s.getStack()[i] << endl;
    }
    return out;
}

int main(){
    Stack st;
    st.push(50);
    st.push(15);
    st.push(20);
    cout << "Stack Awal\n";
    cout << st;
    int nilai=st.top();
    st.pop();
    cout << "\nHasil pop(): " << nilai << endl;
    cout << "\nStack Akhir\n";
    cout << st;
    return 0;
}

#include <iostream>
#include <iomanip>
#define SIZE 100
using namespace std;

class Stack{
    string stack[SIZE];
    int atas;
public:
    Stack(){atas=SIZE;}
    bool empty(){return atas==SIZE;}
    bool full(){return atas==0;}
    void push(string value);
    void pop();
    string top();
    int size(){return SIZE-atas;}
    int getAtas() {return atas;}
    //string *getStack() {return stack;}
};

void Stack::push(string val){
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

string Stack::top(){
    if(empty()){
        cout << "Stack is empty\n";
        return 0;
    }else{
        return stack[atas];
    }
}

int main(){
    string kata;
    Stack stak;

    cin >> kata;
    while(kata != "STOP"){
        stak.push(kata);
        cin >> kata;
    }

    int n = stak.size();
    for(int i=0;i<n-1;i++){
        cout << stak.top() << " ";
        stak.pop();
    }
    cout << stak.top() <<  endl;
    stak.pop();
    return 0;
}

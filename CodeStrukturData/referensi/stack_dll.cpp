#include <iostream>
#include <list>

using namespace std;

class Stack{
    list<int> stack;
    list<int>::iterator atas;
public:
    Stack(){atas=stack.begin();}
    bool empty(){return (atas==stack.end());}
    int size(){ return stack.size();}
    void push(int nilai);
    void pop();
    int top();
    list<int>::iterator getAtas() {return atas;}
    list<int> getStack() {return stack;}
};
void Stack::push(int val){
    stack.push_front(val);
    atas=stack.begin();
}
void Stack::pop(){
    if(empty())
        cout << "Stack is empty\n";
    else{
        ++atas;
        stack.pop_front();
    }
}

int Stack::top(){
    return (*atas);
}

ostream& operator<< (ostream &out, Stack &s){
    if(s.empty())
        out << "Stack is empty\n";
    else{
        list<int>::iterator it=s.getAtas();
        for(int i=0;i<s.size();++it,++i)
            out << (*it) << endl;
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

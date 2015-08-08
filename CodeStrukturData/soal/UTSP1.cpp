#include<iostream>
#include<list>
#include<string>

using namespace std;

class Stack{
    list<string> st;
public:
    void push(string data){ st.push_back(data);}
    void pop(){ st.pop_back();}
    string top(){ return st.back(); }
    int size(){ return st.size();}
};

int main(){
    string kata;
    Stack stak;

    cin >> kata;
    while(kata != "STOP"){
        stak.push(kata);
        cin >> kata;
    }

    int n = stak.size();
    for(int i=0;i<n;i++){
        cout << stak.top() << " ";
        stak.pop();
    }
    cout << endl;
    return 0;
}

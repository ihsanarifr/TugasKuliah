#include <iostream>
#include <stack>
typedef stack<int> Stack;

ostream& operator<< (ostream &out, Stack &s){
    if(s.empty())
        out << "Stack is empty\n";
    else{
        while(!(s.empty())){
            int t = s.top();
            out << t << endl;
            s.pop();
        }
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

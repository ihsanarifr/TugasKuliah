#include<iostream>
#include<iomanip>
#include<string>
#include<cctype>
#include<stack>

using namespace std;
typedef stack<int> Stack;

ostream& operator<< (ostream &out, Stack s){
    if(s.empty()) out << "stack is empty\n";
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
    stack<int> st;
    string str;
    getline(cin,str);
    for(int i=0;i<str.size();i++){
        char ch=str.at(i);
        if(isdigit(ch)){
            int t= (int)ch-48;
            st.push(t);
        }
    }
    cout << st.stop() << endl;
    return 0;
}

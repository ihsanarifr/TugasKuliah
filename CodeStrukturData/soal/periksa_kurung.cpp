#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <stack>
using namespace std;

int main() {
    stack<int> st;
    string str;

    getline(cin, str);

    for (int i=0; i<str.size(); i++) {
        char ch=str.at(i);

        //if (isdigit(ch)) {
            //int t = (int)ch-48;
            st.push(ch);
        //} //else {
        // ambil 2 node dan lakukan operasi
        // simpan hasilnya ke stack
        //}
    }

    cout << st.top() << endl;

    return 0;
}

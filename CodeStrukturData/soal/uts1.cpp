/*
 Dengan menggunakan stack, balikkanlah urutan kemunculan kata dari sebuah kalimat yang diberikan.
Format Masukan

Masukkan terdiri atas paling banyak 1000 kata dengan panjang maksimum 20 karakter. Kata "STOP" menandakan akhir kata dan kata "STOP" tidak ikut diproses.
Format Keluaran

Kata-kata yang telah dibalik urutannya, diakhiri dengan karakter newline.
Contoh Masukan

Aku ingin begini aku ingin begitu ingin ini ingin itu STOP

Contoh Keluaran

itu ingin ini ingin begitu ingin aku begini ingin Aku

*/

#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<string> kata;
public:
    void push(string data){ this->kata.push_back(data);}
    void pop(){ kata.pop_back();};
    string top(){ return kata.back();};
    int size(){ return kata.size();};
};

int main() {
    Stack stack;
    string masuk;

    cin >> masuk;

    while(masuk != "STOP") {
        stack.push(masuk);
        cin >> masuk;
    }

    int n = stack.size();
    for(int i = 0; i < n-1; i++) {
        cout << stack.top() << " ";
        stack.pop();
    }

    cout << stack.top() << endl;
    stack.pop();
    return 0;
    }

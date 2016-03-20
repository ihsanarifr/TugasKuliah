// Program menuliskan teks Hello World
#include <iostream>
#include <iomanip>      // std::setprecision
using namespace std;
int main() {
    int a;
    long b;
    double c;
    cin >> a >> b >> c;
    cout << a << " ";
    std::cout << std::setprecision(4) << c << " ";
    cout << b << endl;
    //cout << "Welcome World!" << endl;
    return 0;
}

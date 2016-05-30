// Program menuliskan teks Hello World
#include <iostream>
#include <iomanip> //std::setprecision
using namespace std;
int main() {
    double a,b,c;
    cin >> a >> b ;
    c = a + b;
    cout << fixed << setprecision(2) << c << endl;
    //std::cout << std::setprecision(3) << c << endl;
    return 0;
}

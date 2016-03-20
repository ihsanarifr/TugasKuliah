#include <iostream>
#include<iomanip>

using namespace std;

int main()
{
    int a;
    int b;
    float c;

    cin >> a >> b;
    cin >> c;

    cout << a << fixed << " " << setprecision(2) << c;
    cout << " " << b;

    return 0;
}

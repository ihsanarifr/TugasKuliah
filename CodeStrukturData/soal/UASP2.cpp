#include<iostream>

using namespace std;

int main(){
    int temp[101]= {0};
    int a,b,c,d,e,i,x,y,sum;

    cin >> a >> b;
    for(i=0;i<b;i++){
        cin >> c >> d >> e;
        temp[c]++;
        temp[d]++;
        temp[e]++;
    }
    cin >> x >> y;
    sum = temp[x]+temp[y];
    cout << sum << endl;


    return 0;
}

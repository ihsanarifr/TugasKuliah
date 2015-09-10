#include<iostream>

using namespace std;

int main(){
    int backup[101]= {0};
    int a,b,c,d,e,i,x,y,jumlah;

    cin >> a >> b;
    for(i=0;i<b;i++){
        cin >> c >> d >> e;
        backup[c]++;
        backup[d]++;
        backup[e]++;
    }
    cin >> x >> y;
    jumlah = backup[x]+backup[y];
    cout << jumlah << endl;


    return 0;
}

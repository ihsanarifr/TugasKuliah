#include <iostream>
#include <iomanip>
#define N 101


using namespace std;

int main(){
    int n,a,b,c,banyak=0;
    int i,j,k,l;
    cin >> n >> a;
    int jembatan[N][N]={0};
    int total[N]={0};

    for(i=0;i<n;i++){
        cin >> b >> c;
        jembatan[b][c]=jembatan[c][b]=1;
    }

    for(j=1;j<=n;j++){
        for(k=1;k<=n;k++){
            banyak=banyak+jembatan[j][k];
        }
        total[j]=banyak;
        banyak=0;
    }

    for (l=1;l<=n;l++){
        cout << total[l] << endl;
    }
    return 0;
}

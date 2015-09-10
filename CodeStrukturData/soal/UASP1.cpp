#include <iostream>
#include <iomanip>
#define N 101


using namespace std;

int main(){
    int n,a,b,c,count=0;
    int i,j,k,l;
    int bridge[N][N]={0};
    int total[N]={0};

    cin >> n >> a;

    for(i=0;i<n;i++){
        cin >> b >> c;
        bridge[b][c]=bridge[c][b]=1;
    }

    for(j=1;j<=n;j++){
        for(k=1;k<=n;k++){
            count=count+bridge[j][k];
        }
        total[j]=count;
        count=0;
    }

    for (l=1;l<=n;l++){
        cout << total[l] << endl;
    }
    return 0;
}

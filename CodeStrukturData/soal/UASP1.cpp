#include <iostream>
#include <iomanip>
#define N 101

using namespace std;

int main(){
    int n,KotaA,KotaB,KotaC;
    int count=0;
    int i,j,k,l;

    cin >> n >> KotaA;

    int bridge[N][N]={0};
    int sum[N]={0};

    for(i=0;i<KotaA;i++){
        cin >> KotaB>> KotaC;
        bridge[KotaB][KotaC]=bridge[KotaC][KotaB]=1;
    }

    for(j=1;j<=n;j++){
        for(k=1;k<=n;k++){
            count=count+bridge[j][k];
        }
        sum[j]=count;
        count=0;
    }

    for (l=1;l<=n;l++){
        cout << sum[l] << endl;
    }
    return 0;
}

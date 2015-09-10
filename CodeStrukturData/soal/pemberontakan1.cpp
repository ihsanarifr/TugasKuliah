#include <iostream>
#include <iomanip>
#define N 101

using namespace std;

int main(){
    int n,KotaA,KotaB,KotaC;
    int bnyk=0;
    int i,j,k,l;
    cin >> n >> KotaA;
    int jembatan[N][N]={0};
    int jumlah[N]={0};

    for(i=0;i<KotaA;i++){
        cin >> KotaB>> KotaC;
        jembatan[KotaB][KotaC]=jembatan[KotaC][KotaB]=1;
    }

    for(j=1;j<=n;j++){
        for(k=1;k<=n;k++){
            bnyk=bnyk+jembatan[j][k];
        }
        jumlah[j]=bnyk;
        bnyk=0;
    }

    for (l=1;l<=n;l++){
        cout << jumlah[l] << endl;
    }
return 0;
}

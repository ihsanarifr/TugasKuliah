#include<iostream>

#include<stdio.h>
using namespace std;

int main(){
    int n,i;
    cin >> n;

    for(i=1;i<n;++i){
        if(i == 93)
        {
            cout << "ERROR" << endl;
            break;
        }else{
            cout << i << endl;
        }
    }
    return 0;
}

#include <iostream>
using namespace std;

class myData{
    int nilai[1001];
    public:
        myData(){ nilai[1001]={0};}
        void insert(int x) { nilai[x]=1; }
        bool find (int x) { return nilai[x]==1; }
};

int main()
{
    myData dt;
    int x;
    cin>>x;
    while (x!= -9)
    {
        dt.insert(x);
        cin>>x;
    }

    int n;
    cin>>n;
    while(n--)
    {
        cin>>x;
        if(dt.find(x))
            cout<<x<<" ada"<<endl;
        else cout<<x<<" tidak ada"<<endl;
    }
    return 0;
}

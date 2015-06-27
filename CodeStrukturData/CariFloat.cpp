#include <iostream>
using namespace std;

class myData{
    double nilai[1001];
    public:
        myData(){ nilai[1001]={0};}
        void insert(int i,double x) { nilai[i]=x; }
        //bool find (int x) { return nilai[x]==1; }
};

int main()
{
    myData dt;
    double x;
    int i=0;
    cin>>x;
    while (x!= -9)
    {
        ++i;
        dt.insert(i,x);
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

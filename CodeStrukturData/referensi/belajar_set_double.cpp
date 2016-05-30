#include<iostream>
#include<set>

using namespace std;

class myData
{
private:
    set<double> myset;
    set<double>::iterator it;

public:
    void masuk(double x)
    {
        myset.insert(x);
    }
};
int main()
{
    int x,n;
    myData d;
    cin >> x;
    while(x!=-9)
    {
        d.find()
        cin >> x;
    }

    cin >> x;
    while(x--)
    {
        cin >> n;
        it=myset.find(n);
        if(*it==n)
        {
            cout << n << " ada" << endl;
        }
        else
        {
            cout << n << " tidak ada"<< endl;
        }
    }

    //cout << "myset containts:";

    //for(it=myset.begin();it!=myset.end();++it)
    //{
    //    cout << " " << *it;
    //}
    //cout << endl;

    return 0;
}

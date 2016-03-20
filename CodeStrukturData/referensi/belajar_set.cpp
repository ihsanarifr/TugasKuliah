#include<iostream>
#include<set>

using namespace std;

int main()
{
    int x,n;
    set<int> myset;
    set<int>::iterator it;

    cin >> x;
    while(x!=-9)
    {
        myset.insert(x);
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

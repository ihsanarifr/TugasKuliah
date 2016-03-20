#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int x,n;
    vector<int> myset;
    vector<int>::iterator it;

    cin >> x;
    it=myset.begin();
    while(x!=-9)
    {
        myset.insert(it,x);
        cin >> x;
    }

    /*cin >> x;
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
    */
    cout << "myset containts:";

    for(it=myset.begin();it!=myset.end();++it)
    {
        cout << " " << *it;
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <set>
using namespace std;

class myData{
    int x,n;
    set<int> myset;
    set<int>::iterator it;

    public:
        void insert(int x) { myset.insert(x); }
        void cek()
        {
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
        }
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
    dt.cek();
    return 0;
}

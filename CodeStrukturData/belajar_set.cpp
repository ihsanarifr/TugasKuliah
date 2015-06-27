#include<iostream>
#include<set>

using namespace std;

int main()
{
    int myints[] = {1,2,3,4,5};
    int x;
    set<int> myset (myints,myints+5);
    set<int>::iterator it;

    cout << "myset containts:";

    for(it=myset.begin();it!=myset.end();++it)
    {
        cout << " " << *it;
    }
    cout << endl;

    return 0;
}

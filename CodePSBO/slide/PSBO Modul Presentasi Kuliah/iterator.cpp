#include <iostream>
#include <vector>
#include <set>
using namespace std;

template <class T, class I>
int sum(T input, I it)
{
    int s = 0;
    //T::iterator;// it;
    for(it=input.begin(); it!=input.end(); ++it)
     s += *it;
    return s;
}

int sum(vector<int> v)
{
    int jum=0;
    for(int i=0;i<v.size();i++)
     jum += v[i];
    return jum;
}

int main ()
{
    vector<int> myvector;
    set<int> myset;
    for (int i=1; i<=5; i++) 
    	myvector.push_back(i);
    for (int i=1; i<=5; i++) 
    	myset.insert(i);
   	
   	
    //cout<<myset[2]<<endl;
    vector<int>::iterator it1; set<int>::iterator it2;
    
    it1=myvector.begin();
    *it1 = 10;
    
    it1++;
    *it1 = 20;
    
    cout << " myvector contains:";
    for (it1=myvector.begin() ; it1 != myvector.end(); it1++ )
        cout << " " << *it1;
    cout<<endl;
    cout << " myset contains:";    
    for (it2=myset.begin() ; it2 != myset.end(); it2++ )
        cout << " " << *it2;
    cout<<endl;
    
    int a = sum< vector<int> >(myvector, it1);
    int b = sum< set<int> >(myset, it2);
    
    cout<<"vector sum = "<<a<<endl;
    
    cout << endl;
    
    system("pause");
    return 0;
}



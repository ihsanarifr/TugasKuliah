#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> myarray;
    myarray.push_back(10);
    myarray.push_back(20);
    vector<int> revarray (myarray.rbegin(),
                         myarray.rend());

    for(int i=0;i<myarray.size();i++)
    {
        cout << myarray[i] << " ";
    }
    cout << endl;
    for(int i=0;i<revarray.size();i++)
    {
        cout << revarray[i] << " ";
    }
    return 0;
}

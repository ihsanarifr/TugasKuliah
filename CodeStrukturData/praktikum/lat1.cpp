#include <vector>
#include <iostream>

using namespace std;

int main(){
    vector<int> myarray;
    //myarray = {1,3,5,7,9,11,13,15,17,19};
    myarray.push_back(1);
    myarray.push_back(3);
    myarray.push_back(5);
    myarray.push_back(7);
    myarray.push_back(9);
    myarray.push_back(11);
    myarray.push_back(13);
    myarray.push_back(15);
    myarray.push_back(17);
    myarray.push_back(19);

    vector<int> revarray(myarray.rbegin(),
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

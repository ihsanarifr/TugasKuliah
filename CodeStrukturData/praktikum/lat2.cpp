#include <vector>
#include <iostream>

using namespace std;

class myData{
    vector<int> myarray;
    int n, data;
public:
    myData(){ n=data=0; }
    void input()
    {
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >> data;
            myarray.push_back(data);
        }
    }
    void print_rev()
    {
        vector<int> revmyarray(myarray.rbegin(),myarray.rend());
        for(int i=0;i<revmyarray.size();i++)
        {
            cout << revmyarray[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    myData dt;
    dt.input();
    dt.print_rev();
}

#include <vector>
#include <iostream>

/* kebalikannya */

using namespace std;

class myData{
    vector<int> myarray,inp;
    int n,m, data;
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

    void cek()
    {
        vector<int> revmyarray(myarray.rbegin(),myarray.rend());
        int status=0;
        cin >> m;
        for(int i=0;i<n;i++)
        {
            cin >> data;
            inp.push_back(data);
        }
        if(revmyarray==inp)
        {
            cout << "Kebalikannya";
        }
        else
        {
            cout << "Bukan Kebalikannya";
        }
        /*if(n<m)
        {
            cout << "Bukan kebalikannya";
        }else
        {
            for(int i=0;i<n;i++)
            {
                cin >> data;
                inp.push_back(data);
                if(revmyarray[i]!=inp[i])
                {
                    status = 1;
                }
            }
            if(status == 1) { cout << "Bukan kebalikannya"; } else { cout << "Kebalikannya"; }
        }*/
    }
};
int main(){
    myData dt;
    dt.input();
    dt.cek();
}

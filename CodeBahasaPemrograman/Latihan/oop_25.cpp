#include <iostream>
#include<iomanip>
#include <vector>
using namespace std;

int main ()
{
  int i;

  vector<int> v6;
  int t,hapus,CountOrigin,CountModified, hasilOrigin=0,hasilModified=0;
  double RataOrigin, RataModified;

  cin >> t;
  do{
    v6.push_back(t);
    cin >> t;
  }while (t!= -9);

  for (i=0; i < v6.size(); i++)
    hasilOrigin += v6[i];

  CountOrigin = v6.size();
  RataOrigin = double(hasilOrigin) / double(CountOrigin);

  cin >> hapus;
  i=0;
  do{
    if(hapus == 1){
        v6.erase(v6.begin());
        cin >> hapus;
        i++;
    }else{
        v6.erase(v6.begin()+hapus-i-1);
        cin >> hapus;
        i++;
    }
  }
  while(hapus != -9);

  for (i=0; i < v6.size(); i++)
    hasilModified += v6[i];

  CountModified = v6.size();
  RataModified = double(hasilModified) / double(CountModified);

  cout << CountOrigin << " " << CountModified << endl;

  if(v6.empty())
    cout << -9.99 << endl;
  else
    cout << fixed << setprecision(2) << RataOrigin << " " << fixed << setprecision(2) << RataModified << endl;

  return 0;
}

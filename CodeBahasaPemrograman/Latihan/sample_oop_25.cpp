#include <iostream>
#include <vector>
using namespace std;

int main ()
{
  unsigned int i;

  vector<int> v1;                               // empty vector
  vector<int> v2 (4,100);                       // 4 nilai 100
  vector<int> v4 (v2);                          // copy dari v2

  // mengisi vector dari array tertentu
  int myints[] = {16,2,77,29};
  vector<int> v5 (myints, myints + sizeof(myints) / sizeof(int) );

  // mengisi 5 nilai vector dari standard input

  vector<int> v6;                               // empty vector
  int t;
  for (i=0; i<5; i++) {
     cin >> t;
     v6.push_back(t);
  }

  cout << "Isi vector v5\n";
  for (i=0; i<v5.size(); i++)
    cout << " " << v5[i];

  cout << "\n\nIsi vector v6\n";

  for (i=0; i < v6.size(); i++)
    cout << " " << v6[i];

  cout << endl;

  return 0;
}

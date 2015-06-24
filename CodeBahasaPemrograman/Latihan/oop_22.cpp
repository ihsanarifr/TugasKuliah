#include <cstdlib>
#include <iostream>
#include <iomanip> //std::setprecision

   using namespace std;
   template <typename T>
   /*T maksimum(T n1, T n2, T n3) {
      T besar = n1;
      if (n2>besar) besar=n2;
      if (n3>besar) besar=n3;
      return besar;
   }
   */
   T rataan(T n1, T n2){
       T hasil[2];
       hasil[0] = n1;
       hasil[1] = n2;
       return hasil;
   }
   int main() {
      // akan memanggil maksimum<int> sesuai dengan tipe data masukan
      //cout << maksimum(10,2,15) << endl;

      // akan memanggil maksimum<double> sesuai dengan tipe data masukan
      //cout << maksimum(2.3, 10.5, 7.251) << endl;

      // krn data masukan membingungkan,
      // maka dipaksa memanggil maksimum<double>
      //cout << maksimum<double>(3,7.5,10) << endl;
      int iterasi;
      double a,i,a1=0.00,b,b1=0.00;

      cin >> iterasi;
      for(i=0;i<iterasi;i++){
            cin >> a >> b;
            //rataan(a,b);
            a1=a1+a;
            b1=b1+b;
        }
        cout << fixed << setprecision(2) << double(a1/iterasi*1.00) << " " << fixed << setprecision(2) << b1/iterasi << endl;
        //rataan(a,b);

      return 0;
   }

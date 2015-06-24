#include <cstdlib>
#include <iostream>

using namespace std;
int floor(double x){
                int a;
                a=x;
                return a;}

int ceil(double x){
                int a;
                a=x;
                if (a!=x)   {
                                return a+1;              }
                else         {
                                return a;  }}
int round(double x){
                int a;
                double c;
                a=x;
                c=(x-a);
                if (c>=0.5){
                                return a+1;}
                else         {
                                return a;  }}

int main(){
                double a;
cout<<"Program Pembulatan \n"<<endl;
cout<<"Masukan angka yang akan dibulatkan : ";
 cin>>a;
cout<<"FLOOR : " << floor(a) << " (dibulatkan kebawah)\n";
cout<<"CEIL  : " << ceil(a) <<  " (dibulatkan keatas)\n";
cout<<"ROUND : " << round(a) << " (dibulatkan keatas jika lebih besar dari 0,5)\n\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}

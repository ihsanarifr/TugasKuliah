#include <iostream>
#include <string>
using namespace std;



//class Person
//{
//    protected:
//        string nama;
//        int usia;
//        
//        
//    public:
//         Person()
//        :nama(""),usia(0)
//        {}
//        
//        Person(string n, int u)
//        :nama(n),usia(u)
//        {}
//        
//        string getnama() const
//        {
//                return nama;
//        }
//        int getusia() const
//        {
//                return usia;
//        }
//        
//        Person operator=(const Person& a)
//        {
//                this->nama = a.nama;
//                this->usia = a.usia;
//                return (*this);
//        }
//    
//};
//
//ostream& operator<<
//(ostream& os, const Person& p)
//{
//    os<<"Nama :"<<p.getnama()<<endl;
//    os<<"Usia :"<<p.getusia()<<endl;
//    return os;
//}

const int MAX = 100;

template <class T>
class Stack
{
    protected:
        int top;
        T arr[MAX];
    
    public:
        Stack()
        :top(0)
        {}
        
        void push(T a)
        {
            arr[top++] = a;
        }
        T pop()
        {
            T a = arr[--top];
            return a;
        }
};

class Pecahan
{
    protected:
        int a;
        int b;
    public:
        Pecahan(int a_p, int b_p)
        :a(a_p), b(b_p)
        {
                //cout<<"konstruktor 2 arg"<<endl;
        }
        
        Pecahan()
        :a(0), b(1)
        {
                //cout<<"konstruktor tanpa arg"<<endl;
        }
        
        Pecahan(int n)
        :a(n), b(1)
        {
                //cout<<"konstruktor 1 arg"<<endl;
        }
        
        
        void tampil()
        {
                cout<<a<<"/"<<b;
        }
        
        void set_a(int a)
        {
                this->a = a;
        }
        void set_b(int b)
        {
                this->b = b;
        }
        
        int get_a() const
        {
                return a;
        }
        int get_b() const
        {
                return b;
        }
             
       Pecahan operator=(const Pecahan& y)
       {
              this->a=y.a;
              this->b=y.b;
              return (*this);
       }
       
       
       //
       Pecahan operator++()
       {
              this->a = this->a + this->b;
              return (*this);
       }
       
       bool operator<(const Pecahan& p) const
       {
              return (this->a*p.b < this->b*p.a);
       }
       
};


template <class T>
void swap(T& a, T& b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <class T>
void mysort(T* a, unsigned n)
{
    int i,j, min;
    for(i=0;i<n;i++)
    {
        min = i;
        for(j=i+1; j<n; j++)
        {
                if(a[j]<a[min])
                  min = j;
        }
        swap(a[min], a[i]);
    }
}

int main()
{
    int a = 3, b = 2;
    swap<int>(a,b);
   
    cout<<"a = "<<a<<" b = "<<b<<endl;
   
    double x=2.1, y = 3.4;
    swap<double>(x,y);
    
    cout<<"x = "<<x<<" y = "<<y<<endl;
    
    Stack<int> S;
    S.push(3);
    S.push(4);
    a = S.pop();
    cout<<"a = "<<a<<endl;
    
    int data[3] = {2,1,5};
    mysort(data,3);
    int i;
    for(i=0; i<3; i++)
        cout<<data[i]<<endl;
        
        
        
    Pecahan pec[3];
    pec[0] = Pecahan(1,2);
    pec[1] = Pecahan(2,3);
    pec[2] = Pecahan(1,1);
    
    mysort<Pecahan>(pec,3);
    for(i=0; i<3; i++)
    {
        pec[i].tampil();
        cout<<endl;
    }
    
    return 0;
}


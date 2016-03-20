#include<iostream>
#include<iomanip>

using namespace std;

class Lingkaran{
    private:
    double radius;
    int x,y;

    public:
    Lingkaran(){ radius = 1.0; x=0;y=0;}
    Lingkaran(double r,int p,int q)
    {
        radius = r;
        x = p;
        y = q;
    }
    void set(int p,int q)
    {
        x = p;
        y = q;
    }
    void set(double r)
    {
        radius = r;
    }

    double getR()
    {
        return radius;
    }

    void print()
    {
        cout << "Lingkaran:" << "(" << x << "," << y << ")" << fixed << setprecision(2) << radius;
    }
};

int main(){
    Lingkaran circle;

    circle.set(1,2);
    circle.set(0.25);
    circle.print();
    return 0;
}

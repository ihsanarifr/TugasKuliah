//#include "stdafx.h"
#include <iostream>
using namespace std;

class Cari
{
public:
    Cari();
	void input();
	void mencari();
	void print();
private:
	int bil[1001];
	int n;
	int x;
};

Cari::Cari()
{
    n=0; x=0; //bil[1001]={0};
}
void Cari::input()
{
	cin >> n;
	while (n != -9)
	{
		if (bil[n] != 1)
		{
			bil[n] = 1;
		}
		cin >> n;
	}
}

void Cari::mencari()
{
	cin >> x;
	for (int i = 0; i < x; i++)
	{
		cin >> n;
		if (bil[n] == 1)
		{
			cout << n << " ada" << endl;
		}
		else
		{
			cout << n << " tidak ada" << endl;
		}
	}
}


int main()
{
	Cari c;
	c.input();
	c.mencari();
	//_getch();
	return 0;
}

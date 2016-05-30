#include<ios>
#include<iostream>
#include<iomanip>
#include<map>
#include<string.h>

using namespace std;

int main(){
    map<string,double> peta;
    peta["wakwaw"] = 38.3;
    peta["Sule"] = 43.5;
    peta["Marjan"] = 55.3;

    map<string,double>::iterator it;
    for(it=peta.begin();it!=peta.end();++it)
        cout << (*it).first << " " << (*it).second << endl;
    return 0;
}

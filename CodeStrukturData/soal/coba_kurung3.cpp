#include<iostream>
using namespace std;
int getMaxDepth(string s){
	int max=0;
	int max_currLen=0;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]=='('){
			max_currLen++;
			if(max<max_currLen){
				max=max_currLen;
			}
		}else if(s[i]==')'){
				if(max_currLen>0){
					max_currLen--;
				}
		    	else
		    	  return -1;
			}
		}
	if(max_currLen!=0)
		return -1;
	return max;
}
int main(){
    string s;
    cin>> s;
    cout<< getMaxDepth(s);
	return 0;
}

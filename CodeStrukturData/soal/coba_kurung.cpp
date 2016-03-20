/*
  C++ Program to check for balanced parentheses in an expression using stack.
  Given an expression as string comprising of opening and closing characters
  of parentheses - (), curly braces - {} and square brackets - [], we need to
  check whether symbols are balanced or not.

  https://gist.github.com/mycodeschool/7207410
*/

#include<iostream>
#include<stack>
#include<string>

using namespace std;
// Function to check whether two characters are opening
// and closing of same type.
bool ArePair(char opening,char closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	else if(opening == '<' && closing == '>') return true; // ditambahkan
	return false;
}
int AreParanthesesBalanced(string exp)
{
    int current_max = 0; // current count
    int max = 0;    // overall maximum count

	stack<char>  S;
	for(int i =0;i<exp.length();i++)
        {
            if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[' || exp[i] == '<'){
                S.push(exp[i]);

                // Penambahan
                current_max++;
                // update max if required
                if (current_max> max)
                    max = current_max;
            }
            else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']' || exp[i] == '>')
            {
                // Penambahan dihitung
                if (current_max>0)
                    current_max--;
                else
                    return 0;

                if(S.empty() || !ArePair(S.top(),exp[i]))
                    return 0;
                else
                    S.pop();
            }else{
                return 0;
            }
    }
    if (current_max != 0)
        return 0;

    return max;//S.empty() ? true:false;

}

int main()
{
	/*Code to test the function AreParanthesesBalanced*/
	string expression;
	//cout<<"Enter an expression:  "; // input expression from STDIN/Console
	cin>>expression;
	if(expression.empty()){
        cout << 0;
	}else if(AreParanthesesBalanced(expression))
		cout<<AreParanthesesBalanced(expression);
	else
		cout<<"Tidak Valid";

    cout << endl;
    return 0;
}

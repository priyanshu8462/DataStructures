#include<iostream>
#include<conio.h>
#include<stack>
using namespace std;
bool isOperand(char c)
{
	if((c>='a' && c<='z') || (c>='A' && c<='Z'))
		return true;
	else
		return false;	
}
bool isOperator(char c)
{
	switch(c)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':return true;
		default :return false;				
	}
	
}

string PrefixToPostfix(string prefix)
{
	stack <string> s;
	for(int i=prefix.length();i>=0;i--)
	{
		if(isOperand(prefix[i]))
		{
			string op(1, prefix[i]);
			s.push(op);
		}
		else if(isOperator(prefix[i]))
		{
			string op1=s.top();
			s.pop();
			string op2=s.top();
			s.pop();
			string exp= op1 +  op2 + prefix[i] ;
			s.push(exp);
		}
	}
	
	return s.top();
}

int main()
{
	string postfix,prefix;
	cout<<"\nEnter a postfix string :";
	cin>>prefix;
	cout<<"\nPREFIX EXPRESSION :"<<prefix;
	postfix=PrefixToPostfix(prefix);
	cout<<endl<<"POSTFIX EXPRESSION :"<<postfix;
	getch();
	return 0;
}

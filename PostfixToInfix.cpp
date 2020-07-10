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

string PostfixToInfix(string postfix)
{
	stack <string> s;
	for(int i=0;i<postfix.length();i++)
	{
		if(isOperand(postfix[i]))
		{
			string op(1, postfix[i]);
			s.push(op);
		}
		else if(isOperator(postfix[i]))
		{
			string op1=s.top();
			s.pop();
			string op2=s.top();
			s.pop();
			string exp='('+ op2 + postfix[i] + op1 + ')';
			s.push(exp);
		}
	}
	
	return s.top();
}

int main()
{
	string infix,postfix;
	cout<<"\nEnter a postfix string :";
	cin>>postfix;
	cout<<"\nPOSTFIX EXPRESSION :"<<postfix;
	infix=PostfixToInfix(postfix);
	cout<<endl<<"INFIX EXPRESSION :"<<infix;
	getch();
	return 0;
}

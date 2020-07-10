#include<iostream>
#include<conio.h>
#include<stack>
using namespace std;
//fuction to check if character is operator
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
int precedence(char c)
{
	switch(c)
	{
		case '^':return 3;
		case '*':
		case '/':return 2;
		case '+':
		case '-':return 1;
		default :return -1;	
	}
}
string InfixToPostfix(stack <char> s,string infix)
{
	string postfix;
	for(int i=0;i<infix.length();i++)
	{
		if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z'))
		{
			postfix+=infix[i];
		}
		else if(infix[i]=='(')
		{
			s.push(infix[i]);
		}
		else if(infix[i]==')')
		{
			while((s.top()!='(') && (!s.empty()))
			{
				char temp=s.top();
				postfix+=temp;
				s.pop();
			}
			if(s.top())
			{
				s.pop();
			}
		}
		else if(isOperator(infix[i]))
		{
			if(s.empty())
			{
				s.push(infix[i]);
			}
			else
			{
				if(precedence(infix[i])>precedence(s.top()))
				{
					s.push(infix[i]);
				}
				else if((precedence(infix[i])==precedence(s.top())) && (infix[i]=='^'))
				{
					s.push(infix[i]);
				}
				else
				{
					while((!s.empty()) && (precedence(infix[i])<=precedence(s.top())))
					{
						char temp=s.top();
						postfix+=temp;
						s.pop();			
					}			
					s.push(infix[i]);
				}
			}
		}
	}
	while(!s.empty())
	{
		postfix+=s.top();
		s.pop();
	}
	return postfix;	
}
int main()
{
	string infix,postfix;
	cout<<"\nEnter an infix operation :";
	getline(cin,infix);
	stack <char> s;    //create a stack data structure from STL *check more
	cout<<"\nINFIX EXPRESSION :"<<infix;
	postfix =InfixToPostfix(s,infix);
	cout<<endl<<"POSTFIX EXPRESSION :"<<postfix;
	getch();
	return 0;
}

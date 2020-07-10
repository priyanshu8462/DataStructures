#include<iostream>
#include<conio.h>
#include<stack>
#include<algorithm>
using namespace std;
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

string InfixToPrefix(stack <char> s,string infix)
{
	string prefix;
	reverse(infix.begin(),infix.end());
	for(int i=0;i<infix.length();i++)
	{
		if(infix[i]=='(')
			infix[i]=')';
		else if(infix[i]==')')
			infix[i]='(';
	}
	
	for(int i=0;i<infix.length();i++)
	{
			if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z'))
				prefix+=infix[i];
				
			else if(infix[i]=='(')
				s.push(infix[i]);
			
			else if(infix[i]==')')
			{
				while((s.top()!='(' ) && (!s.empty()))
				{
					char temp=s.top();
					prefix+=temp;
					s.pop();
				}
				if(s.top()=='(')
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
						s.push(infix[i]);
					else if((precedence(infix[i])==precedence(s.top())) && (infix[i]=='^'))	
					{
						while((precedence(infix[i])==precedence(s.top())) && (infix[i]=='^'))
						{
							prefix+=s.top();
							s.pop();
						}
						s.push(infix[i]);
					}
					
					else if(precedence(infix[i])==precedence(s.top()))
						s.push(infix[i]);
					else
					{
						while((!s.empty()) && (precedence(infix[i])<precedence(s.top()))	)
						{
							prefix+=s.top();
							s.pop();
						}
						
						s.push(infix[i]);
					}	
				}
				
			}		
	}
	
	while(!s.empty())
	{
		prefix+=s.top();
		s.pop();
	}
	reverse(prefix.begin(),prefix.end());
	return prefix;			
}

int main()
{
	string infix,prefix;
	cout<<"\nEnter a infix string :";
	cin>>infix;
	stack <char> s;
	cout<<"\nINFIX EXPRESSION :"<<infix;
	prefix=InfixToPrefix(s,infix);
	cout<<endl<<"PREFIX EXPRESSION :"<<prefix;
	getch();
	return 0;
}

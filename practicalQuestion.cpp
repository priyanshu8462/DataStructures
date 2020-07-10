#include<iostream>
#include<conio.h>
using namespace std;
void func(char a[],char b[],int n1,int n2) 
{
	char c[100];
	int n3=0; 
	for(int i = 0; i<n1; i++)
	{
	bool found = false;
	for(int j = 0; j<n2; j++)
	{
	if(a[i] == b[j])
	{
	found = true;
	break;
	}
	}
	if(!found)
	c[n3++] = a[i];
	}
	for(int i = 0;i<n3;i++)
	cout<<c[i];
	 
}

int main()
{
	char a[50]={'p','r','i','y','a','n','s','h','u'};
	char b[50]={'m','a','t','h','e','m','a','t','i','c','s'};
	func(a,b,9,11);
	getch();
	return 0;
}

